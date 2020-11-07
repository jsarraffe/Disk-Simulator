//
// Created by Jacques Sarraffe on 10/25/20.
//

#ifndef PickUp_QUEUE_PickUpQueue_HPP
#define PickUp_QUEUE_PickUpQueue_HPP
#include<iostream>
#include "../CommonFiles/Queue.hpp"
#include "PickUpQueueNode.hpp"

class Request;

class PickUpQueue: public Queue {

public:
    PickUpQueue(): head(nullptr), tail(nullptr) {}

    virtual void addRequest(Request *request, int cRWHeadTrack, int cRWHeadSector);

    virtual Request *getRequest();
    virtual bool empty();
    virtual void print();
    virtual ~PickUpQueue();

private:
    PickUpQueueNode *head, *tail;

    bool inBetweenHeadAndRWTrack(int cRWHeadTrack, int headTrack, int rNodeTrack);


};


#endif //PickUp_QUEUE_PickUpQueue_HPP
