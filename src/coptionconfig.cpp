#include "coptionconfig.h"

/*
 *  Конструктор
 */
COptionConfig::COptionConfig(TTMConfig      *tm_config,
                             TTMUserColor   *tm_usercolor,
                             QWidget        *parent) :
    QDialog(parent),
    rectForm(QRect(0,0,200,200))
{
    tmConfig = tm_config;
    tmUserColor = tm_usercolor;
//
    setObjectName(QString("COptionConfig"));
    setWindowTitle(QString("Конфигурация"));
    setAttribute(Qt::WA_DeleteOnClose);
//  setGeometry(rectForm);
    resize(rectForm.size());
    setWindowModality(Qt::ApplicationModal);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    vMainBoxLayout = new QVBoxLayout(this);
    vMainBoxLayout->setContentsMargins(10, 10, 10, 10);
    vMainBoxLayout->setSpacing(10);

    chkAutoSelect = new QCheckBox(
                QString("Автовыбор"),this);
    if (tmConfig->auto_select)
        chkAutoSelect->setCheckState(Qt::Checked);
    vMainBoxLayout->addWidget(chkAutoSelect);

    chkAutoLoadList = new QCheckBox(
                QString("Автозагрузка списка в новое окно"), this);
    if (tmConfig->auto_select)
        chkAutoLoadList->setCheckState(Qt::Checked);
    vMainBoxLayout->addWidget(chkAutoLoadList);

    chkAutoLoadSet = new QCheckBox(
                QString("Автозагрузка текущего набора в новое окно"), this);
    if (tmConfig->auto_load_set)
        chkAutoLoadSet->setCheckState(Qt::Checked);
    vMainBoxLayout->addWidget(chkAutoLoadSet);

    chkAutoSwitchDigital = new QCheckBox(
                QString("Автоматически переключать релейные сигналы"), this);
    if (tmConfig->auto_load_set)
        chkAutoLoadSet->setCheckState(Qt::Checked);
    vMainBoxLayout->addWidget(chkAutoSwitchDigital);

    chkPromptQuit = new QCheckBox(
                QString("Подтверждение выхода из программы"), this);
    if (tmConfig->prompt_quit)
        chkPromptQuit->setCheckState(Qt::Checked);
    vMainBoxLayout->addWidget(chkPromptQuit);

    chkShowMaximized = new QCheckBox(
                QString("Максимальное графическое окно"), this);
    if (tmConfig->show_maximized)
        chkShowMaximized->setCheckState(Qt::Checked);
    vMainBoxLayout->addWidget(chkShowMaximized);

    chkDigitalDefault = new QCheckBox(
                QString("Использовать по умолчанию дискретный вид графиков"),
                this);
    if (tmConfig->digital_default)
        chkDigitalDefault->setCheckState(Qt::Checked);
    vMainBoxLayout->addWidget(chkDigitalDefault);

    chkSearchUpdate = new QCheckBox(
                QString("Поиск обновлений"),
                this);
    if (tmConfig->search_update)
        chkSearchUpdate->setCheckState(Qt::Checked);
    vMainBoxLayout->addWidget(chkSearchUpdate);

    chkShowLegend = new QCheckBox(
                QString("Отображать легенду на графике"),this);
    vMainBoxLayout->addWidget(chkShowLegend);

    groupBoxColor = new QGroupBox();
    groupBoxColor->setTitle(QString("Цветовая схема"));
    gGroupBoxLayout = new QGridLayout();
    gGroupBoxLayout->setContentsMargins(10, 10, 10, 10);
    gGroupBoxLayout->setSpacing(10);
    groupBoxColor->setLayout(gGroupBoxLayout);
    rbtnClassic = new QRadioButton(this);
    rbtnClassic->setText(QString("Классика"));
    gGroupBoxLayout->addWidget(rbtnClassic);
    rbtnContrast = new QRadioButton(this);
    rbtnContrast->setText(QString("Контраст"));
    gGroupBoxLayout->addWidget(rbtnContrast);
    rbtnUser = new QRadioButton(this);
    rbtnUser->setText(QString("Пользовательская"));
    gGroupBoxLayout->addWidget(rbtnUser);
    btnCustom = new QPushButton(this);
    btnCustom->setText(QString("Настройка"));
    connect(btnCustom,  SIGNAL(clicked()),
            SLOT(openConfigColor()));
    gGroupBoxLayout->addWidget(btnCustom, 10, 1);
    vMainBoxLayout->addWidget(groupBoxColor, 1);

    switch (tmUserColor->color_scheme)
    {
    case 1:
        rbtnClassic->setChecked(true);
        break;
    case 2:
        rbtnContrast->setChecked(true);
        break;
    case 3:
        rbtnUser->setChecked(true);
        break;
    default:
        rbtnClassic->setChecked(true);
        break;
    }

    hBoxLayout = new QHBoxLayout();
    hBoxLayout->setContentsMargins(10, 10, 10, 10);
    hBoxLayout->setSpacing(10);
    btnAccept = new QPushButton(this);
    btnAccept->setText(QString("Принять"));
    hBoxLayout->addWidget(btnAccept);
    connect(btnAccept, SIGNAL(clicked()),
            this,      SIGNAL(accepted()));
    connect(btnAccept, SIGNAL(clicked()),
            this,      SLOT(close()));
    btnReject = new QPushButton(this);
    btnReject->setText(QString("Отмена"));
    hBoxLayout->addWidget(btnReject);
    connect(btnReject, SIGNAL(clicked()),
            this,      SIGNAL(rejected()));
    connect(btnReject, SIGNAL(clicked()),
            this,      SLOT(close()));
    vMainBoxLayout->addLayout(hBoxLayout, 1);
}

/*
 *  Деструктор
 */
COptionConfig::~COptionConfig()
{
    delete  chkAutoSelect;
    delete  chkAutoLoadList;
    delete  chkAutoLoadSet;
    delete  chkAutoSwitchDigital;
    delete  chkSearchUpdate;
    delete  chkDigitalDefault;
    delete  chkShowLegend;
    delete  chkPromptQuit;
    delete  chkShowMaximized;

    delete rbtnClassic;
    delete rbtnContrast;
    delete rbtnUser;


    delete btnReject;
    delete btnAccept;
    delete hBoxLayout;
    delete groupBoxColor;
}

/*
 *
 */
void COptionConfig::openConfigColor()
{
    optionColor = new COptionColor(tmUserColor, this);
//
    switch (optionColor->exec())
    {
    case QDialog::Accepted: {

    break;
    }
    case QDialog::Rejected: {

    break;
    }
    default:
    break;
    }
}

void COptionConfig::changeConfig()
{

}
