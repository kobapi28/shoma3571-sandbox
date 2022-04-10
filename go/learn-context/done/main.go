package main

import (
	"context"
	"fmt"
	"sync"
)

var wg sync.WaitGroup

// キャンセルされるまでnumをひたすら送信し続けるチャネルを生成
func generator(done chan struct{}, num int) <-chan int {
	out := make(chan int)
	go func() {
		defer wg.Done()

	LOOP:
		for {
			select {
			case <-done: // doneチャネルがcloseされたらbreakが実行される
				break LOOP
			case out <- num: // キャンセルされてなければnumを送信
			}
		}

		close(out)
		fmt.Println("generator closed")
	}()
	return out
}

func useChannel() {
	done := make(chan struct{})
	gen := generator(done, 1)

	wg.Add(1)

	for i := 0; i < 5; i++ {
		fmt.Println(<-gen)
	}
	close(done) // 5回genを使ったら、doneチャネルをcloseしてキャンセルを実行

	wg.Wait()
}



func useContextGenerator(ctx context.Context, num int) <-chan int {
	out := make(chan int)
	go func() {
		defer wg.Done()

	LOOP: 
		for {
			select {
			case <- ctx.Done():
				break LOOP
			case out <- num:
			}			
		}

		close(out)
		fmt.Println("generator closed")
	}()
	return out
}

func useContext() {
	ctx, cancel := context.WithCancel(context.Background())
	gen := useContextGenerator(ctx, 1)

	wg.Add(1)

	for i := 0; i < 5; i++ {
		fmt.Println(<-gen)
	}

	cancel()

	wg.Wait()
}

func main() {
	useChannel()
	useContext()
}