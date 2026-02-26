#include <iostream>
#include "TemperatureConverter.h"

using namespace std;

int main()
{
    float t;
    char u;

    cout << "Enter temperature and unit (C/F): ";
    cin >> t >> u;

    TemperatureConverter obj(t, u);
    obj.convert();
    obj.display();

    return 0;
}
