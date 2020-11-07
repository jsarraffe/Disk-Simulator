//
// Created by Jacques Sarraffe on 10/25/20.
//

#include "PickUpQueue.hpp"
#include "../CommonFiles/Request.hpp"

bool PickUpQueue::inBetweenHeadAndRWTrack(int cRWHeadTrack, int headTrack, int rNodeTrack) {

    return ((cRWHeadTrack > rNodeTrack && headTrack < rNodeTrack) || (cRWHeadTrack < rNodeTrack && headTrack > rNodeTrack));
}

void PickUpQueue::addRequest(Request *request, int cRWHeadTrack, int cRWHeadSector) {

    PickUpQueueNode *rNode = new PickUpQueueNode(request);
    PickUpQueueNode *tmp = head;

    bool isInserted = false;
    if (empty()) {
        head = tail = rNode;
        isInserted = true;
    } else {
        if (inBetweenHeadAndRWTrack(cRWHeadTrack, head->request()->track(), rNode->request()->track())) {
            isInserted = true;
            rNode->next(head);
            head = rNode;
        }

        else if (!isInserted) {
            while (tmp != tail) {    //Check to see if it can get inserted somewhere in the queue

                if (tmp->request()->track() < rNode->request()->track()) {
                    if (tmp->next()->request()->track() > rNode->request()->track()) {
                        isInserted = true;
                        rNode->next(tmp->next());
                        tmp->next(rNode);
                        break;
                    }
                }

                else if(tmp->request()->track() == rNode->request()->track()){
                    if(tmp->next()->request()->track() != rNode->request()->track()){
                        isInserted = true;
                        rNode->next(tmp->next());
                        tmp->next(rNode);
                        break;
                    }
                }
                else {
                    if (tmp->next()->request()->track() < rNode->request()->track()) {
                        isInserted = true;
                        rNode->next(tmp->next());
                        tmp->next(rNode);
                        break;
                    }
                }
                tmp = tmp->next();
            }
        }
    }
    if (!isInserted) {
        tail->next(rNode);
        tail = rNode;
    }
}
Request *PickUpQueue::getRequest() {
    if (empty()) {
        std::cout << "Calling PickUpQueueNode::getRequest() on an empty queue. Terminating...\n";
        exit(1);
    }
    PickUpQueueNode *PickUpNode = head;
    Request *request = PickUpNode->request();
    head = head->next();
    if (head == nullptr)
        tail = nullptr;
    delete PickUpNode;
    return request;
}
bool PickUpQueue::empty() {
    return head == nullptr;
}

void PickUpQueue::print() {
    for (auto cur = head; cur; cur = cur->next())
        cur->request()->print();
}

PickUpQueue::~PickUpQueue() {
    while (head != nullptr) {
        PickUpQueueNode *node = head;
        head = node->next();
        delete node;
    }
}

