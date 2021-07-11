#include "gambler.h"
#include "slotmachine.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    Gambler g;
    SlotMachine s;

    g.writeToFile();
    std::ifstream reader("../gamblers.txt", std::ios_base::app);
    string line;
    getline(reader, line);

    cout << line;

    g.addBalance(s.spin(2));
}
//test git2
