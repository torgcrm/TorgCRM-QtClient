#ifndef TASK_H
#define TASK_H

#include <QString>
#include <QDateTime>

#include "genericmodel.h"

#define JSON_TASK_BEGINDATE   "beginDate"
#define JSON_TASK_COMMENT     "comment"
#define JSON_TASK_ENDDATE     "endDate"
#define JSON_TASK_ID          "id"
#define JSON_TASK_MANAGER     "managerId"
#define JSON_TASK_TITLE       "title"
#define JSON_TASK_TYPE        "type"

namespace CRMModels {
    class Task : public GenericModel
    {
    public:
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

        int getManagerId() const;
        void setManagerId(int value);

    private:
        QString title;
        QDateTime beginDate;
        QDateTime endDate;
        QString comment;
        QString type;
        int managerId;
    };
}

#endif // TASK_H
