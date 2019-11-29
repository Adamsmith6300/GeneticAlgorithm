//
// Created by Adam on 2019-11-15.
//

#ifndef GENETICALGORITHM_CITY_HPP
#define GENETICALGORITHM_CITY_HPP

#include <iostream>
#include <vector>
#include <string>

const int CITIES_IN_TOUR = 32;
const int POPULATION_SIZE = 32;
const int SHUFFLES = 64;
const int ITERATIONS = 1000;
const int MAP_BOUNDARY = 100;
const int PARENT_POOL_SIZE = 5;
const int MUTATION_RATE = 15;
const int NUMBER_OF_PARENTS = 2;
const int NUMBER_OF_ELITES = 1;
const double IMPROVEMENT_THRESHOLD = 0.8;


using namespace std;

class City {

private:
    //between [0,1000]
    int x;
    int y;
    string name;
public:
    City(){}
    City(int x, int y, string name): x{x}, y{y}, name{name} {};
    int get_x(){return x;}
    int get_y(){return y;}
    friend ostream& operator<<(ostream& os, const City& city);

};


#endif //GENETICALGORITHM_CITY_HPP
