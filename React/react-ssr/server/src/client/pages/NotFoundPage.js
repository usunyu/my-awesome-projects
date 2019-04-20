import React from 'react';

const NotFoundPage = ({ staticContext = {} }) => {
  staticContext.notFound = true;
  return (
    <div className="center-align" style={{ marginTop: "200px" }}>
      <h3>404</h3>
      <p>Page not found</p>
    </div>
  );
};

export default {
  component: NotFoundPage,
}
