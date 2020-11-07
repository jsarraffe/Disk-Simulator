//
// Created by Jacques Sarraffe on 10/25/20.
//

#include "PickUpQueueNode.hpp"


class Request;

PickUpQueueNode::PickUpQueueNode(Request *req) : _request(req), _next(nullptr) {}

PickUpQueueNode *PickUpQueueNode::next() {
    return _next;
}
void PickUpQueueNode::next(PickUpQueueNode *node) {
    _next = node;
}
Request *PickUpQueueNode::request() {
    return _request;
}
