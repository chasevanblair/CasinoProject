#ifndef SLOTMACHINE_H
#define SLOTMACHINE_H
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class SlotMachine
{
public:
    SlotMachine();
    void setBet(double b);
    double getBet();
    //return won amount or 0
    double spin(double b);
private:
    //might need to be a ptr for function access instead of getGuess
    vector<string> guess;
    double bet;
    //call from spin to get vals
    double winCheck(vector<string>);
};

#endif // SLOTMACHINE_H
