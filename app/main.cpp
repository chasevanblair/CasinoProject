#include "gambler.h"
#include "slotmachine.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QStringList>
#include <vector>
using namespace std;
vector<Gambler> gList;

Gambler strProcess(QString line){
    QStringList params = line.split(',');
    //gList.push_back(Gambler(params.value(0).toInt(), params.value(1).toStdString(), params.value(2).toDouble()));
    return Gambler(params.value(0).toInt(), params.value(1).toStdString(), params.value(2).toDouble());
}

void qRead(){
    //reads as a qfile and pushes created objects to a vector gList
    QFile file("../app/gamblerList.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            //cout << "q line: " << line.toStdString() << endl;
            gList.push_back(strProcess(line));
        }

}

void choice(){
    string menuChoice;
    cout << "Welcome to the lucky 7 casino!" << endl << "Please enter what you would like to do: " << endl
         << "(1) Select profile" << endl
         << "(2) Create profile" << endl
         << "(3) Play slots" << endl
         << "(q) Quit and save" << endl
         << "Choice: ";
    cin >> menuChoice;

    if(menuChoice == "1"){
        cout << "list here" << endl;
        //user can enter an id and use that data
    }else if(menuChoice == "2"){
        Gambler g;
        g.writeToFile();
    }else if(menuChoice == "3"){
        //launch slot where bet is subtracted from acct balance and the return of spin() is added
        cout << "Enter your bet for the slot machine: ";
    }else if(menuChoice == "q"){
        //quits
    }else{
        cout << "Input invalid. Try Again." << endl;
        choice();
    }
}

int main()
{
    choice();



    //Gambler g;
   // SlotMachine s;

    //g.writeToFile();
    /*read_record();
    fstream fin;
    if(!fin.is_open())
        fin.open("../app/gamblerList.txt", fstream::app);
    string line;
   getline(fin, line);

    cout << "line: " << line << endl;
    fin.close();*/
    qRead();
    for(Gambler g : gList){
        g.toString();
    }
   // g.addBalance(s.spin(2));
}
//test git2
