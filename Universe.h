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
    static const int max_planets;

    vector<Planet> planets;
    bool unsaved_changes;

    Jedi* findJedi(string);
    Planet* findPlanet(string);

    void checkPlanet(string);
    void checkJedi(string);

public:
    Universe();

    void load(ifstream &);
    void save(ofstream &);
    void close();
    bool unsavedChanges();

    void addPlanet(string);
    void addJedi(string,string,string,int,string,double);
    void removeJedi(string,string);
    void promoteJedi(string,double);
    void demoteJedi(string,double);
    void getStrongest(string);
    void getYoungest(string,string);
    void getColour2(string,string);
    void getColour(string);
    void print(string);
    void print2(string,string);

};

#endif // UNIVERSE_H
