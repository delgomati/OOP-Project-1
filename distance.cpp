//
// Created by Owner on 11/1/2022.
//

#include "distance.h"
#include <iostream>
using namespace std;

Distance::Distance(){
    cityName = "";
    distance = 0;

}

// if user inputs the same city twice
Distance::Distance(string name, int newDistance){
    cityName = name;
    if(newDistance>= 0){
        distance = newDistance;
    }
    else{
        distance = 0;
    }
}

//returns variable value:

int Distance::getDistance() {
    return distance;
}

string Distance::getCityName(){
    return cityName;
}
void Distance::setDistance(int newDistance){
    if(newDistance>= 0){
        distance = newDistance;
    }


}