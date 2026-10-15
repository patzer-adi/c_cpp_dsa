#include "SymmetricDates.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

bool SymmetricDates::isPalindrome(const string& s) {
    int n = s.size();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - 1 - i]) return false;
    }
    return true;
}

void SymmetricDates::findAll() {
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for (int year = 2001; year <= 2100; year++) {
        bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        for (int month = 1; month <= 12; month++) {
            int maxDay = daysInMonth[month];
            if (month == 2 && leap) maxDay = 29;
            for (int day = 1; day <= maxDay; day++) {
                stringstream ss;
                ss << setfill('0') << setw(2) << day
                   << setw(2) << month << setw(4) << year;
                if (isPalindrome(ss.str())) {
                    stringstream dateStr;
                    dateStr << setfill('0') << setw(2) << day << "-"
                            << setw(2) << month << "-" << setw(4) << year;
                    dates.push_back(dateStr.str());
                }
            }
        }
    }
}

void SymmetricDates::display() {
    cout << "Symmetric dates in 2001-2100:" << endl;
    for (const string& d : dates) cout << d << endl;
    cout << "Total: " << dates.size() << " symmetric dates found." << endl;
}

void SymmetricDates::run() {
    try {
        findAll();
        display();
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}
