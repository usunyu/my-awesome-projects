import React from 'react';
import { Route } from 'react-router-dom';
import Home from './components/Home';
import UserList from './components/UserList';

export default () => {
  return (
    <div>
      <Route exact path="/" component={Home} />
      <Route exact path="/users" component={UserList} />
    </div>
  );
};
