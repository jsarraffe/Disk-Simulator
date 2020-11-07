//
// Created by Jacques Sarraffe on 10/27/20.
//

#include "LookQueueNode.h"

class Request;

LookQueueNode::LookQueueNode(Request *req) : _request(req), _next(nullptr) {}

LookQueueNode *LookQueueNode::next() {
    return _next;
}
void LookQueueNode::next(LookQueueNode *node) {
    _next = node;
}
Request *LookQueueNode::request() {
    return _request;
}

