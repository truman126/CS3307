#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <fstream>
#include <boost/process.hpp>
#include <numeric>

using namespace std;

namespace bp = boost::process;

namespace Ui {
  class Command;
}
 
class Command
{
  private:
    string commandText;
    string result;
    int returnCode;

  public:

    //empty constructor method
    Command();

    //constructor method with string of the command
    Command(string);

    //destructor method
    ~Command();

    //command that executes the command input
    void executeCommand();

    string getOutput();
    
    
    string getInput();






  

};
#endif // MAINWINDOW_H
