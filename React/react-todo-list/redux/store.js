import { applyMiddleware, compose, createStore } from 'redux'
import reducer from './reducer'
import logger from 'redux-logger'

// add middleware
let finalCreateStore = compose(
    applyMiddleware(logger())
)(createStore)

export default function configureStore(initialState = { todos: [] }) {
    // initialState = initialState || { todos: [] };
    return finalCreateStore(reducer, initialState); 
}