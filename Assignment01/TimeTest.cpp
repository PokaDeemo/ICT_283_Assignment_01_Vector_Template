#include <iostream>
#include "Time.h"

int main()
{
    Time myTime;

    myTime.SetHour(10);
    myTime.GetHour();
    myTime.SetMinute(25);
    myTime.GetMinute();

    cout <<"Test-Time: " << myTime.GetHour() << endl;
    cout << "Test-Time: " << myTime.GetMinute() << endl;
    cout << "Test-Time: " << myTime << endl;

    return 0;
}
