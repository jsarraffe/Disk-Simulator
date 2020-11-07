//
// Created by Ali A. Kooshesh on 10/1/18.
//

#include <iostream>
#include "Request.hpp"

Request::Request(double rTime, int rTrack, int rSector) : _time(rTime), _track(rTrack), _sector(rSector) {}

int Request::track() { return _track; }

int Request::sector() { return _sector; }

double Request::time() { return _time; }

void Request::print() {
    std::cout << time() << " " << track() << " " << sector() << std::endl;
}
