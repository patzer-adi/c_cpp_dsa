#include <iostream>
using namespace std;

class TemperatureConverter
{
private:
    float t;
    char u;

public:
    void input()
    {
        cout << "Enter the temperature and unit (C/F): " << endl;
        cin >> t >> u;
    }

    void convert()
    {
        if (u == 'C' || u == 'c')
        {
            float f = 1.8 * t + 32;
            cout << "Temperature in Fahrenheit: " << f << endl;
        }
        else if (u == 'F' || u == 'f')
        {
            float c = (t - 32) / 1.8;
            cout << "Temperature in Celsius: " << c << endl;
        }
        else
        {
            cout << "Invalid unit! Please enter C or F." << endl;
        }
    }
};

int main()
{
    TemperatureConverter temp;
    temp.input();
    temp.convert();
    return 0;
}
