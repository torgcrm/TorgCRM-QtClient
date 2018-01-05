#ifndef GENERICMODEL_H
#define GENERICMODEL_H

namespace CModels {
class GenericModel;
}

class GenericModel {
public:
    int getId() const;
    void setId(int value);

private:
    int id;
};

#endif // GENERICMODEL_H

int GenericModel::getId() const
{
    return id;
}

void GenericModel::setId(int value)
{
    id = value;
}
