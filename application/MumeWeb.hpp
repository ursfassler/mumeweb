#ifndef MUMEWEB_HPP
#define MUMEWEB_HPP

#include "IMumeDbus.hpp"

#include <QIODevice>

class MumeWeb
{
  public:
    MumeWeb(const IMumeDbus &dbus);

    void request(QIODevice &response);

  private:
    const IMumeDbus &dbus;
};

#endif // MUMEWEB_HPP
