//Title: PA
//Author: Yangfan Qi, Cory Bekker, Sydnie Montoya
//Date: Fall 2011
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>

using namespace std;

#define DEBUG 0
#define debuf if ( DEBUG ) cout


/*
int i[100]{1,2,3,1,};
int v[100]{0,0,0,1,};
int x[100]{0,0,0,0,};
int l[100]{0,0,0,0,};
int c[100]{0,0,0,0,};
*/
int n[100];



int main ( int argc, char* argv[] ){

  n[0][]={1,0,0,0};


  ifstream fin( argv[1] );
  if(fin.fail()){
    cout << "bad file: " << argv[1] << endl;
    exit(1);
  }
  int tmp;



   
  while(fin>>tmp){

    
    




  }



  return 0;
}


