#ifndef WEATHER_H
#define WEATHER_H
#include <iostream>
#include "Vector.h"

using namespace std;

  /**
     * @class Weather
     * @brief Weather Class is created to store the Speed, Solar and Temperature
     * @author Tan Hong Rui Freeman
     * @version 01
     * @date 15/10/2022 Freeman Tan, Started
     *
     */

class Weather
{
    public:
        // Constructor
        Weather();
        /**
        * @brief Default Constructor for Weather
        * An default constructor that is empty
        */
        Weather(float speeds, float solarRadiation, float temperature);
        /**
        * @brief Parameter Constructor for Weather
        * An parameter constructor that is use to create or name the objects by variables.
        */

        // Setter
        void SetSpeed(float speeds);
        /**
        * @brief setter for the Speed
        * @post speeds is changed
        * @param speeds will be changed
        * @return void
        */

        void SetSolar(float solarRadiation);
         /**
        * @brief setter for the Solar
        * @post solarRadiation is changed
        * @param solar will be changed
        * @return void
        */

        void SetTemperature(float temperature);
        /**
        * @brief setter for the Temperature
        * @post temperature is changed
        * @param temperature will be changed
        * @return void
        */

        // Getter
        float GetSpeed() const;
        /**
        * @brief getter for the Speed
        * @pre speeds object must be initialized
        * @return float of the speeds
        */

        float GetSolar() const;
        /**
        * @brief getter for the Solar
        * @pre solarRadiation object must be initialized
        * @return float of the solars
        */

        float GetTemperature() const;
        /**
        * @brief getter for the Temperature
        * @pre temperature object must be initialized
        * @return float of the temperature
        */

    private:
        float m_speed;
        float m_solarRadiation;
        float m_temperature;
};

ostream & operator << (ostream & os, const Weather & weather);
 /**
    * @brief an overload output operator. Use to output the object or result
    * @param ostream is reference to OS. That is use for the output stream using the #include <iostream> header
    * @param weatherObj is just a object variable name that we created for Weather.CPP ostream operator.
    */

istream & operator >> (istream & input, Weather & weather);
 /**
    * @brief an overload output operator. Use to output the object or result
    * @param istream is reference to OS. That is use for the output stream using the #include <iostream> header
    * @param weatherObj is just a object variable name that we created for Weather.CPP istream operator.
    */


#endif // WEATHER_H
