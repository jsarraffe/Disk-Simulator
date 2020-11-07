//
// Created by Ali A. Kooshesh on 10/1/18.
//

#include "FCFSQueue.hpp"


#include "../CommonFiles/Request.hpp"



void FCFSQueue::addRequest(Request *request, int cRWHeadTrack, int cRWHeadSector) {
    FCFSQueueNode *rNode = new FCFSQueueNode(request);
    if( empty() ) {
        head = tail = rNode;
    } else {
        tail->next(rNode);
        tail = rNode;
    }
}

Request *FCFSQueue::getRequest() {
    if( empty() ) {
        std::cout << "Calling FCFSQueueNode::getRequest() on an empty queue. Terminating...\n";
        exit(1);
    }
    FCFSQueueNode *fcfsNode = head;
    Request *request = fcfsNode->request();
    head = head->next();
    if( head == nullptr )
        tail = nullptr;
    delete fcfsNode;
    return request;
}

bool FCFSQueue::empty() {
    return head == nullptr;
}

void FCFSQueue::print() {
    for(auto cur = head; cur; cur = cur->next() )
        cur->request()->print();
}

FCFSQueue::~FCFSQueue() {
    while( head != nullptr ) {
        FCFSQueueNode *node = head;
        head = node->next();
        delete node;
    }
}
