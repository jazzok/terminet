#ifndef CSTATUSBAR_H
#define CSTATUSBAR_H

#include <QWidget>
#include <QStatusBar>

class CStatusBar : public QStatusBar
{
  Q_OBJECT
public:
  explicit CStatusBar(QWidget *parent = nullptr);
          ~CStatusBar();
signals:

};

#endif // CSTATUSBAR_H
