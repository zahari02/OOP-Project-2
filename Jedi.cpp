#include "Jedi.h"

bool Jedi::comp_names(const Jedi *jedi1,const Jedi *jedi2)
{
    return jedi1->name < jedi2->name;
}

bool Jedi::comp_rank(const Jedi *jedi1,const Jedi *jedi2)
{
    if(jedi1->rank.getRankNum() < jedi2->rank.getRankNum())
        return true;
    if( jedi1->rank.getRankNum() == jedi2->rank.getRankNum() )
        return jedi1->name < jedi2->name;
}

Jedi::Jedi()
{

}

Jedi::Jedi(string name,Rank rank,int age,string colour,double strength):
    name(name),rank(rank),age(age),colour(colour),strength(strength)
{

}

void Jedi::load(ifstream &file)
{
    string srank;
    file>>name>>srank;
    if(!Rank::validRank(srank))
        throw exception();
    rank = Rank(srank);
    file>>age>>colour>>strength;
}

void Jedi::save(ofstream &file)
{
    file<<name<< endl;
    file<<rank.getRank()<< endl;
    file<<age<< endl;
    file<<colour<< endl;
    file<<strength<< endl;
}

string Jedi::getName()
{
    return name;
}
void Jedi::promote(double mult)
{
    rank.promote();
    strength*=(1+mult);
}

void Jedi::demote(double mult)
{
    rank.demote();
    strength*=(1-mult);
}

double Jedi::getStrength()
{
    return strength;
}

int Jedi::getAge()
{
    return age;
}

string Jedi::getColour()
{
    return colour;
}

string Jedi::getRank()
{
    return rank.getRank();
}

void Jedi::print() const
{
    cout<<"Jedi: "<<name<< endl;
    cout<<"Rank: "<<rank.getRank()<< endl;
    cout<<"Age: "<<age<< endl;
    cout<<"Saber colour: "<<colour<< endl;
    cout<<"Strength: "<<strength<< endl;
    cout<<endl;
}
