#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include "Attraction.h"

using namespace std;

class FilterStrategy {
public:
    virtual void filter(vector<Attraction*>& attractions, const string& x) = 0;
};

class DateFilterStrategy : public FilterStrategy {
public:
    void filter(vector<Attraction*>& attractions, const string& date) override {
        attractions.erase(remove_if(attractions.begin(), attractions.end(), [&date](Attraction* attr) {
            return attr->date != date;
            }), attractions.end());
    }
};

class StatusFilterStrategy : public FilterStrategy {
public:
    void filter(vector<Attraction*>& attractions, const string& status) override {
        attractions.erase(remove_if(attractions.begin(), attractions.end(), [&status](Attraction* attr) {
            return attr->status != status;
            }), attractions.end());
    }
};
