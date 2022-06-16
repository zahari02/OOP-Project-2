#include "UniverseException.h"

UniverseException::UniverseException(string msg): msg(msg)
{
    //ctor
}

string UniverseException::what()
{
    return msg;
}
