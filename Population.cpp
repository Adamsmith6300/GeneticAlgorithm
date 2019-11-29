//
// Created by Adam on 2019-11-15.
//

#include <random>
#include <algorithm>
#include "Population.hpp"

ostream& operator<<(ostream& os, const Population& pop){
    for(auto it = pop.tours.begin(); it != pop.tours.end(); ++it){
        os << *it << endl;
    }
    return os;
}

vector<Tour> Population::getParentSet(){
    vector<Tour> parents = this->tours;
    random_device rd;
    mt19937 g(rd());
    shuffle(parents.begin()+1, parents.end(), g);
    vector<Tour> subset(parents.begin()+1, parents.begin()+PARENT_POOL_SIZE);
    double bestFitness = subset.begin()->get_fitness();
    for(auto it = subset.begin(); it != subset.end(); ++it){
        if(bestFitness > it->get_fitness()){
            bestFitness = it->get_fitness();
            subset[0] = *it;
        }
    }
    return subset;
}
