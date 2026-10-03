#ifndef BASECONVERTER_HPP
#define BASECONVERTER_HPP

#include <string>
using namespace std;

class BaseConverter {
private:
    int number;
    int base;
    string convert();
public:
    void run();
};

#endif
