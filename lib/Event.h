#include "Base.h"
using namespace std;

//Record the result for each event.
typedef struct eventResult {
    string title;
    string text;
    int deltaScore[IDX_CULTURE_MAX_COUNT];
    int deltarRegularScore[IDX_CULTURE_MAX_COUNT];
} EventResult;

//Record all event could happened
typedef struct eventInfo {
    string title;
    string text;
    int probabiltyNumerator;
    int probabiltyDenominator;
    //Type of culture, value is parameter index which define at Base.h
    int type;
    double impactForCulture[IDX_CULTURE_MAX_COUNT];
} EventInfo;

class EventEngine {
public:
    //Constructor
    EventEngine();
    //Load event script from file
    bool loadEventScript();
    //Calculate and one event happened
    int triggerOneEvent();
    //Calculate and sequence event happened
    int triggerSequenceEvent();
private:
    vector< vector<EventInfo> > eventPool;
    //Record the happened tiems about each types event.
    int eventHappenCount[IDX_CULTURE_MAX_COUNT];
    //Record the delta value about event happened probability for each type
    double deltaOfEventHappened[IDX_CULTURE_MAX_COUNT];
};
