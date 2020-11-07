//
// Created by Jacques Sarraffe on 10/30/20.
//

#include "CLookQueueNode.h"



class Request;

CLookQueueNode::CLookQueueNode(Request *req) : _request(req), _next(nullptr) {}

CLookQueueNode *CLookQueueNode::next() {
    return _next;
}

void CLookQueueNode::next(CLookQueueNode *node) {
    _next = node;
}

Request *CLookQueueNode::request() {
    return _request;
}
