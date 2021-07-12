#include "gambler.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
Gambler::Gambler()
{
    //default const lets instances be defined more on the fly
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
Gambler::Gambler(int id, string n, double b){
    //this will be used for reading in the names from csv
    ID = id;
    name = n;
    balance = b;
}
void Gambler::toString(){
    cout << "ID: " << ID <<", Name: " << name<< ", Balance: $" << balance << endl;
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
int Gambler::getID(){
    return ID;
}
void Gambler::writeToFile(){
    //write to the csv
    /*ofstream outputFile;
    outputFile.open("../gamblers.txt", ofstream::app);
    outputFile << ID <<"," << name<< "," << balance;
    outputFile.close();*/
    //g4g code
    // file pointer
        fstream fout;

        // opens an existing csv file or creates a new file.
        fout.open("../app/gamblerList.txt", ios::out | ios::app);
        if(fout.is_open()){
            fout << ID <<"," << name << "," << balance << "\n";}
        else
            cout << "open failed\n";
    fout.close();
}


//have read in the main because it should execute every time
//maybe put writetofile in a destructor
void Gambler::addBalance(double b){
    balance += b;
}
void Gambler:: subtractBalance(double b){
    balance -= b;
}
