//
// Created by Jacques Sarraffe on 10/27/20.
//

#ifndef LOOKQUEUE_X_LOOKQUEUENODE_H
#define LOOKQUEUE_X_LOOKQUEUENODE_H



class Request;

class LookQueueNode {
public:
    LookQueueNode(Request *req);
    LookQueueNode *next();
    void next(LookQueueNode *node);
    Request *request();

private:
    LookQueueNode *_next;
    Request *_request;


};


#endif //LOOKQUEUE_X_LOOKQUEUENODE_H
