#include <iostream>
#include <fstream>
#include <sstream>
#include "Windlog.h"
#include "MenuOption.h"

using namespace std;


int main()
{
    MenuOption menu; // MenuOption Object
    menu.ReadFile(); // Read the input data file
    menu.MenuList(); // Run/Load the program

    return 0;
}

