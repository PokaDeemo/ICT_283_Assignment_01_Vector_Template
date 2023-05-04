#ifndef MENUOPTION_H
#define MENUOPTION_H

#include "WindLog.h"
#include "Vector.h"

using namespace std;

/**
   * @class MenuOption
   * @brief MenuOption Class is created to store option 1 to 5 and the menu lists
   * @author Tan Hong Rui Freeman
   * @version 01
   * @date 16/10/2022 Freeman Tan, Started
   *
   */

class MenuOption
{
public:
    MenuOption();
    /**
    * @brief Default Constructor for MenuOption
    * An default constructor that is empty
    */

    void ReadFile();
    /**
    * @brief Load data from file to vector
    * @return void
    */

    void Option1();
    /**
    * @brief Option1() is to Display the average wind speed and ambient air temperature from inputed month and year
    * Wind speed in km/h format.
    * Ambient air temperature in degree celius format.
    * @return void
    */

    void Option2();
    /**
    * @brief Option2() is to Display the average wind speed and ambient air temperature of each month from inputed year
    * Wind speed in km/h format.
    * Ambient air temperature in degree celius format.
    * @return void
    */

    void Option3();
    /**
    * @brief Option3() is to display the total solar radiation of each month from inputed year
    * Total solar radiation in KWh/m2 format.
    * Solar radiation values < 100 W/m2 are not used.
    * @return void
    */

    void Option4();
    /**
    * @brief Option3() is to output the data into a csv file format of the average wind speed, ambient air temperature  and total solar radiation  of each month from inputed year
    * Total solar radiation in KWh/m2 format.
    * Wind speed in km/h format.
    * @return void
    */

    void MenuList();
    /**
    * @brief menuList() is to display all the menu option to the user.
    * @return void
    */

private:
    unsigned count; // Count
    Vector <WindLog> windVect; // windlog vector
};

#endif // MENUOPTION_H
