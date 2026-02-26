

class TemperatureConverter
{
private:
    float temperature;
    char unit;

public:
    TemperatureConverter(float temp, char u);
    void convert();
    void display();
};

