import { combineReducers } from 'redux';
import { reducer as formReducer } from 'redux-form';
import { reducer as modalProvider } from 'react-redux-modal-provider';
import PostsReducer from './reducer_posts';

const rootReducer = combineReducers({
    posts: PostsReducer,
    form: formReducer,
    modalProvider: modalProvider,
});

export default rootReducer;
