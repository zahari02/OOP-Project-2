#include <string>
using namespace std;

#ifndef UNIVERSEEXCEPTION_H
#define UNIVERSEEXCEPTION_H


class UniverseException
{
    string msg;
public:
    UniverseException(string msg);
    string what();
};

#endif // UNIVERSEEXCEPTION_H
