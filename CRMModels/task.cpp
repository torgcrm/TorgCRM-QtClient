#include "task.h"

using namespace CRMModels;

QString Task::getTitle() const
{
    return title;
}

void Task::setTitle(const QString &value)
{
    title = value;
}

QDateTime Task::getBeginDate() const
{
    return beginDate;
}

void Task::setBeginDate(const QDateTime &value)
{
    beginDate = value;
}

QDateTime Task::getEndDate() const
{
    return endDate;
}

void Task::setEndDate(const QDateTime &value)
{
    endDate = value;
}

QString Task::getComment() const
{
    return comment;
}

void Task::setComment(const QString &value)
{
    comment = value;
}

QString Task::getType() const
{
    return type;
}

void Task::setType(const QString &value)
{
    type = value;
}

int Task::getManagerId() const
{
    return managerId;
}

void Task::setManagerId(int value)
{
    managerId = value;
}
