#ifndef DECK_H
#define DECK_H
#include <QVector>
#include <card.h>
class Deck
{
public:
    Deck();

    Card deck[52];
};

#endif // DECK_H
