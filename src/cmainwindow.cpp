#include "cmainwindow.h"

/*
 *
 */
CMainWindow::CMainWindow(QWidget *parent) : QWidget(parent)
{
// Локальные переменные
// Программа
// Установка названия приложения
    QApplication::setApplicationName("TermiNet");

// Определение каталога с файлами программы
    QDir dir(QApplication::applicationDirPath());

// Проверка наличия ini файла с настройками
    if (!QFile::exists("conf.ini"))
    {
        QMessageBox::critical(nullptr,
                              "Ошибка!",
                              "Отсутствует файл с настройками conf.ini",
                              QMessageBox::Ok);
    //        exit(1);
    }

// Получение настроек терминала
    if (!getSettings())
    {
        QMessageBox::critical(nullptr,  "Ошибка запуска приложения",
                                        "Ошибка чтения настроек приложения.",
                                        QMessageBox::Ok);
//        exit(2);
    }
#ifdef QT_DEBUG
// Вывод считанных параметров в терминал
    qDebug() << "Параметры работы программы";
    qDebug() << "-> идентификатор: " << tmSettings.id;
    qDebug() << "-> режим работы: " << tmSettings.mode;
#endif

//  Установка разрешения экрана из настроек приложения
//    setFixedSize(QSize(640,480));

// Создание временного каталога в системном Temp
    tmpPath = QString("%1/%2").arg(QDir::tempPath())
                              .arg(QApplication::applicationName());
    dir.mkdir(tmpPath);



}

/*
 *
 */
CMainWindow::~CMainWindow()
{

// Удаление временного каталога из системного Temp
    QDir dir(tmpPath);
    QStringList dirFileList = dir.entryList(QDir::Files);

// Удаление всех файлов из каталога
    while (dirFileList.count())
    {
        QFile file(dir.filePath(dirFileList.last()));
        file.close();
        if (file.remove())
            dirFileList.removeLast();
    }

// Удаление каталога
    dir.rmdir(tmpPath);
}

/*
 *	Фильтр событий
 */
bool CMainWindow::eventFilter(QObject *obj, QEvent *e)
{
    Q_UNUSED(obj);
    if ((e->type() == QEvent::KeyPress) ||
        (e->type() == QEvent::MouseMove) ||
        (e->type() == QEvent::MouseButtonPress) ||
        (e->type() == QEvent::MouseButtonRelease))
    {

    }

//    return QFrame::eventFilter(object, event);
    return true;
}

/*
 *	Получение настроек терминала
 */
bool CMainWindow::getSettings (void)
{
// Определение каталога с файлами программы
    QDir dir(QApplication::applicationDirPath());

// Подключение к ini файлу для получения настроек подключения
//  android
//    QSettings settings(":/agrotrack.ini", QSettings::IniFormat);
//  mac
    QSettings settings(dir.absoluteFilePath("conf.ini"), QSettings::IniFormat);
// Получение настроек терминала
    settings.beginGroup("Main");
    tmSettings.id = settings.value("id", 0).toInt();
    tmSettings.mode = settings.value("region", 0).toInt();
    settings.endGroup();

//  Установка стиля по умолчанию
//    setAppStyle();
    return true;
}


/*
 *  Сохранение настроек
 */
bool CMainWindow::saveSettings(void)
{
#ifndef QT_DEBUG
//  Счетчик количества успешных завершения
//    tmSettings.paramProg.succesrun++;
#endif

//  Определение каталога с файлами программы
    QDir dir(QApplication::applicationDirPath());

//  Подключение к ini файлу для получения настроек подключения
//    QSettings settings(":/agrotrack.ini", QSettings::IniFormat);
    QSettings settings(dir.absoluteFilePath("conf.ini"), QSettings::IniFormat);

//  Сохранение настроек
    settings.beginGroup("Main");
    settings.setValue("id", tmSettings.id);
    settings.setValue("mode", tmSettings.mode);
    settings.endGroup();

#ifdef QT_DEBUG
    qDebug() << "Настройки сохранены";
    qDebug() << "[Main]";
    qDebug() << "id = " << tmSettings.id;
    qDebug() << "mode = " << tmSettings.mode;
#endif
//
    return true;
}

/*
 *	Установка стиля приложения
 */
void CMainWindow::setAppStyle (void)
{
// Стиль по умолчанию
    pathStyle = "://style.css";
/*
// Проверка существования стиля
    if (QFile::exists(pathStyle))
    {
        #ifdef QT_DEBUG
        qDebug() << "Установка стиля приложения: " << tmSettings.display.theme_style;
        #endif
    }
    else
    {
        qDebug() << "Стиль приложения по пути "
                 << pathStyle
                 << "не обнаружен";
    }
*/
// Подключение файла стиля
    QFile* file = new QFile(pathStyle);
    if (file->open(QFile::ReadOnly))
    {
        QString styleSheet = QLatin1String(file->readAll());
        QApplication* app = qobject_cast<QApplication*>(parent());
        app->setStyleSheet(styleSheet);
    }
    file->close();
    delete file;
}


/*
 *   Обработка закрытия формы и сохранение настроек
 */
void CMainWindow::closeEvent(QCloseEvent *e)
{
    if (saveSettings()==true)
    {
        qDebug() << "Appllcation exit";
        e->accept();
    }
    else
        e->ignore();
}
