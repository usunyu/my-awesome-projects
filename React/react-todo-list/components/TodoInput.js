import React, { Component } from 'react'
import actions from '../redux/actions'

class TodoInput extends Component {

    constructor(props, context) {
        super(props, context);
        this.state = {
            inputText: ''
        };
    }

    handleChange(event) {
        this.setState({
            inputText: event.target.value
        });
    }

    handleSubmit(event) {
        event.preventDefault();
        // console.log('submit button clicked');
        this.props.dispatch(actions.addTodo(this.state.inputText));
    }

    render() {
        return (
            <div>
                <input
                    type="text"
                    placeholder="Create your Todo"
                    value={this.state.inputText}
                    onChange={this.handleChange.bind(this)}
                />
                <button onClick={this.handleSubmit.bind(this)}>Submit</button>
            </div>
        )
    }
}

export default TodoInput