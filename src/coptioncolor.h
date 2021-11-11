#ifndef COPTIONCOLOR_H
#define COPTIONCOLOR_H

#include <QDialog>
#include <QFormLayout>
#include <QRect>
#include <QComboBox>

#include "cdatatypes.h"

class COptionColor : public QDialog
{
  Q_OBJECT

public:
    explicit COptionColor(TTMUserColor  *tm_usercolor,
                          QWidget       *parent = nullptr);
            ~COptionColor();

private:
    TTMUserColor    *tmUserColor;

    QRect           rectForm;
    QFormLayout     *formLayout;

    QComboBox   *cmbBackground;
    QComboBox   *cmbBorder;
    QComboBox   *cmbLegend;
    QComboBox   *cmbLegendBorder;
    QComboBox   *cmbGrid;
    QComboBox   *cmbRuler;
    QComboBox   *cmbRay;
};

#endif // COPTIONCOLOR_H
