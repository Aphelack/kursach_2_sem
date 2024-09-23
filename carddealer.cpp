#include "carddealer.h"

CardDealer::CardDealer(QWidget *parent, QPointF start, QPointF end) : QGraphicsView(parent)
{
    // Создаем сцену и добавляем карты
    m_scene.setSceneRect(0, 0, 1000, 1000);
    m_card1.setPixmap(QPixmap("../CardImages/cardback.jpg"));

    m_scene.addItem(&m_card1);

    // Устанавливаем сцену для виджета QGraphicsView
    setScene(&m_scene);

    // Раздаем карты
    dealCards(start, end);
}

void CardDealer::dealCards(QPointF start, QPointF end)
{
    // Создаем анимацию для перемещения карт
    QPropertyAnimation *animation1 = new QPropertyAnimation((QObject*)&m_card1, "pos", this);
    animation1->setDuration(1000); // Длительность анимации (в миллисекундах)
    animation1->setEndValue(QPointF(100, 150)); // Конечная позиция для первой карты



    // Запускаем анимацию
    animation1->start();

}

