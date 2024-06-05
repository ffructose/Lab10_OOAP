#pragma once
//  ������ Template Method ������� ������ ��������� � �����,
//  ��������� ���������� ������ ����� ��������.
//  �� �������� �������� ������������� ���� ����� ��������� ��� ���� ���� ���������.

#include <vector>
#include "MapPoint.h"

using namespace std;

// general algortithm for map points displaying on map
class MapDisplayTemplate {
public:
    void displayMap(const vector<MapPoint*>& objects) const {
        for (const auto& object : objects) {
            object->draw();
            object->display();
        }
    }
};
