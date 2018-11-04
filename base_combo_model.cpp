#include "base_combo_model.h"
#include <QSqlQuery>

namespace {
    enum Columns {
        Id,
        Data,
    };
}

BaseComboModel::BaseComboModel( const QString& visualColumn, const QString& queryTail, QObject *parent ) : QSqlQueryModel( parent ) {
    QSqlQuery query;
    query.prepare( QString( "SELECT %1.id, %2 FROM %3" ).arg( queryTail.split( ' ' ).first() ).arg( visualColumn ).arg( queryTail ) );
    query.exec();
    QSqlQueryModel::setQuery( query );
}

QVariant BaseComboModel::dataFromParent( QModelIndex index, int column ) const {
    return QSqlQueryModel::data( QSqlQueryModel::index( index.row() - 1, column ) );
}

int BaseComboModel::rowCount(const QModelIndex &parent) const {
    return QSqlQueryModel::rowCount( parent ) + 1;
}

QVariant BaseComboModel::data(const QModelIndex & item, int role) const {
    QVariant result;

    if( item.row() == 0 ) {
        switch( role ) {
            case Qt::UserRole:
                result = 0;
                break;
            case Qt::DisplayRole:
                result = "(please select)";
                break;
            default:
                break;
        }
    } else {
        switch( role ) {
            case Qt::UserRole:
                result = dataFromParent( item, Id );
                break;
            case Qt::DisplayRole:
                result = dataFromParent( item, Data );
                break;
            default:
                break;
        }
    }

    return result;
}
