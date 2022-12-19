#include "news.hpp"

int num;
std::vector<NewsObj> newsList;

/**
 * @brief      { function_description }
 *
 * @param[in]  in    { parameter_description }
 * @param[in]  size  The size
 * @param[in]  num   The number
 * @param      out   The out
 *
 * @return     { description_of_the_return_value }
 */
std::size_t callback1(const char* in, std::size_t size, std::size_t num, std::string* out)
{
    const std::size_t totalBytes(size * num);
    out->append(in, totalBytes);
    return totalBytes;
}



/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  numOfNews  The number of news
 */
news::news(int numOfNews){
    num = numOfNews;
    const std::string url("https://newsapi.org/v2/top-headlines?country=ca&pageSize="+std::to_string(num)+"&apiKey=8898ac7732da465da569057d43d2bc9c");

    CURL* curl = curl_easy_init();

    // Set remote URL.
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

    // Don't bother trying IPv6, which would increase DNS resolution time.
    curl_easy_setopt(curl, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V4);

    // Don't wait forever, time out after 10 seconds.
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);

    // // Follow HTTP redirects if necessary.
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    // Response information.
    long httpCode(0);

    std::unique_ptr<std::string> httpData(new std::string());


    // Hook up data handling function.
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback1);

    // Hook up data container (will be passed as the last parameter to the
    // callback handling function).  Can be any pointer type, since it will
    // internally be passed as a void pointer.

    curl_easy_setopt(curl, CURLOPT_WRITEDATA, httpData.get());


    // Run our HTTP GET command, capture the HTTP response code, and clean up.
    curl_easy_perform(curl);
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
    curl_easy_cleanup(curl);



    if (httpCode == 200)
    {
        // parse the result
        Json::Value jsonData(Json::arrayValue);
        Json::Reader jsonReader;

    
        if (jsonReader.parse(*httpData.get(), jsonData))
        {
            for (int i = 0; i < num; i++)
            {
              /* code */
              std::string titleString(jsonData["articles"][i]["title"].asString());
              std::string descripString(jsonData["articles"][i]["description"].asString());
              std::string dateString(jsonData["articles"][i]["publishedAt"].asString());
              std::string urlString(jsonData["articles"][i]["url"].asString());
              NewsObj newNews(titleString,descripString,dateString,urlString);
              newsList.push_back(newNews);

            }

        }
        else
        {
            std::cout << "Could not parse HTTP data as JSON" << std::endl;
            std::cout << "HTTP data was:\n" << *httpData.get() << std::endl;
        }
    }
    else
    {
        std::cout << "Couldn't GET from " << url << " - exiting" << std::endl;
    }
}

/**
 * @brief      Destroys the object.
 */
news::~news(){

}

/**
 * @brief      Gets the news.
 *
 * @return     The news.
 */
std::vector<NewsObj> news::get_news(){
    return newsList;
}

// int main(){
//         int nums = 2;
//         // create a new object createnews storing the news fetch from api
//         news createnews(nums);
//         createnews.get_news();
//         return 0;
// }
