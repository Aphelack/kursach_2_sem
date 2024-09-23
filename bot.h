#ifndef BOT_H
#define BOT_H
#include "combination.h"
#include <random>
class Bot
{
public:
    Bot();

    static Combination* algorithm(QVector<Combination*>, int, QVector<Card>, int);

    static Combination *maxComb(QVector<Card> pull, bool nonFlush = false);


};

#endif // BOT_H
