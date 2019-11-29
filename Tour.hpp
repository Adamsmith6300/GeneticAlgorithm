//
// Created by Adam on 2019-11-15.
//

#ifndef GENETICALGORITHM_TOUR_HPP
#define GENETICALGORITHM_TOUR_HPP

#include "City.hpp"

class Tour {

private:
    vector<City> cities;
    double fitness;

public:
    Tour(){}
    Tour(vector<City> cities): cities{cities} {
    }
    double get_fitness(){return fitness;}
    friend ostream& operator<<(ostream& os, const Tour& tour);
    void shuffleCities();
    void determineFitness();

};


#endif //GENETICALGORITHM_TOUR_HPP
