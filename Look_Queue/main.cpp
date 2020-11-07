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
//        queue = createSTueueFromRandomValues(300, 200);
//    else
    queue = createSTQueueFromInputFile(argc, argv);

    queue->print();

    LookQueue *queue2 = new LookQueue();
    auto *request1 = new Request(1, 79, 4);
    auto *request2 = new Request(2, 53, 4);
    auto *request3 = new Request(3, 3, 4);
    auto *request4 = new Request(4, 53, 4);
    auto *request5 = new Request(4, 5, 4);

    std::cout<<" "<<std::endl;
    std::cout<<"Queue 2"<<std::endl;


//    std::cout<<"r/w: 80 Inserting request with tracks: 79, 53, 79, 52, 5"<<std::endl;
//    queue2->addRequest(request1,79,8);
//    queue2->addRequest(request2,79,9);
//    queue2->addRequest(request3,79,8);
//    queue2->addRequest(request4,79,8);
//    queue2->addRequest(request5,79,8);

//    std::cout<<"r/w: 50 Inserting request with tracks: 79, 53, 79, 52, 5"<<std::endl;
//    queue2->addRequest(request1,50,8);
//    queue2->addRequest(request2,50,9);
//    queue2->addRequest(request3,50,8);
//    queue2->addRequest(request4,50,8);
//    queue2->addRequest(request5,50,8);



    //Checking to see if the Same Track algorithm
    std::cout<<"r/w: 0 Inserting request with tracks: 79, 53, 79, 53, 5"<<std::endl;
    queue2->addRequest(request1,0,8);
    queue2->addRequest(request2,0,9);
    queue2->addRequest(request3,0,8);
    queue2->addRequest(request4,0,8);
    queue2->addRequest(request5,0,8);

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