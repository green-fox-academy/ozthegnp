#include "oop_04.hpp"
#include <iostream>
#include <string>

using namespace std;

int main() {
    // The market price of the houses is 400 EUR / square meters
    // Make the get_price() function work
    // Create a constructor for the House class that takes it's address and area.
    House house = House("Andrassy 66", 349);
    
    cout << "The price of real estate is " << house.get_price() << " EUR" <<endl;

    return 0;
}
