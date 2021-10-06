#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
{

  storedCommands = new vector<Command>;

  // Creating the interface
 
  // Create the button, make "this" the parent
  enter_button = new QPushButton("Enter", this);

  //creating the place to input commands setting this to the parent
  command_input = new QLineEdit(this);

  output_display = new QTextEdit(this);

  previous_command_list = new QListWidget(this);

  return_status = new QLabel(this);


  output_display->setReadOnly(true);


  // set size and location of the interface attributes
  //interface is 650 wide

  command_input->setGeometry(QRect(QPoint(25, 25), QSize(500, 50)));
  enter_button->setGeometry(QRect(QPoint(550, 25), QSize(100, 30)));

  output_display->setGeometry(QRect(QPoint(25, 100), QSize(625, 200)));


  return_status->setGeometry(QRect(QPoint(25, 325), QSize(625, 30)));
  previous_command_list->setGeometry(QRect(QPoint(25, 400), QSize(625, 400)));


 
  // Connect button signal to appropriate slot
  connect(enter_button, &QPushButton::released, this, &MainWindow::handleButton);
  connect(previous_command_list, &QListWidget::clicked, this, &MainWindow::viewHistoryOfItem );
}
 
void MainWindow::handleButton()
{
  // change the text

  if (command_input->text().toStdString() == "") {
    return_status->setText("Please enter a valid command");
  }
  else {
    Command command(command_input->text().toStdString());

    command.executeCommand();

    storeCommand(command);

    //display the text
    return_status->setText("the command has executed");

    output_display->setText(QString::fromStdString(command.getOutput()));

    updateItemHistory(command_input->text().toStdString());
  
  
  }





  

  // resize button
  // m_button->resize(100,100);

  command_input->setText("");

  return_status->setText("return status");
}

void MainWindow::storeCommand(Command new_command)
{
  storedCommands->push_back(new_command);

}

void MainWindow::updateItemHistory(string commandText){
    previous_command_list->addItem(QString::fromStdString(commandText));
  
}

void MainWindow::viewHistoryOfItem() {

    //search for the item in the vector by using the row number being selected



    // display the text 
    output_display->setText(QString::fromStdString(storedCommands[0][previous_command_list->currentRow()].getOutput()));

    //display the return status
    // return_status->setText(QString::fromStdString(storedCommands[0][previous_command_list->currentRow()].getReturnStatus()));


    
}