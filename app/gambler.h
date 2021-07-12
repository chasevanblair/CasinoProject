#ifndef GAMBLER_H
#define GAMBLER_H
#include<string>
using namespace std;
class Gambler
{
public:
    Gambler();
    Gambler(int id, string name, double balance);
    void setName(string n);
    void setBalance(double b);
    string getName();
    double getBalance();
    void setID(int i);
    int getID();
    void writeToFile();
    void addBalance(double b);
    void toString();
    void subtractBalance(double b);
private:
    int ID;
    string name;
    double balance;
};

#endif // GAMBLER_H
