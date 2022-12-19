#ifndef EVENT_H
#define EVENT_H

//include statements
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//#include <sqlite3.h>
#include <string>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#include <cstring>
#include <ctime>

using namespace std;
class myevent
{

    //private variables declaration
    private:
    string name, description;
    tm date;

    //constructor and functions declaration
    public:
    myevent(string name, string date, string description);
    ~myevent();
    string get_name();
    string get_date();
    string get_description();
    int daysUntil();
    void set_name(string event_name);
    void set_date(string event_date);
    void set_description(string event_description);
};

#endif
