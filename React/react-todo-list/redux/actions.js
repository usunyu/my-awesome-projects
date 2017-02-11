let actions = {
    
    addTodo: function(text) {
        return {
            type: 'ADD_TODO',
            text: text,
        }
    },

    completeTodo: function(id) {
        return {
            type: 'COMPLETE_TODO',
            id: id,
        }
    },

    deleteTodo: function(id) {
        return {
            type: 'DELETE_TODO',
            id: id,
        }
    },

    createNewUserID: function() {
        return {
            type: 'CREATE_USER_ID',
            id: Math.round(Math.random() * 100),
        }
    }

}

// store.dispatch(addTodo('some text'))
export default actions