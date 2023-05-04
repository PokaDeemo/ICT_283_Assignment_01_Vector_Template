#ifndef TIME_H
#define TIME_H

#include <iostream>

using namespace std;

/**
 * @class Time
 * @brief Time Class is created to store the day, month and year
 * @author Tan Hong Rui Freeman
 * @version 01
 * @date 6/10/2022 Freeman Tan, Started
 *
 */

class Time
{
public:
    Time();
    /**
    * @brief Default Constructor for Time
    * @param An default constructor that is empty
    */

    Time(int hours, int minutes);
    /**
    * @brief Parameter Constructor for Time
    * @param An parameter constructor that is use to create or name the objects by variables.
    */

    void SetHour(int hours);
    /**
    * @brief setter for the Hour
    * @param hours represents private hour
    * @post hour is changed
    */

    void SetMinute(int minutes);
    /**
    * @brief setter for the Minute
    * @param minutes represents private minute
    * @post minute is changed
    */

    int GetHour() const;
    /**
    * @brief getter for the Hour
    * @pre hour object must be initialised
    * @return Get the hour
    */

    int GetMinute() const;
    /**
    * @brief getter for the Minute
    * @pre minute object must be initialised
    * @return Get the minute
    */

private:
    int m_hour;
    int m_minute;
};

ostream & operator << (ostream & os, const Time & time);
/**
* @brief an overload output operator. Use to output the object or result
* @param ostream is reference to OS. That is use for the output stream using the #include <iostream> header
* @param time is just a object variable name that we created for Time.CPP ostream operator.
*/

istream & operator >> (istream & input, Time & time);
/**
* @brief an overload input operator. Use to get input from the user or files
* @param istream is reference to input. That is use for the input stream using the #include <iostream> header
* @param time is just a object variable name that we created for Time.CPP istream operator.
*/


#endif // TIME_H

