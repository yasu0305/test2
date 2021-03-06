#include "digitalclock.h"

DigitalClock::DigitalClock(QWidget *parent)
  : QLCDNumber(parent)
{

  QTimer *timer = new QTimer(this);

  connect(timer, &QTimer::timeout, this, &DigitalClock::showTime);
  timer->start(1000);

}


void DigitalClock::showTime()
{

  QDateTime time = QDateTime::currentDateTime();
  QString text = time.toString("hh:mm");

  if ((time.toSecsSinceEpoch() % 2) == 0)
    text[2] = ' ';

  display(text);

}
