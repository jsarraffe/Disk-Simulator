//
// Created by Jacques Sarraffe on 10/30/20.
//

#ifndef DISKSIM_X_CLOOKQUEUE_H
#define DISKSIM_X_CLOOKQUEUE_H


#include<iostream>
#include "../CommonFiles/Queue.hpp"
#include "CLookQueueNode.h"

class Request;

class CLookQueue: public Queue {

public:
    CLookQueue(): curr(nullptr), next(nullptr) {}

    virtual void addRequest(Request *request, int cRWHeadTrack, int cRWHeadSector);

    virtual Request *getRequest();
    virtual bool empty();
    virtual void print();
    virtual ~CLookQueue();

private:
//    CLookQueueNode *head, *tail;
    CLookQueueNode *addToOrderedList(CLookQueueNode* list, Request *req);

    CLookQueueNode *getFromOrderedList(CLookQueueNode* list);


    bool inBetweenHeadAndRWTrack(int cRWHeadTrack, int headTrack, int rNodeTrack);
    CLookQueueNode *curr;
    CLookQueueNode *next;
};


#endif //DISKSIM_X_CLOOKQUEUE_H
