#include "Planet.h"

const int Planet::max_jedi = 10000;

Planet::Planet()
{

}

Planet::Planet(string & newname): name(newname)
{

}

void Planet::load(ifstream & file)
{
    string new_name;
    file>>new_name;
    name = new_name;

    int njedi;
    file>>njedi;
    if(njedi < 0 || max_jedi < njedi)
        throw exception();

    people.resize( njedi );
    for(int i=0; i<njedi; i++)
    {
        people[i].load(file);
    }
}
