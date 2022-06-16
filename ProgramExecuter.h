#include "Universe.h"

#include <string>
#include <vector>
#include <iostream>
#include <exception>
#include <fstream>
using namespace std;

#ifndef PROGRAMEXECUTER_H
#define PROGRAMEXECUTER_H

typedef vector<string> str_arr;

class ProgramExecuter
{
private:

    static const str_arr commands;
    static const string help;

    Universe universe;
    bool opened;
    string filename;

    bool stop_program;
    string command;
    str_arr args;

    ProgramExecuter();

    void read_command();

    void mainMenu();
    int commandNumber();
    void parseExec();

    void parse_0();
    void parse_sssisd(int &,double &);
    void parse_sd(double &);
    void parse_ss();
    void parse_s();
    void parse_ps();

    void open(string &fname);
    void save();
    void saveas();
    void exit();

public:

    static ProgramExecuter PE;
    void run();
};

#endif // PROGRAMEXECUTER_H
