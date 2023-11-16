#include <iostream>
using namespace std;
int main()
{
    double radius, height, surface_area, volume;
    cout << "Enter the radius of the cylinder (meters):\n";
    cin >> radius;
    cout << "Enter the height of the cylinder (meters):\n";
    cin >> height;
    surface_area = 2 * 3.14159 * radius * height + 2 * 3.14159 * radius * radius; //calculates area from 2(pi)rh + 2(pi)r(squared)
    volume = 3.14159 * radius * radius * height; // calculates volume from (pi)r(squared)
    cout << "The surface area of a cylinder of radius " << radius << " and height " << height << " is " << surface_area << " square meters (or m^2)\n";
    cout << "The volume of a cylinder of radius " << radius << " and height " << height << " is " << volume << " cubic meters (or m^3)\n";
    return 0;
}