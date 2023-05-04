#include <iostream>
#include "Weather.h"

int main()
{
    Weather myWeather;

    myWeather.SetSolar(3);
    myWeather.SetSpeed(6);
    myWeather.SetTemperature(9);

    myWeather.GetSolar();
    myWeather.GetSpeed();
    myWeather.GetTemperature();

    cout << myWeather.GetSolar() <<endl;
    cout << myWeather.GetSpeed() <<endl;
    cout << myWeather.GetTemperature() <<endl;

    cout <<"Weather-Test: "<< myWeather.GetSolar() << ',' << myWeather.GetSpeed() << ',' << myWeather.GetTemperature() << endl;
    cout << myWeather << endl;

    return 0;
}
