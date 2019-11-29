
#include "main.hpp"
#include <iostream>
#include <fstream>
#include <random>
#include <sstream>

#include "City.hpp"
#include "Tour.hpp"
#include "Population.hpp"


using namespace std;

int main() {
    fstream f{"cities.txt"};

    string line;
    vector<City> citiesList;
    random_device rd; // obtain a random number from hardware
    mt19937 eng(rd()); // seed the generator
    uniform_int_distribution<> distr(0, MAP_BOUNDARY); // define the range
    for(int i = 0; i < 5; ++i){
        getline(f,line);
        istringstream iss{line};
        string cityName;
        iss >> cityName;
        int x = distr(eng);
        int y = distr(eng);
        City newCity{x,y,cityName};
        citiesList.push_back(newCity);
    }
    vector<Tour> tours;
    double bestFitness;
    for(int i = 0; i < 10; ++i){
        Tour newTour{citiesList};
        newTour.shuffleCities();
        newTour.determineFitness();
        if(i == 0){
            bestFitness = newTour.get_fitness();
        }
        if(bestFitness > newTour.get_fitness()){
            bestFitness = newTour.get_fitness();
            tours[0] = newTour;
        } else {
            tours.push_back(newTour);
        }
    }
    Population pop{tours};
//    cout << pop;
    Population parentSet1(pop.getParentSet());
    cout << "PARENT1: " << parentSet1 << endl;
    Population parentSet2(pop.getParentSet());
    cout << "PARENT1: " << parentSet2 << endl;
//    cout << pop;
    return 0;
}