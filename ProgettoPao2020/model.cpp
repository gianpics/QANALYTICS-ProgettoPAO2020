#include "model.h"

model::model()
{

}

void model::setSelected(u_int _SSN)
{
    selected = &list[_SSN];
}

QLineSeries *model::graphFollowers(u_int _id_account) const
{
    QLineSeries * series = new QLineSeries();
}
