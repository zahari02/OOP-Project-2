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

    static bool comp_names(const Jedi*,const Jedi*);
    static bool comp_rank(const Jedi*,const Jedi*);

    Jedi();
    Jedi(string,Rank,int,string,double);

    void load(ifstream&);
    void save(ofstream&);

    void promote(double mult);
    void demote(double mult);


    string getName();
    double getStrength();
    int getAge();
    string getColour();
    string getRank();

    void print() const;

};

#endif // JEDI_H
