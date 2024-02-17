#include <iostream>

using namespace std;

int square( int y )
{
   return y * y;
}

int main(int argc, char *argv[]){
   cout << argv[1] << endl;
   
   int x = atoi(argv[1]);
   
   for ( x = 1; x <= atoi(argv[1]); x++ ) {
      cout << " " << square(x) << "  ";
   }
   cout << endl;

   return 0;
}
