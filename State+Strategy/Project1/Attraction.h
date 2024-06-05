#pragma once

#include <string>
#include <iostream>

using namespace std;

class Attraction {
public:
    string name;
    string description;
    int allowed_age;
    string date;
    string status;

    Attraction(string n, string d, int age, string dt, string st) {
        this->name = n;
        this->description = d;
        this->allowed_age = age;
        this->date = dt;
        this->status = st;
    }

    void display() const {
        cout << "������i��: " << name << ", ����: " << description << ", �i���� ���������: " << allowed_age
            << ", ����: " << date << ", ������: " << status << endl;
    }
};
