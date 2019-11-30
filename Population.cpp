//
// Created by Adam on 2019-11-15.
//

#include "Population.hpp"

ostream& operator<<(ostream& os, const Population& pop){
    for(auto it = pop.tours.begin(); it != pop.tours.end(); ++it){
        os << *it << endl;
    }
    return os;
}

Population Population::getParentSet(){
    vector<Tour> parents = this->tours;
    random_device rd;
    mt19937 g(rd());
    shuffle(parents.begin()+1, parents.end(), g);
    vector<Tour> subset(parents.begin()+1, parents.begin()+PARENT_POOL_SIZE+1);
    Population set{subset};
    return set;
}

Tour Population::moveBestTourToFront(){
    auto itBest = tours.begin();
    double bestFitness = itBest->get_fitness();
    for (auto it = tours.begin(); it != tours.end(); ++it) {
        if (bestFitness > it->get_fitness()) {
            bestFitness = it->get_fitness();
            itBest = it;
        }
    }
    auto x = *itBest;
    Tour best = *itBest;
    tours.erase(itBest);
    tours.insert(tours.begin(), x);
    return best;
}

double Population::evaluateFitness(){
    double bestDistance = std::numeric_limits<float>::max();
    for(auto it = this->tours.begin(); it != this->tours.end(); ++it){
        it->determineFitness();
        if(it->get_fitness() < bestDistance){
            bestDistance = it->get_fitness();
        }
    }
    return bestDistance;
}
