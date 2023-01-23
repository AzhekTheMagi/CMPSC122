// driver for Fraction project part 2 
#include "Frac2.h"
#include <iostream>
using namespace std;

int main()
{
   Fraction c( 7, 3 ), d( 3, 9 ), x;

//   c.printFraction();
   cout << c;
   cout << " + " ;
 //  d.printFraction();
   cout << d;
   cout << " = ";
   x = c + d;
//   x.printFraction();
   cout << x;

   cout << '\n';
//   c.printFraction();
   cout <<c;

   cout << " - " ;
//   d.printFraction();
   cout << d;
   cout << " = ";
   x = c - d;
//   x.printFraction();
   cout <<x;

   cout << '\n';
//   c.printFraction();
   cout << c;
   cout << " * " ;
//   d.printFraction();
   cout << d;
   cout << " = ";
   x = c * d;
//   x.printFraction();
   cout <<x;

   cout << '\n';
//   c.printFraction();
   cout <<c;
   cout << " / " ;
//   d.printFraction();
   cout << d;
   cout << " = ";
   x = c / d;
//   x.printFraction();
   cout << x;

   cout << '\n';
//   c.printFraction();
   cout << c;
   cout << " is:\n";

   cout << ( ( c > d ) ? "  > " : "  <= " );
//   d.printFraction();
   cout << d;
   cout << " according to the overloaded > operator\n";

   cout << ( ( c < d ) ? "  < " : "  >= " );
//   d.printFraction();
   cout << d;
   cout << " according to the overloaded < operator\n";

   system("pause");
   return 0;
}

