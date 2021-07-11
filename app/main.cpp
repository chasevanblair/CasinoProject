#include "gambler.h"
#include "slotmachine.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char menuChoice;
    cout << "Welcome to the lucky 7 casino!" << endl << "Please enter what you would like to do: " << endl
         << "(1) Select profile" << endl
         << "(2) Create profile" << endl
         << "(3) Play slots" << endl
         << "(q) Quit and save" << endl
         << "Choice: ";
    cin >> menuChoice;

    Gambler g;
    SlotMachine s;

    //g.writeToFile();
    std::ifstream reader("../gamblers.txt", std::ios_base::app);
    string line;
    getline(reader, line);

    cout << endl << line;

    g.addBalance(s.spin(2));
}
//test git2
