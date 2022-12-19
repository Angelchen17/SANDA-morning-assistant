//#include "event.h"
#include "getGCal.h"

using namespace std;
class Calendar{
    private:
    vector <myevent> event_list;
    
    public:
    Calendar();
    ~Calendar();
    int AddEvent(string name, string date, string description);
    int DeleteEvent(string name);
    vector<myevent> ViewEvents();
    //int DaysUntil(string name);
    vector<myevent> GoogleEvents();
    int EditEvent(string name, string newName , string date, string description);

};
