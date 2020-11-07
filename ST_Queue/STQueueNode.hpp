//
// Created by Jacques Sarraffe on 10/25/20.
//

#ifndef ST_QUEUE_STQUEUENODE_HPP
#define ST_QUEUE_STQUEUENODE_HPP


class Request;

class STQueueNode {
public:
    STQueueNode(Request *req);
    STQueueNode *next();
    void next(STQueueNode *node);
    Request *request();

private:
    STQueueNode *_next;
    Request *_request;
};


#endif //ST_QUEUE_STQUEUENODE_HPP
