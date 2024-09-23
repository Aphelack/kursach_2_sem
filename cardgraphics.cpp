#include "cardgraphics.h"

CardGraphics::CardGraphics(Card card)
{
    this->setGeometry(Card::cardSize);
    if (card.visible){
        card.pict = card.pict.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::FastTransformation);
        this->setPixmap(card.pict);
    }
    else{
        QPixmap backDeck("/home/lidskae/kursach/CardImages/cardback.jpg");
        backDeck = backDeck.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::FastTransformation);
        this->setPixmap(backDeck);
    }
}
