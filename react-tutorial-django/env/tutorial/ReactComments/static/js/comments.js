/** @jsx React.DOM */
// comments.js

var converter = new Showdown.converter();
var Comment = React.createClass({displayName: 'Comment',
    render: function() {
        var rawMarkup = converter.makeHtml(this.props.children.toString());
        return (
            React.DOM.div( {className:"comment"}, 
                React.DOM.h2( {className:"commentAuthor"}, 
                    this.props.author
                ),
                React.DOM.span( {dangerouslySetInnerHTML:{__html: rawMarkup}} )
            )
        );
    }
});

var CommentList = React.createClass({displayName: 'CommentList',
    render: function() {
        var commentNodes = this.props.data.map(function (comment) {
            return (
                Comment( {author:comment.author}, 
                    comment.text
                )
            );
        });
        return (
            React.DOM.div( {className:"commentList"}, 
                commentNodes
            )
        );
    }
});

var CommentForm = React.createClass({displayName: 'CommentForm',
    handleSubmit: function() {
        var author = this.refs.author.getDOMNode().value.trim();
        var text = this.refs.text.getDOMNode().value.trim();
        if (!text || !author) {
            return false;
        }
        this.props.onCommentSubmit({author: author, text: text});
        this.ref.author.getDOMNode().value = '';
        this.ref.text.getDOMNode().value = '';
        return false;
    }, 
    render: function() {
        return (
            React.DOM.form( {className:"commentForm", onSubmit:this.handleSubmit}, 
                React.DOM.input( {type:"text", ref:"author", placeholder:"Your name"} ),
                React.DOM.input( {type:"text", ref:"text", placeholder:"Say something..."} ),
                React.DOM.input( {type:"submit", value:"Post"} )
            )
        );
    }
});

var CommentBox = React.createClass({displayName: 'CommentBox',
    loadCommentsFromServer: function() {
        $.ajax({
            url: this.props.url,
            dataType: 'json',
            success: function(data) {
                this.setState({data: data});
            }.bind(this),
            error: function(xhr, status, err) {
                console.error(this.props.url, status, err.toString());
            }.bind(this)
        });
    },
    handleCommentSubmit: function(comment) {
        var comments = this.state.data;
        var newComments = comments.concat([comment]);
        this.setState({data: newComments});
        $.ajax({
            url: this.props.url,
            dataType: 'json',
            type: 'POST',
            data: comment,
            success: function(data) {
                this.setState({data: data});
            }.bind(this),
            error: function(xhr, status, err) {
                console.error(this.props.url, status, err.toString());
            }.bind(this)
        });
    },
    getInitialState: function() {
        return {data: []};
    },
    componentWillMount: function() {
        this.loadCommentsFromServer();
        setInterval(this.loadCommentsFromServer, this.props.pollInterval);
    },
    render: function() {
        return (
            React.DOM.div( {className:"commentBox"}, 
                React.DOM.h1(null, "Comments"),
                CommentList( {data:this.state.data} ),
                CommentForm( {onCommentSubmit:this.handleCommentSubmit} )
            )
        );
    }
});
React.renderComponent(
    CommentBox( {url:"/api/v1/comments/", pollInterval:2000}),
    document.getElementById('content')
);
