//
// Created by Owner on 11/1/2022.
//

#ifndef HW4_DISTANCE_H
#define HW4_DISTANCE_H
#include <iostream>
#include <string>
using namespace std;

class Distance {
public:
    Distance();
    Distance(string cityName, int distance);
    string getCityName();
    int getDistance();
    void setDistance(int newDistance);
private:
    int distance;
    string cityName;
};


#endif //HW4_DISTANCE_H