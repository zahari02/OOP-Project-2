#include "Universe.h"

const int Universe::max_planets = 10000;

Jedi* Universe::findJedi(string name)
{
    Jedi * jedi;
    for(int i=0; i<planets.size(); i++)
    {
        jedi = planets[i].findJedi(name);
        if(jedi!=nullptr)
            return jedi;
    }
    return nullptr;
}

Planet* Universe::findPlanet(string name)
{
    for(int i=0; i<planets.size(); i++)
    {
        if(planets[i].getName() == name)
            return &(planets[i]);
    }
    return nullptr;
}


void Universe::checkPlanet(string planet)
{
    if(findPlanet(planet) == nullptr)
        throw UniverseException("Planet not found\n");
}

void Universe::checkJedi(string jedi)
{
    if(findJedi(jedi) == nullptr)
        throw UniverseException("Jedi not found\n");
}

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

    planets.clear();
    planets.resize( nplanets );
    for(int i=0; i<nplanets; i++)
    {
        planets[i].load(file);
    }
    unsaved_changes = false;
}

void Universe::save(ofstream &file)
{
    file << planets.size() << endl;

    for(int i=0; i< planets.size(); i++)
    {
        planets[i].save(file);
    }

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
    Planet * planet = findPlanet(name);
    if(planet == nullptr)
    {
        planets.push_back(Planet(name));
        cout<<"Planet added\n";
    }
    else
        cout<<"Error: Planet already exists.\n";
    unsaved_changes = true;
}

void Universe::addJedi(string pname,string jname,string rank,int age,string colour,double strength)
{
    checkPlanet(pname);

    Planet * planet = findPlanet(pname);
    Jedi * jedi = findJedi(jname);
    if(jedi != nullptr)
    {
        cout<<"Error: This jedi already exists\n";
        return;
    }
    if(age < 0 || strength < 0 || !Rank::validRank(rank))
    {
        cout<<"Error: wrong data\n";
        return;
    }
    planet->addJedi(jname,rank,age,colour,strength);
    unsaved_changes = true;
}

void Universe::removeJedi(string jname,string pname)
{
    checkPlanet(pname);
    Planet * planet = findPlanet(pname);
    planet->removeJedi(jname);
    unsaved_changes = true;
}

void Universe::promoteJedi(string jname,double mult)
{
    checkJedi(jname);
    Jedi *jedi = findJedi(jname);
    if(mult<=0)
    {
        cout<<"Error: multiplier is not positive\n";
        return;
    }
    jedi->promote(mult);
    unsaved_changes = true;
}

void Universe::demoteJedi(string jname,double mult)
{
    checkJedi(jname);
    Jedi *jedi = findJedi(jname);
    if(mult<=0 || mult >= 1)
    {
        cout<<"Error: multiplier must be between 0 and 1\n";
        return;
    }
    jedi->demote(mult);
    unsaved_changes = true;
}

void Universe::getStrongest(string pname)
{
    checkPlanet(pname);
    Planet * planet = findPlanet(pname);
    planet->printStrongest();
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
    for(int i=0; i < planets.size(); i++)
    {
        if(planets[i].getName() == name)
        {
            planets[i].print();
            return;
        }
    }
}

void Universe::print2(string pname1,string pname2)
{

}
