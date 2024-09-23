#ifndef INFOWIDGET_H
#define INFOWIDGET_H

#include <QWidget>
#include <QFile>
namespace Ui {
class InfoWidget;
}

class InfoWidget : public QWidget
{
    Q_OBJECT

public:

    ~InfoWidget();
    static InfoWidget* getInstance(QWidget *parent = nullptr, QString filename = "");

private:
    static InfoWidget* singleTon;
    explicit InfoWidget(QWidget *parent = nullptr, QString filename = "");
    Ui::InfoWidget *ui;
};

#endif // INFOWIDGET_H
