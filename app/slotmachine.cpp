#include "slotmachine.h"

SlotMachine::SlotMachine()
{
    //fill vector with possibilites
    //5x
    guess.push_back("Cherry");
    //2x
    guess.push_back("Orange");
    //1.5x
    guess.push_back("Plum");
    //4x
    guess.push_back("Bell");
    //7x
    guess.push_back("7");
    //1x
    guess.push_back("Bar");
}
void SlotMachine::setBet(double b){
    bet = b;
}
double SlotMachine::winCheck(vector<string> v){
    double mult = 0;
    if ( std::equal(v.begin() + 1, v.end(), v.begin()) )
    {
        cout << "Winner!" << endl;
        string val = v[0];
        if(val == "Cherry"){
            mult = 5;
        }else if(val == "Orange"){
            mult = 2;
        }else if(val == "Plum"){
            mult = 1.5;
        }else if(val == "Bell"){
            mult = 4;
        }else if(val == "7"){
            mult = 7;
        }else if(val == "Bar"){
            mult = 1;
        }
    }else{
        cout << "No win" << endl;
    }
    return mult;
}
double SlotMachine::spin(double b){
    vector<string> results;
    for(int i = 0; i < 3; i++){
        int ind = rand() % 6;
        results.push_back(guess[ind]);
    }
    for(int i = 0; i < 3; i++){
        cout << results[i] << " ";
        //need method to check winning nums and their win amts 2x 3x 4x
    }
    cout << endl;
    //format decimal to x.xx format
    double ret = b * winCheck(results);
    cout << "$" << ret << " added to account." << endl;
    return ret;
}
