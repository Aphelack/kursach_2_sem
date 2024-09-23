#ifndef PLAYARENA_H
#define PLAYARENA_H

#include <QMainWindow>
#include <deck.h>
#include <cardgraphics.h>
#include <player.h>
#include <set>
#include <QFile>
#include <random>
#include <QHBoxLayout>
#include <unistd.h>
#include <combination.h>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>
#include <QVector2D>
#include "menu.h"
#include "bot.h"
#include "namings.h"
#include "carddealer.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class PlayArena;
}
QT_END_NAMESPACE

class PlayArena : public QMainWindow
{
    Q_OBJECT

public:
    PlayArena(QWidget *parent = nullptr);
    ~PlayArena();

private slots:
    void on_startRound_clicked();


    void on_passButton_clicked();

    void setActivePlayer(int i);

    void on_showButton_clicked();

    void on_hideButton_clicked();

    void on_hideAllButton_clicked();

    void on_pushButton_clicked();

    void on_helpButton_clicked();

    void on_acceptButton_clicked();

private:
    Ui::PlayArena *ui;

    void setPlayers();

    void setButtons();

    void setSettings();

    void setNamings();

    QString manager[6];

    void drawCard(QHBoxLayout* widget, Card);

    int playerNum;

    QVector<Player*>players;

    std::set<int> generateCards(int count);

    void Dealling();

    QVector<CardGraphics*>used;

    Deck myDeck;

    Combination* Turn();

    QVector<Combination*>history;

    QLabel* indecators[6];

    Combination* lastTurn;

    std::random_device rd;

    QVector<Card>pull;

    int cardsInGame;

    Player *activePlayer();

    Player* nextPlayer(int);

    Player* previousPlayer(int);

    void endGame();

    int maxPlayers;

    QString languagePackagePath;

    void Lose(Player*);

    Combination* previousTurn = nullptr;

    QStringList accessedCombinations;

    QStringList accessedValues;

    QStringList accessedSuits;

    bool pass = false;

    Player* firstMove;

    void showHands();

    void hideHands();

    void hideAllhands();

    void reDrawHands();

    void dealCardsAnimation(QWidget*, QWidget*);

    QMap<int, QSet<int>> Seats = {{2, {0, 3}},
                                  {3, {0, 2, 4}},
                                  {4, {0, 1, 3, 4}},
                                  {5, {0, 1, 2, 4, 5}},
                                  {6, {0, 1, 2, 3, 4, 5}}
    };
};
#endif // PLAYARENA_H
