//
// Created by Jacques Sarraffe on 10/27/20.
//

#include "LookQueue.h"
#include "../CommonFiles/Request.hpp"

bool LookQueue::inBetweenHeadAndRWTrack(int cRWHeadTrack, int headTrack, int rNodeTrack) {

    return ((cRWHeadTrack <= rNodeTrack && rNodeTrack <= headTrack ));

}
void LookQueue::addRequest(Request *request, int cRWHeadTrack, int cRWHeadSector) {

    bool isInserted = false;
    LookQueueNode *rNode = new LookQueueNode(request);
    LookQueueNode *tmp = head;
    if( empty() ) {
        head = tail = rNode;
    } else {
        if(inBetweenHeadAndRWTrack(cRWHeadTrack, head->request()->track(), rNode->request()->track())){
             isInserted = true;
             rNode->next(head);
             head = rNode;
        }
        else if(rNode->request()->track() > cRWHeadTrack && !isInserted){
            while (tmp != tail) {    //Check to see if it can get inserted somewhere in the queue in ascending order
                //otherwise check to see if you can insert it in descending order
                if (tmp->request()->track() <= rNode->request()->track()) {
                    if (tmp->next()->request()->track() > rNode->request()->track()) {
                        isInserted = true;
                        rNode->next(tmp->next());
                        tmp->next(rNode);
                        break;
                    }
                    else if(tmp->next()->request()->track() < cRWHeadTrack) {
                        if(tmp->next()->request()->track() < rNode->request()->track())
                        {
                            isInserted = true;
                            rNode->next(tmp->next());
                            tmp->next(rNode);
                            break;
                        }
                    }
                }
                tmp = tmp->next();
            }
        }
        else if(rNode->request()->track() < cRWHeadTrack && !isInserted){
            LookQueueNode *tmp = head;
            while (tmp != tail) {    //Check to see if it can get inserted somewhere in the queue, in decending order
                if (tmp->request()->track() > rNode->request()->track()) {
                    if (tmp->next()->request()->track() < rNode->request()->track()) {
                        isInserted = true;
                        rNode->next(tmp->next());
                        tmp->next(rNode);
                        break;
                    }
                }
                tmp = tmp->next();
            }
        }
        if (!isInserted) {
            tail->next(rNode);
            tail = rNode;
        }
    }
}

Request *LookQueue::getRequest() {
    if (empty()) {
        std::cout << "Calling LookQueueNode::getRequest() on an empty queue. Terminating...\n";
        exit(1);
    }
    LookQueueNode *LookNode = head;
    Request *request = LookNode->request();
    head = head->next();
    if (head == nullptr)
        tail = nullptr;
    delete LookNode;
    return request;
}

bool LookQueue::empty() {
    return head == nullptr;
}

void LookQueue::print() {
    for (auto cur = head; cur; cur = cur->next())
        cur->request()->print();
}

LookQueue::~LookQueue() {
    while (head != nullptr) {
        LookQueueNode *node = head;
        head = node->next();
        delete node;
    }
}
