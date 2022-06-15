#include "ProgramExecuter.h"

const vector<string> ProgramExecuter::commands =
{
    "open",         // 0
    "close",        // 1
    "save",         // 2
    "save_as",      // 3
    "help",         // 4
    "exit",         // 5
    "add_planet",   // 6
    "create_jedi",  // 7
    "remove_jedi",  // 8
    "promote_jedi", // 9
    "demote_jedi",  // 10
    "get_strongest_jedi",   // 11
    "get_youngest_jedi",    // 12
    "get_most_used_saber_color",   // 13
    "print"  // 14
    // planet + planet 15
};

const string ProgramExecuter::help =
"The following commands are supported:\n"
"All folders in filename <file> must be separated with '/' \n"
"open <file>     opens <file>\n"
"close      closes currently opened file without saving\n"
"save       saves the currently open file\n"
"save_as <file>      saves the currently open file in <file>\n"
"help       prints this information\n"
"exit       exists the program\n"
"add_planet <planet_name>\n"
"create_jedi <planet_name> <jedi_name> <jedi_rank> <jedi_age> <saber_color> <jedi_strength>\n"
"removeJedi <jedi_name> <planet_name>\n"
"promote_jedi <jedi_name> <multiplier>\n"
"demote_jedi <jedi_name> <multiplier>\n"
"get_strongest_jedi <planet_name>\n"
"get_youngest_jedi <planet_name> <jedi_rank>\n"
"get_most_used_saber_color <planet_name> <jedi_rank>\n"
"get_most_used_saber_color <planet_name>\n"
"print <planet_name>\n"
"print <jedi_name>\n"
"<planet_name> + <planet_name>      prints info for two planets\n"
;

ProgramExecuter::ProgramExecuter(): stop_program(false), opened(false), unsaved_changes(false)
{

}

void ProgramExecuter::read_command()
{
    string buff;

    cin>>command;
    args.clear();
    while(cin.peek()!='\n')
    {
        cin>>buff;
        args.push_back(buff);
    }
}

void ProgramExecuter::mainMenu()
{
    read_command();
    try
    {
        parseExec();
    }
    catch(exception &e)
    {
        cout<<"Invalid command\n";
    }
}

int ProgramExecuter::commandNumber()
{
    for(int i=0; i<commands.size(); i++)
        if(command == commands[i])
            return i;
    return -1;
}


void ProgramExecuter::parseExec()
{
    int cnum = commandNumber();

    if(args.size() == 2 && args[0] == "+")
        cnum = 15;

    if(cnum > 5 && opened == false)
    {
        cout<<"You must open file first\n";
        return;
    }

    if(cnum == -1)
    {
        throw exception();
    }
    if(cnum == 0)  // open <file>
    {
        parse_s();
        open(args[0]);
    }
    if(cnum == 1) // close
    {
        parse_0();
        opened = false;
        unsaved_changes = false;
        cout<<"File closed.\n";
    }
    if(cnum == 2) // save
    {
        parse_0();
        save();
    }
    if(cnum == 3) // save_as <file>
    {
        parse_s();
        saveas();
    }
    if(cnum == 4)  // help
    {
        parse_0();
        cout<<help<< endl;
    }
    if(cnum == 5)  // exit
    {
        parse_0();
        exit();
        stop_program = true;
    }
    if(cnum == 6)  // add planet <planet name>
    {
        parse_s();
        universe.addPlanet(args[0]);
    }
    if(cnum == 7) // create jedi <planet_name> <jedi_name> <jedi_rank> <jedi_age> <saber_color> <jedi_strength>
    {
        int age;
        double strength;
        parse_sssisd(age,strength);
        universe.addJedi(args[0],args[1],args[2],age,args[4],strength);
    }
    if(cnum == 8) // removeJedi <jedi_name> <planet_name>
    {
        parse_ss();
        universe.removeJedi(args[0],args[1]);
    }
    if(cnum == 9) //
    {

    }
    if(cnum == 10)
    {

    }
    if(cnum == 11)
    {

    }
    if(cnum == 12)
    {

    }
    if(cnum == 13)
    {

    }
    if(cnum == 14)
    {

    }
    if(cnum == 15)
    {

    }
}

void ProgramExecuter::parse_0()
{
    if(args.size() != 0)
        throw exception();
}

void ProgramExecuter::parse_sssisd(int &age,double &strength)
{
    if(args.size() != 6)
        throw exception();
    age = stoi(args[3]);
    strength = stod(args[5]);
}

void ProgramExecuter::parse_sd(double &mult)
{
    if(args.size() != 2)
        throw exception();
    mult = stod( args[1] );
}

void ProgramExecuter::parse_ss()
{
    if(args.size() != 2)
        throw exception();
}

void ProgramExecuter::parse_s()
{
    if(args.size() != 1)
        throw exception();
}

void ProgramExecuter::open(string fname)
{
    if(opened)
    {
        cout<<"You must close the current file first"<< endl;
        return;
    }

    filename = fname;
    ifstream file;
    file.open(fname);

    if(!file)
    {
        ofstream ofile;
        ofile.open(fname);
        if(!ofile)
        {
            cout<<"Error creating file\n";
            return;
        }
        ofile<<"0\n";
        ofile.close();
    }

    try
    {
        universe.read(file);
    }
    catch(exception &e)
    {
        cout<<"Error reading file\n";
        return;
    }

    opened = true;
    file.close();
}

void ProgramExecuter::save()
{
    ofstream file;
    file.open(filename);
    if(!file)
    {
        cout<<"Error saving file\n";
        return;
    }
    universe.save(file);
    unsaved_changes = false;
    file.close();
}


void saveas()
{
    string fname;
    ofstream file;
    file.open(args[0]);
    if(!file)
    {
        cout<<"Error saving file\n";
        return;
    }
    universe.save(file)
    unsaved_changes = false;
    file.close();
}

void ProgramExecuter::exit()
{
    if(unsaved_changes == true)
    {
        cout<<"You have an open file with unsaved changes, please select close or save(as) first.\n";
        read_command();
        int cnum = commandNumber();
        if(cnum == 1)
            return;
        else if(cnum == 2)
        {
            parse_0();
            save();
        }
        else if(cnum == 3)
        {
            parse_s();
            saveas();
        }
        else
            throw exception();
    }
}
/*
void ProgramExecuter::parse_ps()
{
    if(args.size() != 2 || args[0]!='+')
        throw exception();
}
*/
ProgramExecuter ProgramExecuter::PE;

void ProgramExecuter::run()
{
    cout << help<< endl;
    while(!stop_program)
    {
        mainMenu();
    }
}
