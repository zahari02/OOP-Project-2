#include "Jedi.h"
#include "UniverseException.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#ifndef PLANET_H
#define PLANET_H

class Planet
{
    static const int max_jedi;

    vector<Jedi> people;
    string name;

    void checkJedi(string);
    void checkPopulated();
    void checkRank(string rank);

public:

    Planet();
    Planet(string&);
    void load(ifstream&);
    void save(ofstream&);
    void addJedi(string,string,int,string,double);

    string & getName();
    vector<const Jedi*> getJedi();

    void print();
    Jedi* findJedi(string);
    void removeJedi(string);
    void printStrongest();
    void printYoungest(string rank);
    void printColourRank(string rank);
    void printColourMaster();
    void print_sorted();

};

#endif // PLANET_H
