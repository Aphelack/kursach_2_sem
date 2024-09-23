#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include "playarena.h"
#include "settings.h"
#include "infowidget.h"
namespace Ui {
class Menu;
}

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:
    void on_startGame_clicked();

    void on_OpenSettings_clicked();

    void on_getRulls_clicked();

private:
    Ui::Menu *ui;
};

#endif // MENU_H
