#ifndef HAND_H
#define HAND_H
#include <QSet>
#include "card.h"
class Hand
{
public:
    Hand();

    QVector<Card>hand;

    void setCards(QVector<Card>);
};

#endif // HAND_H
