//
// Created by Adam on 2019-11-15.
//

#include <random>
#include <algorithm>
#include "Tour.hpp"

ostream& operator<<(ostream& os, const Tour& tour){
    for(auto it = tour.cities.begin(); it != tour.cities.end(); ++it){
        os << *it;
    }
    os << "Fitness: " << tour.fitness << endl;
    return os;
}

void Tour::shuffleCities(){
    random_device rd;
    mt19937 g(rd());
    shuffle(this->cities.begin(), this->cities.end(), g);
}
void Tour::determineFitness(){
    double totalDistance = 0.0;

    for(auto it = this->cities.begin(); it != this->cities.end() - 1; ++it){
        double xDifference = abs(it->get_x() - (it + 1)->get_x());
        double yDifference = abs(it->get_y() - (it + 1)->get_y());
        double distance = sqrt(pow(xDifference,2) + pow(yDifference,2));
        totalDistance += distance;
    }
    this->fitness = (1.0/totalDistance)*MAP_BOUNDARY;
//    cout << this->fitness << endl;
}