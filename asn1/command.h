#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <fstream>
#include <boost/process.hpp>

using namespace std;

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





  

};
#endif // MAINWINDOW_H
