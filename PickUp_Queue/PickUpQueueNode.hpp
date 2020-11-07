//
// Created by Jacques Sarraffe on 10/25/20.
//

#ifndef PickUp_QUEUE_PickUpQueueNODE_HPP
#define PickUp_QUEUE_PickUpQueueNODE_HPP


class Request;

class PickUpQueueNode {
public:
    PickUpQueueNode(Request *req);
    PickUpQueueNode *next();
    void next(PickUpQueueNode *node);
    Request *request();

private:
    PickUpQueueNode *_next;
    Request *_request;
};



#endif //PickUp_QUEUE_PickUpQueueNODE_HPP
