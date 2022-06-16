#include "Jedi.h"
#include "UniverseException.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

#ifndef PLANET_H
#define PLANET_H

class Planet
{
    static const int max_jedi;

    vector<Jedi> people;
    string name;

    void checkJedi(string);

public:

    Planet();
    Planet(string&);
    void load(ifstream&);
    void save(ofstream&);
    void addJedi(string,string,int,string,double);

    string & getName();

    void print();
    Jedi* findJedi(string);
    void removeJedi(string);
    void printStrongest();
};

#endif // PLANET_H
