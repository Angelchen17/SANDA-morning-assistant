#include "weather.hpp"

    std::string city;
    std::string localtm;
    std::string temp;
    std::string feel;

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
std::size_t callback(const char* in,std::size_t size,std::size_t num, std::string* out)
{
    const std::size_t totalBytes(size * num);
    out->append(in, totalBytes);
    return totalBytes;
}


/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  location  The location
 */
weather::weather(std::string location){

    const std::string url("http://api.weatherstack.com/current?access_key=7aab90ab86a338c3d93e978fa580ed12&query="+location);

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
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);

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
        Json::Value jsonData;
        Json::Reader jsonReader;

    
        if (jsonReader.parse(*httpData.get(), jsonData))
        {
            
            std::cout << "Successfully parsed JSON data" << std::endl;
            std::cout << "\nJSON data received:" << std::endl;
            std::cout << jsonData.size() << std::endl;
            std::cout << jsonData.toStyledString() << std::endl;

            city = jsonData["location"]["name"].asString();
            localtm = jsonData["location"]["localtime"].asString();
            temp = jsonData["current"]["temperature"].asString();
            feel = jsonData["current"]["feelslike"].asString();



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
weather::~weather(){
}

/**
 * @brief      Gets the city.
 *
 * @return     The city.
 */
std::string weather::get_city(){
    return city;
}

/**
 * @brief      Gets the time.
 *
 * @return     The time.
 */
std::string weather::get_time(){
    return localtm;
}

/**
 * @brief      Gets the temporary.
 *
 * @return     The temporary.
 */
std::string weather::get_temp(){
    return temp;
}

/**
 * @brief      Gets the feel.
 *
 * @return     The feel.
 */
std::string weather::get_feel(){
    return feel;
}


//int main(){
//    std::string city = "Toronto";
//    weather Createweather(city);
//    std::string locationWeather = Createweather.get_city();
//    std::string currentTemp = Createweather.get_temp();
//    std::cout << "the temperature at " << locationWeather << " is: " << currentTemp << std::endl;

//    return 0;
//}

