#ifndef DISPDATETIME_H
#define DISPDATETIME_H

#include <QLabel>
#include <QTime>
#include <QTimer>

class DispDateTime : public QLabel
{

  Q_OBJECT

public:
  DispDateTime(QWidget *parent = nullptr);

public slots:
  void showTime();

private slots:

signals:
  void valueChanged();

};

#endif
