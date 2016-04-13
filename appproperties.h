#ifndef APPPROPERTIES_H
#define APPPROPERTIES_H

#include <QStringList>

class QString;

class AppProrepties
{
public:
    AppProrepties();
    QString version();
    QString name();

private:
    QString _appVersion;
    QString _appName;
    QStringList _supportedFormats;
};

#endif // APPPROPERTIES_H
