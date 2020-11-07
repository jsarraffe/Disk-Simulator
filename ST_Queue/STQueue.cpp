//
// Created Jacques Sarraffe  on 10/30/20.
//

#include "STQueue.hpp"

#include "../CommonFiles/Request.hpp"

void STQueue::addRequest(Request *request, int cRWHeadTrack, int cRWHeadSector) {
    STQueueNode *rNode = new STQueueNode(request);
    bool isInserted = false;
    if( empty() ) {
        head = tail = rNode;
    } else {
        STQueueNode *tmp = head;
        while(tmp != tail)
        {
            if(tmp->request()->track() == rNode->request()->track()){
                if(tmp->next()->request()->track() != rNode->request()->track()){
                    isInserted = true;
                    rNode->next(tmp->next());
                    tmp->next(rNode);
                    break;
                }
            }
            tmp = tmp->next();
        }
        if(!isInserted){
            if(cRWHeadTrack == rNode->request()->track()){
                rNode->next(head);
                head = rNode;
            }
            else{
                tail->next(rNode);
                tail = rNode;
            }
        }
    }
}
Request *STQueue::getRequest() {
    if( empty() ) {
        std::cout << "Calling STQueueNode::getRequest() on an empty queue. Terminating...\n";
        exit(1);
    }
    STQueueNode *fcfsNode = head;
    Request *request = fcfsNode->request();
    head = head->next();
    if( head == nullptr )
        tail = nullptr;
    delete fcfsNode;
    return request;
}
bool STQueue::empty() {
    return head == nullptr;
}
void STQueue::print() {
    for(auto cur = head; cur; cur = cur->next() )
        cur->request()->print();
}
STQueue::~STQueue() {
    while( head != nullptr ) {
        STQueueNode *node = head;
        head = node->next();
        delete node;
    }
}
