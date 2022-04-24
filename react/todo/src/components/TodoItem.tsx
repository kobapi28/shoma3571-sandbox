import React, { useContext } from "react";
import { TodoContext } from "../App";
import { Todo } from "../types/todo"

type Props = {
  item: Todo;
  index: number;
}

export const TodoItem: React.VFC<Props> = ({ item, index }) => {
  const context = useContext(TodoContext)
  const updateStatus = (id: string) => {
    const items: Todo[] = context.items;
    const updatedItems = items.map((item) => {
      if (item.id === id) {
        item.isFinished = !item.isFinished;
      }
      return item
    })
    context.setItems(updatedItems)
  }

  return (
    <div>
      <p>{item.title}</p>
      <p>{item.date.toLocaleDateString()}</p>
      <p>{item.badge}</p>
      <button onClick={() => updateStatus(item.id)}>{item.isFinished ? '未完了に戻す': '完了！'}</button>
    </div>
  )
} 