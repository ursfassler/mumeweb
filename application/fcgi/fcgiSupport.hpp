#ifndef FCGISUPPORT_HPP
#define FCGISUPPORT_HPP

#include <QMap>
#include <QString>

QMap<QString,QString> envToMap(const char * const * env);

#endif // FCGISUPPORT_HPP
