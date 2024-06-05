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
    MapPoint* attraction1 = new Attraction("�i��� ���", "���� �������");
    MapPoint* restaurant1 = new Restaurant("����i���", "��i��� ��������������");

    Command* addAttractionCmd = new AddCommand(mapPoints, attraction1);

    addAttractionCmd->execute();

    // map
    MapDisplayTemplate mapDisplay;
    cout << endl << "���� ����� ������i��i�:" << endl;
    mapDisplay.displayMap(mapPoints);

    // add
    Command* addRestaurantCmd = new AddCommand(mapPoints, restaurant1);
    addRestaurantCmd->execute();

    // map
    cout << endl << "\n���� ����� ������i��i� �i��� ��������� �����:" << endl;
    mapDisplay.displayMap(mapPoints);

    // delete
    Command* removeRestaurantCmd = new RemoveCommand(mapPoints, restaurant1);
    removeRestaurantCmd->execute();

    // map
    cout << endl << "\n���� ����� ������i��i� �i��� ��������� �����:" << endl;
    mapDisplay.displayMap(mapPoints);

    
    delete attraction1;
    delete restaurant1;
    delete addAttractionCmd;
    delete addRestaurantCmd;
    delete removeRestaurantCmd;

    return 0;
}
