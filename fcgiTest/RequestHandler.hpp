#ifndef REQUESTHANDLER_HPP
#define REQUESTHANDLER_HPP

#include <http.hpp>
#include <QObject>

class RequestHandler :
    public QObject
{
    Q_OBJECT

  public slots:
    void accepted(HttpHeader header, HttpData data);

  private:
    unsigned count{0};
};

#endif // REQUESTHANDLER_HPP
