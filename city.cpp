//
// Created by Owner on 11/1/2022.
//

#include "city.h"
#include "distance.h"
#include <iostream>
using namespace std;

//creating class

City::City() {
    name = "";
    countOfDistances = 0;
}

City::City(string cityName){
    name = cityName;
    countOfDistances = 0;
}

//sets the city name with the coordinating distance
void City::setDistance(string targetCity, int distance) {

    for (int i = 0; i < MAX_CITIES; i++){

        if (listDistances[i].getCityName() == targetCity){
            listDistances[i].setDistance(distance);
        }

        else if (listDistances[i].getCityName() == ""){
            Distance currDistance(targetCity, distance);
            listDistances[i] = currDistance;
            break;
        }
    }

}

void City::addDetour(string targetCityName, int detourDistance){
    // Needs to search for a Distance object with the given city’s name. When found, computes
    //the new distance and sets it to the object.
    for (int i=0; i< countOfDistances; i++){
        if(listDistances[i].getCityName() == targetCityName){
            listDistances[i].setDistance(detourDistance + listDistances[i].getDistance());
            break;
        }
    }
}

// Computes the distance to another city
int City::distanceTo(string cityName){

    for (int i = 0; i < MAX_CITIES; i++){
        if (listDistances[i].getCityName() == cityName){
            return listDistances[i].getDistance();
        }
    }


}
//calculates the cost of the trip and taking into account detour, gas cost, the mpg
double City::tripCost(string targetCityName, double mpg, double gasCost){
    int distanceNum;
    for (Distance distance: listDistances){
        if(distance.getCityName() == targetCityName){
            distanceNum = distance.getDistance();
        }
    }

    double cost = (distanceNum / mpg) * gasCost;
    return cost;
}

//calculates the average distance between the distances in the array
double City::getAverageDistance(){
    int sum = 0;
    int numCities = 0;
    double average;
    for (Distance distance: listDistances){
        if (distance.getCityName() != name && distance.getDistance() != 0){
            sum += distance.getDistance();
            numCities++;
        }

    }

    average = (double)sum / (double)numCities;
    return average;
}

//sorts that data for smallest distance in the array
string City::getClosestCity(){
    int closestDistance = 1000000;
    string closestCityName = "";
    for (Distance distance: listDistances){
        if (distance.getDistance() != 0 && distance.getDistance() < closestDistance){
            closestDistance = distance.getDistance();
            closestCityName = distance.getCityName();
        }
    }
    return closestCityName;
}

//sorts the data for largest distance in the array
string City::getFarthestCity(){
    int farthestDistance = 0;
    string farthestCityName = "";
    for (Distance distance: listDistances){
        if (distance.getDistance() > farthestDistance){
            farthestDistance = distance.getDistance();
            farthestCityName = distance.getCityName();
        }
    }
    return farthestCityName;
}

//sorts the data for the second smallest distance in the array
string City::getSecondClosestCity(){
    int secondClosestDistance = 1000000;
    string secondClosestCityName = "";
    string closestCityName = getClosestCity();
    for (Distance distance: listDistances){
        if (distance.getDistance() !=0 && distance.getDistance() < secondClosestDistance && distance.getCityName() != closestCityName){
            secondClosestDistance = distance.getDistance();
            secondClosestCityName = distance.getCityName();
        }
    }
    return secondClosestCityName;

}

//sorts the data for the second largest distance in the array
string City::getSecondFarthestCity(){

    int secondFarthestDistance = 0;
    string secondFarthestCityName = "";
    string farthestCityName = getFarthestCity();
    for (Distance distance: listDistances){
        if (distance.getDistance() > secondFarthestDistance && distance.getCityName() != farthestCityName){
            secondFarthestDistance = distance.getDistance();
            secondFarthestCityName = distance.getCityName();
        }
    }
    return secondFarthestCityName;
}

// inputs name of city
string City::getName() {
    return name;
}
// setting inputed value to the cityName
void City::setName(string cityName){
    name = cityName;
}

// indexing the distances array
Distance City::getDistance(int index) {
    return listDistances[index];
}
