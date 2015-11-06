#include "http.hpp"

void registerHttpTypes()
{
  qRegisterMetaType<HttpHeader>("HttpHeader");
  qRegisterMetaType<HttpData>("HttpData");
}
