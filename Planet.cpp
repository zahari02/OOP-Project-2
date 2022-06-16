#include "Planet.h"

const int Planet::max_jedi = 10000;

void Planet::checkJedi(string jname)
{
    if(findJedi(jname) == nullptr)
        throw UniverseException("Jedi not found\n");
}

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

void Planet::save(ofstream & file)
{
    file<< name << endl;
    file<< people.size() << endl;
    for(int i=0; i< people.size(); i++)
    {
        people[i].save(file);
    }
}

void Planet::addJedi(string jname,string rank,int age,string colour,double strength)
{
    people.push_back(Jedi(jname,rank,age,colour,strength));
}

string& Planet::getName()
{
    return name;
}

void Planet::print()
{
    cout<<"Planet: "<<name<< endl;
    cout<<people.size()<<" jedi: "<< endl;
    for(int i=0; i<people.size(); i++)
        people[i].print();
}

Jedi* Planet::findJedi(string name)
{
    for(int i=0; i<people.size(); i++)
        if( people[i].getName() == name)
            return &(people[i]);
    return nullptr;
}

void Planet::removeJedi(string jname)
{
    checkJedi(jname);
    for(int i=0; i<people.size(); i++)
        if( people[i].getName() == jname)
        {
            people.erase( people.begin()+i );
            return;
        }
}

void Planet::printStrongest()
{
    if(people.empty())
    {
        cout<<"No jedi on planet\n";
        return;
    }
    Jedi jedi = people[0];
    for(int i=1; i<people.size(); i++)
    {
        if( jedi.getStrength() < people[i].getStrength())
            jedi = people[i];
    }
    jedi.print();
}
