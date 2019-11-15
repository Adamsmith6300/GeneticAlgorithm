
#include "main.hpp"
#include <iostream>
#include <fstream>
#include <random>
#include <sstream>

#include "City.hpp"



using namespace std;

int main() {
    fstream f{"cities.txt"};

    string line;
    vector<City> citiesList;
    random_device rd; // obtain a random number from hardware
    mt19937 eng(rd()); // seed the generator
    uniform_int_distribution<> distr(0, MAP_BOUNDARY); // define the range

    while(getline(f,line)){
        istringstream iss{line};
        string cityName;
        iss >> cityName;
        int x = distr(eng);
        int y = distr(eng);
        City newCity{x,y,cityName};
        citiesList.push_back(newCity);
    }
//    for(auto it = citiesList.begin(); it != citiesList.end(); ++it){
//        cout << *it << endl;
//    }

    return 0;
}