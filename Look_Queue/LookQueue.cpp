//
// Created by Jacques Sarraffe on 10/30/20.
//

#include "LookQueue.h"

#include "../CommonFiles/Request.hpp"

LookQueueNode *LookQueue::addToOrderedListDec(LookQueueNode *list, Request *req) {
    LookQueueNode *tmp = list;
    LookQueueNode *rNode = new LookQueueNode(req);
    if( list == NULL) {
        return rNode;
    }
    else{
        if(tmp->request()->track() < rNode->request()->track())
        {
            rNode->next(list);
            return rNode;
        }
        else{
            while(tmp->next() != NULL)
            {
                if(tmp->request()->track() >= rNode->request()->track())
                {
                    if(tmp->next()->request()->track() < rNode->request()->track())
                    {
                        rNode->next(tmp->next());
                        tmp->next(rNode);
                        return list;

                    }
                }
                tmp = tmp->next();
            }
            if(tmp->next() == NULL)
            {
                tmp->next(rNode);
                tmp = rNode;
                return list;
            }
        }
    }
}
LookQueueNode *LookQueue::addToOrderedList(LookQueueNode *list, Request *req) {
    //function adds an element in a linked list in increasing order.
    LookQueueNode *tmp = list;
    LookQueueNode *rNode = new LookQueueNode(req);
    if( list == NULL) {
        return rNode;
    }
    else{
        if(tmp->request()->track() > rNode->request()->track())
        {
            rNode->next(list);
            return rNode;
        }
        else{
            while(tmp->next() != NULL)
            {
                if(tmp->request()->track() <= rNode->request()->track())
                {
                    if(tmp->next()->request()->track() > rNode->request()->track())
                    {
                        rNode->next(tmp->next());
                        tmp->next(rNode);
                        return list;

                    }
                }
                tmp = tmp->next();
            }
            if(tmp->next() == NULL)
            {
                tmp->next(rNode);
                tmp = rNode;
                return list;
            }
        }
    }
}

void LookQueue::addRequest(Request *request, int cRWHeadTrack, int cRWHeadSector) {
    //Function fills out two linked list, one for request below the R/w head and one above it

    if(cRWHeadTrack <= request->track())
    {
        curr = addToOrderedList(curr, request);
    }
    else{
        next = addToOrderedListDec(next, request);
    }
}
Request *LookQueue::getRequest() {
    if( empty() ) {
        std::cout << "Calling LookQueueNode::getRequest() on an empty queue. Terminating...\n";
        exit(1);
    }

    if(curr == NULL){
        curr = next;
        next = NULL;
    }
    LookQueueNode *LookNode = curr;


    Request *request = LookNode->request();
    curr = curr->next();
    delete LookNode;
    return request;
}

bool LookQueue::empty() {
    return (curr == NULL && next == NULL);
}

void LookQueue::print() {
    for(auto cur = curr; cur; cur = cur->next() )
        cur->request()->print();
    for(auto cur = next; cur; cur = cur->next() )
        cur->request()->print();
}

LookQueue::~LookQueue() {
    while( curr != nullptr ) {
        LookQueueNode *node = curr;
        curr = node->next();
        delete node;
    }
    while( next != nullptr ) {
        LookQueueNode *node = next;
        next = node->next();
        delete node;
    }
}





