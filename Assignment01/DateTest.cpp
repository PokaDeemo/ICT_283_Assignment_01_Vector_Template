#include <iostream>
#include "Date.h"

using namespace std;

int main()
{
    //cout << myResult << endl;

    Date myDate;
    myDate.SetDay(26);
    myDate.SetMonth(12);
    myDate.SetYear(2022);

    myDate.ConvertMonth(12);

    cout << myDate.ConvertMonth(12) <<endl;
    cout << myDate.GetDay() << endl;
    cout << myDate.GetMonth() << endl;
    cout << myDate.GetYear() << endl;
    cout << myDate <<endl;

    return 0;
}
