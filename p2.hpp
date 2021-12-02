#ifndef P2_HPP
#define P2_HPP
// #include "dAccess.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>

/*
    P2 is part two of the project, i wrote this a bit neater because it is much larger.
    I it compares multiple strings and prints out a grid of their similarities.
*/

class p2
{
public:
    p2();

private:
    std::vector<int> lengths;

    void runTwo();
    std::vector<int> computeLengths(std::string file);
    void directAccess(std::string file);
    void showPositionsArray();
    int LCM(std::string s1, std::string s2);
    char calculateSimilarity(std::string s1, std::string s2);
};

#endif