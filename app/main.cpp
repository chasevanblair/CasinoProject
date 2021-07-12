#include "gambler.h"
#include "slotmachine.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void read_record()
{

    // File pointer
    fstream fin;

    // Open an existing file
    if(!fin.is_open())
        fin.open("../app/gamblerList.txt", fstream::app);

    // Get the roll number
    // of which the data is required
    int id, idComp, count = 0;
    cout << "Enter the ID number: ";
    cin >> id;

    // Read the Data from the file
    // as String Vector
    vector<string> row;
    string line, word, temp;

    while (!fin.eof()) {
        cout << "In loop\n";
        row.clear();

        // read an entire row and
        // store it in a string variable 'line'
        getline(fin, line);
        cout << "line: " << line << endl;
        // used for breaking words
        stringstream s(line);

        // read every column data of a row and
        // store it in a string variable, 'word'
        while (getline(s, word, ',')) {

            // add all the column data
            // of a row to a vector
            row.push_back(word);
        }

        // convert string to integer for comparision
        idComp = stoi(row[0]);

        // Compare the roll number
        if (idComp == id) {
            // Print the found data
            count = 1;
            cout << "Account ID " << row[0] << " selected." << endl;
            cout << "Name: " << row[1] << endl;
            cout << "Balance: " << row[2] << endl;

            break;
        }
    }
    if (count == 0)
        cout << "Record not found\n";
}


int main()
{


    string menuChoice;
    /*cout << "Welcome to the lucky 7 casino!" << endl << "Please enter what you would like to do: " << endl
         << "(1) Select profile" << endl
         << "(2) Create profile" << endl
         << "(3) Play slots" << endl
         << "(q) Quit and save" << endl
         << "Choice: ";
    cin >> menuChoice;*/

    Gambler g;
    SlotMachine s;

    g.writeToFile();
    read_record();
    //fstream fin;
    //if(!fin.is_open())
    //    fin.open("../app/gamblerList.txt", ios::in);
    //string line;
    //getline(fin, line);

    //cout << endl << line;
    //fin.close();
    g.addBalance(s.spin(2));
}
//test git2
