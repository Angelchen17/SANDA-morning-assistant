#ifndef NEWSOBJ_H
#define NEWSOBJ_H

#include <iostream>

class NewsObj
{
private:
	std::string title;
	std::string description;
	std::string publishedAt;
	std::string urlLink;
public:
	NewsObj(std::string titleString, std::string desString, std::string pubString, std::string urlString);
	~NewsObj();
	std::string get_title();
	std::string get_descrip();
	std::string get_date();
	std::string get_url();
};


#endif