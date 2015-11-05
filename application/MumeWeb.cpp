#include "MumeWeb.hpp"

MumeWeb::MumeWeb(const IMumeDbus &aDbus) :
  dbus{aDbus}
{
}

void MumeWeb::request(QIODevice &response)
{
  const QString state = dbus.switchState() ? "on" : "off";
  const QString doc{"<mume><switch state=\"" + state + "\"/></mume>"};
  response.write(doc.toStdString().c_str());
}

