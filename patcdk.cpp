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
    //  fin.getline(temp);
    getline(fin,temp);    
    names.push_back(temp);
  }

  fin >> nameCount;

  
  for(int i=1; i<names.size(); i++){
    int b=0;
    int g=0;
    cout<<names[i]<< " is ";
    for(int j=0; j < names[i].length(); j++)
      if(names[i][j]=='b' || names[i][j]=='B')
	b++;
      else if(names[i][j]=='g' || names[i][j]=='G')
	g++;

    if(g>b)
      cout << "GOOD"<<endl;
    else if(g<b)
      cout<< "BADDY"<<endl;
    else 
      cout <<"NEUTRAL"<<endl;


  }

  return 0;
}
