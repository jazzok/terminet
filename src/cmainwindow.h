#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H


#include <QApplication>
#include <QMainWindow>
#include <QDir>
#include <QMessageBox>
#include <QFile>
#include <QFrame>
#include <QSettings>
#include <QCloseEvent>
#include <QListWidget>

#include "cdatatypes.h"
#include "cmenubar.h"
#include "ctoolbar.h"
#include "cstatusbar.h"

#include "coptionconfig.h"

class CMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    CMainWindow(QWidget *parent = nullptr);
    ~CMainWindow();

private:
    QString         tmpPath;
    TTMSettings     tmSettings;
    TMConfig        tmConfig;
    TMUserColor     tmUserColor;
    QString         pathStyle;
    bool            init;
    CMenuBar        *menuBar;
    CToolBar        *toolBar;
    CStatusBar      *statusBar;
    QListWidget     *listWidget;
//
    COptionConfig       *optionConfig;
///
    void  createMenu            (void);
    void  createToolBar         (void);
    void  createStatusBar       (void);
    void  moveToCenter          (void);

protected:
    virtual void    showEvent       (QShowEvent*    e);
    virtual void    closeEvent      (QCloseEvent*   e);
    virtual void    resizeEvent     (QResizeEvent*  e);
    bool            eventFilter		(QObject*		obj,
                                    QEvent*         e);
private slots:
    void    setAppStyle     (void);
    bool    getSettings     (void);
    bool    saveSettings    (void);
///
    void  openOptionConfig      (void);
};
#endif // CMAINWINDOW_H
