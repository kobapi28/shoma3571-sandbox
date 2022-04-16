import { useContext } from "react"
import { TodoContext } from "../App";
import { Todo } from "../types/todo";

export const AddTodo: React.VFC = () => {
  const context = useContext(TodoContext);
  const addTodo = () => {
    const item: Todo = {
      id: Date.now().toString(), title: 'add', isFinished: false, badge: [],
      date: new Date()
    }
    const newItems = [...context.items, item]
    context.setItems(newItems)
  }
  return (
    <>
      <input/>
      <button onClick={() => addTodo()}>add</button>
    </>
  )
}