#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>

class CardDealer : public QGraphicsView
{
    Q_OBJECT
public:
    CardDealer(QWidget *parent = nullptr, QPointF start = {0, 0}, QPointF end = {0, 0});

private:
    QGraphicsScene m_scene;
    QGraphicsPixmapItem m_card1;
    //QGraphicsPixmapItem m_card2;

    void dealCards(QPointF, QPointF);
};

