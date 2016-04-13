#include "appproperties.h"

#include <QString>

AppProrepties::AppProrepties() :
    _appVersion("0.7"),
    _appName("ViewMarker")
{}

QString AppProrepties::version()
{
    return _appVersion;
}

QString AppProrepties::name()
{
    return _appName;
}
