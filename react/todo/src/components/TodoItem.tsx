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
        item.isFinished = true;
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
      <p>{item.isFinished ? '完了': '未完了'}</p>
      <button onClick={() => updateStatus(item.id)}>DONE!</button>
    </div>
  )
} 