#include "NewsObj.hpp"

using namespace std;

	string title;
	string description;
	string publishedAt;
	string urlLink;


	/**
	 * @brief      Constructs a new instance.
	 *
	 * @param[in]  titleString  The title string
	 * @param[in]  desString    The description string
	 * @param[in]  pubString    The pub string
	 * @param[in]  urlString    The url string
	 */
	NewsObj::NewsObj(std::string titleString, std::string desString, std::string pubString, std::string urlString){
		title = titleString;
		description = desString;
		publishedAt = pubString;
		urlLink = urlString;
	}

	/**
	 * @brief      Destroys the object.
	 */
	NewsObj::~NewsObj(){

	}

	/**
	 * @brief      Gets the title.
	 *
	 * @return     The title.
	 */
	string NewsObj::get_title(){
		return title;
	}

	/**
	 * @brief      Gets the descrip.
	 *
	 * @return     The descrip.
	 */
	string NewsObj::get_descrip(){
		return description;
	}

	/**
	 * @brief      Gets the date.
	 *
	 * @return     The date.
	 */
	string NewsObj::get_date(){
		return publishedAt;
	}

	/**
	 * @brief      Gets the url.
	 *
	 * @return     The url.
	 */
	string NewsObj::get_url(){
		return urlLink;
	}
