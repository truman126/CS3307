/**
 * command.cpp
 * Author: Truman Johnston, tjohn54@uwo.ca
 * File Contents: This Class handles the commands entered into the gui
 * Date: Oct 5, 2021
 * */

#include "command.h"

string commandText; //input text from user
string result;      //output after executing the command
int returnCode;     //exit code returned by the program

/**
  * function: Command
  * description: empty constructor for the object
  * parameters: none
  * returns: none
  * */
Command::Command()
{
    commandText = "";
    result = "";
    returnCode = 0;
}

/**
  * function: Command
  * description: empty constructor for the object
  * parameters: the string that was inputted into the gui
  * returns: none
  * */
Command::Command(string new_commandText)
{
    commandText = new_commandText;
    result = "";
    returnCode = 0;
}

/**
  * function: ~Command
  * description: destructor for the object
  * parameters: none
  * returns: none
  * */
Command::~Command()
{
    //empty body
}

// METHODS

/**
  * function: executeCommand
  * description: attempts to execute the command entered by the user
  * parameters: none
  * returns: none
  * */
void Command::executeCommand()
{
    //pipe stream used to capture standard output
    bp::ipstream output;

    //temp string used to convert the std out to a string
    std::string line;

    // a try catch block, stops command line errors
    try
    {

        returnCode = bp::system(commandText, (bp::std_out & bp::std_err) > output); //executes the command and pipes the output into a pipe stream variable
        //to print the output into a string
        while (std::getline(output, line))
        {
            result += line;
        }

        //catches if the command is invalid
    }
    catch (bp::process_error e)
    {
        returnCode = -1;

        result = "An error has occurred!";
    }
}
/**
  * function: getOutput()
  * description: getter for the output of the command
  * parameters: none
  * returns: string result of the output of the command
  * */
string Command::getOutput()
{
    return result;
}

/**
  * function: getInput()
  * description: getter for the input of the user
  * parameters: none
  * returns: string result of the input from the user
  * */
string Command::getInput()
{
    return commandText;
}

/**
  * function: getReturnCode()
  * description: getter for the exit code from the shell
  * parameters: none
  * returns: int result of the exit code from the shell
  * */
int Command::getReturnCode()
{
    return returnCode;
}

/**
  * function: setInput()
  * description: setter input command from the user
  * parameters: string: command that the user input
  * returns: none
  * */
void Command::setInput(string new_command)
{
    commandText = new_command;
}
