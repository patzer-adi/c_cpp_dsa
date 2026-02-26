#include <iostream>
using namespace std;

class TemperatureConverter
{
private:
    float temperature;
    char unit;

public:
    TemperatureConverter(float temp, char u)
    {
        temperature = temp;
        unit = u;
    }

    void convert()
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

    void display()
    {
        cout << "Converted Temperature: "
             << temperature << " " << unit << endl;
    }
};

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
