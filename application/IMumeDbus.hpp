#ifndef IMUMEDBUS
#define IMUMEDBUS

class IMumeDbus
{
  public:
    virtual ~IMumeDbus() = default;

    virtual bool switchState() const = 0;
};

#endif // IMUMEDBUS

