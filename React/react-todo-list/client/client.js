import React from 'react'
import { render } from 'react-dom'
import App from '../components/App'
import configureStore from '../redux/store'
import { Provider } from 'react-redux'

let initialState = {
    todos: [{
        id: 0,
        completed: false,
        text: 'initial todo for demo purposes'
    }]
}

let store = configureStore(initialState)

// configure and create our store
// var store = createStore(reducers, initialState)  // []

render(
	// define the encompassing component,
	// DOM element we want to mount it to.
    <Provider store={store}>
	   <App />
    </Provider>,
	document.getElementById('app')
)