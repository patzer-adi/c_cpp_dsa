#include <iostream>
#include "TemperatureConverter.h"

using namespace std;

TemperatureConverter::TemperatureConverter(float temp, char u)
{
    temperature = temp;
    unit = u;
}

void TemperatureConverter::convert()
{
    if (unit == 'C' || unit == 'c')
    {
        temperature = 1.8 * temperature + 32;
        unit = 'F';
    }
    else if (unit == 'F' || unit == 'f')
    {
        temperature = (temperature - 32) / 1.8;
        unit = 'C';
    }
}

void TemperatureConverter::display()
{
    cout << "Converted Temperature: " 
         << temperature << " " << unit << endl;
}
