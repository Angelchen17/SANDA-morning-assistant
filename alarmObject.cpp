
#include "alarmObject.hpp"

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

//helper classes
void alarmObject::renderText(){ // alarm prompt when starting the alarm
    if(!renderedText) {
        renderedText = true;
		cout << alarmname << " alarm" << " at " << alarmtime.tm_hour << ":" << alarmtime.tm_min << " is running ... " << endl;
		cout << "Type the alarm name to delete the alarm." << endl;
    }
}

//constructor
alarmObject::alarmObject(string alarmName, vector<string> timeList) : running(true), renderedText(false),
    alarmThread(&alarmObject::startAlarm, this),inputThread(&alarmObject::input, this) 
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
}

//destructor
alarmObject::~alarmObject(){
    inputThread.join();
    alarmThread.join();
}

//to quit the program
inline void alarmObject::quit() {
    running = false;
}

void alarmObject::startAlarm(){
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
			quit();
        }
    }
}

void alarmObject::input() {  //deleteAlarm thread
    while (running) {
        lock_guard<mutex> locker(inputMutex);
        getUserInput();  //deleteAlarm prompt
    }
}

//if with the list: get input from the start class
void alarmObject::getUserInput() { //get prompt
    string input;
    getline(cin, input);	
    checkAlarmname(input); 
}


void alarmObject::checkAlarmname(string input) { //delete alarm
    if (input == alarmname){ //if alarm name is true
        cout << "Alarm deleted successfully" << endl; 
        quit();
    }
}

void alarmObject::difference(){
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