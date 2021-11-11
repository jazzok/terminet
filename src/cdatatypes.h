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

typedef struct TMConfig
{
    int		auto_select;
    int		auto_load_list;
    int		auto_load_set;
    int		auto_sign;
    int		auto_switch_digital;
    int     digital_default;
    int     search_update;
    int     show_maximized;
    int     prompt_quit;
} TTMConfig;
Q_DECLARE_METATYPE(TTMConfig);
Q_DECLARE_METATYPE(TTMConfig*);


typedef struct TMUserColor
{
    int			color_scheme;
    int			user_background;
    int			user_legend;
    int			user_border_graph;
    int			user_border_legend;
    int			user_grid;
} TTMUserColor;
Q_DECLARE_METATYPE(TTMUserColor);
Q_DECLARE_METATYPE(TTMUserColor*);

#endif // CDATATYPES_H
