#ifndef COMBINATION_H
#define COMBINATION_H

#include <QSet>
#include <QMap>
#include "card.h"
class Combination
{
public:


    Combination(int, int, int, int);

    static QVector<Card> lastCombination;

    Comb comb;

    Value value1;

    Value value2;

    Suit suit;

    bool find(QVector<Card>*);

    bool isBigger(Combination*);

    bool isCorrect();
};

#endif // COMBINATION_H
