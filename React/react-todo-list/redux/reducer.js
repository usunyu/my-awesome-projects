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
        default:
            return state;
    }
}

export default reducer