import React, { createContext, useState } from 'react';
import { AddTodo } from './components/AddTodo';
import { Header } from './components/Header';
import { TodoList } from './components/TodoList';
import { Todo } from './types/todo';

type TodoProvider = {
  items: Todo[];
  setItems: React.Dispatch<React.SetStateAction<Todo[]>>;
}
export const TodoContext = createContext<TodoProvider>({} as TodoProvider);

function App() {
  const [items, setItems] = useState<Todo[]>([])
  return (
      <TodoContext.Provider value={{items, setItems}}>
        <Header/>
        <AddTodo/>
        <div style={{display: 'flex'}}>
          <TodoList items={items.filter(item => !item.isFinished)}/>
          <TodoList items={items.filter(item => item.isFinished)}/>
        </div>
      </TodoContext.Provider>
  );
}

export default App;
