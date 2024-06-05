#pragma once

#include <vector>
#include <string>
#include "Attraction.h"
#include "FilterStrategy.h"

using namespace std;

// declaring to avoid circular dep.
class AttractionListContext;

class AttractionListState {
public:
    virtual void handle(AttractionListContext* context, const string& x) = 0;
};

class FilteredState : public AttractionListState { // concrete State
private:
    FilterStrategy* filterStrategy;

public:
    FilteredState(FilterStrategy* strategy)
    {
        this->filterStrategy = strategy;
    }

    void handle(AttractionListContext* context, const string& x) override;
};
