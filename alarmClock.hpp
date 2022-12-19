#ifndef ALARMOBJECT_H
#define ALARMOBJECT_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <future>
#include <chrono>
#include <list>
#include <memory>
#include <thread>
#include <mutex>
#include <atomic>


#include "time.h"

class alarmClock{
private:
    tm alarmtime, local, diffalarm;
    time_t now;
    std::string alarmname;
    //test
    std::atomic<bool> running;
    std::atomic<bool> renderedText;
    std::mutex inputMutex;
    std::mutex alarmMutex;
    std::thread alarmThread;     //thread for creating alarms
    std::thread inputThread;
    int result;

    void renderText();

public:
    alarmClock(std::string alarmName, std::vector<std::string> timeList);
    alarmClock();
    ~alarmClock();
    void difference();
    void startAlarm();
    std::string getAlarmName(){ return alarmname;}
    inline void quit();
    void deleteAlarm(std::string name);
    void input();
    void Result();
    int getResult(){return result;}
    //void getUserInput();
    //void checkAlarmname(std::string input);
};

#endif
