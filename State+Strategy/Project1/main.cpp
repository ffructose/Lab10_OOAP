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
    context.addAttraction(new Attraction(" ���", "���� �������", 12, "2004-06-21", "������"));
    context.addAttraction(new Attraction(" �����", "���", 8, "2004-06-21", "�������"));
    context.addAttraction(new Attraction(" �i�", "���", 10, "2004-06-21", "������"));
    context.addAttraction(new Attraction(" ���i����", "���", 10, "2004-06-21", "�������"));
    context.addAttraction(new Attraction(" ��i�", "���", 10, "2004-06-22", "�������"));
    context.addAttraction(new Attraction(" ����", "���", 10, "2004-06-23", "������"));
    context.addAttraction(new Attraction(" ��i���", "���", 10, "2004-06-24", "������"));

    // Filter by date
    FilterStrategy* dateFilter = new DateFilterStrategy();
    AttractionListState* filteredByDate = new FilteredState(dateFilter);
    context.setState(filteredByDate);
    context.apply("2004-06-21");

    cout << "\n������ ������i��i�, �i���������� �� ����� 2004-06-21:" << endl;
    context.display();

    // Filter by status
    FilterStrategy* statusFilter = new StatusFilterStrategy();
    AttractionListState* filteredByStatus = new FilteredState(statusFilter);
    context.setState(filteredByStatus);
    context.apply("������");

    cout << "\n������ ������i��i�, �i���������� �� �������� '������':" << endl;
    context.display();

    // Clean up
    delete dateFilter;
    delete filteredByDate;
    delete statusFilter;
    delete filteredByStatus;

    return 0;
}
