import React, { Component } from 'react';
import { Modal, Button } from 'react-bootstrap';

class PostsDeleteConfirmModal extends Component {
    onConfirmClick() {
        this.props.onDeleteClick();
        this.props.hideModal();
    }

    render() {
        return (
            <Modal show={this.props.show}>
                <Modal.Body>
                    Are you sure delete this post?
                </Modal.Body>
                <Modal.Footer>
                    <Button onClick={this.props.hideModal}>Cancel</Button>
                    <Button
                        bsStyle="primary"
                        onClick={this.onConfirmClick.bind(this)}>
                        Confirm
                    </Button>
                </Modal.Footer>
            </Modal>
        );
    }
}

export default PostsDeleteConfirmModal;
