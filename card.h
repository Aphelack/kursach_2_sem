#ifndef CARD_H
#define CARD_H
#include "cardEnums.h"
#include <QPixmap>
#include <QRect>
class Card
{
public:
    Card();

    Card(int, int);

    Card(Suit, Value, QPixmap*);

    Suit suit;

    Value value;

    QPixmap pict;

    bool visible = true;

    void setVisible(bool);

    constexpr static QRect cardSize = QRect(0, 0, 106, 152);

};

#endif // CARD_H
