#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
{
  // Creating the interface
 
  // Create the button, make "this" the parent
  enter_button = new QPushButton("Enter", this);

  //creating the place to input commands setting this to the parent
  command_input = new QLineEdit(this);

  output_display = new QLabel(this);

  previous_command_list = new QListView(this);

  return_status = new QLabel(this);




  // set size and location of the interface attributes
  //interface is 650 wide

  command_input->setGeometry(QRect(QPoint(25, 25), QSize(500, 50)));
  enter_button->setGeometry(QRect(QPoint(550, 25), QSize(100, 30)));

  output_display->setGeometry(QRect(QPoint(25, 100), QSize(625, 400)));


  return_status->setGeometry(QRect(QPoint(25, 600), QSize(625, 30)));
  previous_command_list->setGeometry(QRect(QPoint(25, 100), QSize(625, 400)));



  
  // layout->setSpacing(10);

  // widg->show();

 
  // Connect button signal to appropriate slot
  connect(enter_button, &QPushButton::released, this, &MainWindow::handleButton);
}
 
void MainWindow::handleButton()
{
  // change the text

  if (command_input->text().toStdString() == "") {
    return_status->setText("Please enter a valid command");
  }
  else {
    // Command command(command_input->text().toStdString());

    // command.executeCommand();

    //display the text
    return_status->setText("the command has executed");
  }



  

  // resize button
  // m_button->resize(100,100);

  command_input->setText("");

  return_status->setText("return status");
}
