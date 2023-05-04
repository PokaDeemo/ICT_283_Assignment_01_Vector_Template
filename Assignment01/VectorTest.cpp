#include <iostream>
#include <string>
#include "Vector.h"


using namespace std;

int main()
{
    Vector<string> vector01;
    //vector01.~Vector();
    vector01.PushBack("a");
    //vector01.Clear();
    vector01.PushBack("b");
    vector01.PushBack("c");
    //vector01.popBack();
    vector01.PushBack("d");
    vector01.PushBack("e");
    vector01.PushBack("f");
    //vector01.popBack();
    //vector01.~Vector();
    vector01.PushBack("h");
    vector01.PushBack("g");

    //vector01.Clear();

    cout << "Vector 01" << endl;
    vector01.printList();
    cout << "Vector Index number 2: " << vector01.At(2) << endl;
    Vector <string> vector02(vector01);

    vector01 = vector02; // Copy Constructor Testing.

    cout << "Vector 02" << endl;
    vector02.printList();

    return 0;
}
