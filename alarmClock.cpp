
#include "alarmClock.hpp"

using namespace std;

tm alarmtime,diffalarm;
time_t now = time(0);
tm local = *localtime(&now);
string alarmname;
atomic<bool> running;
atomic<bool> renderedText;
mutex inputMutex;
mutex alarmMutex;
thread alarmThread;     //thread for creating alarms
thread inputThread;     //thread for reading inputs (to delete alarm)
int result;

/**
 * @brief      Displays the running alarm text.
 */
void alarmClock::renderText(){ // alarm prompt when starting the alarm
    if(!renderedText) {
        renderedText = true;
        //cout << alarmname << " alarm" << " at " << alarmtime.tm_hour << ":" << alarmtime.tm_min << " is running ... " << endl;
        cout << "Alarm is running. Type the alarm name to delete the alarm." << endl;
    }
}

/* constructor
 *
 * @param[in]  alarmName  The alarm name
 * @param[in]  timeList   The time list
 */
alarmClock::alarmClock(string alarmName, vector<string> timeList) : running(true), renderedText(false),
    alarmThread(&alarmClock::startAlarm, this),inputThread(&alarmClock::input, this)
{
    now = time(0);
    local = *localtime(&now);
    alarmtime = local;	//set the alarm time orginally to current time

    alarmname = alarmName;

    int mm = stoi(timeList[1]);
    int hh = stoi(timeList[0]);

    alarmtime.tm_sec = 0;
    alarmtime.tm_min = mm;
    alarmtime.tm_hour = hh;

    result =0;
}

void alarmClock::Result(){
    result =1;
}

alarmClock::alarmClock(){}

/**
 * @brief      Destroys the object and threads.
 */
alarmClock::~alarmClock(){
    inputThread.join();
    alarmThread.join();
}

/**
 * @brief      Sets running to false to quit the program.
 */
inline void alarmClock::quit() {
    running = false;
}

void alarmClock::deleteAlarm(string name){
//    if (name == alarmname){
    cout << "delete success" << endl;
    quit();
//    }
}

/**
 * @brief      Starts an alarm.
 */
void alarmClock::startAlarm(){
    while (running) {
        lock_guard<mutex> locker(alarmMutex);
        renderText();   //send alarm prompt
        now = time(0);
        local = *localtime(&now);
        difference();
        if (diffalarm.tm_hour == 0 && diffalarm.tm_min == 0 && diffalarm.tm_sec == 0){
            // when the time difference becomes 0, start the alarm
            cout << '\a';
            cout<<endl<<"<<<<<< Alarm: " << alarmname << " - Time is up! >>>>>>"<<endl<<endl;
            cout << "Press any key to close the alarm" << endl;
            Result();
            //QMessageBox::information(this,"Message", "Time is up!", QMessageBox::Ok);
            quit();
        }
    }
}

/**
 * @brief      Gets the input from user.
 */
void alarmClock::input() {
//    while (running) {
//        lock_guard<mutex> locker(inputMutex);
//        getUserInput();
//    }
}

///**
// * @brief      Wait for user input.
// */
//void alarmClock::getUserInput() {
//    string input;
//    getline(cin, input);
//    checkAlarmname(input);
//}

///**
// * @brief      Check if the user input matches the alarm name.
// */
//void alarmClock::checkAlarmname(string input) { //delete alarm
//    if (input == alarmname){ //if alarm name is true
//        cout << "Alarm deleted successfully" << endl;
//        quit();
//    }
//}

/**
 * @brief      Calculate the time difference between alarm time and the real time.
 */
void alarmClock::difference(){
    now = time(0);
    local = *localtime(&now);
    int diff = difftime(mktime(&alarmtime),mktime(&local)); //return the difference in time in seconds
    diffalarm.tm_sec = diff % 60;
    int timeInMin = diff / 60; //calculate the difference in minutes
    diffalarm.tm_hour = timeInMin / 60;
    diffalarm.tm_min = timeInMin % 60;
    if (diff < 0)
    {
        /* if the difference is less than 0, it is the alarm for next day */
        diffalarm.tm_hour = 23 + diffalarm.tm_hour;
        diffalarm.tm_min = 0 - diffalarm.tm_min;
        diffalarm.tm_sec = 0 - diffalarm.tm_sec;
    }
}
