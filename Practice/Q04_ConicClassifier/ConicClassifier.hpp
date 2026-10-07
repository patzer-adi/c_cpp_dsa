#ifndef CONICCLASSIFIER_HPP
#define CONICCLASSIFIER_HPP

#include <string>
using namespace std;

class ConicClassifier {
private:
    double a, b, c, h, g, f;
    string classify();
public:
    void run();
};

#endif
