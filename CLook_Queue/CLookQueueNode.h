//
// Created by Jacques Sarraffe on 10/30/20.
//

#ifndef DISKSIM_X_CLOOKQUEUENODE_H
#define DISKSIM_X_CLOOKQUEUENODE_H



class Request;

class CLookQueueNode {
public:
    CLookQueueNode(Request *req);
    CLookQueueNode *next();
    void next(CLookQueueNode *node);
    Request *request();

private:
    CLookQueueNode *_next;
    Request *_request;
};



#endif //DISKSIM_X_CLOOKQUEUENODE_H
