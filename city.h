//
// Created by Owner on 11/1/2022.
//

#ifndef HW4_CITY_H
#define HW4_CITY_H
#include <iostream>
#include <string>
#include "distance.h"

using namespace std;




class City {
public:
    City();
    City(string cityName);
    //City(City const &aCity);
    string getName();
    void setName(string cityName);
    void setDistance(string targetCityName, int distance);
    Distance getDistance(int index);
    void addDetour(string targetCityName, int detourDistance);
    int distanceTo(string cityName);
    double tripCost(string targetCityName, double mpg, double gasCost);

    double getAverageDistance();
    string getClosestCity();
    string getFarthestCity();
    string getSecondClosestCity();
    string getSecondFarthestCity();

private:
    string name;
    int countOfDistances;
    static const int MAX_CITIES = 30;
    Distance listDistances[MAX_CITIES];
};

#endif //HW4_CITY_H
