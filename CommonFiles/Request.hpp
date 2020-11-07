//
// Created by Ali A. Kooshesh on 10/1/18.
//

#ifndef FCFS_QUEUE_REQUEST_HPP
#define FCFS_QUEUE_REQUEST_HPP

class Request {
public:
    Request(double rTime, int rTrack, int rSector);

    int track();
    int sector();
    double time();
    void print();

private:
    double _time;
    int _track, _sector;

};

#endif //FCFS_QUEUE_REQUEST_HPP
