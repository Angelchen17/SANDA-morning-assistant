#ifndef NEWS_H
#define NEWS_H

#include <iostream>
#include <cstdint>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
 #include <sstream>
#include <curl/curl.h>
#include <json/json.h>
//#include "nlohmann/json.hpp"
#include "NewsObj.hpp"


class news{
private:
	int num;
	std::vector<NewsObj> newslist;

public:

    news(int numOfNews);
    
    ~news();
    
    std::vector<NewsObj> get_news();


};

#endif
