import _ from 'lodash';
import React, { Component } from 'react';
import { Field, reduxForm } from 'redux-form';
import { Link } from 'react-router-dom';
import { connect } from 'react-redux';
import { createPost } from '../actions';

// {...field.input}
// =>
// onChange={field.input.onChange}
// onFocus={field.input.onFocus}
// onBlur={field.input.onBlur}

const FIELDS = {
    title: {
        name: 'title',
        type: 'input',
        label: 'Title for post',
        // validate: () => {},
    },
    categories: {
        name: 'categories',
        type: 'input',
        label: 'Categories for post',
    },
    content: {
        name: 'content',
        type: 'textarea',
        label: 'Post contents',
    }
};

class PostsNew extends Component {
    renderField(field) {
        const { meta } = field;
        const className = `form-group ${meta.touched && meta.error ? 'has-danger' : ''}`;
        return (
            <div className={className}>
                <label>{field.label}</label>
                <field.type
                    className='form-control'
                    type='text'
                    {...field.input} />
                <div className='text-help'>
                    {meta.touched ? meta.error : null}
                </div>
            </div>
        );
    }

    onSubmit(values) {
        this.props.createPost(values, () => {
            this.props.history.push('/');
        });
    }

    render() {
        const { handleSubmit } = this.props;
        return (
            <form onSubmit={handleSubmit(this.onSubmit.bind(this))}>
                <h3>Create A New Post</h3>
                {_.map(FIELDS, (field) => {
                    return (
                        <Field
                            key={field.name}
                            label={field.label}
                            name={field.name}
                            type={field.type}
                            component={this.renderField} />
                    );
                })}
                <button type='submit' className='btn btn-primary'>Submit</button>
                <Link to='/' className='btn btn-danger'>Cancel</Link>
            </form>
        );
    }
}

function validate(values) {
    const errors = {};

    _.each(FIELDS, (type, field) => {
        if (!values[field]) {
            errors[field] = `Enter a ${field}`;
        }
    });
    // if (!values.title || values.title.length < 3) {
    //     errors.title = 'Enter a title that is at least 3 char!';
    // }
    // if (!values.categories) {
    //     errors.categories = 'Enter some categories!';
    // }
    // if (!values.content) {
    //     errors.content = 'Enter some content!';
    // }
    return errors;
}

export default reduxForm({
    validate, // validate: validate
    fields: _.keys(FIELDS),
    form: 'PostsNewForm'
})(
    connect(null, {createPost})(PostsNew)
);
