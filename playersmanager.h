#ifndef PLAYERSMANAGER_H
#define PLAYERSMANAGER_H

#include <QMainWindow>
#include <QFile>
#include "settings.h"
namespace Ui {
class PlayersManager;
}

class PlayersManager : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlayersManager(QWidget *parent = nullptr);
    ~PlayersManager();

private slots:
    void on_acceptButton_clicked();

    void on_Player_1_clicked();

    void on_Player_2_clicked();

    void on_Player_3_clicked();

    void on_Player_4_clicked();

    void on_Player_5_clicked();

    void on_Player_6_clicked();

private:
    Ui::PlayersManager *ui;

    void Filling();

    bool isBot1 = false;
    bool isBot2 = false;
    bool isBot3 = false;
    bool isBot4 = false;
    bool isBot5 = false;
    bool isBot6 = false;
};

#endif // PLAYERSMANAGER_H
