#ifndef CARDGRAPHICS_H
#define CARDGRAPHICS_H

#include <QLabel>
#include <card.h>
#include <QPaintEvent>
#include <QPixmap>
#include <QPainter>
class CardGraphics : public QLabel
{
    Q_OBJECT
public:
    explicit CardGraphics(Card card);


signals:
};

#endif // CARDGRAPHICS_H
