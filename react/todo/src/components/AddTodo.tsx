import React, { useContext, useState } from "react"
import { TodoContext } from "../App";
import { Todo } from "../types/todo";

export const AddTodo: React.VFC = () => {
  const context = useContext(TodoContext);
  const [title, setTitle] = useState<string>('')
  const [tag, setTag] = useState<string>('')

  const handleTitle = (e: React.ChangeEvent<HTMLInputElement>) => {
    setTitle(e.target.value)
  }
  const handleTag = (e: React.ChangeEvent<HTMLInputElement>) => {
    setTag(e.target.value)
  }

  const addTodo = () => {
    const item: Todo = {
      id: Date.now().toString(), title, isFinished: false, badge: tag,
      date: new Date()
    }
    const newItems = [...context.items, item]
    context.setItems(newItems)
  }


  return (
    <>
      <input placeholder="タイトル" onChange={handleTitle}/>
      <input placeholder="タグ" onChange={handleTag}/>
      <button onClick={() => addTodo()}>追加</button>
    </>
  )
}