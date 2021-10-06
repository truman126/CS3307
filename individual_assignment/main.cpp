/**
 * main.cpp
 * Author: Truman Johnston, tjohn54@uwo.ca
 * File Contents: This Class contains the main function
 * Date: Oct 5, 2021
 * */

#include "mainwindow.h"

/**
  * function: main
  * description: executes the program
  * parameters: command line arguments
  * returns: returns the app gui
  * */
int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  MainWindow mainWindow;
  mainWindow.showMaximized();
  return app.exec();
}
