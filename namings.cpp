#include "namings.h"

Namings::Namings(QString filename) {
    setNamings(filename);
}

void Namings::setNamings(QString filename)
{
    QFile language(filename);

    if (language.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&language);

        QString in = stream.readLine();
        if (in != "Combinations:"){
            qDebug() << "error in opening english language package";
            return;
        }
        while((in = stream.readLine()) != ""){
            accessedCombinations.append(in);
        }

        in = stream.readLine();
        if (in != "Accessed Values:"){
            qDebug() << "error in opening english language package";
            return;
        }
        while((in = stream.readLine()) != ""){
            accessedValues.append(in);
        }

        in = stream.readLine();
        if (in != "Accessed Suits:"){
            qDebug() << "error in opening english language package";
            return;
        }
        while((in = stream.readLine()) != ""){
            accessedSuits.append(in);
        }




        language.close();
    }
}
