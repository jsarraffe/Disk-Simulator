//
// Created by Ali A. Kooshesh on 10/1/18.
//

#include "FCFSQueueNode.hpp"

class Request;

FCFSQueueNode::FCFSQueueNode(Request *req) : _request(req), _next(nullptr) {}

FCFSQueueNode *FCFSQueueNode::next() {
    return _next;
}

void FCFSQueueNode::next(FCFSQueueNode *node) {
    _next = node;
}

Request *FCFSQueueNode::request() {
    return _request;
}
