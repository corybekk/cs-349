/*
Eric Brewer - 'e'
Corey Bekker - 'c'
8/29/11
CS349
Watts
Problem 1a - Central Primes - 
*/

#include <iostream>
#include <fstream>
using namespace std;
#include <stdlib.h>

#define DEBUG 0
#define debug if ( DEBUG ) cout

int main( int argc, char* argv[] ){

  ifstream fin( argv[1] );
  if( fin.fail() ){
    cerr << "Bad file: " << argv[1] << endl;
    exit( 1 );
  }

  int N = 0;
  int C = 0;
  int* primes = new int[400];
  int index = 1;
  bool divisible;

  while( fin >> N ){
    
    fin >> C;
    
    primes[0] = 2;
    for( int i = 3; i < N-1; i++ ){
      divisible = false;
      for( int j = 0; j < index && !divisible; j++ )
	if( !( i % primes[j] ) )
	  divisible = true;
      if( !divisible ){
	primes[index] = i;
	index++;
      }
    }
    
    for( int i = 0; i < index; i++ )
      debug << primes[i] << ' ';
    debug << endl;
    
    cout << N << ' ' << C << ": ";
    if( C < index / 2 ){
      for( int i = index / 2 - C + index % 2; i < index / 2 + C; i++ )
	cout << primes[i] << ' ';
      cout << endl;
    }
    else{
      for( int i = 0; i < index; i++ )
	cout << primes[i] << ' ';
      cout << endl;
    }
  }

  return 0;
}
