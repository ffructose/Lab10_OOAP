#pragma once
//  ������ Command ���������� ����� �� ��'���,
//  ���������� ��������������� �볺��� � ������ ��������,
//  ��������� ��� ���������� ������.


#include <vector>
#include <algorithm>
#include "MapPoint.h"

using namespace std;

class Command {
public:
    virtual void execute() = 0;
};

class AddCommand : public Command {
private:
    vector<MapPoint*>& points;
    MapPoint* point;

public:
    AddCommand(vector<MapPoint*>& objs, MapPoint* obj) : points(objs), point(obj) {}

    void execute() override {
        points.push_back(point);
        cout << "������ �����: " << point->name << endl;
    }
};

class RemoveCommand : public Command {
private:
    vector<MapPoint*>& points;
    MapPoint* point;

public:
    RemoveCommand(vector<MapPoint*>& objs, MapPoint* obj) : points(objs), point(obj) {}

    void execute() override {
        points.erase(remove(points.begin(), points.end(), point), points.end());
        cout << "�������� �����: " << point->name << endl;
    }
};
