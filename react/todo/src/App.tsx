import { Header } from './components/Header';
import { Search } from './components/Search';
import { TodoList } from './components/TodoList';
import { Todo } from './types/todo';

const items: Todo[] = [
  {
    id: 'hogehoge',
    title: 'hoge',
    date: new Date(),
    badge: ['hoge', 'fuga'],
    isFinished: false
  },
  {
    id: 'hogehogehoge',
    title: 'hoge',
    date: new Date(),
    badge: ['hoge', 'fuga'],
    isFinished: false
  },
  {
    id: 'aaa',
    title: 'hoge',
    date: new Date(),
    badge: ['hoge', 'fuga'],
    isFinished: false
  }
]

function App() {
  return (
    <div>
      <Header/>
      <Search/>
      <TodoList items={items}/>
    </div>
  );
}

export default App;
