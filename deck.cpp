#include "deck.h"

Deck::Deck() {
    deck[0] = (Card(Suit::Hearts, Value::ace, new QPixmap("/home/lidskae/kursach/CardImages/AH.jpg")));
    deck[1] = (Card(Suit::Hearts, Value::king, new QPixmap("/home/lidskae/kursach/CardImages/KH.jpg")));
    deck[2] = (Card(Suit::Hearts, Value::queen, new QPixmap("/home/lidskae/kursach/CardImages/QH.jpg")));
    deck[3] = (Card(Suit::Hearts, Value::jack, new QPixmap("/home/lidskae/kursach/CardImages/JH.jpg")));
    deck[4] = (Card(Suit::Hearts, Value::ten, new QPixmap("/home/lidskae/kursach/CardImages/10H.jpg")));
    deck[5] = (Card(Suit::Hearts, Value::nine, new QPixmap("/home/lidskae/kursach/CardImages/9H.jpg")));
    deck[6] = (Card(Suit::Hearts, Value::eight, new QPixmap("/home/lidskae/kursach/CardImages/8H.jpg")));
    deck[7] = (Card(Suit::Hearts, Value::seven, new QPixmap("/home/lidskae/kursach/CardImages/7H.jpg")));
    deck[8] = (Card(Suit::Hearts, Value::six, new QPixmap("/home/lidskae/kursach/CardImages/6H.jpg")));
    deck[9] = (Card(Suit::Hearts, Value::five, new QPixmap("/home/lidskae/kursach/CardImages/5H.jpg")));
    deck[10] = (Card(Suit::Hearts, Value::four, new QPixmap("/home/lidskae/kursach/CardImages/4H.jpg")));
    deck[11] = (Card(Suit::Hearts, Value::three, new QPixmap("/home/lidskae/kursach/CardImages/3H.jpg")));
    deck[12] = (Card(Suit::Hearts, Value::two, new QPixmap("/home/lidskae/kursach/CardImages/2H.jpg")));
    deck[13] = (Card(Suit::Spades, Value::ace, new QPixmap("/home/lidskae/kursach/CardImages/AS.jpg")));
    deck[14] = (Card(Suit::Spades, Value::king, new QPixmap("/home/lidskae/kursach/CardImages/KS.jpg")));
    deck[15] = (Card(Suit::Spades, Value::queen, new QPixmap("/home/lidskae/kursach/CardImages/QS.jpg")));
    deck[16] = (Card(Suit::Spades, Value::jack, new QPixmap("/home/lidskae/kursach/CardImages/JS.jpg")));
    deck[17] = (Card(Suit::Spades, Value::ten, new QPixmap("/home/lidskae/kursach/CardImages/10S.jpg")));
    deck[18] = (Card(Suit::Spades, Value::nine, new QPixmap("/home/lidskae/kursach/CardImages/9S.jpg")));
    deck[19] = (Card(Suit::Spades, Value::eight, new QPixmap("/home/lidskae/kursach/CardImages/8S.jpg")));
    deck[20] = (Card(Suit::Spades, Value::seven, new QPixmap("/home/lidskae/kursach/CardImages/7S.jpg")));
    deck[21] = (Card(Suit::Spades, Value::six, new QPixmap("/home/lidskae/kursach/CardImages/6S.jpg")));
    deck[22] = (Card(Suit::Spades, Value::five, new QPixmap("/home/lidskae/kursach/CardImages/5S.jpg")));
    deck[23] = (Card(Suit::Spades, Value::four, new QPixmap("/home/lidskae/kursach/CardImages/4S.jpg")));
    deck[24] = (Card(Suit::Spades, Value::three, new QPixmap("/home/lidskae/kursach/CardImages/3S.jpg")));
    deck[25] = (Card(Suit::Spades, Value::two, new QPixmap("/home/lidskae/kursach/CardImages/2S.jpg")));
    deck[26] = (Card(Suit::Clubs, Value::ace, new QPixmap("/home/lidskae/kursach/CardImages/AC.jpg")));
    deck[27] = (Card(Suit::Clubs, Value::king, new QPixmap("/home/lidskae/kursach/CardImages/KC.jpg")));
    deck[28] = (Card(Suit::Clubs, Value::queen, new QPixmap("/home/lidskae/kursach/CardImages/QC.jpg")));
    deck[29] = (Card(Suit::Clubs, Value::jack, new QPixmap("/home/lidskae/kursach/CardImages/JC.jpg")));
    deck[30] = (Card(Suit::Clubs, Value::ten, new QPixmap("/home/lidskae/kursach/CardImages/10C.jpg")));
    deck[31] = (Card(Suit::Clubs, Value::nine, new QPixmap("/home/lidskae/kursach/CardImages/9C.jpg")));
    deck[32] = (Card(Suit::Clubs, Value::eight, new QPixmap("/home/lidskae/kursach/CardImages/8C.jpg")));
    deck[33] = (Card(Suit::Clubs, Value::seven, new QPixmap("/home/lidskae/kursach/CardImages/7C.jpg")));
    deck[34] = (Card(Suit::Clubs, Value::six, new QPixmap("/home/lidskae/kursach/CardImages/6C.jpg")));
    deck[35] = (Card(Suit::Clubs, Value::five, new QPixmap("/home/lidskae/kursach/CardImages/5C.jpg")));
    deck[36] = (Card(Suit::Clubs, Value::four, new QPixmap("/home/lidskae/kursach/CardImages/4C.jpg")));
    deck[37] = (Card(Suit::Clubs, Value::three, new QPixmap("/home/lidskae/kursach/CardImages/3C.jpg")));
    deck[38] = (Card(Suit::Clubs, Value::two, new QPixmap("/home/lidskae/kursach/CardImages/2C.jpg")));
    deck[39] = (Card(Suit::Diamonds, Value::ace, new QPixmap("/home/lidskae/kursach/CardImages/AD.jpg")));
    deck[40] = (Card(Suit::Diamonds, Value::king, new QPixmap("/home/lidskae/kursach/CardImages/KD.jpg")));
    deck[41] = (Card(Suit::Diamonds, Value::queen, new QPixmap("/home/lidskae/kursach/CardImages/QD.jpg")));
    deck[42] = (Card(Suit::Diamonds, Value::jack, new QPixmap("/home/lidskae/kursach/CardImages/JD.jpg")));
    deck[43] = (Card(Suit::Diamonds, Value::ten, new QPixmap("/home/lidskae/kursach/CardImages/10D.jpg")));
    deck[44] = (Card(Suit::Diamonds, Value::nine, new QPixmap("/home/lidskae/kursach/CardImages/9D.jpg")));
    deck[45] = (Card(Suit::Diamonds, Value::eight, new QPixmap("/home/lidskae/kursach/CardImages/8D.jpg")));
    deck[46] = (Card(Suit::Diamonds, Value::seven, new QPixmap("/home/lidskae/kursach/CardImages/7D.jpg")));
    deck[47] = (Card(Suit::Diamonds, Value::six, new QPixmap("/home/lidskae/kursach/CardImages/6D.jpg")));
    deck[48] = (Card(Suit::Diamonds, Value::five, new QPixmap("/home/lidskae/kursach/CardImages/5D.jpg")));
    deck[49] = (Card(Suit::Diamonds, Value::four, new QPixmap("/home/lidskae/kursach/CardImages/4D.jpg")));
    deck[50] = (Card(Suit::Diamonds, Value::three, new QPixmap("/home/lidskae/kursach/CardImages/3D.jpg")));
    deck[51] = (Card(Suit::Diamonds, Value::two, new QPixmap("/home/lidskae/kursach/CardImages/2D.jpg")));
}
