#ifndef PLAYER_H
#define PLAYER_H
#include "hand.h"
#include <QHBoxLayout>
class Player
{
public:
    Player(int);

    QVector<Card>hand;

    int handSize = 6;

    int num;

    bool inGame;

    QHBoxLayout* handWidget;

    bool isActive = true;

    bool isBot;
};

#endif // PLAYER_H
