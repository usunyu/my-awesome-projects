import { applyMiddleware, compose, createStore } from 'redux'
import rootReducer from './reducers'
import logger from 'redux-logger'

// add middleware
let finalCreateStore = compose(
    applyMiddleware(logger())
)(createStore)

export default function configureStore(initialState = { todos: [], user: {} }) {
    // initialState = initialState || { todos: [] };
    return finalCreateStore(rootReducer, initialState); 
}