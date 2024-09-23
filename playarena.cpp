#include "playarena.h"
#include "ui_playarena.h"

PlayArena::PlayArena(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PlayArena)
{
    ui->setupUi(this);


    QPalette pal = ui->BetHistory->viewport()->palette();
    QPixmap backgroundImage("/home/lidskae/kursach/clock.jpeg"); // Replace with your image path
    backgroundImage = backgroundImage.scaled(ui->BetHistory->size(), Qt::IgnoreAspectRatio);
    pal.setBrush(QPalette::Base, QBrush(backgroundImage));
    ui->BetHistory->viewport()->setPalette(pal);
    QPixmap bkgnd("/home/lidskae/kursach/pic.gif");
    //this->setGeometry(0, 0, );
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
    //this->setStyleSheet("{background-image: url(:/home/lidskae/kursach/download.jpeg);}");
    setPlayers();
    setNamings();
    setButtons();

}

PlayArena::~PlayArena()
{

    delete ui;
}


void PlayArena::drawCard(QHBoxLayout *widget, Card card)
{
    widget->addWidget(new CardGraphics(card));
}


std::set<int> PlayArena::generateCards(int count)
{
    int l = 0, r = 51;

    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(l, r);

    std::set<int> uniqueNumbers;
    while (uniqueNumbers.size() < count) {
        uniqueNumbers.insert(dist(gen));
    }

    return uniqueNumbers;
}


void PlayArena::Dealling()
{
    used.resize(0);
    pull.resize(0);
    setActivePlayer(firstMove->num);
    ui->messadge->setStyleSheet("");
    QLayoutItem* item;
    while ((item = ui->cardPull->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    ui->acceptButton->setEnabled(true);
    ui->showButton->setEnabled(true);
    ui->hideAllButton->setEnabled(true);
    ui->hideButton->setEnabled(true);
    std::set<int>generated = generateCards(cardsInGame);
    std::vector<int>generatedVector(generated.size());
    int size = generated.size();
    for(int i = 0; i < size; i++){
        int num = *(generated.begin());
        generatedVector[i] = num;
        generated.erase(num);
    }

    //std::sample(generated.begin(), generated.end(), std::back_inserter(generatedSwaped),
    //            3, std::mt19937{std::random_device{}()});

    for (auto& player : players){
        QLayoutItem* item;
        while ((item = player->handWidget->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        if (player->inGame){
            player->hand.resize(0);


            for (int i = 0; i < player->handSize; i++){
                std::mt19937 gen(rd());
                std::uniform_int_distribution<int> dist(0, generatedVector.size() - 1);
                int ind = dist(gen);
                int indexNow = generatedVector[ind];
                generatedVector.erase(ind + generatedVector.begin());

                if (player->isActive)
                    myDeck.deck[indexNow].visible = true;
                else
                    myDeck.deck[indexNow].visible = false;
                used.push_back(new CardGraphics(myDeck.deck[indexNow]));
                pull.push_back(myDeck.deck[indexNow]);


                player->handWidget->addWidget(*(used.end() - 1));
                player->hand.push_back(myDeck.deck[indexNow]);
                //deck->deck[indexNow].used = true;
                //dealCardsAnimation(ui->deckImageWidget, ui->handWidget0);

                //generated.erase(indexNow);
        }

            //animation
        }

    }

    history.resize(0);
    ui->BetHistory->setRowCount(0);
    if (pass) on_passButton_clicked();
        hideAllhands();
    previousTurn = nullptr;
}


void PlayArena::setActivePlayer(int i)
{
    for (auto player : players){
        player->isActive = false;
    }
    players[i]->isActive = true;
    for (int j = 0; j < 6; j++)
        indecators[j]->setStyleSheet("");
    indecators[i]->setStyleSheet("QLabel{background-color:yellow}");
}


Combination *PlayArena::Turn()
{
    if (pass)
        return nullptr;

    Combination* turn = new Combination(ui->combinationTitles->currentIndex(),
                                        ui->value_1Titles->currentIndex(),
                                        ui->value_2Titles->currentIndex(),
                                        ui->SuitTitles->currentIndex());
    return turn;
}


Player *PlayArena::activePlayer()
{
    for (auto player : players){
        if (player->isActive)
            return player;
    }
    return nullptr;
}


Player *PlayArena::nextPlayer(int i)
{
    for (int j = i + 1; j < players.size(); j++){
        if (players[j]->inGame)
            return players[j];
    }
    for (int j = 0; j <= i; j++){
        if (players[j]->inGame)
            return players[j];
    }

}


Player *PlayArena::previousPlayer(int i)
{
    for (int j = i - 1; j >= 0; j--){
        if (players[j]->inGame)
            return players[j];
    }
    for (int j = players.size() - 1; j >= i; j--){
        if (players[j]->inGame)
            return players[j];
    }
}


void PlayArena::endGame()
{
    ui->endwidget->show();
    ui->endMesssadge->setText("Player " + QString::number(activePlayer()->num) + " has won!");
}


void PlayArena::Lose(Player *player)
{
    if (player->handSize == 6){
        player->inGame = false;
        playerNum--;

        cardsInGame -= 6;
    }
    else{
        player->handSize++;
        cardsInGame++;
    }
    indecators[player->num]->setStyleSheet("QLabel{background-color:red}");
}


void PlayArena::showHands()
{
    for (auto player : players){
        if (player->inGame){
            for (auto& card : player->hand)
                card.setVisible(true);
        }
    }
    reDrawHands();
}


void PlayArena::hideHands()
{
    for (auto player : players){
        if (player->isActive){
            for (auto& card : player->hand){
                card.visible = true;

            }
        }
        else if (player->inGame){
            for (auto& card : player->hand)
                card.visible = false;
        }
    }
    reDrawHands();
}


void PlayArena::hideAllhands()
{
    for (auto player : players){
        if (player->inGame){
            for (auto& card : player->hand)
                card.setVisible(false);
        }
    }
    reDrawHands();
}


void PlayArena::reDrawHands()
{
    used.resize(0);
    for (auto& player : players){
        QLayoutItem* item;
        while ((item = player->handWidget->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        if (player->inGame){
            for (int i = 0; i < player->handSize; i++){
                Card currentCard = player->hand[i];

                used.push_back(new CardGraphics(currentCard));
                player->handWidget->addWidget(*(used.end() - 1));
            }

            //animation
        }

    }
    qDebug() << "ok";
}


void PlayArena::dealCardsAnimation(QWidget* start, QWidget* end)
{
    QWidget* movingWidget = new QWidget(this);
    QLabel* movingCard = new QLabel(movingWidget);
    movingCard->setGeometry(start->geometry());
    QPixmap backDeck("/home/lidskae/kursach/CardImages/cardback.jpg");
    backDeck = backDeck.scaled(movingCard->size(), Qt::IgnoreAspectRatio, Qt::FastTransformation);
    movingCard->setPixmap(backDeck);

    movingWidget->setGeometry(start->geometry());

    movingCard->show();
    QRect widgetRect = start->geometry();

    // Calculate the center point
    double center_x_start = widgetRect.x() + widgetRect.width() / 2;
    double center_y_start = widgetRect.y() + widgetRect.height() / 2;
    QPointF startPoint = {center_x_start, center_y_start};

    widgetRect = end->geometry();

    // Calculate the center point
    double center_x_end = widgetRect.x() + widgetRect.width() / 2;
    double center_y_end = widgetRect.y() + widgetRect.height() / 2;

    QPointF endPoint = {center_x_end, center_y_end};



    QVector2D vect(endPoint - startPoint);
    vect.normalize();
    QRect starttpos = ui->deckImageWidget->geometry();
    int dist = sqrt(pow(endPoint.x() - startPoint.x(), 2) + pow(endPoint.y() - startPoint.y(), 2));
    for (int i = 0; i < 100; i++){
        movingWidget->move(movingWidget->pos().x() + 20 * vect.x(), movingWidget->pos().y() + 20 * vect.y());
        QRect currentpos = ui->deckImageWidget->geometry();
        update();
        sleep(0.001);
    }
}


void PlayArena::on_startRound_clicked()
{
    setActivePlayer(0);
    Dealling();
}

void PlayArena::on_acceptButton_clicked()
{
    Player* active = activePlayer();

    //if (lastTurn != nullptr) return;
    Combination* lastTurn;
    if (!active->isBot){
        lastTurn = Turn();
        if (lastTurn!= nullptr && !lastTurn->isCorrect()) return;
    }
    else
        lastTurn = Bot::algorithm(history, playerNum, active->hand, pull.size());


    if (lastTurn!= nullptr && !lastTurn->isCorrect()){
        qDebug() << "comb is not correct";
        return;
    }

    if (lastTurn == nullptr){
        showHands();
        if (!previousTurn->find(&pull)){
            Lose(previousPlayer(active->num));
            QLabel* message = new QLabel(this);
            message->setStyleSheet("QLabel{background-color:red}");
            ui->cardPull->addWidget(message);
        }
        else{
            Lose(active);
            for (Card card : Combination::lastCombination){
                card.visible = true;
                ui->cardPull->addWidget(new CardGraphics(card));
            }
            //ui->messadge->setStyleSheet("QLabel{background-color:green}");
        }
        //setActivePlayer(nextPlayer(firstMove->num)->num);
        firstMove = nextPlayer(firstMove->num);
        ui->acceptButton->setEnabled(false);

    }
    else if (previousTurn == nullptr || lastTurn->isBigger(previousTurn)){
        qDebug() << "accepted " << active->num << " ";
        int n = history.size();
        history.push_back(lastTurn);

        ui->BetHistory->insertRow(n);
        for (int i = 0; i <= n; i++){
            Combination currentComb = *history[n - i];
            ui->BetHistory->setItem(i, 0, new QTableWidgetItem(accessedCombinations.at((int)currentComb.comb)));
            ui->BetHistory->setItem(i, 1, new QTableWidgetItem(accessedValues.at((int)currentComb.value1)));
            if (currentComb.comb == Comb::Two_Pair || currentComb.comb == Comb::Full_House)
                ui->BetHistory->setItem(i, 2, new QTableWidgetItem(accessedValues.at((int)currentComb.value2)));
            else
                ui->BetHistory->setItem(i, 2, new QTableWidgetItem("-"));
            if (currentComb.comb == Comb::Flush || currentComb.comb == Comb::Staight_Flush)
                ui->BetHistory->setItem(i, 3, new QTableWidgetItem(accessedSuits.at((int)currentComb.suit)));
            else
                ui->BetHistory->setItem(i, 3, new QTableWidgetItem("-"));
        }
        previousTurn = lastTurn;
        setActivePlayer(nextPlayer(active->num)->num);
        hideAllhands();
    }
    else{
        lastTurn = *(history.end() - 1);
        qDebug() << "This combination is younger";
    }
    if (playerNum == 1) {
        endGame();
        return;
    }
}


void PlayArena::on_passButton_clicked()
{
    if (previousTurn == nullptr) {
        qDebug() << "You should make bet";
        return;
    }
    if (pass){
        ui->showButton->setEnabled(true);
        ui->hideAllButton->setEnabled(true);
        ui->hideButton->setEnabled(true);
        ui->acceptButton->setEnabled(true);
        ui->combinationTitles->setEnabled(true);
        ui->value_1Titles->setEnabled(true);
        ui->value_2Titles->setEnabled(true);
        ui->SuitTitles->setEnabled(true);
        //setActivePlayer(nextPlayer(firstMove->num)->num);
        pass = false;

    }
    else{
        ui->showButton->setEnabled(false);
        ui->hideAllButton->setEnabled(false);
        ui->hideButton->setEnabled(false);
        ui->combinationTitles->setEnabled(false);
        ui->value_1Titles->setEnabled(false);
        ui->value_2Titles->setEnabled(false);
        ui->SuitTitles->setEnabled(false);
        pass = true;
    }

}


void PlayArena::on_showButton_clicked()
{
    showHands();
}


void PlayArena::on_hideButton_clicked()
{
    hideHands();
}


void PlayArena::on_hideAllButton_clicked()
{
    hideAllhands();
}


void PlayArena::on_pushButton_clicked()
{
    Menu* menu = new Menu;
    menu->show();
    this->hide();
}


void PlayArena::setPlayers()
{
    const int maxPlayers = 6;
    QLabel* deckImage = new QLabel(ui->deckImageWidget);
    deckImage->setGeometry(Card::cardSize);
    QPixmap backDeck("/home/lidskae/kursach/CardImages/cardback.jpg");
    backDeck = backDeck.scaled(deckImage->size(), Qt::IgnoreAspectRatio, Qt::FastTransformation);
    deckImage->setPixmap(backDeck);


    QWidget* handArray[maxPlayers] = {ui->handWidget0,
                                      ui->handWidget1,
                                      ui->handWidget2,
                                      ui->handWidget3,
                                      ui->handWidget4,
                                      ui->handWidget5};

    setSettings();

    players.resize(maxPlayers);
    QFile seats("/home/lidskae/kursach/seats.txt");
    if (seats.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&seats);
        for (int i = 0; i < maxPlayers; i++){
            Player* player = new Player(i);
            player->handWidget = new QHBoxLayout(handArray[i]);
            players[i] = player;

            QString color = stream.readLine().split(" ").at(2);

            if (Seats[playerNum].contains(i)){
                players[i]->inGame = true;
                if (color == "green")
                    players[i]->isBot = false;
                else
                    players[i]->isBot = true;
            }
            else{
                players[i]->inGame = false;
            }
        }
        seats.close();
    }

    firstMove = players[0];

    cardsInGame = 2 * playerNum;

    indecators[0] = ui->activeIndecator_0;
    indecators[1] = ui->activeIndecator_1;
    indecators[2] = ui->activeIndecator_2;
    indecators[3] = ui->avtiveIndecator_3;
    indecators[4] = ui->avtiveIndecator_4;
    indecators[5] = ui->avtiveIndecator_5;
}


void PlayArena::setButtons()
{
    for (auto title : accessedCombinations){
        ui->combinationTitles->addItem(title);
    }
    for (auto title : accessedValues){
        ui->value_1Titles->addItem(title);
        ui->value_2Titles->addItem(title);
    }
    for (auto title : accessedSuits){
        ui->SuitTitles->addItem(title);
    }
    ui->acceptButton->setEnabled(false);
    ui->showButton->setEnabled(false);
    ui->hideAllButton->setEnabled(false);
    ui->hideButton->setEnabled(false);
    //ui->endwidget->hide();
}


void PlayArena::setSettings()
{
    QFile settings("/home/lidskae/kursach/Settings.txt");
    if (settings.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&settings);
        qDebug() << "file settings opened";
        QString in;
        in = stream.readLine();
        playerNum = in.split(" ").value(2).toInt();

        in = stream.readLine().split(" ").at(2);
        if (in == "English")
            languagePackagePath = "/home/lidskae/kursach/English.txt";
        if (in == "Русский")
            languagePackagePath = "/home/lidskae/kursach/Russian.txt";
        settings.close();
    }
    QFile seats("/home/lidskae/kursach/seats.txt");
    if (seats.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&seats);
        QString in;
        qDebug() << "file seats opened";
        for (int i = 0; i < 6; i++){
            in = stream.readLine().split(" ").value(2);
            manager[i] = in;
        }

        seats.close();
    }
}

void PlayArena::setNamings()
{
    Namings* namings = new Namings(languagePackagePath);
    accessedCombinations = namings->accessedCombinations;
    accessedValues = namings->accessedValues;
    accessedSuits = namings->accessedSuits;

}


void PlayArena::on_helpButton_clicked()
{
    InfoWidget* rulls = InfoWidget::getInstance(nullptr, "../kursach/rulls_Rus.txt");
    rulls->show();
}




