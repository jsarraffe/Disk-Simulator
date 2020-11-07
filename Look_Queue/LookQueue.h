//
// Created by Jacques Sarraffe on 10/30/20.
//

#ifndef DISKSIM_X_LookQUEUE_H
#define DISKSIM_X_LookQUEUE_H


#include<iostream>
#include "../CommonFiles/Queue.hpp"
#include "LookQueueNode.h"

class Request;

class LookQueue: public Queue {

public:
    LookQueue(): curr(nullptr), next(nullptr) {}

    virtual void addRequest(Request *request, int cRWHeadTrack, int cRWHeadSector);

    virtual Request *getRequest();
    virtual bool empty();
    virtual void print();
    virtual ~LookQueue();

private:
//    LookQueueNode *head, *tail;
    LookQueueNode *addToOrderedList(LookQueueNode* list, Request *req);

    LookQueueNode *addToOrderedListDec(LookQueueNode* list, Request *req);


    LookQueueNode *curr;
    LookQueueNode *next;
};


#endif //DISKSIM_X_LookQUEUE_H
