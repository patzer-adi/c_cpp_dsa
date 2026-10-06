#include "FileStats.hpp"
#include <fstream>
#include <iostream>
using namespace std;

void FileStats::analyze() {
    ifstream file(filename);
    if (!file.is_open())
        throw runtime_error("Cannot open file: " + filename);

    string line;
    bool inWord = false;

    while (getline(file, line)) {
        lines++;
        characters += line.size();
        characters++; // count the newline

        for (char c : line) {
            if (c == '.' || c == '!' || c == '?')
                sentences++;
            if (c == ' ' || c == '\t') {
                if (inWord) { words++; inWord = false; }
            } else {
                inWord = true;
            }
        }
        if (inWord) { words++; inWord = false; }
    }

    file.close();
}

void FileStats::display() {
    cout << "number of lines : " << lines
         << "  |  number of words : " << words
         << "  |  number of characters : " << characters
         << "  |  number of sentences : " << sentences << endl;
}

void FileStats::run() {
    try {
        lines = words = characters = sentences = 0;
        cout << "Enter filename: ";
        cin >> filename;
        analyze();
        display();
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}
