#ifndef QUADRATICFACTORIZER_HPP
#define QUADRATICFACTORIZER_HPP

#include <string>
using namespace std;

class QuadraticFactorizer {
private:
    double a, b, c;
    string factorize();
public:
    void run();
};

#endif
