#include "bot.h"

Bot::Bot() {}

Combination *Bot::algorithm(QVector<Combination *> history, int playersNum, QVector<Card> hand, int pullSize)
{

    std::vector<int>suits(4);

    Combination* maxFlush = new Combination(0, 0, 0, 0);
    if (history.size() == 0 || (int)history[history.size() - 1]->comb < 5){
        int flushCount = 0;
        for (Card card : hand){
            suits[(int)card.suit]++;
        }
        for (int suit : suits){
            if (suit >= 3){
                int maxCard = 0;
                for (Card card : hand){
                    if ((int)card.suit == suit)
                        maxCard = std::max(maxCard, (int)card.value);
                }
                if (maxCard < 5); continue;
                    Combination* newFlush = new Combination((int)Comb::Flush, maxCard, 0, suit);
                if (newFlush->isBigger(maxFlush)){
                    maxFlush = newFlush;
                    flushCount = maxCard;
                }
            }
        }
        if (flushCount >= 5){
            int maxCard = 0;
            for (Card card : hand){
                if (card.suit == maxFlush->suit)
                    maxCard = std::max(maxCard, (int)card.value);
            }
            if (maxCard >= 4)
                maxFlush = new Combination((int)Comb::Flush, maxCard, 0, (int)maxFlush->suit);
        }
        else if ((int)maxFlush->value1 < 9 && flushCount == 3 || (int)maxFlush->value1 < 5 && flushCount == 4){
            srand(time(0));
            int ranValue = random() % 3;
            maxFlush = new Combination((int)Comb::Flush, ranValue + 10, 0, (int)maxFlush->suit);
        }
        else maxFlush = new Combination(0, 0, 0, 0);
    }

    if (history.size() == 0){
        /*QVector<Card>randomCards(hand.size() / 2 + 1 + hand.size());
        for (int i = 0; i < hand.size(); i++){
            randomCards[i] = hand[i];
        }
        for (int i = hand.size(); i < hand.size() / 2 + 1 + hand.size(); i++){
            std::random_device rd;
            std::mt19937 mt(rd());
            std::uniform_int_distribution<int> distVal(0, 12);
            std::uniform_int_distribution<int> distSuit(0, 3);

            int val = distVal(mt);

            int suit = distSuit(mt);
            Card ranCard(val, suit);
            randomCards[i] = ranCard;
        }

        return maxComb(randomCards);*/
        return maxComb(hand);
    }
    QVector<Card>newPull;

    std::vector<int>values(13);
    for (int i = 1; i <= history.size(); i++){
        Combination* combination = history[history.size() - i];

        if (i % playersNum == playersNum - 1) {
            if (combination->comb == Comb::Pair){
                values[(int)combination->value1] -= 2;
            }
            if (combination->comb == Comb::Kiker){
                values[(int)combination->value1] -= 1;
            }
            if (combination->comb == Comb::Two_Pair){
                values[(int)combination->value1] -= 2;
                values[(int)combination->value2] -= 2;
            }
        }
        else{
            if (combination->comb == Comb::Staight_Flush) return nullptr;

            if (combination->comb == Comb::Flush){
                for (Card card : hand){
                    if(card.suit == combination->suit && card.value > combination->value1){
                        Combination* newFlush = new Combination((int)Comb::Flush, (int)card.value, 0, (int)card.suit);
                        if (newFlush->isBigger(maxFlush))
                            maxFlush = newFlush;
                    }
                }
            }
            if (combination->comb == Comb::Pair && values[(int)combination->value1] < 2){
                values[(int)combination->value1] = 2;
            }

            if (combination->comb == Comb::Kiker && values[(int)combination->value1] < 1){
                values[(int)combination->value1] = 1;
            }

            if (combination->comb == Comb::Two_Pair){
                if (values[(int)combination->value1] < 2)
                    values[(int)combination->value1] = 2;
                if (values[(int)combination->value2] < 2)
                    values[(int)combination->value2] = 2;
            }

            if (combination->comb == Comb::Full_House){
                if (values[(int)combination->value1] < 3)
                    values[(int)combination->value1] = 3;
                if (values[(int)combination->value2] < 2)
                    values[(int)combination->value2] = 2;
            }

            if (combination->comb == Comb::Set && values[(int)combination->value1] < 3){
                values[(int)combination->value1] = 3;
            }

            if (combination->comb == Comb::Quads && values[(int)combination->value1] < 4){
                values[(int)combination->value1] = 4;
            }

            if (combination->comb == Comb::Straight){
                for (int i = 0; i < 5; i++)
                    values[(int)combination->value1 - i]++;
            }
        }
    }
    for (Card card : hand){
        values[(int)card.value]++;
    }

    for (int v = 0; v < 13; v++){
        for (int i = 0; i < std::min(4, values[v]); i++){
            newPull.push_back(Card(v, i));
        }
    }

    Combination* maxNonFlush = maxComb(newPull, true);
    Combination* last = *(history.end() - 1);
    if (maxFlush->isBigger(last)) return maxFlush;
    if (maxNonFlush->isBigger(last)) return maxNonFlush;

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> det(0, 99);
    int var = det(mt);
    switch((int)last->comb){
    case 0:{
        if (var < 30){
            return new Combination(1, (int)last->value1, 0, 0);
        }
        if (var < 60){
            return new Combination(1, (int)hand[0].value, 0, 0);
        }
        if (var < 90){
            std::uniform_int_distribution<int> distVal(0, 12);
            return new Combination(1, distVal(mt), 0, 0);
        }

        if (pullSize >= 12)
            return new Combination(2, (int)hand[0].value, (int)last->value1, 0);
        return new Combination(1, (int)hand[0].value, 0, 0);
        break;
    }
    case 1:{
        if (var < 40){
            return new Combination(2, (int)hand[0].value, (int)last->value1, 0);
        }
        if (var < 80){
            if ((int)maxComb(hand)->value1 > (int)last->value1)
                return new Combination(1, (int)maxComb(hand)->value1, 0, 0);

            if (pullSize >= 14){
                std::uniform_int_distribution<int> distVal(0, 12);
                int v = (int)last->value1;
                while(v != (int)last->value1)
                    v = distVal(mt);
                return new Combination(2, (int)maxComb(hand)->value1, v, 0);
            }
            return nullptr;
        }
        if (pullSize >= 14)
            return new Combination(3, (int)maxComb(hand)->value1, 0, 0);
        return nullptr;
        break;
    }
    case 2:{
        return nullptr;
        break;
    }
    case 3:{
        return nullptr;
        break;
    }
    default:
        return nullptr;
    }
    return nullptr;
}


Combination *Bot::maxComb(QVector<Card> pull, bool nonFlush)
{
    Combination* current;
    Combination* last = new Combination(0, 0, 0, 0);
    for (int com = 0; com < 9; com++){
        if (nonFlush && (com == 5 || com == 9)) continue;
        for (int val1 = 0; val1 < 13; val1++){
            if (com == 2 || com == 6){
                for (int val2 = 0; val2 < 13; val2++){
                    if (val1 == val2) continue;
                    current = new Combination(com, val1, val2, 0);
                    if (current->isBigger(last) && current->find(&pull)) last = current;
                }
            }
            else if (com == 5 || com == 7){
                for (int sui = 0; sui < 4; sui++){
                    current = new Combination(com, val1, 0, sui);
                    if (current->isBigger(last) && current->find(&pull)) last = current;
                }
            }
            else{
                current = new Combination(com, val1, 0, 0);
                if (current->isBigger(last) && current->find(&pull)) last = current;
            }
        }
    }
    return last;
}




