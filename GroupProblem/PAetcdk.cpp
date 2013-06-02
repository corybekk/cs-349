//Title: PAe
//Author: Yangfan Qi, Cory Bekker, Sydnie Montoya
//Date: Fall 2011
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>

using namespace std;

#define DEBUG 0
#define debuf if ( DEBUG ) cout

int main ( int argc, char* argv[] ){

  ifstream fin( argv[1] );
  if(fin.fail()){
    cout << "bad file: " << argv[1] << endl;
    exit(1);
  }

  int nameCount = 0;
  string temp;
  vector<string>names;

  while( !fin.eof() ){

    getline(fin,temp);
    names.push_back(temp);
  }

  fin >> nameCount;

  
  for(int i=1; i<names.size(); i++){
    int sum=0;
    
    cout<<names[i]<< " is ";
    for(int j=0; j < names[i].length(); j++)
      if(names[i][j]!=' ') 
	sum += (int) toupper(names[i][j]);

    sum%=5;
    
    if(sum==0)
    cout <<"fire" <<endl;
    else if (sum==1)
      cout << "water"<<endl;
    else if (sum==2)
      cout << "earth"<<endl;
    else if (sum==3)
      cout << "wood"<<endl;
    else if (sum==4)
      cout << "metal"<<endl;
      /*
    if(sum==0)
      cout << "dark" << endl;
    else if(sum ==1)
      cout << "light" <<endl;
    */

  }

  return 0;
}
