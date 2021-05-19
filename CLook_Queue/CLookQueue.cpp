//
// Created by Jacques Sarraffe on 10/30/20.
//

#include "CLookQueue.h"

#include "../CommonFiles/Request.hpp"

CLookQueueNode *CLookQueue::addToOrderedList(CLookQueueNode *list, Request *req) {
    //function adds an element in a linked list in increasing order.
    CLookQueueNode *tmp = list;
    CLookQueueNode *rNode = new CLookQueueNode(req);
    if( list == NULL) {
        return rNode;
    }
    //
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

void CLookQueue::addRequest(Request *request, int cRWHeadTrack, int cRWHeadSector) {
     //Function fills out two linked list, one for request below the R/w head and one above it

        if(cRWHeadTrack <= request->track())
        {
            curr = addToOrderedList(curr, request);
        }
        else{
            next = addToOrderedList(next, request);
        }
}
Request *CLookQueue::getRequest() {
    if( empty() ) {
        std::cout << "Calling CLookQueueNode::getRequest() on an empty queue. Terminating...\n";
        exit(1);
    }

    if(curr == NULL){
        curr = next;
        next = NULL;
    }
    CLookQueueNode *cLookNode = curr;


    Request *request = cLookNode->request();
    curr = curr->next();
    delete cLookNode;
    return request;
}

bool CLookQueue::empty() {
    return (curr == NULL && next == NULL);
}

void CLookQueue::print() {
    for(auto cur = curr; cur; cur = cur->next() )
        cur->request()->print();
    for(auto cur = next; cur; cur = cur->next() )
        cur->request()->print();
}

CLookQueue::~CLookQueue() {
    while( curr != nullptr ) {
        CLookQueueNode *node = curr;
        curr = node->next();
        delete node;
    }
    while( next != nullptr ) {
        CLookQueueNode *node = next;
        next = node->next();
        delete node;
    }
}



