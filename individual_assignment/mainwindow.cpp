/**
 * mainwindow.cpp
 * Author: Truman Johnston, tjohn54@uwo.ca
 * File Contents: Contains the main window that renders the gui
 * Date: Oct 5, 2021
 * */

#include "mainwindow.h"

/**
  * function: MainWindow()
  * description: sets up the window for the gui
  * parameters: a pointer to the parent widget
  * returns: none
  * */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
  // a vector to store old commands
  storedCommands = new vector<Command>;

  // Creating the interface

  // Create the button, make "this" the parent
  enter_button = new QPushButton("Enter", this);

  //creating the place to input commands setting this to the parent
  command_input = new QLineEdit(this);

  // this is the display for what the command outputs
  output_display = new QTextEdit(this);

  //this is a list of previously executed commands
  previous_command_list = new QListWidget(this);

  //this displays the exit code from the command
  return_status = new QLabel(this);

  //so that the output cannot be edited
  output_display->setReadOnly(true);

  // set size and location of the interface attributes
  //interface is 650 wide

  command_input->setGeometry(QRect(QPoint(25, 25), QSize(500, 50)));
  enter_button->setGeometry(QRect(QPoint(550, 25), QSize(100, 30)));

  output_display->setGeometry(QRect(QPoint(25, 100), QSize(625, 200)));

  return_status->setGeometry(QRect(QPoint(25, 325), QSize(625, 30)));

  previous_command_list->setGeometry(QRect(QPoint(25, 400), QSize(625, 400)));

  \ // Connect button signal to appropriate slot
      connect(enter_button, &QPushButton::released, this, &MainWindow::handleCommand);

  //calls the viewHistoryOfItem function when an item on the list is selected.
  connect(previous_command_list, &QListWidget::clicked, this, &MainWindow::viewHistoryOfItem);
}

/**
  * function: handleCommand
  * description: handles commands in the text input once the execute button is clicked
  * parameters: none
  * returns: none
  * */
void MainWindow::handleCommand()
{

  //checks if the command line is empty
  if (command_input->text().toStdString() == "")
  {
    output_display->setText("Please enter a valid command");
  }

  //attempts to execute the command
  else
  {
    //creates a new command object sending the command input to the contructor
    Command command(command_input->text().toStdString());

    //this executes the command
    command.executeCommand();

    //executes the store command function, stores the current command in a vector to be referenced for later
    storeCommand(command);

    //display the exit code
    return_status->setText(QString::number(command.getReturnCode()));

    //displays the output of the command to the output display
    output_display->setText(QString::fromStdString(command.getOutput()));

    //updates the previous item display
    updateItemHistory(command_input->text().toStdString());
  }
}
/**
  * function: storeCommand
  * description: stores the command object in a vector
  * parameters: Command object new_command
  * returns: none
  * */
void MainWindow::storeCommand(Command new_command)
{
  //stores the command in the vector
  storedCommands->push_back(new_command);
}

/**
  * function: updateItemHistory
  * description: updates the item history list
  * parameters: the string input command from the user
  * returns: none
  * */
void MainWindow::updateItemHistory(string commandText)
{
  //adds the item to the previous item display
  previous_command_list->addItem(QString::fromStdString(commandText));
}

/**
  * function: viewHistoryOfItem
  * description: shows the output of the command and exit code to the user if
  * they click on a previously entered command on the gui
  * 
  * parameters: none
  * returns: none
  * */
void MainWindow::viewHistoryOfItem()
{

  //search for the item in the vector by using the row number being selected

  // display the output
  output_display->setText(QString::fromStdString(storedCommands[0][previous_command_list->currentRow()].getOutput()));

  //display the return status
  return_status->setText(QString::number(storedCommands[0][previous_command_list->currentRow()].getReturnCode()));
}