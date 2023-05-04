#include <iostream>
#include "Time.h"

// Default Constructor
Time::Time()
{
    m_hour = 0;
    m_minute = 0;
}

// Parameter Constructor
Time::Time(int hours, int minutes)
{
    m_hour = hours;
    m_minute = minutes;
}

// Setter
void Time::SetHour(int hours)
{
    m_hour = hours;
}

void Time::SetMinute(int minutes)
{
    m_minute = minutes;
}

// Getter
int Time::GetHour() const
{
    return m_hour;
}

int Time::GetMinute() const
{
    return m_minute;
}

// Input Statements
istream & operator >> (istream & input, Time & time)
{
    string hour,minute;

    getline(input,hour,':');
    getline(input,minute,',');

    time.SetHour(stoi(hour));
    time.SetMinute(stoi(minute));

    return input;
}

ostream & operator << (ostream & os, const Time & time)
{
    os << time.GetHour() << ":" << time.GetMinute() << endl;

    return os;
}
