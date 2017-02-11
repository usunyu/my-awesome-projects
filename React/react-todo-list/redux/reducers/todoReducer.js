function getID(todos) {
    return todos.reduce((maxID, todo) => {
        return Math.max(todo.id, maxID);
    }, -1) + 1;
}

let todoReducer = function(todos = [], action) {
    switch(action.type) {
        case 'ADD_TODO':
            return [{
                // add new todo info
                text: action.text,
                completed: false,
                id: getID(todos),
            }, ...todos]
        case 'COMPLETE_TODO':
            return todos.map((todo) => {
                return todo.id === action.id ? 
                Object.assign({}, todo, {completed: !todo.completed}) : todo
            })
        case 'DELETE_TODO':
            return todos.filter((todo) => {
                return todo.id !== action.id
            })
        default:
            return todos;
    }
}

export default todoReducer