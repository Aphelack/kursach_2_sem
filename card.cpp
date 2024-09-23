#include "card.h"

Card::Card(){}


Card::Card(Suit _suit, Value _value, QPixmap* _pict) {
    suit = _suit;
    value = _value;
    pict = *_pict;
}

void Card::setVisible(bool _visible)
{
    visible = _visible;
}


Card::Card(int _value, int _suit)
{
    switch(_value){
    case 0: {
        value = Value::two;
        break;
    }
    case 1: {
        value = Value::three;
        break;
    }
    case 2: {
        value = Value::four;
        break;
    }
    case 3: {
        value = Value::five;
        break;
    }
    case 4: {
        value = Value::six;
        break;
    }
    case 5: {
        value = Value::seven;
        break;
    }
    case 6: {
        value = Value::eight;
        break;
    }
    case 7: {
        value = Value::nine;
        break;
    }
    case 8: {
        value = Value::ten;
        break;
    }
    case 9: {
        value = Value::jack;
        break;
    }
    case 10: {
        value = Value::queen;
        break;
    }
    case 11: {
        value = Value::king;
        break;
    }
    case 12: {
        value = Value::ace;
        break;
    }
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

