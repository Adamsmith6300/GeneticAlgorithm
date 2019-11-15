//
// Created by Adam on 2019-11-15.
//

#include "City.hpp"


ostream& operator<<(ostream& os, const City& city){
    os << city.name + ": ";
    os << city.x << ", " << city.y << endl;
    return os;
}
