import { FETCH_WEATHER } from '../actions/index';

export default function(state = [], action) {
    switch(action.type) {
        case FETCH_WEATHER:
            console.log('action receive: ', action.payload.data);
            // concat create a new array, no state mutation
            //return state.concat([action.payload.data]);
            // ES6 flavor
            return [ action.payload.data, ...state ]; // [city, city...] NOT [city, [city...]]
    }
    return state;
}
