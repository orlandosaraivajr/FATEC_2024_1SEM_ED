/*
Função Square com o uso de protótipo de funções
*/

#include <iostream>

using namespace std;

int square(int);
float square2(float);

int main(int argc, char *argv[]){
   int x;
   for ( x = 1; x <= 10; x++ ) {
      cout << " " << square(x) << "  ";
   }
   cout << " " << square2(2.5) << "  ";
   cout << endl;

   return 0;
}

int square( int y )
{
   return y * y;
}

float square2( float y )
{
   return y * y;
}