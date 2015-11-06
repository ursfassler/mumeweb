#ifndef FCGIREQUEST_HPP
#define FCGIREQUEST_HPP

#include <http.hpp>
#include <fcgio.h>
#include <QThread>

class FcgiRequest :
    public QIODevice
{
  public:
    FcgiRequest(FCGX_Request *request);
    ~FcgiRequest();

  protected:
    qint64 readData(char * data, qint64 maxSize) override;
    qint64 writeData(const char * data, qint64 maxSize) override;

  private:
    FCGX_Request * const request;

};


class FcgiServer final :
    public QThread
{
    Q_OBJECT

  public:
    FcgiServer(QObject *parent);
    ~FcgiServer();

    void run() override;

  signals:
    void accepted(HttpHeader header, HttpData data);

  public slots:
    void stop();

  private:
    FCGX_Request *accept();

};

#endif // FCGIREQUEST_HPP
