/**
 * mainwindow.h
 * Author: Truman Johnston, tjohn54@uwo.ca
 * File Contents: Contains the header for the main window that renders the gui
 * Date: Oct 5, 2021
 * */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QPushButton>
#include <QLineEdit>
#include <QListWidget>
#include <QLabel>
#include <QTextEdit>
#include <Vector>
#include <algorithm>

using namespace std;

#include "command.h"

using namespace boost::process;

namespace Ui
{
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT
public:
  explicit MainWindow(QWidget *parent = nullptr);

private:
  /**
  * function: handleCommand
  * description: handles commands in the text input once the execute button is clicked
  * parameters: none
  * returns: none
  * */

  void handleCommand();

  /**
  * function: storeCommand
  * description: stores the command object in a vector
  * parameters: Command object new_command
  * returns: none
  * */
  void storeCommand(Command);

  /**
  * function: updateItemHistory
  * description: updates the item history list
  * parameters: the string input command from the user
  * returns: none
  * */
  void updateItemHistory(string);

  /**
  * function: viewHistoryOfItem
  * description: shows the output of the command and exit code to the user if
  * they click on a previously entered command on the gui
  * 
  * parameters: none
  * returns: none
  * */
  void viewHistoryOfItem();

  vector<Command> *storedCommands;
  QPushButton *enter_button;
  QLineEdit *command_input;
  QListWidget *previous_command_list;
  QLabel *return_status;
  QTextEdit *output_display;
};
#endif // MAINWINDOW_H
