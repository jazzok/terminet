#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H


#include <QApplication>
#include <QWidget>
#include <QDir>
#include <QMessageBox>
#include <QFile>
#include <QFrame>
#include <QSettings>
#include <QCloseEvent>
#include <QGridLayout>

#include "cdatatypes.h"

class CMainWindow : public QWidget
{
    Q_OBJECT

public:
    CMainWindow(QWidget *parent = nullptr);
    ~CMainWindow();

private:
    QString         tmpPath;
    TTMSettings     tmSettings;
    QString         pathStyle;
    bool            init;

protected:
    virtual void    closeEvent      (QCloseEvent*   e);
    bool            eventFilter     (QObject*       obj,
                                    QEvent*         e);
private slots:
    void    setAppStyle     (void);
    bool    getSettings     (void);
    bool    saveSettings    (void);

};
#endif // CMAINWINDOW_H
