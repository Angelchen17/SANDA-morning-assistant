#include "nlohmann/json.hpp"
#include <fstream>
#include <iostream>
//#include "getGCal.h"
#include "event.h"
#include <cstring>

/// for convenience
using myjson = nlohmann::json;



/**
 * @brief      { return google calendar events }
 *
 * @return     { return a list of google calendar events, or NULL if nothing was found }
 */
vector <myevent> ListGCal (void){
    std::ifstream f("data.json");
    myjson data = myjson::parse(f);
    vector <myevent> event_list;

    //std::cout<<data.dump(4)<<std::endl;

    for (auto& el : data.items())
    {
        string date = el.value()["date"];
        string name = el.value()["name"];
        string description = el.value()["description"];

        myevent new_event(name, date, description);
        event_list.push_back(new_event);
    }

    return event_list;

}
