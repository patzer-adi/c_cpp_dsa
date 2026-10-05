#ifndef FLOATFORMATTER_HPP
#define FLOATFORMATTER_HPP

#include <string>
using namespace std;

class FloatFormatter {
private:
    string fractional;
    string integral;
    string format();
public:
    void run();
};

#endif
