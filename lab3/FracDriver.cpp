// driver for cmpsc122 Fraction Driver part 1
#include <iostream>
#include "Frac.h"
using namespace std;

int main() {
   Fraction x(-3,8), y(-15,-20), z, w(5);

   x.printFraction();
   cout << " + ";
   y.printFraction();
   z = x.add(y);
   cout << " = ";
   z.printFraction();
   cout << endl;
   z.printFraction();
   cout << " = ";
   z.printFractionAsFloat();
   cout << endl << endl;

   x.printFraction();
   cout << " - ";
   y.printFraction();
   z = x.subtract(y);
   cout << " = ";
   z.printFraction();
   cout << endl;
   z.printFraction();
   cout << " = ";
   z.printFractionAsFloat();
   cout << endl << endl;

   x.printFraction();
   cout << " * ";
    y.printFraction();
   z = x.multiply(y);
   cout << " = ";
    z.printFraction();
    cout << endl;
   z.printFraction();
   cout << " = ";
    z.printFractionAsFloat();
    cout << endl << endl;

   x.printFraction();
    cout << " / ";
    y.printFraction();
   z = x.divide(y);
   cout << " = ";
    z.printFraction();
    cout << endl;
   z.printFraction();
   cout << " = ";
    z.printFractionAsFloat();
    cout << endl;

	system( "pause" );
   return 0;
}


/*Sample run:

-3/8 + 3/4 = 3/8
3/8 = 0.375

-3/8 - 3/4 = -9/8
-9/8 = -1.125

-3/8 * 3/4 = -9/32
-9/32 = -0.28125

-3/8 / 3/4 = -1/2
-1/2 = -0.5
Press any key to continue . . .
*/
