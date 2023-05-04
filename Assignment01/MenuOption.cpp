#include "MenuOption.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


// empty default constructor
MenuOption::MenuOption()
{

}

// is to read the input data/files
void MenuOption::ReadFile()
{
    // Variables
    WindLog windObj; // windlog object
    string str; // temp string

    // to open the input data file and load it
    ifstream infile("Data/MetData_Mar01-2014-Mar01-2015-ALL.csv" );
    //ifstream infile("Data/MetData_Mar01-2015-Mar01-2016-ALL.csv" );

    // it will prompt this statement if no input data file is found
    if(!infile)
    {
         cout << "error reading file!";
    }
    else
    {
        // skip the first line of the row
        getline(infile, str);
        //ofstream ofile( "Test_File.txt" );
        while(!infile.eof())
        {
            // end of file validation
            if((infile.peek() == '\n') || infile.eof())
            {
                getline(infile, str, '\n');
                continue;
            }
            else
            {
                // pushing all data into windVect
                infile >> windObj;
                windVect.PushBack(windObj);
                //ofile <<windObj;
            }
        }

        // close the input file
        infile.close();
        cout << "--- Extraction File End!!! ---" <<endl << endl;
        //ofile.close();

        // windVect extraction and printing data. To test if the vector is working
        /*int count = 50;
        for(int i=0;i<count;i++)
        {
            cout << windVect.At(i) << endl;
            count= 50;
        }*/

  }
} // END OF READFILE()

// Display the average wind speed and ambient air temperature from input month and year
void MenuOption::Option1()
{
    cout << "--- [Option 1] ---\n";

    // Variables
    int month = 0;
    int year = 0;
    float sumWS = 0.0;
    float sumTemp = 0.0;
    int tempMonth = 0;
    int tempYear = 0;
    Date dObj;

    // validation check for the month
    while(month <= 0 || month > 12)
    {
        // prompt the user input of the month
        cout << "Enter a month please!. Between [1-12]: " << endl;
        cin >> month;
    } // END OF WHILE LOOP

    // prompt for user input of the year
    cout << "Enter a year please!" << endl;
    cin >> year;

    //Calculation for the average of wind speed and ambient air temperature
    // If data not found it will print this statement
   if(count = 0)
    {
        cout << dObj.ConvertMonth(month) << " Invalid Data!" << endl;
    }
   else
    {
         // getting speed and temperature from the Vector
        for(int i=0; i < windVect.Size(); i++)
        {
                tempMonth = windVect.At(i).GetDate().GetMonth();
                tempYear = windVect.At(i).GetDate().GetYear();
                if(tempMonth == month && tempYear == year)
                {
                    sumWS += windVect.At(i).GetWeather().GetSpeed();
                    sumTemp += windVect.At(i).GetWeather().GetTemperature();
                    count++;
                }
        }

        // calculation of the average speed and temperature
        float avgWS = (sumWS / count) * 3.6;
        float avgTemp = sumTemp / count;

        // Display the data output
        cout << dObj.ConvertMonth(month) << " " << year << ": "
       << fixed << setprecision(1) << avgWS << " km/h, " << fixed
       << setprecision(1) << avgTemp << " degree C: " << endl;
    }
}// END OF option1()


// Display the average wind speed and ambient air temperature of each month from the input year.
void MenuOption::Option2()
{
    cout << "--- [Option 2] ---\n";

    // Variables
    int year;
    int tempMonth;
    int tempYear;
    float sumWS = 0.0;
    float sumTemp = 0.0;
    Date dObj;

    // prompt for user input of the year
    cout <<"Enter a specific year please: " << endl;
    cin >> year;

    // display the user input
    cout << "\n--- [Result] ---\n";
    cout << year << endl;

    for(int i = 1; i <= 12; i++)
    {
        // reseting the variables for each month
        count = 0;
        sumTemp = 0.0;
        sumWS = 0.0;

        // If data not found it will print this statement
        if(count = 0)
        {
            cout << dObj.ConvertMonth(i) << " Invalid Data!" << endl;
        }
        else
        {
             // getting speed and temperature from the Vector
            for(int j=0; j < windVect.Size(); j++)
            {
                tempMonth = windVect.At(j).GetDate().GetMonth();
                tempYear = windVect.At(j).GetDate().GetYear();
                if(tempMonth == i && tempYear == year)
                {
                    sumWS += windVect.At(j).GetWeather().GetSpeed();
                    sumTemp += windVect.At(j).GetWeather().GetTemperature();
                    count++;
                }
            }

            // calculation of the average speed and temperature
            float avgWS = (sumWS / count) * 3.6;
            float avgTemp = sumTemp / count;

            // Display the data output
            cout << dObj.ConvertMonth(i) << " " << year << ": "
            << fixed << setprecision(1) << avgWS << " km/h, " << fixed
            << setprecision(1) << avgTemp << " degree C: " << endl;
        }
    } // END OF FOR LOOP
} // END OF option2()


// Display the total solar radiation of each month from the input year
void MenuOption::Option3()
{
    cout << "--- [Option 3] ---\n";

    // Variables
    int year;
    int tempMonth;
    int tempYear;
    float sumSR = 0.0;
    Date dObj;

    // prompt for user input of the year
    cout <<"Enter a specific year please: " << endl;
    cin >> year;

    // display the user input
    cout << "\n--- [Result] ---\n";
    cout << year << endl;

    for(int i = 1; i <= 12; i++)
    {
        // reseting the variables for each month
        sumSR = 0;
        count = 0;

        // Calculation and print the total solar radiation of each month
        // If data not found it will print this statement
       if(count = 0)
        {
            cout << dObj.ConvertMonth(i) << " Invalid Data!" << endl;
        }
       else
        {
            // getting solar radiation from the Vector
            for(int j=0; j < windVect.Size(); j++)
            {
                tempMonth = windVect.At(j).GetDate().GetMonth();
                tempYear = windVect.At(j).GetDate().GetYear();
                if(tempMonth == i && tempYear == year )
                {
                    if(windVect.At(j).GetWeather().GetSolar() >= 100)
                    {
                        sumSR += windVect.At(j).GetWeather().GetSolar();
                        count++;
                    }
                }
            }

            // Calculation of the total solar radiation of the average of each hours
            float totalSR = sumSR/6000;

            // Display the data output
            cout << dObj.ConvertMonth(i) << " : "
            << fixed << setprecision(1) << totalSR
            << " kWh/m2 " << endl;
        }
    }
} // END OF option3()

// Print into file the average wind speed, ambient air temperature and total solar radiation of each month from input year.

void MenuOption::Option4()
{
    cout << "--- [Option 4] ---\n";

    // Variables
    int year;
    int tempMonth;
    int tempYear;
    float sumWS = 0.0;
    float sumTemp = 0.0;
    float sumSR = 0.0;
    bool Empty = true;
    Date dObj;
    ofstream output;

    // prompt for user input of the year
    cout <<"Enter a specific year please: " << endl;
    cin >> year;

    // opening the output file
    output.open("Data/WindTempSolar.csv");

    // display the user input year
    output << year << endl;

    for(int i = 1; i <= 12; i++)
    {
        // reseting the variables for each month
        sumSR = 0;
        sumWS = 0;
        sumTemp = 0;
        count = 0;

          // if year has no data
        if(count = 0)
        {
            if(Empty)
            {
                output << "Invalid Data/No Data output" << endl;
            }
        }
        else
        {
            // getting the speed, temperature and solar radiation from the Vector
            for(int j=0; j < windVect.Size(); j++)
            {
                tempMonth = windVect.At(j).GetDate().GetMonth();
                tempYear = windVect.At(j).GetDate().GetYear();
                if(tempMonth == i && tempYear == year)
                {
                    sumWS += windVect.At(j).GetWeather().GetSpeed();
                    sumTemp += windVect.At(j).GetWeather().GetTemperature();

                    if(windVect.At(j).GetWeather().GetSolar() >= 100)
                    {
                        sumSR += windVect.At(j).GetWeather().GetSolar();
                    }
                    count++;
                }
            }

            // Calculate and write the average wind speed, temperature and total solar radiation for each month into the file.
            Empty = false;
            float avgWS = (sumWS/count) * 3.6;
            float avgTemp = sumTemp / count;
            float totalSR = sumSR / 6000;

            // print the output into a csv format file.
            output << dObj.ConvertMonth(i) << "\n Avg WS: " << ","
            << fixed << setprecision(1) << avgWS << "\n Avg Temp: " <<","
            << fixed << setprecision(1) << avgTemp << "\n Avg SR: " << ","
            << fixed << setprecision(1) << totalSR << endl;
        }
    } // END OF FOR LOOP

    // closing output file
    output.close();
    cout << "----- Finish output the data into [CSV FORMAT]!. -----" << endl;
} // END OF option4()


void MenuOption::MenuList()
{
    int option = 0;

    // --- Menu List --- //
    cout << "----- [MENU] -----" << endl << endl << endl;
    cout << "[1]. The average wind speed and average ambient air temperature for a specified month and year." << endl;
    cout << "[2]. Average wind speed and average ambient air temperature for each month of a specified year." << endl;
    cout << "[3]. Total solar radiation in kWh/m2 for each month of a specified year." << endl;
    cout << "[4]. Average wind speed (km/h), average ambient air temperature and total solar radiation in kWh/m2 for each month of a specified year." << endl;
    cout << "[5]. Exit the program " << endl << endl;

    // The program will continue to loop until user choose to exit ( select option 5 )
    while(option != 5)
    {
        // --- User Input Option --- //
        cout << "\nEnter an Menu Option Please !! " << endl;
        cin >> option;

        // Display the average wind speed and ambient air temperature from input month and year.
        switch(option)
        {
            // Display the average wind speed and ambient air temperature from input month and year.
            case 1:
            {
                Option1();
                break;
            }
                // Display the average wind speed and ambient air temperature from input month and year.
            case 2:
            {
                Option2();
                break;
            }
                 // Display the total solar radiation of each month from the input year.
            case 3:
            {
                Option3();
                break;
            }
                // Print into file the average wind speed, ambient air temperature and total solar radiation of each month from input year.
            case 4:
            {
                Option4();
                break;
            }
            case 5:
            {
                cout <<"----- Terminating/Exiting the Program -----" << endl;
                break;
            }
            default:
            {
                cout << "\nInvalid Option!!!. Please enter your option again.\n" << endl;
            }
        } // END OF SWITCH-CASE
    } // END OF WHILE LOOP
} // END OF MenuList()



