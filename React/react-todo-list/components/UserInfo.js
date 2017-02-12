import React, { Component } from 'react'

class UserInfo extends Component {

    handleNewID() {
        // dispatch an action
        this.props.actions.createNewUserID();
    }

    handleNewIDIfOdd() {
        this.props.actions.createNewUserIDIfOdd();
    }

    handleNewIDAsync() {
        this.props.actions.createNewUserIDAsync();
    }

    render() {
        return (
            <li>
                <div>username: {this.props.user.username}</div>
                <div>id: {this.props.user.id}</div>
                <button onClick={this.handleNewID.bind(this)}>Update with random ID</button>
                <button onClick={this.handleNewIDIfOdd.bind(this)}>Update only if odd</button>
                <button onClick={this.handleNewIDAsync.bind(this)}>Update async</button>
            </li>
        )
    }
}

export default UserInfo