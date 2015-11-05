#include "Event.h"

EventEngine::EventEngine() {
    int i;
    printf("Construct of EventEngine\n");
    memset(eventHappenCount, 0, IDX_CULTURE_MAX_COUNT);
    memset(deltaOfEventHappened, 0, IDX_CULTURE_MAX_COUNT);
    eventPool.resize(IDX_CULTURE_MAX_COUNT);
    for(i = 0; i < IDX_CULTURE_MAX_COUNT; i++) {
        eventPool[i].clear();
    }
}

bool EventEngine::loadEventScript() {
    return true;
}

int EventEngine::triggerOneEvent() {
    return 0;
}

int EventEngine::triggerSequenceEvent() {
    int eventType = randomPositiveInt(0, IDX_CULTURE_MAX_COUNT - 1);
    cout << "event trigger: " << cultureIdxToString(eventType) << endl;
    return 0;
}
