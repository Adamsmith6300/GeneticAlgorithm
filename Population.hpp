//
// Created by Adam on 2019-11-15.
//

#ifndef GENETICALGORITHM_POPULATION_HPP
#define GENETICALGORITHM_POPULATION_HPP

#include <vector>
#include "Tour.hpp"

class Population {

private:
    vector<Tour> tours;

public:
    Population(vector<Tour> tours): tours{tours}{}
    friend ostream& operator<<(ostream& os, const Population& pop);
    vector<Tour> getParentSet();
};


#endif //GENETICALGORITHM_POPULATION_HPP
