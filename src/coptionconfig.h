#ifndef COPTIONCONFIG_H
#define COPTIONCONFIG_H

#include <QDialog>
#include <QFormLayout>
#include <QCheckBox>
#include <QGroupBox>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QPushButton>

#include "cdatatypes.h"
#include "coptioncolor.h"

class COptionConfig : public QDialog
{
  Q_OBJECT

public:
  explicit COptionConfig(TTMConfig      *tm_config,
                         TTMUserColor   *tm_usercolor,
                         QWidget        *parent = nullptr);
          ~COptionConfig();

private:
    TTMConfig       *tmConfig;
    TTMUserColor    *tmUserColor;
    QRect           rectForm;
    QVBoxLayout     *vMainBoxLayout;
//
    QCheckBox       *chkAutoSelect;
    QCheckBox       *chkAutoLoadList;
    QCheckBox       *chkAutoLoadSet;
    QCheckBox       *chkAutoSwitchDigital;
    QCheckBox       *chkSearchUpdate;
    QCheckBox       *chkDigitalDefault;
    QCheckBox       *chkShowLegend;
    QCheckBox       *chkPromptQuit;
    QCheckBox       *chkShowMaximized;
//
    QGroupBox       *groupBoxColor;
    QGridLayout     *gGroupBoxLayout;
    QRadioButton    *rbtnClassic;
    QRadioButton    *rbtnContrast;
    QRadioButton    *rbtnUser;
    QPushButton     *btnCustom;
//
    COptionColor    *optionColor;
//
    QHBoxLayout     *hBoxLayout;
    QPushButton     *btnAccept;
    QPushButton     *btnReject;

private slots:
    void    openConfigColor (void);
    void    changeConfig    (void);
};

#endif // COPTIONCONFIG_H
