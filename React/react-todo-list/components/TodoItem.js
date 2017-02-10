import React, { Component } from 'react'

class TodoItem extends Component {

    handleComplete() {
        // this.props.dispatch(actions.completeTodo(this.props.todo.id));
        this.props.actions.completeTodo(this.props.todo.id);
    }

    handleDelete() {
        // this.props.dispatch(actions.deleteTodo(this.props.todo.id));
        this.props.actions.deleteTodo(this.props.todo.id);
    }

    render() {
        return (
            <li>
                <div>{this.props.todo.text}</div>
                <button onClick={this.handleComplete.bind(this)}>Mark as completed</button>
                <button onClick={this.handleDelete.bind(this)}>Delete todo</button>
            </li>
        )
    }
}

export default TodoItem