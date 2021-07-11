#include "gambler.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
Gambler::Gambler()
{
    //TODO probably a better way to implement the nonstring inputs
    //dont get them from const
    string i;
    cout << "ID: ";
    getline(cin, i);
    ID = stoi(i);

    cout << "Name: ";
    getline(cin, name);

    cout << "Account balance: ";
    string b;
    getline(cin, b);
    balance = stod(b);
}
double Gambler::getBalance(){
    return balance;
}
string Gambler::getName(){
    return name;
}
void Gambler::setBalance(double b){
    balance = b;
}
void Gambler::setName(string n){
    name = n;
}
void Gambler::writeToFile(){
    //write to the csv
    ofstream outputFile;
    outputFile.open("../file.txt");
    outputFile << ID <<"," << name<< "," << balance;
    outputFile.close();
}//have read in the main because it should execute every time
//maybe put writetofile in a destructor
void Gambler::addBalance(double b){
    balance += b;
}
