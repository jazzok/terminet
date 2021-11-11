#include "ctoolbar.h"

/*
 *  Конструктор
 */
CToolBar::CToolBar(QWidget *parent) : QToolBar(parent)
{
//  Установка параметров окна
    setMovable(false);
    setIconSize(QSize(24,24));
    setFixedHeight(28);
    setOrientation(Qt::Horizontal);
    setToolButtonStyle(Qt::ToolButtonIconOnly);
    setFloatable(false);

    actFileOpen = new QAction(QString("actFileOpen"),this);
    actFileOpen->setShortcut(QKeySequence("Ctrl+O"));
    actFileOpen->setToolTip(QString("Открыть"));
    actFileOpen->setStatusTip(QString("Открыть"));
    actFileOpen->setWhatsThis(QString("Открыть"));
    actFileOpen->setIcon(QPixmap("://icons/wxp_1.ico"));
    connect(actFileOpen,  SIGNAL(triggered()),
            this,         SIGNAL(trigFileOpen()));
    addAction(actFileOpen);

    actFileOpenCurrent = new QAction(QString("actFileOpenCurrent"),this);
    actFileOpenCurrent->setShortcut(QKeySequence("Ctrl+O"));
    actFileOpenCurrent->setToolTip(QString("Открыть в том же окне"));
    actFileOpenCurrent->setStatusTip(QString("Открыть в том же окне"));
    actFileOpenCurrent->setWhatsThis(QString("Открыть в том же окне"));
    actFileOpenCurrent->setIcon(QPixmap("://icons/wxp_1.ico"));
    connect(actFileOpenCurrent, SIGNAL(triggered()),
            this,               SIGNAL(trigFileOpenCurrent()));
    addAction(actFileOpenCurrent);

    actSelectParam = new QAction(QString("actSelectParam"),this);
    actSelectParam->setShortcut(QKeySequence("Ctrl+O"));
    actSelectParam->setToolTip(QString("Выбор параметров"));
    actSelectParam->setStatusTip(QString("Выбор параметров"));
    actSelectParam->setWhatsThis(QString("Выбор параметров"));
    actSelectParam->setIcon(QPixmap("://icons/w98_directory_control_panel.ico"));
    connect(actSelectParam,  SIGNAL(triggered()),
            this,         SIGNAL(trigSelectParam()));
    addAction(actSelectParam);

    actPrint = new QAction(QString("actPrint"),this);
    actPrint->setText(QString("Печать"));
    actPrint->setShortcut(QKeySequence("Ctrl+P"));
    actPrint->setToolTip(QString("Печать"));
    actPrint->setStatusTip(QString("Печать"));
    actPrint->setWhatsThis(QString("Печать"));
    actPrint->setIcon(QPixmap("://icons/wxp_168.ico"));
    connect(actPrint,  SIGNAL(triggered()),
            this,         SIGNAL(trigPrint()));
    addAction(actPrint);

    actCopy = new QAction(QString("actCopy"),this);
    actCopy->setText(QString("Копировать"));
    actCopy->setShortcut(QKeySequence("Ctrl+C"));
    actCopy->setToolTip(QString("Копировать"));
    actCopy->setStatusTip(QString("Копировать"));
    actCopy->setWhatsThis(QString("Копировать"));
    actCopy->setIcon(QPixmap("://icons/wxp_1.ico"));
    connect(actCopy,  SIGNAL(triggered()),
            this,     SIGNAL(trigCopy()));
    addAction(actCopy);

    cmbDimension = new QComboBox(this);
    QStringList stringList = QStringList(QString("Исх. размерность"));
    cmbDimension->addItems(stringList);
    addWidget(cmbDimension);


    actViewGrid = new QAction(QString("actViewGrid"),this);
    actViewGrid->setShortcut(QKeySequence("Ctrl+O"));
    actViewGrid->setToolTip(QString("Координатная сетка"));
    actViewGrid->setStatusTip(QString("Координатная сетка"));
    actViewGrid->setWhatsThis(QString("Координатная сетка"));
    actViewGrid->setIcon(QPixmap("://icons/wxp_1.ico"));
    connect(actViewGrid,  SIGNAL(triggered()),
            this,         SIGNAL(trigViewGrid()));
    addAction(actViewGrid);

    actViewTable = new QAction(QString("actViewTable"),this);
    actViewTable->setShortcut(QKeySequence("Ctrl+O"));
    actViewTable->setToolTip(QString("Таблица значений"));
    actViewTable->setStatusTip(QString("Таблица значений"));
    actViewTable->setWhatsThis(QString("Таблица значений"));
    actViewTable->setIcon(QPixmap("://icons/wxp_1.ico"));
    connect(actViewTable,  SIGNAL(triggered()),
            this,         SIGNAL(trigViewTable()));
    addAction(actViewGrid);

    addSeparator();
    actZoomOut = new QAction(this);
  //  actZoomOut->setShortcut(QKeySequence("Ctrl+O"));
    actZoomOut->setToolTip(QString("Уменьшить"));
    actZoomOut->setStatusTip(QString("Уменьшить"));
    actZoomOut->setWhatsThis(QString("Уменьшить"));
    actZoomOut->setIcon(QPixmap("://icons/wxp_23.ico"));
    connect(actZoomOut, SIGNAL(triggered()),
            this,       SIGNAL(trigZoomOut()));
    addAction(actZoomOut);
    actZoomAuto = new QAction(this);
  //  actZoomAuto->setShortcut(QKeySequence("Ctrl+O"));
    actZoomAuto->setToolTip(QString("Автомасштаб"));
    actZoomAuto->setStatusTip(QString("Автомасштаб"));
    actZoomAuto->setWhatsThis(QString("Автомасштаб"));
    actZoomAuto->setIcon(QPixmap("://icons/wxp_23.ico"));
    connect(actZoomAuto,  SIGNAL(triggered()),
            this,         SIGNAL(trigZoomAuto()));
    addAction(actZoomAuto);
    actZoomIn = new QAction(this);
  //  actZoomIn->setShortcut(QKeySequence("Ctrl+O"));
    actZoomIn->setToolTip(QString("Увеличить"));
    actZoomIn->setStatusTip(QString("Увеличить"));
    actZoomIn->setWhatsThis(QString("Увеличить"));
    actZoomIn->setIcon(QPixmap("://icons/wxp_23.ico"));
    connect(actZoomIn,  SIGNAL(triggered()),
            this,       SIGNAL(trigZoomIn()));
    addAction(actZoomIn);
    addSeparator();

    actCalc = new QAction(QString("actCalc"),this);
    actCalc->setText(QString("Калькулятор"));
    actCalc->setShortcut(QKeySequence("Ctrl+O"));
    actCalc->setToolTip(QString("Калькулятор"));
    actCalc->setStatusTip(QString("Калькулятор"));
    actCalc->setWhatsThis(QString("Калькулятор"));
    actCalc->setIcon(QPixmap("://icons/w98_calculator.ico"));
    connect(actCalc,  SIGNAL(triggered()),
            this,         SIGNAL(trigCalc()));
    addAction(actCalc);

    actZeroAxis = new QAction(QString("actZeroAxis"),this);
    //actZeroAxis->setText(QString("о"));
    actZeroAxis->setShortcut(QKeySequence("Ctrl+O"));
    actZeroAxis->setToolTip(QString("Нулевая ось"));
    actZeroAxis->setStatusTip(QString("Нулевая ось"));
    actZeroAxis->setWhatsThis(QString("Нулевая ось"));
    actZeroAxis->setIcon(QPixmap("://icons/wxp_1.ico"));
    connect(actZeroAxis,  SIGNAL(triggered()),
            this,         SIGNAL(trigZeroAxis()));
    addAction(actZeroAxis);

    actMathStat = new QAction(QString("actMathStat"),this);
  //  actMathStat->setText(QString("о"));
  //  actMathStat->setShortcut(QKeySequence("Ctrl+O"));
    actMathStat->setToolTip(QString("Математическая статистика"));
    actMathStat->setStatusTip(QString("Математическая статистика"));
    actMathStat->setWhatsThis(QString("Математическая статистика"));
    actMathStat->setIcon(QPixmap(":/icon2/Ob01/kformula.ico"));
    connect(actMathStat,  SIGNAL(triggered()),
            this,         SIGNAL(trigMathStat()));
    addAction(actMathStat);
}

/*
 *  Деструктор
 */
CToolBar::~CToolBar()
{
    delete cmbDimension;
}
