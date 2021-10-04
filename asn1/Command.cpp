#include "command.h"


string commandText; //input text from user
string result = "";
int returnCode;

//constructor with no parameters
Command::Command()
{
    commandText = "";
    result = "";
    returnCode = 0;
}

//constructor with parameters
Command::Command(string new_commandText)
{
    commandText = new_commandText;
    result = "";
    returnCode = 0;
}

//destructor
Command::~Command()
{
    //empty body
}


// METHODS

