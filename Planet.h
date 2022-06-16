#include "Jedi.h"

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

public:

    Planet();
    Planet(string&);
    void load(ifstream&);
    void save(ofstream&);
};

#endif // PLANET_H
