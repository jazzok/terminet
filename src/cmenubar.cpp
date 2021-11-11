#include "cmenubar.h"

/*
 *  Конструктор
 */
CMenuBar::CMenuBar(QWidget *parent) : QMenuBar(parent)
{
//
  menuFile = new QMenu("Файл",this);
  addMenu(menuFile);
//

//
  actFileNew = new QAction(QString("FileNew"),this);
  actFileNew->setObjectName(QString("actFileNew"));
  actFileNew->setText(QString("Новый"));
  actFileNew->setShortcut(QKeySequence("Ctrl+N"));
  actFileNew->setToolTip(QString("Новый"));
  actFileNew->setStatusTip(QString("Новый"));
  actFileNew->setWhatsThis(QString("Новый"));
  actFileNew->setIcon(QPixmap("://icons/wxp_1.ico"));
  connect(actFileNew,  SIGNAL(triggered()),
          this,        SIGNAL(trigFileNew()));
  menuFile->addAction(actFileNew);

  actFileOpen = new QAction(QString("FileOpen"),this);
  actFileOpen->setObjectName(QString("actFileOpen"));
  actFileOpen->setText(QString("Открыть"));
  actFileOpen->setShortcut(QKeySequence("Ctrl+N"));
  actFileOpen->setToolTip(QString("Открыть"));
  actFileOpen->setStatusTip(QString("Открыть"));
  actFileOpen->setWhatsThis(QString("Открыть"));
  actFileOpen->setIcon(QPixmap("://icons/wxp_1.ico"));
  connect(actFileOpen,  SIGNAL(triggered()),
          this,         SIGNAL(trigFileOpen()));
  menuFile->addAction(actFileOpen);

  actFileOpenCurrent = new QAction(QString("FileOpenCurrent"),this);
  actFileOpenCurrent->setObjectName(QString("actFileOpenCurren"));
  actFileOpenCurrent->setText(QString("Открыть в том же окне"));
  actFileOpenCurrent->setShortcut(QKeySequence("Ctrl+O"));
  actFileOpenCurrent->setToolTip(QString("Открыть в том же окне"));
  actFileOpenCurrent->setStatusTip(QString("Открыть в том же окне"));
  actFileOpenCurrent->setWhatsThis(QString("Открыть в том же окне"));
  actFileOpenCurrent->setIcon(QPixmap("://icons/wxp_1.ico"));
  connect(actFileOpenCurrent, SIGNAL(triggered()),
          this,               SIGNAL(trigFileOpenCurrent()));
  menuFile->addAction(actFileOpenCurrent);
//
  actFileSaveFragment = new QAction(QString("FileSaveFragment"),this);
  actFileSaveFragment->setObjectName(QString("actFileSaveFragment"));
  actFileSaveFragment->setText(QString("FileSaveFragment"));
  actFileSaveFragment->setShortcut(QKeySequence("Ctrl+X"));
  actFileSaveFragment->setToolTip(QString("FileSaveFragment"));
  actFileSaveFragment->setStatusTip(QString("FileSaveFragment"));
  actFileSaveFragment->setWhatsThis(QString("FileSaveFragment"));
  actFileSaveFragment->setIcon(QPixmap("://icons/wxp_1.ico"));
  connect(actFileSaveFragment, SIGNAL(triggered()),
          this,         SIGNAL(trigFileSaveFragment()));
  menuFile->addAction(actFileSaveFragment);
//
  actFileSaveTAB = new QAction(QString("FileSaveTAB"),this);
  actFileSaveTAB->setObjectName(QString("actFileSaveTAB"));
  actFileSaveTAB->setText(QString("FileSaveMGF"));
  actFileSaveTAB->setShortcut(QKeySequence("Ctrl+X"));
  actFileSaveTAB->setToolTip(QString("FileSaveMGF"));
  actFileSaveTAB->setStatusTip(QString("FileSaveMGF"));
  actFileSaveTAB->setWhatsThis(QString("FileSaveMGF"));
  actFileSaveTAB->setIcon(QPixmap("://icons/wxp_1.ico"));
  connect(actFileSaveTAB, SIGNAL(triggered()),
          this,         SIGNAL(trigFileSaveMGF()));
  menuFile->addAction(actFileSaveTAB);
//
  actFileSaveMGF = new QAction(QString("FileSaveMGF"),this);
  actFileSaveMGF->setObjectName(QString("actFileSaveMGF"));
  actFileSaveMGF->setText(QString("FileSaveMGF"));
  actFileSaveMGF->setShortcut(QKeySequence("Ctrl+X"));
  actFileSaveMGF->setToolTip(QString("FileSaveMGF"));
  actFileSaveMGF->setStatusTip(QString("FileSaveMGF"));
  actFileSaveMGF->setWhatsThis(QString("FileSaveMGF"));
  actFileSaveMGF->setIcon(QPixmap("://icons/wxp_1.ico"));
  connect(actFileSaveMGF, SIGNAL(triggered()),
          this,         SIGNAL(trigFileSaveMGF()));
  menuFile->addAction(actFileSaveMGF);
//
  actFileSaveSample = new QAction(QString("FileSaveSample"),this);
  actFileSaveSample->setObjectName(QString("actFileSaveSample"));
  actFileSaveSample->setText(QString("Закрыть"));
  actFileSaveSample->setShortcut(QKeySequence("Ctrl+X"));
  actFileSaveSample->setToolTip(QString("Закрыть"));
  actFileSaveSample->setStatusTip(QString("Закрыть"));
  actFileSaveSample->setWhatsThis(QString("Закрыть"));
  actFileSaveSample->setIcon(QPixmap("://icons/wxp_1.ico"));
  connect(actFileSaveSample, SIGNAL(triggered()),
          this,         SIGNAL(trigFileSaveSample()));
  menuFile->addAction(actFileSaveSample);

//
  actFileSaveProtocol = new QAction(QString("FileSaveProtocol"),this);
  actFileSaveProtocol->setObjectName(QString("actFileSaveProtocol"));
  actFileSaveProtocol->setText(QString("Сохранить протокол"));
  actFileSaveProtocol->setShortcut(QKeySequence("Ctrl+X"));
  actFileSaveProtocol->setToolTip(QString("Сохранить протокол"));
  actFileSaveProtocol->setStatusTip(QString("Сохранить протокол"));
  actFileSaveProtocol->setWhatsThis(QString("Сохранить протокол"));
  actFileSaveProtocol->setIcon(QPixmap("://icons/wxp_1.ico"));
  connect(actFileSaveProtocol, SIGNAL(triggered()),
          this,         SIGNAL(trigFileSaveProtocol()));
  menuFile->addAction(actFileSaveProtocol);
//
  actFileSaveColor = new QAction(QString("FileSaveColor"),this);
  actFileSaveColor->setObjectName(QString("actFileSaveColor"));
  actFileSaveColor->setText(QString("Сохранить палитру"));
  actFileSaveColor->setShortcut(QKeySequence("Ctrl+X"));
  actFileSaveColor->setToolTip(QString("Сохранить палитру"));
  actFileSaveColor->setStatusTip(QString("Сохранить палитру"));
  actFileSaveColor->setWhatsThis(QString("Сохранить палитру"));
  actFileSaveColor->setIcon(QPixmap("://icons/wxp_1.ico"));
  connect(actFileSaveColor, SIGNAL(triggered()),
          this,         SIGNAL(trigFileSaveColor()));
  menuFile->addAction(actFileSaveColor);
//
  actFileClose = new QAction(QString("FileClose"),this);
  actFileClose->setObjectName(QString("actFileClose"));
  actFileClose->setText(QString("Закрыть"));
  actFileClose->setShortcut(QKeySequence("Ctrl+X"));
  actFileClose->setToolTip(QString("Закрыть"));
  actFileClose->setStatusTip(QString("Закрыть"));
  actFileClose->setWhatsThis(QString("Закрыть"));
  actFileClose->setIcon(QPixmap("://icons/wxp_1.ico"));
  connect(actFileClose, SIGNAL(triggered()),
          this,         SIGNAL(trigFileClose()));
  menuFile->addAction(actFileClose);
//
  actFileExit = new QAction(QString("FileExit"),this);
  actFileExit->setObjectName(QString("actFileExit"));
  actFileExit->setText(QString("Выход"));
  actFileExit->setShortcut(QKeySequence("Ctrl+Q"));
  actFileExit->setToolTip(QString("Выход"));
  actFileExit->setStatusTip(QString("Выход"));
  actFileExit->setWhatsThis(QString("Выход"));
  actFileExit->setIcon(QPixmap("://icons/wxp_1.ico"));
  connect(actFileExit,  SIGNAL(triggered()),
          this,         SIGNAL(trigFileExit()));
  menuFile->addAction(actFileExit);

//
  menuEdit = new QMenu("&Редактор",this);
  addMenu(menuEdit);
  actEditCopy = new QAction(QString("EditCopy"),this);
  actEditCopy->setObjectName(QString("actEditCopy"));
  actEditCopy->setText(QString("Копировать"));
  actEditCopy->setShortcut(QKeySequence("Ctrl+C"));
  actEditCopy->setToolTip(QString("Копировать"));
  actEditCopy->setStatusTip(QString("Копировать"));
  actEditCopy->setWhatsThis(QString("Копировать"));
  actEditCopy->setIcon(QPixmap("://icons/wxp_1.ico"));
  connect(actEditCopy,  SIGNAL(triggered()),
          this,         SIGNAL(trigEditCopy()));
  menuEdit->addAction(actEditCopy);
//
  menuView = new QMenu("&Показать",this);
  addMenu(menuView);
  actViewParam = new QAction(QString("ViewParam"),this);
  actViewParam->setObjectName(QString("actViewParam"));
  actViewParam->setText(QString("Характеристики"));
  actViewParam->setShortcut(QKeySequence("Ctrl+C"));
  actViewParam->setToolTip(QString("Характеристики"));
  actViewParam->setStatusTip(QString("Характеристики"));
  actViewParam->setWhatsThis(QString("Характеристики"));
  actViewParam->setIcon(QPixmap("://icons/w2k_wmp_56.ico"));
  connect(actViewParam, SIGNAL(triggered()),
          this,         SIGNAL(trigViewParam()));
  menuView->addAction(actViewParam);

///
  menuOptions = new QMenu("&Настройка",this);
  addMenu(menuOptions);

  actOptionConfig = new QAction(QString("OptionConfig"),this);
  actOptionConfig->setObjectName(QString("actOptionConfig"));
  actOptionConfig->setText(QString("Конфигурация"));
  actOptionConfig->setShortcut(QKeySequence("Ctrl+O"));
  actOptionConfig->setToolTip(QString("Конфигурация"));
  actOptionConfig->setStatusTip(QString("Конфигурация"));
  actOptionConfig->setWhatsThis(QString("Конфигурация"));
  actOptionConfig->setIcon(QPixmap("://icon2/Ob01/package_settings.ico"));
  connect(actOptionConfig,  SIGNAL(triggered()),
          this,             SIGNAL(trigOptionConfig()));
  menuOptions->addAction(actOptionConfig);

//
  menuHelp = new QMenu("&Помощь",this);
  addMenu(menuHelp);
  actHelpAbout = new QAction(QString("HelpAbout"),this);
  actHelpAbout->setObjectName(QString("actHelpAbout"));
  actHelpAbout->setText(QString("о"));
  actHelpAbout->setShortcut(QKeySequence("Ctrl+O"));
  actHelpAbout->setToolTip(QString("О"));
  actHelpAbout->setStatusTip(QString("О"));
  actHelpAbout->setWhatsThis(QString("О"));
  actHelpAbout->setIcon(QPixmap("://icons/w2k_help.ico"));
  connect(actHelpAbout, SIGNAL(triggered()),
          this,         SIGNAL(trigHelpAbout()));
  menuHelp->addAction(actHelpAbout);
}

/*
 *  Деструктор
 */
CMenuBar::~CMenuBar()
{

    actFileNew->disconnect();
    delete actFileNew;
    actFileNew = nullptr;
    actFileOpen->disconnect();
    delete actFileOpen;
    actFileOpen = nullptr;
    actFileOpenCurrent->disconnect();
    delete actFileOpenCurrent;
    actFileOpenCurrent = nullptr;
    actFileSaveFragment->disconnect();
    delete actFileSaveFragment;
    actFileSaveFragment = nullptr;
    actFileSaveTAB->disconnect();
    delete actFileSaveTAB;
    actFileSaveTAB = nullptr;
    actFileSaveMGF->disconnect();
    delete actFileSaveMGF;
    actFileSaveMGF = nullptr;
    actFileSaveSample->disconnect();
    delete actFileSaveSample;
    actFileSaveSample = nullptr;
    actFileSaveProtocol->disconnect();
    delete actFileSaveProtocol;
    actFileSaveProtocol = nullptr;
    actFileSaveColor->disconnect();
    delete actFileSaveColor;
    actFileSaveColor = nullptr;
    actFileClose->disconnect();
    delete actFileClose;
    actFileClose = nullptr;
    actFileExit->disconnect();
    delete actFileExit;
    actFileExit = nullptr;

    menuFile->disconnect();
    delete menuFile;
    menuFile = nullptr;
//
    delete menuEdit;
//
    delete menuView;

//
    delete menuOptions;
//
    delete menuWindow;
//
    delete menuHelp;
}
