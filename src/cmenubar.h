#ifndef CMENU_H
#define CMENU_H

#include <QWidget>
#include <QMenu>
#include <QMenuBar>

class CMenuBar : public QMenuBar
{
  Q_OBJECT
public:
  explicit CMenuBar(QWidget *parent = nullptr);
          ~CMenuBar();
signals:
    void trigFileNew            (void);
    void trigFileOpen           (void);
    void trigFileOpenCurrent    (void);
    void trigFileSaveFragment   (void);
    void trigFileSaveTAB        (void);
    void trigFileSaveMGF        (void);
    void trigFileSaveSample     (void);
    void trigFileSaveProtocol   (void);
    void trigFileSaveColor      (void);
    void trigFileClose          (void);
    void trigFileExit           (void);
//
    void trigEditCopy           (void);
//
    void trigViewParam          (void);
    void trigViewPreLaunch      (void);
    void trigViewProperty       (void);
    void trigViewMapSignal      (void);
//
    void trigOptionZeroAxis     (void);
    void trigOptionRangeView    (void);
    void trigOptionConfig       (void);
    void trigOptionPassword     (void);
//
    void trigWindowCascade      (void);
    void trigWindowHorizontal   (void);
    void trigWindowVertical     (void);
    void trigWindowAll          (void);
//
    void trigHelpAbout          (void);

private:
//
  QAction *actFileNew;
  QAction *actFileOpen;
  QAction *actFileOpenCurrent;
  QAction *actFileSaveFragment;
  QAction *actFileSaveTAB;
  QAction *actFileSaveMGF;
  QAction *actFileSaveSample;
  QAction *actFileSaveProtocol;
  QAction *actFileSaveColor;
  QAction *actFileClose;
  QAction *actFileExit;
//
  QAction *actEditCopy;
//
  QAction *actViewParam;

//
  QAction *actOptionZeroAxis;
  QAction *actOptionRangeView;
  QAction *actOptionConfig;
  QAction *actOptionPassword;


//
  QAction *actHelpAbout;
//
  QMenu *menuFile;
  QMenu *menuEdit;
  QMenu *menuView;
  QMenu *menuFunction;
  QMenu *menuOptions;
  QMenu *menuWindow;
  QMenu *menuHelp;
};

#endif // CMENU_H

