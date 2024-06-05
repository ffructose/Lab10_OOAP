#include <iostream>
#include "Attraction.h"
#include "FilterStrategy.h"
#include "AttractionListState.h"
#include "AttractionListContext.h"

using namespace std;

int main() {
    setlocale(LC_CTYPE, "ukr");

    AttractionListContext context;

    // Add attractions
    context.addAttraction(new Attraction(" пес", "дуже страшна", 12, "2004-06-21", "працюЇ"));
    context.addAttraction(new Attraction(" жабка", "ква", 8, "2004-06-21", "закрито"));
    context.addAttraction(new Attraction(" кiт", "м€у", 10, "2004-06-21", "працюЇ"));
    context.addAttraction(new Attraction(" капiбара", "м€у", 10, "2004-06-21", "закрито"));
    context.addAttraction(new Attraction(" змiй", "м€у", 10, "2004-06-22", "закрито"));
    context.addAttraction(new Attraction(" Їжик", "м€у", 10, "2004-06-23", "працюЇ"));
    context.addAttraction(new Attraction(" шлiмак", "м€у", 10, "2004-06-24", "працюЇ"));

    // Filter by date
    FilterStrategy* dateFilter = new DateFilterStrategy();
    AttractionListState* filteredByDate = new FilteredState(dateFilter);
    context.setState(filteredByDate);
    context.apply("2004-06-21");

    cout << "\n—писок атракцiонiв, фiльтрований за датою 2004-06-21:" << endl;
    context.display();

    // Filter by status
    FilterStrategy* statusFilter = new StatusFilterStrategy();
    AttractionListState* filteredByStatus = new FilteredState(statusFilter);
    context.setState(filteredByStatus);
    context.apply("працюЇ");

    cout << "\n—писок атракцiонiв, фiльтрований за статусом 'працюЇ':" << endl;
    context.display();

    // Clean up
    delete dateFilter;
    delete filteredByDate;
    delete statusFilter;
    delete filteredByStatus;

    return 0;
}
