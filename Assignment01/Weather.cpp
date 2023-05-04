#include "Weather.h"

// Default Constructor
Weather::Weather()
{
    m_speed = 0;
    m_solarRadiation = 0;
    m_temperature = 0;
}

// Parameter Constructor
Weather::Weather(float speeds, float solarRadiation, float temperature)
{
    m_speed = speeds;
    m_solarRadiation = solarRadiation;
    m_temperature = temperature;
}

// Setter
void Weather::SetSpeed(float speeds) // Setter for the speed so that this speed will be this speed
{
    m_speed = speeds;
}

void Weather::SetSolar(float solarRadiation) // Setter for the solar so that this solar will be this solar
{
    m_solarRadiation = solarRadiation;
}

void Weather::SetTemperature(float temperature) // Setter for the temperature so that this temperature will be this temperature
{
    m_temperature = temperature;
}

// Getter
float Weather::GetSpeed() const // Getter for the speed it will return the speed
{
    return m_speed;
}

float Weather::GetSolar() const // Getter for the solar it will return the solar
{
    return m_solarRadiation;
}

float Weather::GetTemperature() const // Getter for the temperature it will return the temperature
{
    return m_temperature;
}

// Input Statements
istream & operator >> (istream & input, Weather & weather)
{
    string speed, solarRadiation, temperature, line;

    // ignore the 9 column to get the value of the wind speed
    for(int i = 0; i < 9; i++)
    {
        getline(input,line,',');
    }
    getline(input, speed, ',');
    weather.SetSpeed(stof(speed));

    getline(input, solarRadiation, ',');
    weather.SetSolar(stof(solarRadiation));

    // ignore 5 column to get the value of the temperature
    for(int i = 0; i < 5; i++)
    {
        getline(input,line,',');
    }

    getline(input, temperature, '\n');
    weather.SetTemperature(stof(temperature));


    return input;
}

// Output Statements
ostream & operator << (ostream & os, const Weather & weather)
{
    os <<"Speed:" << weather.GetSpeed()
    << "\nSolar Radiation: " << weather.GetSolar()
    << "\nTemperature: " << weather.GetTemperature() << endl;

    return os;
}
