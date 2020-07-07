#ifndef TEST_H
#define TEST_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class test
{
public:
  test();
  Ui::MainWindow *ui;
private:

  void on_pushButton_4_clicked();
};

#endif // TEST_H
