#include <iostream>
#include <vector>
#include "MapPoint.h"
#include "Command.h"
#include "TemplateMethod.h"

using namespace std;

int main() {
    setlocale(LC_CTYPE, "ukr");

    vector<MapPoint*> mapPoints;

    // creating map points
    MapPoint* attraction1 = new Attraction("гiрка пес", "дуже страшна");
    MapPoint* restaurant1 = new Restaurant("Вернiсаж", "елiтне обслуговування");

    Command* addAttractionCmd = new AddCommand(mapPoints, attraction1);

    addAttractionCmd->execute();

    // map
    MapDisplayTemplate mapDisplay;
    cout << endl << "Мапа парку атракцiонiв:" << endl;
    mapDisplay.displayMap(mapPoints);

    // add
    Command* addRestaurantCmd = new AddCommand(mapPoints, restaurant1);
    addRestaurantCmd->execute();

    // map
    cout << endl << "\nМапа парку атракцiонiв пiсля додавання точки:" << endl;
    mapDisplay.displayMap(mapPoints);

    // delete
    Command* removeRestaurantCmd = new RemoveCommand(mapPoints, restaurant1);
    removeRestaurantCmd->execute();

    // map
    cout << endl << "\nМапа парку атракцiонiв пiсля видалення точки:" << endl;
    mapDisplay.displayMap(mapPoints);

    
    delete attraction1;
    delete restaurant1;
    delete addAttractionCmd;
    delete addRestaurantCmd;
    delete removeRestaurantCmd;

    return 0;
}
