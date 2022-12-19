#ifndef WEATHER_H
#define WEATHER_H

#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <chrono>
#include <unistd.h>
#include <cstdint>
#include <iostream>
#include <memory>
#include <string>

#include <curl/curl.h>
#include <json/json.h>


class weather{
private:
    std::string city;
	std::string localtm;
	std::string temp;
	std::string feel;


public:

    weather(std::string location);
    
    ~weather();
    
    std::string get_city();
	std::string get_time();
	std::string get_temp();
	std::string get_feel();


};

#endif
