//
// Created by Jacques Sarraffe on 10/25/20.
//

#ifndef ST_QUEUE_STQUEUE_HPP
#define ST_QUEUE_STQUEUE_HPP
#include<iostream>
#include "../CommonFiles/Queue.hpp"
#include "STQueueNode.hpp"

class Request;

class STQueue: public Queue {

public:
    STQueue(): head(nullptr), tail(nullptr) {}

    virtual void addRequest(Request *request, int cRWHeadTrack, int cRWHeadSector);

    virtual Request *getRequest();
    virtual bool empty();
    virtual void print();
    virtual ~STQueue();

private:
    STQueueNode *head, *tail;

};


#endif //ST_QUEUE_STQUEUE_HPP
