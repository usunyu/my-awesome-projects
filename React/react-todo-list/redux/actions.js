let actions = {
    addTodo: function(text) {
        return {
            type: 'ADD_TODO',
            text: text,
        }
    }
}

// store.dispatch(addTodo('some text'))
export default actions