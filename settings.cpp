#include "settings.h"
#include "ui_settings.h"

Settings::Settings(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Settings)
{
    ui->setupUi(this);
    for (auto language : avaliableLanguages)
        ui->languageBox->addItem(language);

    QFile settings("/home/lidskae/kursach/Settings.txt");
    if (settings.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&settings);
        qDebug() << "file opened";
        QString in;
        in = stream.readLine();
        int playerNum = in.split(" ").value(2).toInt();


        ui->getPlayersNum->setValue(playerNum);
        in = stream.readLine();
        QString lang = in.split(" ").value(2);
        ui->languageBox->setCurrentText(lang);
        settings.close();
    }
}

Settings::~Settings()
{
    delete ui;
}

void Settings::on_canselButton_clicked()
{
    Menu* menu = new Menu;
    menu->show();
    this->hide();
}


void Settings::on_savebutton_clicked()
{
    QFile settings("/home/lidskae/kursach/Settings.txt");
    if (settings.open(QIODevice::ReadWrite | QIODevice::Text)){
        settings.resize(0);
        QTextStream out(&settings);
        qDebug() << "file opened";

        out << "players : " << ui->getPlayersNum->text() << '\n';
        out << "language : " << ui->languageBox->currentText();
        settings.close();
    }
    Menu* menu = new Menu;
    menu->show();
    this->hide();
}


void Settings::on_manageButton_clicked()
{
    PlayersManager* playersManager = new PlayersManager;
    playersManager->show();
}

