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
        // do some async call
        // onSuccess: dispatch({type: ...})
        return {
            type: 'CREATE_USER_ID',
            id: Math.round(Math.random() * 100),
        }
    },

    createNewUserIDIfOdd: function() {
        return (dispatch, getState) => {
            const { user } = getState();
            if (user.id % 2 == 0) {
                return;
            }
            dispatch(actions.createNewUserID())
        }
    },

    createNewUserIDAsync: function() {
        return (dispatch) => {

            // $.get('url', {
            //     success: (res) => {
            //         dispatch(createNewUserID(res.data))
            //     }
            // })

            setTimeout(() => {
                dispatch(actions.createNewUserID())
            }, 2500);
        }
    },
}

// store.dispatch(addTodo('some text'))
export default actions