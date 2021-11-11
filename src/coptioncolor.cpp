#include "coptioncolor.h"

/*
 *  Конструктор
 */
COptionColor::COptionColor(TTMUserColor *tm_usercolor,
                           QWidget      *parent) :
    QDialog(parent),
    rectForm(QRect(0,0,200,200))
{
    tmUserColor = tm_usercolor;
////  Установка параметров окна
    setObjectName(QString("COptionColor"));
    setAccessibleName(QString("COptionColor"));
    setWindowTitle(QString("Настройка палитры"));
    setAttribute(Qt::WA_DeleteOnClose);
    setGeometry(rectForm);

//  Инициализация
    formLayout = nullptr;
    cmbBackground = nullptr;
    cmbBorder = nullptr;
    cmbGrid = nullptr;
    cmbRuler = nullptr;
    cmbRay = nullptr;

//
    formLayout = new QFormLayout(this);
    formLayout->setContentsMargins(10, 10, 10, 10);
    formLayout->setSpacing(10);

    QStringList colorNames;
    colorNames <<"black"<<"white"<<"darkGray"<<"gray"<<"lightGray"<<"red"<<"green"<<"blue"<<"cyan"<<"magenta"<<"yellow"<<"darkRed"<<"darkGreen"<<"darkBlue"<<"darkCyan"<<"darkMagenta"<<"darkYellow";

    cmbBackground = new QComboBox(this);
    cmbBackground->setFixedWidth(40);

    int size = cmbBackground->style()->pixelMetric(QStyle::PM_SmallIconSize);
    QPixmap pixmap(size, size);
    int cont=0;
    foreach (QString name, colorNames)
    {
        cmbBackground->addItem("1", QColor(cont));
        cmbBackground->setItemData(cont, QColor(name), Qt::DecorationRole);
        pixmap.fill(QColor(name));
        cmbBackground->setItemData(cont, pixmap, Qt::DecorationRole);
        cont=cont+1;
    }
    formLayout->addRow(QString("Цвет фона"), cmbBackground);
//
    cmbBorder = new QComboBox(this);
    formLayout->addRow(QString("Цвет границы"), cmbBorder);
    cmbGrid = new QComboBox(this);
    formLayout->addRow(QString("Цвет сетки"), cmbGrid);
    cmbRuler = new QComboBox(this);
    formLayout->addRow(QString("Цвет шкалы"), cmbRuler);
    cmbRay = new QComboBox(this);
    formLayout->addRow(QString("Цвет луча"), cmbRay);
    cmbLegend = new QComboBox(this);
    formLayout->addRow(QString("Цвет легенды"), cmbLegend);
    cmbLegendBorder = new QComboBox(this);
    formLayout->addRow(QString("Цвет границы легенды"), cmbLegendBorder);
    setLayout(formLayout);
}

/*
 *
 *  Деструктор
 */
COptionColor::~COptionColor()
{
  delete formLayout;

}
