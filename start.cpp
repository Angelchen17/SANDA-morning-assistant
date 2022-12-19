#include <signal.h>
#include "alarmObject.hpp"

using namespace std;

/**
 * Signal detect function
 * Exits when user hits ctrl c
 * @param signum gets the signal Ctrl C
 */
void signal_callback_handler(int signum) {
	cout << "Alarm function ends." << endl;
	exit(signum);
}

int start() {
    //vector<alarmObject> alarmList;	//create alarm list

	signal(SIGINT, signal_callback_handler);    //look for ctrl c

	//Start program, prompt for alarm name and time
	string input;
	cout << "Welcome to the alarm function!" << endl;
	cout << "Instructions:" << endl;
	cout << "To create an alarm, follow the prompts and enter time and name for the alarm." << endl;
	cout << "To delete an alarm, follow the prompts and enter the alarm name to delete." << endl;
	cout << "To end the alarm function, press Ctrl C." << endl;
	cout << " " << endl;

	//loop start

	//Get Alarm Name
	string inputname;  
	cout << "Please enter the name of the alarm: ";
	cin >> inputname;

	//Get Alarm Time and catch errors
	cout << "Enter alarm time in 24-hour format hh:mm: ";
	cin >> input;
	if (input.size() > 5 || input.size() < 3){
		/* if the time is not valide, restart the program  */
		cout << "Please enter a time in format 00:00 only." << endl;
		return 0;																//instead of return, change to loop. catch quit/ctrlC
	}
	string segment;
	stringstream makeStream(input);
	vector<string> inputlist;
	while(getline(makeStream, segment, ':')){
		inputlist.push_back(segment);
	}

	//if input not int - catch error

	int mm = stoi(inputlist[1]);
	int hh = stoi(inputlist[0]);

	if (mm > 59 || mm < 0)
	{
		/* if the time is not valide, restart the program  */
		cout << "Please enter a minute between 00-59!" << endl;
		return 0;
	}
	if (hh >= 24 || hh < 0)
	{
		/* if the time is not valide, restart the program  */
		cout << "Please enter an hour between 00-23!" << endl;
		return 0;
	}


	

	alarmObject newAlarm(inputname, inputlist);
	//alarmList.push_back(newAlarm);


    return 0;
}
