#pragma once

#include <string>
#include <iostream>

using namespace std;

class MapPoint {
public:
    string name;
    string description;

    virtual void display() const = 0;
    virtual void draw() const = 0;
};

class Attraction : public MapPoint {
public:
    Attraction(string n, string d) {
        name = n;
        description = d;
    }

    void display() const override {
        cout << "Атракцiон: " << name << ", Опис: " << description << endl;
    }

    void draw() const override {
        
        cout << "Малювання атракцiону: " << name << endl;
    }
};

class Restaurant : public MapPoint {
public:
    Restaurant(string n, string d) {
        name = n;
        description = d;
    }

    void display() const override {
        cout << "Ресторан: " << name << ", Опис: " << description << endl;
    }

    void draw() const override {
        
        cout << "Малювання ресторану: " << name << endl;
    }
};

