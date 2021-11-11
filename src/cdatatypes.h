#ifndef CDATATYPES_H
#define CDATATYPES_H
#include <QMetaType>
#include <QList>
#include <QString>
#include <QHash>
#include <QDateTime>
#include <QVariant>

//  Структура общих настроек
typedef struct TMSettings		        // настройки
{
    int					id;				// идентификатор терминала
    int                 mode;           // режим работы (0 - тест, 1 - работа, 2 - отладка)
} TTMSettings;
Q_DECLARE_METATYPE(TTMSettings);
Q_DECLARE_METATYPE(TTMSettings*);

#endif // CDATATYPES_H
