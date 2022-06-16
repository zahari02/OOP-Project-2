#include <string>
#include <vector>
using namespace std;

#ifndef RANK_H
#define RANK_H

class Rank
{
    static const vector<string> ranks;
    static const int max_rank;
    int rank_num;

public:

    static bool validRank(string rank);

    Rank();
    Rank(string rank);
    //void setRank(string rank);
    string getRank();
    void promote();
    void demote();
};

#endif // RANK_H
