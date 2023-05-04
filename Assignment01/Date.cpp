#include "Date.h"

Date::Date() // Default Constructor
{
    m_day = 0;
    m_month = 0;
    m_year = 0;
}

Date::Date(int day, int month, int year) // Parameter Constructor
{
    m_day = day;
    m_month = month;
    m_year = year;
}

// Setter
void Date::SetDay(int day)
{
    m_day = day;
}

void Date::SetMonth(int month)
{
    m_month = month;
}

void Date::SetYear(int year)
{
    m_year = year;
}

// Getter
int Date::GetDay() const
{
    return m_day;
}

int Date::GetMonth() const
{
    return m_month;
}

int Date::GetYear() const
{
    return m_year;
}

string Date::ConvertMonth(int month)
{
    switch(month)
    {
    case 1 :
        return "January";
    case 2 :
        return "February";
    case 3 :
        return "March";
    case 4 :
        return "April";
    case 5 :
        return "May";
    case 6 :
        return "June";
    case 7 :
        return "July";
    case 8 :
        return "August";
    case 9 :
        return "September";
    case 10 :
        return "October";
    case 11 :
        return "November";
    case 12 :
        return "December";
    }
}

// istream operator
istream & operator >> (istream & input, Date & date)
{
    string day,month,year;

    getline(input,day,'/');
    getline(input,month,'/');
    getline(input,year,' ');

    date.SetDay(stoi(day));
    date.SetMonth(stoi(month));
    date.SetYear(stoi(year));

    return input;
}

// ostream operator
ostream & operator << (ostream & os, const Date & date)
{
    os << "Date : " << date.GetDay() << "/" << date.GetMonth()
       << "/" << date.GetYear() << endl;

    return os;
}
