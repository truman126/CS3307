#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QListView>
#include <QLabel>

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
private:
  QPushButton *enter_button;
  QLineEdit *command_input;
  QListView *previous_command_list;
  QLabel *return_status;
  QLabel *output_display;
};
#endif // MAINWINDOW_H
