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
Gambler *currentGambler = NULL;
SlotMachine s;

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

//checks ids to see if that id exists in the file then returns the index
//return -1 if not found
int findID(string id){
    int i = 0;
    for(Gambler t : gList){
        if(t.getID() == stoi(id)){
            return i;
        }
        i++;
    }
    return -1;
}

void choice(){
    //TODO recursion broke after implementing findID
    //option 2 also throws stoi error for some reason
    string menuChoice;
    cout << "Welcome to the lucky 7 casino!" << endl << "Please enter what you would like to do: " << endl
         << "(1) Select profile" << endl
         << "(2) Create profile" << endl
         << "(3) Play slots" << endl
         << "(q) Quit and save" << endl
         << "Choice: ";
    cin >> menuChoice;

    if(menuChoice == "1"){
        cout << "Saved customers:" << endl;

        for(Gambler t : gList){
            t.toString();
        }
        cout << "Enter ID of account: " << endl;
        string idIn;
        cin >> idIn;
        int loc = findID(idIn);
        cout << "lostacitn " << loc << endl;
        if (loc != -1)
            *currentGambler = gList[loc];
        else
            cout << "player does not exist" << endl;

        choice();
        //set currentGambler to the Gambler that has that id val
        //user can enter an id and use that data
    }else if(menuChoice == "2"){
        currentGambler = new Gambler();

        currentGambler->writeToFile();
        choice();
    }else if(menuChoice == "3"){
        string bet;
        //launch slot where bet is subtracted from acct balance and the return of spin() is added
        cout << "Enter your bet for the slot machine: ";
        cin >> bet;
        currentGambler->subtractBalance(stod(bet));
       currentGambler->addBalance(s.spin(stod(bet)));
        choice();
        }
    else if(menuChoice == "q"){
        //quits
        if(currentGambler != NULL){
            //needs to update file not create another entry
            currentGambler->writeToFile();
        }else{
            //creates
            currentGambler->writeToFile();


        }
    }else{
        cout << "Input invalid. Try Again." << endl;
        choice();

    }

}

int main()
{




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
     choice();
    for(Gambler g : gList){
        g.toString();
    }
   // g.addBalance(s.spin(2));
}
//test git2
