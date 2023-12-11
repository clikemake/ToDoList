#include "customitemdelegate.h"
#include <QPainter>

CustomItemDelegate::CustomItemDelegate(QObject *parent) : QStyledItemDelegate(parent){}

void CustomItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(option.state &QStyle::State_Selected){
        painter->fillRect(option.rect, option.palette.highlight());
    }

    QString taskName = index.data(Qt::DisplayRole).toString();
    QString taskDisc = index.data(Qt::UserRole + 1).toString();
    QString dateStart = index.data(Qt::UserRole + 2).toString();
    QString dateEnd = index.data(Qt::UserRole + 3).toString();

    QString displayText = QString("%1\nОписание:\n%2\nДата начала:%3\nДата окончания:%4")
                              .arg(taskName,taskDisc,dateStart,dateEnd);
    painter->drawText(option.rect, Qt::AlignCenter, displayText);
}
