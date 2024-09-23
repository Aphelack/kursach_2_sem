#ifndef SETTINGS_H
#define SETTINGS_H

#include <QMainWindow>
#include "playersmanager.h"
#include "menu.h"
#include <QFile>
namespace Ui {
class Settings;
}

class Settings : public QMainWindow
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = nullptr);
    ~Settings();

private slots:
    void on_canselButton_clicked();

    void on_savebutton_clicked();



    void on_manageButton_clicked();

private:
    Ui::Settings *ui;

    QStringList avaliableLanguages{"English",
                                   "Русский"};
};

#endif // SETTINGS_H
