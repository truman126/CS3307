#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

namespace Ui {
  class MainWindow;
}
 
class MainWindow : public QMainWindow
{
  Q_OBJECT
public:
  explicit MainWindow(QWidget *parent = nullptr);
private slots:
  void handleButton();
  void storeCommand(Command);
  void updateItemHistory(string);
  void viewHistoryOfItem();

private:
  vector<Command> *storedCommands;
  QPushButton *enter_button;
  QLineEdit *command_input;
  QListWidget *previous_command_list;
  QLabel *return_status;
  QTextEdit *output_display;

};
#endif // MAINWINDOW_H
