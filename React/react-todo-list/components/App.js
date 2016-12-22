import React, { Component } from 'react'
import TextInput from './TextInput'

class App extends Component {

	render() {
		return (
            <div className="app">
                <h1>This is App component</h1>
                <TextInput/>
            </div>
        )
	}

}

export default App