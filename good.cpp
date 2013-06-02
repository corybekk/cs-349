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

string math ="";

int domath();

int main ( int argc, char* argv[] ){


  ifstream fin( argv[1] );
  if(fin.fail()){
    cout << "bad file: " << argv[1] << endl;
    exit(1);
  }
  string tmp;
  getline(fin,tmp);
   
  while(!fin.eof()){
    tmp = "";
    math ="";
    int x =0;
    getline(fin,tmp);
    
    
    for(int i =0; i < tmp.size(); i++){
      if(tmp[i]!=' ')
	math+=tmp[i];
      else {
	x = tmp[i+1];
	break;
      }
    }
    
    for(int i =0; i < math.size(); i++){
      if(math[i]=='x')
	math[i]= x;
    }
    



    //test
    cout << math<<endl;
    // cout << domath()<<endl;
  }

  vector <int> a;
  for(int i=0; i <10; i++)
    a.push_back(i);

  a.erase(a.begin()+3);

  for(int i=0; i <10; i++)
    cout <<a[i]<<endl;


  return 0;
}


int domath(){
  int total =0;
  vector <int> n;
  vector <char> s;

 
    for(int i =0; i < math.size();i++){
      if(math[i]=='1')
	n.push_back(1);
      else if(math[i]=='0')
        n.push_back(0);
      else if(math[i]=='2')
        n.push_back(2);
      else if(math[i]=='3')
        n.push_back(3);
      else if(math[i]=='4')
        n.push_back(4);
      else if(math[i]=='5')
        n.push_back(5);
      else if(math[i]=='6')
        n.push_back(6);
      else if(math[i]=='7')
        n.push_back(7);
      else if(math[i]=='8')
        n.push_back(8);
      else if(math[i]=='9')
        n.push_back(9);
      else {
	s.push_back(math[i]);
      }
    }

    while( s.size()>0){
      /*
      cout << "still in while loop and the size is: "<<n.size()<<endl;
      for(int i=0; i < n.size();i++)
	printf("n[%i]: %i \n",i,n[i]);
      */      
      int c =0;
      for(int i=0; i < s.size();i++)
	if(s[i]=='/' || s[i]=='*')
	  c = i;

      if(s[c]=='+'){
	total = n[c]+n[c+1];
	n.erase(n.begin()+c,n.begin()+c+1);
	s.erase(s.begin()+c);

	n.push_back(total);
	cout<< "total is: " <<total<<endl;
      }
      else if(s[c]=='-'){
        total = n[c]-n[c+1];
        n.erase(n.begin()+c,n.begin()+c+1);
        s.erase(s.begin()+c);

	n.push_back(total);
	cout<< "total is: " <<total<<endl;

      }
      else if(s[c]=='*'){
        total = n[c]*n[c+1];
        n.erase(n.begin()+c,n.begin()+c+1);
        s.erase(s.begin()+c);


	  n.push_back(total);
	cout<< "total is: " <<total<<endl;
      
      }
      else if(s[c]=='/'){
        total = n[c]/n[c+1];
        n.erase(n.begin()+c,n.begin()+c+1);
        s.erase(s.begin()+c);

	
	  n.push_back(total);
	cout<< "total is: " <<total<<endl;
      
      }




    }


    return n[0];



}
