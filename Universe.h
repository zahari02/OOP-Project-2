#include "Planet.h"

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;


#ifndef UNIVERSE_H
#define UNIVERSE_H


class Universe
{
    vector<Planet> planets;
public:
    void read(ifstream &);
    void save(ofstream &);
    void addPlanet(string);
    void addJedi(string,string,string,int,string,double);
    void removeJedi(string,string);
};

#endif // UNIVERSE_H
