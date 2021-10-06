/**
 * command.h
 * Author: Truman Johnston, tjohn54@uwo.ca
 * File Contents: This header is for the class that handles the commands entered into the gui
 * Date: Oct 5, 2021
 * */

#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <fstream>
#include <boost/process.hpp>
#include <numeric>

using namespace std;

namespace bp = boost::process;

namespace Ui
{
  class Command;
}

class Command
{
private:
  string commandText;
  string result;
  int returnCode;

public:
  /**
  * function: Command
  * description: empty constructor for the object
  * parameters: none
  * returns: none
  * */
  Command();

  /**
  * function: Command
  * description: empty constructor for the object
  * parameters: the string that was inputted into the gui
  * returns: none
  * */
  Command(string);

  /**
  * function: ~Command
  * description: destructor for the object
  * parameters: none
  * returns: none
  * */
  ~Command();

  /**
  * function: executeCommand
  * description: attempts to execute the command entered by the user
  * parameters: none
  * returns: none
  * */
  void executeCommand();

  /**
  * function: getOutput()
  * description: getter for the output of the command
  * parameters: none
  * returns: string result of the output of the command
  * */
  string getOutput();

  /**
  * function: getInput()
  * description: getter for the input of the user
  * parameters: none
  * returns: string result of the input from the user
  * */
  string getInput();

  /**
  * function: getReturnCode()
  * description: getter for the exit code from the shell
  * parameters: none
  * returns: int result of the exit code from the shell
  * */
  int getReturnCode();

  /**
  * function: setInput()
  * description: setter input command from the user
  * parameters: string: command that the user input
  * returns: none
  * */
  void setInput(string);
};
#endif // MAINWINDOW_H
