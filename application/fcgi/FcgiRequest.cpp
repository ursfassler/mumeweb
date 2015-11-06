#include "FcgiRequest.hpp"

#include "fcgiSupport.hpp"

FcgiRequest::FcgiRequest(FCGX_Request *aRequest) :
  request{aRequest}
{
}

FcgiRequest::~FcgiRequest()
{
  FCGX_Finish_r(request);

  delete request;
}

qint64 FcgiRequest::readData(char *data, qint64 maxSize)
{
  return FCGX_GetStr(data, maxSize, request->in);
}

qint64 FcgiRequest::writeData(const char *data, qint64 maxSize)
{
  return FCGX_PutStr(data, maxSize, request->out);
}




FcgiServer::FcgiServer(QObject *parent) :
  QThread{parent}
{
  FCGX_Init();
}

FcgiServer::~FcgiServer()
{
}

void FcgiServer::run()
{
  while (true) {
    FCGX_Request *request = accept();
    if (request == nullptr) {
      return;
    }

    const auto header = envToMap(request->envp);
    const auto data = HttpData(new FcgiRequest(request));

    accepted(header, data);
  }
}

void FcgiServer::stop()
{
  FCGX_ShutdownPending();
}

FCGX_Request *FcgiServer::accept()
{
  FCGX_Request *request = new FCGX_Request();

  if (FCGX_InitRequest(request, 0, 0) != 0) {
    delete request;
    return nullptr;
  }

  if(FCGX_Accept_r(request) != 0) {
    delete request;
    return nullptr;
  }

  return request;
}

