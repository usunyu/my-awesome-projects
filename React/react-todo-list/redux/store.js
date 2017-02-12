import { applyMiddleware, compose, createStore } from 'redux'
import rootReducer from './reducers'
import logger from 'redux-logger'
import thunk from 'redux-thunk'

// add middleware
let finalCreateStore = compose(
    applyMiddleware(thunk, logger())
)(createStore)

export default function configureStore(initialState = { todos: [], user: {} }) {
    // initialState = initialState || { todos: [] };
    return finalCreateStore(rootReducer, initialState); 
}