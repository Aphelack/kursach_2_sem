#include "playersmanager.h"
#include "ui_playersmanager.h"

PlayersManager::PlayersManager(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PlayersManager)
{
    ui->setupUi(this);
    ui->playerLabel->setStyleSheet("QLabel { background-color: green; color: black; }");
    ui->botLabel->setStyleSheet("QLabel { background-color: red; color: black; }");
    Filling();
}

PlayersManager::~PlayersManager()
{
    delete ui;
}

void PlayersManager::Filling()
{
    QFile file("/home/lidskae/kursach/seats.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&file);
        qDebug() << "file opened";
        QString color;
        color = stream.readLine().split(" ").at(2);
        ui->Player_1->setStyleSheet("QPushButton{background-color:" + color + "}");
        if (color == "red") isBot1 = true;

        color = stream.readLine().split(" ").at(2);
        ui->Player_2->setStyleSheet("QPushButton{background-color:" + color + "}");
        if (color == "red") isBot2 = true;

        color = stream.readLine().split(" ").at(2);
        ui->Player_3->setStyleSheet("QPushButton{background-color:" + color + "}");
        if (color == "red") isBot3 = true;

        color = stream.readLine().split(" ").at(2);
        ui->Player_4->setStyleSheet("QPushButton{background-color:" + color + "}");
        if (color == "red") isBot4 = true;

        color = stream.readLine().split(" ").at(2);
        ui->Player_5->setStyleSheet("QPushButton{background-color:" + color + "}");
        if (color == "red") isBot5 = true;

        color = stream.readLine().split(" ").at(2);
        ui->Player_6->setStyleSheet("QPushButton{background-color:" + color + "}");
        if (color == "red") isBot6 = true;

        file.close();
    }
}

void PlayersManager::on_acceptButton_clicked()
{
    QFile file("/home/lidskae/kursach/seats.txt");
    if (file.open(QIODevice::ReadWrite | QIODevice::Text)){
        file.resize(0);
        QTextStream out(&file);
        if (isBot1)
            out << "player1 : red" << '\n';
        else
            out << "player1 : green" << '\n';
        if (isBot2)
            out << "player2 : red" << '\n';
        else
            out << "player2 : green" << '\n';
        if (isBot3)
            out << "player3 : red" << '\n';
        else
            out << "player3 : green" << '\n';
        if (isBot4)
            out << "player4 : red" << '\n';
        else
            out << "player4 : green" << '\n';
        if (isBot5)
            out << "player5 : red" << '\n';
        else
            out << "player5 : green" << '\n';
        if (isBot6)
            out << "player6 : red" << '\n';
        else
            out << "player6 : green" << '\n';

    }
    file.close();
    this->hide();
}


void PlayersManager::on_Player_1_clicked()
{
    if (!isBot1){
        ui->Player_1->setStyleSheet("QPushButton{background-color:red}");
        isBot1 = true;
    }
    else{
        ui->Player_1->setStyleSheet("QPushButton{background-color:green}");
        isBot1 = false;
    }
}


void PlayersManager::on_Player_2_clicked()
{
    if (!isBot2){
        ui->Player_2->setStyleSheet("QPushButton{background-color:red}");
        isBot2 = true;
    }
    else{
        ui->Player_2->setStyleSheet("QPushButton{background-color:green}");
        isBot2 = false;
    }
}


void PlayersManager::on_Player_3_clicked()
{
    if (!isBot3){
        ui->Player_3->setStyleSheet("QPushButton{background-color:red}");
        isBot3 = true;
    }
    else{
        ui->Player_3->setStyleSheet("QPushButton{background-color:green}");
        isBot3 = false;
    }
}


void PlayersManager::on_Player_4_clicked()
{
    if (!isBot4){
        ui->Player_4->setStyleSheet("QPushButton{background-color:red}");
        isBot4 = true;
    }
    else{
        ui->Player_4->setStyleSheet("QPushButton{background-color:green}");
        isBot4 = false;
    }
}


void PlayersManager::on_Player_5_clicked()
{
    if (!isBot5){
        ui->Player_5->setStyleSheet("QPushButton{background-color:red}");
        isBot5 = true;
    }
    else{
        ui->Player_5->setStyleSheet("QPushButton{background-color:green}");
        isBot5 = false;
    }
}


void PlayersManager::on_Player_6_clicked()
{
    if (!isBot6){
        ui->Player_6->setStyleSheet("QPushButton{background-color:red}");
        isBot6 = true;
    }
    else{
        ui->Player_6->setStyleSheet("QPushButton{background-color:green}");
        isBot6 = false;
    }
}

