#include "dispdatetime.h"

DispDateTime::DispDateTime(QWidget *parent)
  : QLabel(parent)
{

  QTimer *timer = new QTimer(this);

//  connect(timer, &QTimer::timeout, this, &DispDateTime::showTime);
//  timer->start(1000);

}


void DispDateTime::showTime()
{

  QDateTime time = QDateTime::currentDateTime();
  QString text = time.toString("yyyy/MM/dd hh:mm:ss");

  setText(text);

}
