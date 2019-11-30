//
// Created by Adam on 2019-11-15.
//

#ifndef GENETICALGORITHM_TOUR_HPP
#define GENETICALGORITHM_TOUR_HPP

#include "City.hpp"

class Tour {

private:
    vector<City*> cities;
    double fitness;

public:
    Tour(){}
    Tour(vector<City*> cities): cities{cities}, fitness{std::numeric_limits<float>::max()}{
    }
    double get_fitness(){return fitness;}
    friend ostream& operator<<(ostream& os, const Tour& tour);
    void shuffleCities();
    void determineFitness();
    vector<City*> getCities(){return cities;}
    void mutateTour();

};


#endif //GENETICALGORITHM_TOUR_HPP
