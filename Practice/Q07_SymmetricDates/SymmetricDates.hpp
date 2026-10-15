#ifndef SYMMETRICDATES_HPP
#define SYMMETRICDATES_HPP

#include <vector>
#include <string>
using namespace std;

class SymmetricDates {
private:
    vector<string> dates;
    bool isPalindrome(const string& s);
    void findAll();
    void display();
public:
    void run();
};

#endif
