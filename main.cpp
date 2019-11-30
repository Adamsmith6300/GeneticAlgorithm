
#include <iostream>
#include <fstream>
#include <random>
#include <sstream>
#include <stdlib.h>
#include "City.hpp"
#include "Tour.hpp"
#include "Population.hpp"

using namespace std;

vector<City*> make_citiesList();
Tour crossTours(Tour p1, Tour p2);
void mutateTours(vector<Tour> crosses);

int main() {
    vector<City*> citiesList = make_citiesList();
    vector<Tour> tours;
    for(int i = 0; i < POPULATION_SIZE; ++i){
        Tour newTour{citiesList};
        newTour.shuffleCities();
        newTour.determineFitness();
        tours.push_back(newTour);
    }
    Population pop{tours};

//Gen Algo Starts
    Tour baseElite = pop.moveBestTourToFront();
    double baseDistance = baseElite.get_fitness();
    double bestDistance = baseDistance;
    srand (time(NULL));
    int count = 0;
//    while (bestDistance/baseDistance > IMPROVEMENT_THRESHOLD && count < ITERATIONS){
while(count < 10){
    cout << count << endl;
        Tour elite = pop.moveBestTourToFront();
        vector<Tour> crosses;
        crosses.push_back(elite);
        while(crosses.size() < pop.getTours().size()){
            Population setOne = pop.getParentSet();
            Tour parentOne = setOne.moveBestTourToFront();
            Population setTwo = pop.getParentSet();
            Tour parentTwo = setTwo.moveBestTourToFront();
            Tour mergedTour = crossTours(parentOne, parentTwo);
            crosses.push_back(mergedTour);
        }
        mutateTours(crosses);
        pop.setTours(crosses);
        bestDistance = pop.evaluateFitness();
        ++count;
//
//        cout << "Iteration: " << count << endl;
//        cout << "Distance/Fitness: " << bestDistance << endl;
//        if(bestDistance < baseDistance){
//            cout << "Improvement achieved" << endl;
//        } else {
//            cout << "Improvement not achieved" << endl;
//        }
//        cout << "Improved by: " << bestDistance/baseDistance << endl;
    }



    Tour bestRoute = pop.moveBestTourToFront();
    cout << "FINAL RESULTS:" << endl;
    cout << "Number of iterations:" << count << endl;
    cout << "Base Distance:" << baseDistance << endl;
    cout << "Best Distance:" << bestDistance << endl;
    if(bestDistance/baseDistance > IMPROVEMENT_THRESHOLD){
        cout << "Improvement Factor Achieved!" << endl;
    } else {
        cout << "Improvement Factor NOT Achieved!" << endl;
    }
    cout << "Base Route: " << endl;
    cout << baseElite << endl;
    cout << "Best Route Taken: " << endl;
    cout << bestRoute << endl;


    return 0;
}


void mutateTours(vector<Tour> crosses){
    int randAsInt = (rand() % 10) + 20;
    double randPercent = (double)randAsInt/100.00;
    int mutationCount = randPercent * crosses.size();
    int count = 0;
    while (count < mutationCount){
        int randTourIndex = rand() % crosses.size() + 1;
        crosses[randTourIndex].mutateTour();
        ++count;
    }
}



Tour crossTours(Tour p1, Tour p2){
    vector<City*> newTourCities;
    vector<City*> p1Cities = p1.getCities();
    vector<City*> p2Cities = p2.getCities();
    int upToFromP1 = rand() % p1Cities.size();
    for(int i = 0; i <= upToFromP1; ++i){
        newTourCities.push_back(p1Cities[i]);
    }
    for(auto it = p2Cities.begin(); it != p2Cities.end(); ++it){
        if(std::find(newTourCities.begin(), newTourCities.end(), *it) == newTourCities.end()) {
            newTourCities.push_back(*it);
        }
    }
    Tour mergedTour{newTourCities};
    return mergedTour;
}


vector<City*> make_citiesList(){
    fstream f{"cities.txt"};
    string line;
    vector<City*> citiesList;
    random_device rd; // obtain a random number from hardware
    mt19937 eng(rd()); // seed the generator
    uniform_int_distribution<> distr(0, MAP_BOUNDARY); // define the range
    for(int i = 0; i < CITIES_IN_TOUR; ++i){
        getline(f,line);
        istringstream iss{line};
        string cityName;
        iss >> cityName;
        int x = distr(eng);
        int y = distr(eng);
        City* newCity = new City(x,y,cityName);
        citiesList.push_back(newCity);
    }
    return citiesList;
}
