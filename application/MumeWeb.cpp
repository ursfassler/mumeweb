#include "MumeWeb.hpp"

#include <QTextStream>

MumeWeb::MumeWeb(const IMumeDbus &aDbus) :
  dbus{aDbus}
{
}

void MumeWeb::request(HttpHeader header, HttpData data)
{
  data->open(QIODevice::ReadWrite);
  QTextStream stream{data.data()};

  stream << "Content-Type: text/xml" << HttpLineEnd;

  stream << HttpLineEnd;

  stream << "<mume>";
  stream << "<switch state=\"";
  stream << (dbus.switchState() ? "on" : "off");
  stream << "\"/>";
  stream << "</mume>";

  data->close();
}
