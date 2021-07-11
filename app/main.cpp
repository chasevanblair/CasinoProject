#include "gambler.h"
#include "slotmachine.h"
using namespace std;

int main()
{
    Gambler g;
    SlotMachine s;


    g.addBalance(s.spin(2));
}
