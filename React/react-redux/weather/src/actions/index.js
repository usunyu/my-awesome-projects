import axios from 'axios';

const API_KEY = '6a9e4406f0c3fbd18b6a6cebcce08584';
const ROOT_URL = `http://api.openweathermap.org/data/2.5/forecast?appid=${API_KEY}`;

export const FETCH_WEATHER = 'FETCH_WEATHER';

export function fetchWeather(city) {
    const url = `${ROOT_URL}&q=${city},us`;
    const request = axios.get(url);

    console.log('Request: ', request);

    return {
        type: FETCH_WEATHER,
        payload: request
    }
}
