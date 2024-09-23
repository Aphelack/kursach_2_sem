#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Menu)
{
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_startGame_clicked()
{
    InfoWidget* rulls = InfoWidget::getInstance(nullptr, "../kursach/rulls_Rus.txt");
    rulls->hide();
    PlayArena* playArena = new PlayArena;
    playArena->showMaximized();
    this->hide();
}


void Menu::on_OpenSettings_clicked()
{
    Settings* settings = new Settings;
    settings->show();
    this->hide();
}


void Menu::on_getRulls_clicked()
{
    InfoWidget* rulls = InfoWidget::getInstance(nullptr, "../kursach/rulls_Rus.txt");
    rulls->show();
}

