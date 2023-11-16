#include <iostream>
using namespace std;
int main()
{
    double share, price, stock, commission, total;
    cout << "How many shares did you buy?\n";
    cin >> share;
    cout << "How much is each share?\n";
    cin >> price;
    stock = share * price; //The amount paid for the stock alone (without the commission)
    commission = stock * 0.02; //The amount of the commission
    total = stock + commission; //The total amount paid(for the stock plus the commission)
    cout << "Stock:$" << stock << "\n";
    cout << "Commission:$" << commission << "\n";
    cout << "Total:$" << total << "\n";
}