#include <iostream>
using namespace std;
int main()
{
    double celsius, fahrenheit, rankin;
    cout << "Please enter the temperature in Degrees C:\n";
    cin >> celsius;
    fahrenheit = celsius * 9 / 5 + 32;
    rankin = fahrenheit + 459.67;
    cout << "That is ";
    cout << rankin;
    cout << " Degrees Rankin\n";
}
