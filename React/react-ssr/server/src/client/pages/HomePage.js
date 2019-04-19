import React from 'react';

const HomePage = () => {
  return (
    <div>
      <div>This is Home Page</div>
      <button onClick={() => {console.log('Hi');}}>Press me!</button>
    </div>
  );
};

export default {
  component: HomePage,
}
