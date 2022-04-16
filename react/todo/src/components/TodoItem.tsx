import { Todo } from "../types/todo"

type Props = {
  item: Todo;
}

export const TodoItem: React.VFC<Props> = ({ item }) => {
  return (
    <div>
      <label htmlFor={'title' + item.id}>{item.title}</label>
      <input type='checkbox' id={'title' + item.id}/>
      <p>{item.date.toLocaleDateString()}</p>
      <p>{item.badge}</p>
    </div>
  )
} 