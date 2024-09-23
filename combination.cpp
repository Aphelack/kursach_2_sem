#include "combination.h"
#include <set>

Combination::Combination(int _comb, int _value1, int _value2, int _suit)
{
    switch(_comb){
    case 0: {
        comb = Comb::Kiker;
        break;
    }
    case 1: {
        comb = Comb::Pair;
        break;
    }
    case 2: {
        comb = Comb::Two_Pair;
        break;
    }
    case 3: {
        comb = Comb::Set;
        break;
    }
    case 4: {
        comb = Comb::Straight;
        break;
    }
    case 5: {
        comb = Comb::Flush;
        break;
    }
    case 6: {
        comb = Comb::Full_House;
        break;
    }
    case 7: {
        comb = Comb::Quads;
        break;
    }
    case 8: {
        comb = Comb::Straight;
        break;
    }
    }

    switch(_value1){
    case 0: {
        value1 = Value::two;
        break;
    }
    case 1: {
        value1 = Value::three;
        break;
    }
    case 2: {
        value1 = Value::four;
        break;
    }
    case 3: {
        value1 = Value::five;
        break;
    }
    case 4: {
        value1 = Value::six;
        break;
    }
    case 5: {
        value1 = Value::seven;
        break;
    }
    case 6: {
        value1 = Value::eight;
        break;
    }
    case 7: {
        value1 = Value::nine;
        break;
    }
    case 8: {
        value1 = Value::ten;
        break;
    }
    case 9: {
        value1 = Value::jack;
        break;
    }
    case 10: {
        value1 = Value::queen;
        break;
    }
    case 11: {
        value1 = Value::king;
        break;
    }
    case 12: {
        value1 = Value::ace;
        break;
    }
    }

    if (comb == Comb::Two_Pair || comb == Comb::Full_House){
        switch(_value2){
        case 0: {
            value2 = Value::two;
            break;
        }
        case 1: {
            value2 = Value::three;
            break;
        }
        case 2: {
            value2 = Value::four;
            break;
        }
        case 3: {
            value2 = Value::five;
            break;
        }
        case 4: {
            value2 = Value::six;
            break;
        }
        case 5: {
            value2 = Value::seven;
            break;
        }
        case 6: {
            value2 = Value::eight;
            break;
        }
        case 7: {
            value2 = Value::nine;
            break;
        }
        case 8: {
            value2 = Value::ten;
            break;
        }
        case 9: {
            value2 = Value::jack;
            break;
        }
        case 10: {
            value2 = Value::queen;
            break;
        }
        case 11: {
            value2 = Value::king;
            break;
        }
        case 12: {
            value2 = Value::ace;
            break;
        }
        }

    }
    else{
        value2 = Value::two;
    }

    switch(_suit){
    case 0:{
        suit = Suit::Hearts;
        break;
    }
    case 1:{
        suit = Suit::Spades;
        break;
    }
    case 2:{
        suit = Suit::Diamonds;
        break;
    }
    case 3:{
        suit = Suit::Clubs;
        break;
    }
    }
}

QVector<Card> Combination::lastCombination = {};

bool Combination::find(QVector<Card>* pull)
{
    QMap<int, int>values;
    for (auto card : *pull){
        values[(int)card.value]++;
    }
    if (comb == Comb::Kiker){
        if (values[(int)value1] >= 1){

            lastCombination.resize(0);
            for (Card card : *pull){
                if (card.value == value1){
                    lastCombination.push_back(card);
                    break;
                }
            }
            return true;
        }
    }
    if (comb == Comb::Pair){
        if (values[(int)value1] >= 2){

            lastCombination.resize(0);
            int count = 0;
            for (Card card : *pull){
                if (card.value == value1){
                    lastCombination.push_back(card);
                    count++;
                    if (count == 2)
                        break;
                }
            }
            return true;
        }
    }
    if (comb == Comb::Two_Pair){
        if (values[(int)value1] >= 2 && values[(int)value2] >= 2){

            lastCombination.resize(0);
            int count1 = 0;
            int count2 = 0;
            for (Card card : *pull){
                if (card.value == value1 && count1 < 2){
                    lastCombination.push_back(card);
                    count1++;
                }
                if (card.value == value2 && count2 < 2){
                    lastCombination.push_back(card);
                    count2++;
                }
            }

            return true;
        }
    }
    if (comb == Comb::Set){
        if (values[(int)value1] >= 3){
            lastCombination.clear();
            lastCombination.resize(2);
            int count = 0;
            for (Card card : *pull){
                if (card.value == value1){
                    lastCombination.push_back(card);
                    count++;
                    if (count == 3)
                        break;
                }
            }
            return true;
        }
    }
    if (comb == Comb::Straight){
        if ((int)value1 < 4)
            return false;
        for (int i = 0; i < 5; i++){
            if (values[(int)value1 - i] == 0)
                return false;
        }

        lastCombination.resize(0);
        std::set<int>straight;
        for (int i = 0; i < 5; i++){
            straight.insert((int)value1 - i);
        }
        for (Card card : *pull){
            if (straight.count((int)card.value)){
                lastCombination.push_back(card);
                straight.erase((int)card.value);
            }
        }

        return true;
    }
    if (comb == Comb::Flush){
        std::vector<std::vector<int>>suits(4);
        for (auto card : *pull){
            suits[(int)card.suit].push_back((int)card.value);
        }
        for (int i = 0; i < 4; i++)
            std::sort(suits[i].begin(), suits[i].end());
        if (suits[(int)suit].size() <= 4) return false;
        if (suits[(int)suit][4] <= (int)value1){
            lastCombination.resize(0);
            for (Card card : *pull)
                if (card.suit == suit && (int)card.value == (int)value1){
                    lastCombination.push_back(card);
                    break;
                }
            if (lastCombination.size() == 0) return false;
            for (Card card : *pull){
                if (card.suit == suit && (int)card.value < (int)value1){
                    lastCombination.push_back(card);
                    if (lastCombination.size() == 5) break;
                }

            }

            return true;
        }


    }
    if (comb == Comb::Full_House){
        if (values[(int)value1] >= 3 && values[(int)value2] >= 2){

            int count1 = 0;
            int count2 = 0;
            for(Card card : *pull){
                if (card.value == value1 && count1 < 3){
                    lastCombination.push_back(card);
                    count1++;
                }

                if (card.value == value2 && count2 < 2){
                    lastCombination.push_back(card);
                    count2++;
                }

                if (count1 == 3 && count2 == 2) break;
            }
            return true;
        }
    }
    if (comb == Comb::Quads){
        if (values[(int)value1] == 4){
            lastCombination.resize(0);
            for (Card card : *pull)
                if (card.value == value1)
                    lastCombination.push_back(card);

            return true;
        }
    }
    if (comb == Comb::Staight_Flush){
        lastCombination.resize(0);
        std::set<int>straight;
        for (int i = 0; i < 5; i++){
            straight.insert((int)value1 - i);
        }
        for (Card card : *pull){
            if (card.suit == suit && straight.count((int)card.value)){
                lastCombination.push_back(card);
                straight.erase((int)card.value);
            }
        }
        if (lastCombination.size() == 5)
            return true;

        return false;
    }
    lastCombination.resize(0);
    return false;
}

bool Combination::isBigger(Combination* a)
{
    if (a->comb == Comb::Two_Pair && this->comb == Comb::Two_Pair && a->value1 == this->value2 && a->value2 == this->value1) return false;
    return (10000 * (int)a->comb + 100 * (int)a->value1 + (int)a->value2) < (10000 * (int)this->comb + 100 * (int)this->value1 + (int)this->value2);
}


bool Combination::isCorrect()
{
    if ((this->comb == Comb::Flush || this->comb == Comb::Staight_Flush || this->comb == Comb::Straight) && (int)(this->value1) <= 3) return false;
    if ((this->comb == Comb::Two_Pair || this->comb == Comb::Full_House) && this->value1 == this->value2) return false;

    return true;
}





