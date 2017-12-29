#ifndef mine_h
#define mine_h
#include "Arduino.h"

class mine
{
  public:
    mine(void);
    void setapikey(String);
    boolean send(int, int); // type, value, seq
  private:
    String _apikey;
    String _url;
    char* _host;
    int _httpPort;   
    int _seq = 0;
};

#endif
