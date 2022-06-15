#include "Rank.h"

const vector<string> Rank::ranks = {
    "YOUNGLING",
    "INITIATE",
    "PADAWAN",
    "KNIGHT-ASPIRANT",
    "KNIGHT",
    "MASTER",
    "BATTLE_MASTER",
    "GRAND_MASTER"
};

const int Rank::max_rank = ranks.size();

Rank::Rank()
{
    rank_num=0;
}

bool Rank::validRank(string rank)
{
    //string buff;
    for(string buff : ranks)
        if(buff == rank)
            return true;
    return false;
}

void Rank::setRank(string rank)
{
    for(int i=0; i<=max_rank; i++)
        if(ranks[i] == rank)
        {
            rank_num = i;
            break;
        }
}

string Rank::getRank()
{
    return ranks[rank_num];
}

void Rank::promote()
{
    if(rank_num < max_rank)
        rank_num++;
}

void Rank::demote()
{
    if(rank_num > 0)
        rank_num--;
}
