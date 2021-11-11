#ifndef CTOOLBAR_H
#define CTOOLBAR_H

#include <QWidget>
#include <QToolBar>
#include <QComboBox>
#include <QSize>

class CToolBar : public QToolBar
{
  Q_OBJECT

public:
    explicit CToolBar(QWidget *parent = nullptr);
            ~CToolBar();
signals:
    void  trigFileOpen        (void);
    void  trigFileOpenCurrent (void);
    void  trigSelectParam     (void);
    void  trigPrint           (void);
    void  trigCopy            (void);
    void  trigZoomIn          (void);
    void  trigZoomOut         (void);
    void  trigZoomAuto        (void);
    void  trigViewGrid        (void);
    void  trigViewTable       (void);
    void  trigCalc            (void);
    void  trigZeroAxis        (void);
    void  trigMathStat        (void);

private:
    QAction     *actFileOpen;
    QAction     *actFileOpenCurrent;
    QAction     *actSelectParam;
    QAction     *actPrint;
    QAction     *actCopy;
    QAction     *actViewGrid;
    QAction     *actViewTable;
    QComboBox   *cmbDimension;
    QAction     *actZoomIn;
    QAction     *actZoomOut;
    QAction     *actZoomAuto;
    QAction     *actCalc;
    QAction     *actZeroAxis;
    QAction     *actMathStat;
};

#endif // CTOOLBAR_H
