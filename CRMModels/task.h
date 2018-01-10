#ifndef TASK_H
#define TASK_H

#include <QString>
#include <QDateTime>

#include "genericmodel.h"

namespace CModels {
    class Task : public GenericModel
    {
    public:
        Task();
        QString getTitle() const;
        void setTitle(const QString &value);

        QDateTime getBeginDate() const;
        void setBeginDate(const QDateTime &value);

        QDateTime getEndDate() const;
        void setEndDate(const QDateTime &value);

        QString getComment() const;
        void setComment(const QString &value);

        QString getType() const;
        void setType(const QString &value);

    private:
        QString title;
        QDateTime beginDate;
        QDateTime endDate;
        QString comment;
        QString type;
    };
}

#endif // TASK_H
