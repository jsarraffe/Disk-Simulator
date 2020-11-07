//
//Created by Jacques Sarraffe on 10/25/20.
//

#include <random>
#include <cstdlib>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include "LookQueue.h"
#include "../CommonFiles/Request.hpp"


LookQueue *createSTQueueFromInputFile(int argc, char *argv[] ) {

    if( argc != 2) {
        std::cout << "usage: " << argv[0] << " nameOfAnInputFile\n";
        exit(1);
    }

    std::ifstream inputStream;
    inputStream.open(argv[1], std::ios::in);
    if( ! inputStream.is_open()) {
        std::cout << "Unable top open " << argv[1] << ". Terminating...";
        perror("Error when attempting to open the input file.");
        exit(1);
    }
    auto *queue = new LookQueue();
    int time, track, sector;
    while(inputStream >> time && inputStream >> track && inputStream >> sector) {
        auto *request = new Request(time, track, sector);
        queue->addRequest(request, 79,0);
    }
    return queue;
}

int main(int argc, char *argv[]) {
    const int randomTest = true;
    LookQueue *queue = nullptr;

//    if( randomTest )
//        queue = createSTQueueFromRandomValues(300, 200);
//    else

queue = createSTQueueFromInputFile(argc, argv);


    queue->print();

    LookQueue *queue2 = new LookQueue();
    auto *request1 = new Request(1, 22, 4);
    auto *request2 = new Request(2, 52, 4);
    auto *request3 = new Request(3, 3, 2);
    auto *request4 = new Request(4, 53, 5);
    auto *request5 = new Request(4, 3, 3);
    auto *request6 = new Request(4, 8, 4);
    auto *request7 = new Request(4, 51, 4);
    auto *request8 = new Request(4, 53, 6);

    std::cout<<" "<<std::endl;
    std::cout<<"Queue 2"<<std::endl;

    int _intRwh = 12;

    std::cout<<"r/w:" <<_intRwh<<""<<std::endl;
    queue2->addRequest(request1,_intRwh,8);
    queue2->addRequest(request2,_intRwh,9);
    queue2->addRequest(request3,_intRwh,3);
    queue2->addRequest(request4,_intRwh,2);
    queue2->addRequest(request5,_intRwh,6);
    queue2->addRequest(request6,_intRwh,3);
    queue2->addRequest(request7,_intRwh,4);
    queue2->addRequest(request8,_intRwh,6);

    queue2->print();
    std::cout<<"Getting a request"<<std::endl;
    queue2->getRequest();
    queue2->print();
    std::cout<<"Getting a request"<<std::endl;
    queue2->getRequest();
    queue2->print();
    std::cout<<"Getting a request"<<std::endl;
    queue2->getRequest();
    queue2->print();
    std::cout<<"Getting a request"<<std::endl;
    queue2->getRequest();
    queue2->print();



    delete queue2;



    delete queue;

    return 0;
}