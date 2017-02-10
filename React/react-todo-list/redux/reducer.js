function getID(state) {
    return state.todos.reduce((maxID, todo) => {
        return Math.max(todo.id, maxID);
    }, -1) + 1;
}

let reducer = function(state, action) {
    switch(action.type) {
        case 'ADD_TODO':
            return Object.assign({}, state, {
                todos: [{
                    // add new todo info
                    text: action.text,
                    completed: false,
                    id: getID(state),
                }, ...state.todos]
            })
        case 'COMPLETE_TODO':
            return Object.assign({}, state, {
                todos: state.todos.map((todo) => {
                    return todo.id === action.id ? 
                        Object.assign({}, todo, {completed: !todo.completed}) : todo
                })
            })
        case 'DELETE_TODO':
            return Object.assign({}, state, {
                todos: state.todos.filter((todo) => {
                    return todo.id !== action.id
                })
            })
        default:
            return state;
    }
}

export default reducer