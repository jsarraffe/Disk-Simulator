//
// Created by Jacques Sarraffe on 10/27/20.
//

#ifndef LOOKQUEUE_X_LOOKQUEUE_H
#define LOOKQUEUE_X_LOOKQUEUE_H

#include<iostream>
#include "../CommonFiles/Queue.hpp"
#include "LookQueueNode.h"


class Request;

class LookQueue: public Queue {

public:
    LookQueue(): head(nullptr), tail(nullptr) {}

    virtual void addRequest(Request *request, int cRWHeadTrack, int cRWHeadSector);

    virtual Request *getRequest();
    virtual bool empty();
    virtual void print();
    virtual ~LookQueue();

private:
    LookQueueNode *head, *tail;
    bool inBetweenHeadAndRWTrack(int cRWHeadTrack, int headTrack, int rNodeTrack);
};


#endif //LOOKQUEUE_X_LOOKQUEUE_H
