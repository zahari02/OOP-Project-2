#include "Universe.h"

const int Universe::max_planets = 10000;

Universe::Universe()
{
    unsaved_changes = false;
}

void Universe::load(ifstream &file)
{
    int nplanets;
    file>>nplanets;
    if(nplanets < 0 || max_planets < nplanets)
        throw exception();

    planets.resize( nplanets );
    for(int i=0; i<nplanets; i++)
    {
        planets[i].load(file);
    }
}

void Universe::save(ofstream &file)
{
    unsaved_changes = false;
}

void Universe::close()
{
    planets.clear();
    unsaved_changes = false;
}

bool Universe::unsavedChanges()
{
    return unsaved_changes;
}

void Universe::addPlanet(string name)
{

}

void Universe::addJedi(string pname,string jname,string rank,int age,string colour,double strength)
{

}

void Universe::removeJedi(string jname,string pname)
{

}

void Universe::promoteJedi(string jname,double mult)
{

}

void Universe::demoteJedi(string jname,double mult)
{

}

void Universe::getStrongest(string pname)
{

}

void Universe::getYoungest(string pname,string rank)
{

}

void Universe::getColour2(string pname,string rank)
{

}

void Universe::getColour(string pname)
{

}

void Universe::print(string name)
{

}

void Universe::print2(string pname1,string pname2)
{

}
