#include "Planet.h"

const int Planet::max_jedi = 10000;

void Planet::checkJedi(string jname)
{
    if(findJedi(jname) == nullptr)
        throw UniverseException("Jedi not found\n");
}

void Planet::checkPopulated()
{
    if(people.empty())
        throw UniverseException("No jedi on planet\n");
}

void Planet::checkRank(string rank)
{
    bool found = false;
    for(int i=0; i<people.size(); i++)
    {
        if( people[i].getRank() == rank)
        {
            found = true;
            break;
        }
    }
    if(!found)
        throw UniverseException("No jedi with rank " + rank + " on planet\n");
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

vector<const Jedi*> Planet::getJedi()
{
    vector<const Jedi*> jedi_p( people.size() );
    for(int i=0; i< people.size(); i++)
        jedi_p[i] = &people[i];
    return jedi_p;
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
    checkPopulated();
    Jedi jedi = people[0];
    for(int i=1; i<people.size(); i++)
    {
        if( jedi.getStrength() < people[i].getStrength())
            jedi = people[i];
    }
    jedi.print();
}

void Planet::printYoungest(string rank)
{
    checkPopulated();
    checkRank(rank);
    Jedi * jedi = nullptr;
    for(int i=0; i<people.size(); i++)
    {
        if( people[i].getRank() == rank)
        {
            if(jedi==nullptr)
                jedi = &people[i];
            else
            {
                if( jedi->getAge() > people[i].getAge() )
                    jedi = &people[i];
                else if ( jedi->getAge() == people[i].getAge())
                    if( Jedi::comp_names( &people[i], jedi) )
                        jedi = &people[i];
            }
        }
    }
    jedi->print();
}

void Planet::printColourRank(string rank)
{
    checkPopulated();
    checkRank(rank);
    string best_colour="";
    int max_colour_amount = 0;
    for(int i=0; i < people.size(); i++)
    {
        int colour_amount = 0;
        if( people[i].getRank() == rank)
        {
            for(int j=i; j < people.size(); j++)
            {
                if( people[j].getRank() == rank && people[j].getColour() == people[i].getColour())
                    colour_amount++;
            }
            if( colour_amount > max_colour_amount )
            {
                max_colour_amount = colour_amount;
                best_colour = people[i].getColour();
            }
        }
    }
    cout<<best_colour<< endl;
}

void Planet::printColourMaster()
{
    checkPopulated();
    checkRank("GRAND_MASTER");
    string best_colour="";
    int max_colour_amount = 0;
    for(int i=0; i < people.size(); i++)
    {
        int colour_amount = 0;
        if( people[i].getRank() == "GRAND_MASTER")
        {
            for(int j=0; j < people.size(); j++)
            {
                if(people[j].getColour() == people[i].getColour())
                    colour_amount++;
            }
            if( colour_amount > max_colour_amount )
            {
                max_colour_amount = colour_amount;
                best_colour = people[i].getColour();
            }
        }
    }
    cout<<best_colour<< endl;
}

void Planet::print_sorted()
{
    checkPopulated();
    vector<const Jedi*> jedi_arr( getJedi() );
    sort(jedi_arr.begin(),jedi_arr.end(),Jedi::comp_rank);
    for(int i=0; i< jedi_arr.size(); i++)
    {
        jedi_arr[i]->print();
    }
}
