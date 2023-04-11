#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include "city.h"
using namespace std;

//Declaring const and array
const int CITIES_TO_LOAD =15;
City listCities[CITIES_TO_LOAD];

// declaring functions
void loadCities(City cities[]);
string toUpperCase(string aString);
string checkCityNameExists(string cityName);


int main() {

    // Declare variables
    string sourceCity, destinationCity;
    string city1Name, city2Name;
    string closestCity, secondClosestCity;
    string farthestCity, secondFarthestCity;
    int option, detourDistance, detourOption;
    bool exit = false;
    bool loadFile = false;
    cout <<  fixed << setprecision(2 );
    //displays main menu
    do{
        cout << "---------------------------------\n"
                " Main Menu\n"
                "------------------------------\n"
                "1) Load Cities and Distances\n"
                "2) Add Weather Detour\n"
                "3) Distance Between Cities\n"
                "4) Distance and Trip Cost\n"
                "5) Average Trip Distance\n"
                "6) Closest City\n"
                "7) Farthest City\n"
                "8) Closest Two Cities\n"
                "9) Farthest Two Cities\n"
                " 99) EXIT\n"
                "------------------------------" << endl;

        //Incase user does not choose load data first
        cin >> option;
        if (!loadFile && option != 1){
            cout << "Warning: the data base has not been loaded. Please select 1 to load the data base before continuing" << endl;
            continue;
        }

//Swithc cases that call functions from city.cpp and distance.cpp depending which number is inputed by user
        switch (option) {
            case 1:
                loadCities(listCities);
                loadFile = true;
                break;
            case 2:
                // Adding a weather detour will ask for a source city, a destination city, and a detour distance
                //which will be added to the travel distance between the source and destination. Your program should also
                //ask if the detour is one way (source to target) or both ways (source to target and target to source) as well.
                cin.ignore();
                cout << "Enter source city: ";
                getline(cin, sourceCity);
                sourceCity = toUpperCase(sourceCity);
                sourceCity = checkCityNameExists(sourceCity);

                cout << "Enter destination city: ";
                getline(cin, destinationCity);
                destinationCity = toUpperCase(destinationCity);
                destinationCity = checkCityNameExists(destinationCity);


                cout << "Enter detour distance: ";
                cin >> detourDistance;

                cout << "Is the detour: " << endl;
                cout << "1) one way (source to target)"<< endl;
                cout << "2) both ways (source to target and target to source)" << endl;
                cin >> detourOption;


                for (City city: listCities){
                    if (city.getName() == sourceCity){
                        city.addDetour(destinationCity, detourDistance);
                    }
                    if (detourOption == 2 && city.getName() == destinationCity){
                        city.addDetour(sourceCity, detourDistance);
                    }
                }

                break;
            case 3:
            case 4:
                // asks the user for two city names and will display the distance, expressed in miles between the
                //two cities. E.g., “The current distance between DENVER and LOS ANGELES is 1410 miles.” (this includes a
                //75mile detour)
                cin.ignore();
                cout << "Enter the name of the first city: ";
                getline(cin, city1Name);
                city1Name = toUpperCase(city1Name);
                city1Name = checkCityNameExists(city1Name);


                cout << "Enter the name of the second city: ";
                getline(cin, city2Name);
                city2Name = toUpperCase(city2Name);
                city2Name = checkCityNameExists(city2Name);


                int mpg;
                double gasCost;
                if (option == 4){
                    cout << "Enter the average miles per gallon (mpg) performance of the car: ";
                    cin >> mpg;
                    cout << "Enter the average cost of gas: ";
                    cin >> gasCost;
                }

                int distanceBetween;
                double costTrip;
                for (City city: listCities){
                    if (city.getName() == city1Name){
                        distanceBetween = city.distanceTo(city2Name);
                        if (option == 4){
                            costTrip = city.tripCost(city2Name, mpg, gasCost);
                        }
                        break;
                    }
                }
                cout << "The current distance between " << city1Name << " and " << city2Name << " is: " << endl;
                cout << distanceBetween << " miles. "<< endl;

                if (option == 3){
                    cout << endl;
                }
                else if(option == 4){
                    cout << "The trip would cost $" << costTrip << " in a car that preforms " << mpg << "mpg and a gas price of $" << gasCost << "/gallon." << endl;
                }

                break;

            case 5:
                cin.ignore();
                cout << "Enter the name of the city: ";
                getline(cin, sourceCity);
                sourceCity = toUpperCase(sourceCity);
                sourceCity = checkCityNameExists(sourceCity);

                double averageDistance;
                for (City city: listCities){
                    if (city.getName() == sourceCity){
                        averageDistance = city.getAverageDistance();
                        break;
                    }
                }

                cout << "From " << sourceCity << " the average trip distance is " << averageDistance << " miles." << endl;
                break;

            case 6:
            case 8:
                cin.ignore();
                cout << "Enter the name of the city: ";
                getline(cin, sourceCity);
                sourceCity = toUpperCase(sourceCity);
                sourceCity = checkCityNameExists(sourceCity);

                int distanceClosest, distanceSecondClosest;
                for (City city: listCities){
                    if (city.getName() == sourceCity){
                        closestCity = city.getClosestCity();
                        distanceClosest = city.distanceTo(closestCity);
                        if (option == 8){
                            secondClosestCity = city.getSecondClosestCity();
                            distanceSecondClosest = city.distanceTo(secondClosestCity);
                        }
                        break;
                    }
                }
                if (option == 6){
                    cout << "The closest city to " << sourceCity << " is " << closestCity << ", " << distanceClosest << " miles away." << endl;
                }
                else if (option == 8){
                    cout << "The two closest cities to " << sourceCity << " are " << closestCity << ", " << distanceClosest << " miles away, and ";
                    cout << secondClosestCity << ", " << distanceSecondClosest << " miles away" << endl;
                }

                break;

            case 7:
            case 9:
                cin.ignore();
                cout << "Enter the name of the city: ";
                getline(cin, sourceCity);
                sourceCity = toUpperCase(sourceCity);
                sourceCity = checkCityNameExists(sourceCity);

                int distanceFarthest, distanceSecondFarthest;
                for (City city: listCities){
                    if (city.getName() == sourceCity){
                        farthestCity = city.getFarthestCity();
                        distanceFarthest = city.distanceTo(farthestCity);
                        if (option == 9){
                            secondFarthestCity = city.getSecondFarthestCity();
                            distanceSecondFarthest = city.distanceTo(secondFarthestCity);
                        }
                        break;
                    }
                }

                if (option == 7){
                    cout << "The farthest city to " << sourceCity << " is " << farthestCity << ", " << distanceFarthest << " miles away." << endl;
                }
                else if (option == 9){
                    cout << "The two farthest cities to " << sourceCity << " are " << farthestCity << ", " << distanceFarthest << " miles away, and ";
                    cout << secondFarthestCity << ", " << distanceSecondFarthest << " miles away" << endl;
                }

                break;
//Exit option for the user to end the program
            case 99:
                cout << "Are you sure you want to exit? (y/n): ";
                char answer;
                cin >> answer;
                answer = toupper(answer);
                if (answer == 'Y'){
                    exit = true;
                }

                break;
            default:
                cout << "Invalid option, please chose one of the numbers listed" << endl;
                break;

        }

    } while(!exit);


}

// Loads the city information and creates the objects to store the distance information
void loadCities(City cities[]){
    ifstream cityFile("cities.txt");
    if (cityFile.fail()){
        cerr << "Error opening cities file";
    }

    ifstream distancesFile("distances.txt");
    if (distancesFile.fail()){
        cerr << "Error opening distances file";
    }


    // Fill in array of Cities
    for (int i = 0; i < CITIES_TO_LOAD; i++){
        int cityIndex;
        string cityNameSpace;

        cityFile >> cityIndex;
        // Get rid of leading spaces
        getline(cityFile, cityNameSpace);
        string cityName;
        bool reachName = false;
        for (char c: cityNameSpace){
            if (c != ' '){
                reachName = true;
            }
            if (reachName){
                cityName +=  c;
            }
        }

        cityName = toUpperCase(cityName);

        City currCity(cityName);
        cities[cityIndex-1] = currCity;
    }


    for (int curr = 0; curr < CITIES_TO_LOAD; curr++){
        for (int target = 0; target < CITIES_TO_LOAD; target++){

            int distance;
            distancesFile >> distance;
            cities[curr].setDistance(cities[target].getName(), distance);

        }
    }

}

//ensures that even if user uses upper or lower case, the city inputted is interpreted by the program
string toUpperCase(string aString){
    string output = "";
    for (char c: aString){
        output += toupper(c);
    }
    return output;
}

//Incase user inputs  a city name that is not apart of the filie cities.txt
string checkCityNameExists(string cityName){

    while (true){
        for (City city: listCities){
            if (city.getName() == cityName){
                return cityName;
            }
        }
        cout << "Error: city name is not included. Please enter another city: ";
        getline(cin, cityName);
        cityName = toUpperCase(cityName);
    }

}