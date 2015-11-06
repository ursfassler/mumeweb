#include "RequestHandler.hpp"
#include <http.hpp>
#include <fcgi/FcgiRequest.hpp>

#include <QCoreApplication>
#include <QTextStream>
#include <QTimer>

int main(int argc, char *argv[])
{
  registerHttpTypes();

  QCoreApplication a(argc, argv);

  FcgiServer server{&a};
  QObject::connect(&a, SIGNAL(aboutToQuit()), &server, SLOT(stop()));
  server.start();

  RequestHandler requestHandler;

  QObject::connect(&server, SIGNAL(accepted(HttpHeader, HttpData)), &requestHandler, SLOT(accepted(HttpHeader, HttpData)));

//  QTimer::singleShot(3*1000, &a, SLOT(quit()));

  auto const ret = a.exec();
  server.wait();
  return ret;
}

