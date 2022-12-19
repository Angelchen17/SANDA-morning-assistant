#include "event.h"
#include <time.h>


/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  event_name         The event name
 * @param[in]  event_date         The event date
 * @param[in]  event_description  The event description
 */
myevent::myevent(string event_name, string event_date, string event_description)
{
    name = event_name;
    //int year,month,dd,hh,mm,ss;
    struct tm ed;

    strptime(event_date.c_str(),"%Y/%m/%d %H:%M:%S",&ed);
    date = ed;
    cout<<"tm output:"<<ed.tm_year<<"/"<<ed.tm_mon<<"/"<<ed.tm_mday<<endl;
    description = event_description;
}


/**
 * @brief      Destroys the object.
 */
myevent::~myevent()
{
}


/**
 * @brief      Gets the name.
 *
 * @return     The name.
 */
string myevent::get_name()
{
    return name;
}


/**
 * @brief      Gets the date.
 *
 * @return     The date.
 */
string myevent::get_date()
{
    char dateString[100];
    strftime(dateString, sizeof(dateString), "%Y/%m/%d %H:%M:%S", &date);
    return dateString;
}


/**
 * @brief      Gets the description.
 *
 * @return     The description.
 */
string myevent::get_description()
{
    return description;
}

/**
 * @brief      { function_description }
 *
 * @return     { description_of_the_return_value }
 */
int myevent::daysUntil(){
    time_t t = mktime(&date);
    time_t n = time(0);
    double difference = difftime(t,n)/ (60 * 60 * 24);
    return int(difference);
}

/**
 * @brief      Sets the name.
 *
 * @param[in]  event_name  The event name
 */
void myevent::set_name(string event_name)
{
    name = event_name;
}

/**
 * @brief      Sets the date.
 *
 * @param[in]  event_date  The event date
 */
void myevent::set_date(string event_date)
{
    //int year,month,dd,hh,mm,ss;
    struct tm ed;

    //const char *zStart = event_date.c_str();
    /*
    sscanf(zStart, "%d/%d/%d %d:%d:%d", &year, &month, &dd, &hh, &mm, &ss);
    ed.tm_year = year - 1900;
    ed.tm_mon = month - 1;
    ed.tm_mday = dd;
    ed.tm_hour = hh;
    ed.tm_min = mm;
    ed.tm_sec = ss;
    ed.tm_isdst = -1;
    */
    strptime(event_date.c_str(),"%Y/%m/%d %H:%M:%S",&ed);
    date = ed;
}

/**
 * @brief      Sets the description.
 *
 * @param[in]  event_description  The event description
 */
void myevent::set_description(string event_description)
{
    description = event_description;
}
