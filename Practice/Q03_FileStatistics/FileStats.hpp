#ifndef FILESTATS_HPP
#define FILESTATS_HPP

#include <string>
using namespace std;

class FileStats {
private:
    string filename;
    int lines, words, characters, sentences;
    void analyze();
    void display();
public:
    void run();
};

#endif
