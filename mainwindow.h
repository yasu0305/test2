#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include "digitalclock.h"
#include "dispdatetime.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{

  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private slots:
  void disp_date_time();
  void disp_text_browser();
  void on_pushButton_clicked();
  void on_pushButton_2_clicked();
  void on_pushButton_3_clicked();


  void on_lineEdit_returnPressed();

  void on_pushButton_4_clicked();

private:
  Ui::MainWindow *ui;
  QTimer *timer, *timer2;

};

#endif // MAINWINDOW_H
