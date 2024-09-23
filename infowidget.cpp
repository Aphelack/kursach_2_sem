#include "infowidget.h"
#include "ui_infowidget.h"

InfoWidget::InfoWidget(QWidget *parent, QString filename)
    : QWidget(parent)
    , ui(new Ui::InfoWidget)
{
    ui->setupUi(this);
    QFile info(filename);

    if (info.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&info);
        QString text = stream.readAll();
        ui->InfoField->setText(text);

        info.close();
    }
    ui->InfoField->setAlignment(Qt::AlignJustify);
    this->setFixedSize(500, 450);
}


InfoWidget::~InfoWidget()
{
    singleTon = nullptr;
    delete ui;
}

InfoWidget* InfoWidget::singleTon = nullptr;

InfoWidget* InfoWidget::getInstance(QWidget* parent, QString filename)
{
    if (singleTon == nullptr) {
        singleTon = new InfoWidget(parent, filename);
    }
    return singleTon;
}
