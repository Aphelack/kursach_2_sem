#ifndef NAMINGS_H
#define NAMINGS_H
#include <QString>
#include <QFile>
#include <QTextStream>
#include <qdebug.h>
class Namings
{
public:
    Namings(QString filename);

    QStringList accessedCombinations;

    QStringList accessedValues;

    QStringList accessedSuits;

private:
    void setNamings(QString);
};

#endif // NAMINGS_H
