#include <iostream>
#include <fstream>
#include <sstream>
#include "WindLog.h"
#include "MenuOption.h"

using namespace std;

//INPUT AND OUTPUT TESTER
int main()
{
    WindLog windObj;
     Vector<WindLog> windVect;

  ifstream infile("Data/MetData_Mar01-2014-Mar01-2015-ALL.csv" );
    if(!infile){
         cout << "error reading file!";
        return -1;
    }
    else
  {
        string str;
        getline(infile, str); // skip the first line
        ofstream ofile( "test.txt" );
        while(!infile.eof())
        {
            if((infile.peek() == '\n') || infile.eof()) //Check the end of the file for extra next line
            {
                getline(infile, str, '\n');
                continue;
            }
            else
            {
                infile >> windObj;
                windVect.PushBack(windObj); // input all data into vector
                ofile <<windObj;
            }
        }
         cout << "file end" <<endl;
        infile.close();
        ofile.close();

        int count =10;
        for(int i=0;i<count;i++) //loop vector extraction and printing data
        {
            cout << windVect.At(i).GetDate().GetYear() << endl;
            count=10;
        }
  }
    return 0;
}
