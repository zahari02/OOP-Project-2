#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "Rank.h"

#ifndef JEDI_H
#define JEDI_H


class Jedi
{
    string name;
    Rank rank;
    int age;
    string colour;
    double strength;

public:
    Jedi();
    Jedi(string,Rank,int,string,double);

    void load(ifstream&);
    void save(ofstream&);

    string& getName();
    void promote(double mult);
    void demote(double mult);
    double getStrength();
    int getAge();
    string& getColour();
    void print();

};

#endif // JEDI_H
