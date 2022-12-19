#include "calendar.hpp"

using namespace std;

//vector <event> event_list;

/**
 * @brief      Constructs a new instance.
 */
Calendar::Calendar(){
   vector<myevent> e;
   event_list=e;
}

/**
 * @brief      Destroys the object.
 */
Calendar::~Calendar(){

}

/**
 * @brief      Adds an event.
 *
 * @param[in]  event_name         The event name
 * @param[in]  event_date         The event date
 * @param[in]  event_description  The event description
 *
 * @return     { return 0 if successful, return -1 if failed }
 */
int Calendar::AddEvent(string event_name, string event_date, string event_description){
   int check;
   int year,month,day,hour,minute,second;
   check = sscanf(event_date.c_str(),"%d/%d/%d %d:%d:%d",&year,&month,&day,&hour,&minute,&second);
   if(check==-1){
      return -1;
   }else{
      if(year<1900 || year >3000){
         return -1;
      }
      if(month<1 || month>12){
         return -1;
      }
      if(day<1 || day>31){
         return -1;
      }
      if(hour<0 || hour>23){
         return -1;
      }
      if(minute<0 || minute>59){
         return -1;
      }
      if(second<0 || second>59){
         return -1;
      }
      cout<<"year: "<<year<<" month: "<<month<<" day: "<<day<<"\n"<<endl;
      cout<<"date: "<<event_date<<"\n"<<endl;
      myevent new_event(event_name,event_date,event_description);
      event_list.push_back(new_event);
      cout<<"event "<<event_name<<" added sucessfully to the calendar!\n"<<endl;
      return 0;
   }
}

/**
 * @brief      { delete event by searching for the name of the event }
 *
 * @param[in]  event_name  The event name
 *
 * @return     { return 0 if sucessful, return -1 if failed }
 */
int Calendar::DeleteEvent(string event_name){
   if (event_list.size() == 0)
         {
            cout << "There is no event in the list.\n";
            return -1;
         }

         /*
         string name;
         cout << "Please enter the event name\n";
         cin >> name;
         */
         int found = 0;
         int counter = 0;

         while (event_list.size() != 0 && counter < event_list.size())
         {

            if (event_list[counter].get_name() == event_name)
            {
               found ++;
               if (counter == event_list.size())
               {
                  event_list.pop_back();
               }

               else
               {
                  for (int k = counter; k < event_list.size()-1; k ++)
                  {
                     event_list[k] = event_list[k+1];
                  }
                  event_list.pop_back();
               }
            }
            counter ++;
         }

         if (found == 0)
         {
            cout << " No matching event was found" << "\n";
            return -1;
         }

         else
         {
            cout << "We have deleted " << found << " event(s) named " << event_name << "\n";
            return 0;
         }
}

/**
 * @brief      { return a vector list of event to be viewed }
 *
 * @return     { return a vector list of event }
 */
vector<myevent> Calendar::ViewEvents(){
   return event_list;
}

/**
 * @brief      { return google events }
 *
 * @return     { return a vector list of google events }
 */
vector<myevent> Calendar::GoogleEvents(){
   vector <myevent> google_events;
   google_events = ListGCal();
   return google_events;
}

/**
 * @brief      { edit event }
 *
 * @param[in]  name         The name
 * @param[in]  newName      The new name
 * @param[in]  date         The date
 * @param[in]  description  The description
 *
 * @return     { return 0 if succesful, -1 if failed }
 */
int Calendar::EditEvent(string name, string newName = "", string date="", string description = "" ){
    //cout<<"hi\n"<<endl;
    if (event_list.size() == 0)
         {
            cout << "There is no event in the list.\n";
            return -1;
         }

         /*
         string name;
         cout << "Please enter the event name\n";
         cin >> name;
         */
         int found = 0;
         int counter = 0;

         while (event_list.size() != 0 && counter < event_list.size())
         {

            if (event_list[counter].get_name() == name)
            {
               found ++;
               cout<<"found!\n"<<endl;
               /*
               string newName;
               string newDate;
               string newHour;
               string newDescription;
               char datetime[100];

               cout << "Please enter new event name\n";
               cin >> newName;

               event_list[counter].set_name(newName);

               cout << "Please enter the new event date in the format YYYY/MM/DD\n";
               cin >> newDate;
               cout << "Please enter the new event time in the format 00:00:00\n";
               cin >> newHour;
               sprintf(datetime,"%s %s",newDate.c_str(),newHour.c_str());
               string s =datetime;
               event_list[counter].set_date(s);

               cout << "Please enter new event description\n";
               cin >> newDescription;
               event_list[counter].set_description(newDescription);
               */
               if(newName!=""){
                  event_list[counter].set_name(newName);
               }
               if(date!=""){
                  cout<<"changing date\n"<<endl;
                  int check;
                  int year,month,day,hour,minute,second;
                  check = sscanf(date.c_str(),"%d/%d/%d %d:%d:%d",&year,&month,&day,&hour,&minute,&second);
                  if(check==-1){
                     cout<<"change date error\n";
                  }
                  else{event_list[counter].set_date(date);}
               }
               if(description!=""){
                   cout<<"changing description\n"<<endl;
                  event_list[counter].set_description(description);
               }
            }
            counter ++;
         }

         if (found == 0)
         {
            cout << " No matching event was found" << "\n";
            return -1;
         }

         else
         {
            cout << "We have edited " << found << " event(s) named " << name << "\n";
            return 0;
         }
}

//int main()
//{
//   string command;

//   // Date for the welcoming message.
//   time_t now = time(0);
//   char* full_time = ctime(&now);
//   string newtime = (string)full_time;
//   string now1 = newtime.substr(4,6) + ", " + newtime.substr(20,4);

//   Calendar* myCal = new Calendar();
//   cout << "Welcome to the calender.\nThe current date is: " << now1 << endl << "\n";

//   // Receive command.
//   cout << "Please enter a command:\n1 to add event\n2 to delete event\n3 to view all events\n4 to view google events\n5 to edit events\ne to exit\n";
//   cin >> command;

//   // Perform the actions below while the the command is not "e".
//   while (command != "e")
//   {

//      // Add an event.
//      if (command == "1")
//      {
//         string name;
//         string date;
//         string description;
//         string hour;
//         char datetime[100];
//         cout << "Please enter the event name\n";
//         cin >> name;
//         cout << "Please enter the event date in the format YYYY/MM/DD\n";
//         cin >> date;
//         cout << "Please enter the event time in the format 00:00:00\n";
//         cin >> hour;
//         sprintf(datetime,"%s %s",date.c_str(),hour.c_str());
//         //cout << "date time: "<<datetime<<endl;

//         cout << "Please enter the event description\n";
//         cin >> description;

//         string s = datetime;
//         myCal->AddEvent(name,s,description);
//      }

//      // Remove an event.
//      if (command == "2")
//      {

//         string name;
//         cout << "Please enter the event name\n";
//         cin >> name;

//        int r = myCal->DeleteEvent(name);
//        if(r!=0){
//         cout<<"delete failed\n";
//        }
//         /*
//         int found = 0;
//         int counter = 0;

//         while (event_list.size() != 0 && counter < event_list.size())
//         {

//            if (event_list[counter].get_name() == name)
//            {
//               found ++;
//               if (counter == event_list.size())
//               {
//                  event_list.pop_back();
//               }

//               else
//               {
//                  for (int k = counter; k < event_list.size()-1; k ++)
//                  {
//                     event_list[k] = event_list[k+1];
//                  }
//                  event_list.pop_back();
//               }
//            }
//            counter ++;
//         }

//         if (found == 0)
//         {
//            cout << " No matching event was found" << "\n";
//         }

//         else
//         {
//            cout << "We have deleted " << found << " event(s) named " << name << "\n";
//         }*/
//      }

//      // List all events.
//      if (command == "3")
//      {
//         vector<event> list = myCal->ViewEvents();
//         if (list.size() == 0)
//         {
//            cout << "There is no event in the list.\n";
//            goto NEXT;
//         }

//         for (int i = 0; i < list.size(); i++)
//         {
//            cout << "\nEvent name: " << list[i].get_name() <<"\nEvent date: " << list[i].get_date() << "\nEvent description: " << list[i].get_description() <<"\nDays until event: " << list[i].daysUntil() <<"\n";
//         }
//      }

//      if (command == "4")
//      {
//         vector <event> google_events;
//         google_events = myCal->GoogleEvents();
//         if (google_events.size() == 0)
//         {
//            cout << "There is no event in the list.\n";
//            goto NEXT;
//         }

//         for (int i = 0; i < google_events.size(); i++)
//         {
//            cout << "\nEvent name: " << google_events[i].get_name() <<"\nEvent date: " << google_events[i].get_date() << "\nEvent description: " << google_events[i].get_description() <<"\n";
//         }
//      }


//      if (command == "5")
//      {
//         /*
//         if (event_list.size() == 0)
//         {
//            cout << "There is no event in the list.\n";
//            goto NEXT;
//         }
//         */

//         string name;
//         string newName;
//         string newDate;
//         string newHour;
//         string newDescription;
//         char datetime[100];
//         cout << "Please enter the event name\n";
//         cin >> name;
//         cout<<"Please enter new name to be changed, if not leave blank\n";
//         cin >> newName;
//         cout<<"Please enter new day to be changed in the format YYYY/MM/DD, if not leave blank\n";
//         cin >> newDate;
//         if(newDate==""){
//            cout<<"Please enter new hour to be changed in the format HH:MM:SS, if not leave blank\n";
//            cin >> newHour;
//            sprintf(datetime,"%s %s",newDate.c_str(),newHour.c_str());
//            newDate=datetime;
//         }
//         cout<<"Please enter new description, if not leave blank\n";
//         cin >> newDescription;

//         int r = myCal->EditEvent(name,newName,newDate,newDescription);
//         if(r!=0){
//            cout<<"Edit failed\n";
//         }

//         /*
//         int found = 0;
//         int counter = 0;

//         while (event_list.size() != 0 && counter <= event_list.size())
//         {

//            if (event_list[counter].get_name() == name)
//            {
//               found ++;
//               string newName;
//               string newDate;
//               string newHour;
//               string newDescription;
//               char datetime[100];

//               cout << "Please enter new event name\n";
//               cin >> newName;

//               event_list[counter].set_name(newName);

//               cout << "Please enter the new event date in the format YYYY/MM/DD\n";
//               cin >> newDate;
//               cout << "Please enter the new event time in the format 00:00:00\n";
//               cin >> newHour;
//               sprintf(datetime,"%s %s",newDate.c_str(),newHour.c_str());
//               string s =datetime;
//               event_list[counter].set_date(s);

//               cout << "Please enter new event description\n";
//               cin >> newDescription;
//               event_list[counter].set_description(newDescription);


//            }
//            counter ++;
//         }

//         if (found == 0)
//         {
//            cout << " No matching event was found" << "\n";
//         }

//         else
//         {
//            cout << "We have edited " << found << " event(s) named " << name << "\n";
//         }
//         */
//      }

//NEXT:
//      cout << "\nPlease enter a command:\n1 to add event\n2 to delete event\n3 to view all events\n4 to view google events\n5 to edit events\ne to exit\n";
//      cin >> command;
//   }
//}
