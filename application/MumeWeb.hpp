#ifndef MUMEWEB_HPP
#define MUMEWEB_HPP

#include "IMumeDbus.hpp"

#include "http.hpp"

#include <QObject>

class MumeWeb :
    public QObject
{
    Q_OBJECT

  public:
    MumeWeb(const IMumeDbus &dbus);

  public slots:
    void request(HttpHeader header, HttpData data);

  private:
    const IMumeDbus &dbus;
};

#endif // MUMEWEB_HPP
