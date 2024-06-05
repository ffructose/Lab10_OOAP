#pragma once

#include "AttractionListState.h"
#include <vector>

using namespace std;

class AttractionListContext {
private:
    vector<Attraction*> attractions;
    AttractionListState* state;

public:
    void setState(AttractionListState* newState) {
        this->state = newState;
    }

    void apply(const string& x) {
        if (state) {
            state->handle(this, x);
        }
    }

    void addAttraction(Attraction* attraction) {
        attractions.push_back(attraction);
    }

    vector<Attraction*>& getAttractions() {
        return attractions;
    }

    void display() const {
        for (const auto& attraction : attractions) {
            attraction->display();
        }
    }
};

// realization of method from class filteredstate 
void FilteredState::handle(AttractionListContext* context, const string& x) { 
    filterStrategy->filter(context->getAttractions(), x);
}
