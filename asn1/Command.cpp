#include "command.h"


string commandText; //input text from user
string result;
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

void Command::executeCommand()
{
    bp::ipstream output;
    std::string line;
    
    
    try {
        bp::system(commandText, (bp::std_out & bp::std_err)  > output); //executes the command and pipes the output into a pipe stream variable
        //to print the output into a string
        while (std::getline(output,line)){
            result += line;
        }
    } catch(bp::process_error e){
        cout << "error" << endl;
        result = "An error has occurred!";

    }


    

    

}

string Command::getOutput(){
    return result;
}

string Command::getInput(){
    return commandText;
}

