// Title: P5a PigEwu Boggle
// Author: Ashley Campbell, Nick Hughes, Cory Bekker
// Date: 10/3/11

#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;

void getWords1( char box[6][6], string word, int x, int y );
void getWords2( char box[6][6], string word, int x, int y );
bool isWord( string word );

vector<string> results1;
vector<string> results2;
vector<string> output;
char box1[6][6];
char box2[6][6];

int main( int argc, char* argv[ ] )
{
  ifstream fin( argv[ 1 ] );
  if( fin.fail( ) )
    {
      cout << "Invalid input.\n";
      exit( 1 );
    }

  char a;
  fin >> a;

  while( a != '#' )
    {
      for( int r = 0; r < 6; r++ )
	{
	  if( r == 0 || r == 5 )
	    for( int c = 0; c < 6; c++ )
	      box1[r][c] = ' ';
	  else
	    {
	      for( int c = 0; c < 6; c++ )
		{
		  if( r == 1 && c == 1 )
		    box1[r][c] = a;
		  else if( c == 0 || c == 5 )
		    box1[r][c] = ' ';
		  else
		    fin >> box1[r][c];
		}
	      for( int c = 1; c < 5; c++ )
		{
		  if( c == 0 || c == 5 )
		    box2[r][c] = ' ';
		  else
		    fin >> box2[r][c];
		}
	    }
	}
      getWords1( box1, "", 0, 0 );
      getWords2( box2, "", 0, 0 );
      fin >> a;

      for( int i =  0; i < results1.size( ); i++ )
	for( int j = 0; j < results2.size( ); j++ )
	  if( results1[i] == results2[j] )
	    output.push_back( results1[i] );
      if( output.size( ) == 0 )
	cout << "There are no common words for this pair of boggle boards.\n";
      else
	{
	  //sort( output.begin( ), output.end( ) );
	  for( int i = 0; i < output.size( ); i++ )
	    cout << output[i] << endl;
	}
    }

  /*
  for( int r = 0; r < 6; r++ )
    {
      for( int c = 0; c < 6; c++ )
	cout << box1[r][c] << ' ';
      cout << endl;
    }
  */

  fin.close( );
  return 0;
}

void getWords1( char box[6][6], string word, int x, int y )
{
  cout << "getWords1: " << word << endl;
  if( word.length( ) == 4 )
    {
      if( isWord( word ) )
	results1.push_back( word );
    }
  else if( word.length( ) == 0 )
    {
      char temp[6][6];
      for( int r = 0; r < 6; r++ )
	for( int c = 0; c < 6; c++ )
	  temp[r][c] = box[r][c];

      for( int r = 1; r < 5; r++ )
	for( int c = 1; c < 5; c++ )
	  {
	    word = temp[r][c];
	    temp[r][c] = ' ';
	    getWords1( temp, word, r, c );
	  }
    }
  else
    {
      for( int r = x-1; r <= x+1; x++ )
	for( int c = y-1; c <= y+1; y++ )
	  if( box[r][c] != ' ' )
	    {
	      word = word + box[r][c];
	      box[r][c] = ' ';
	      getWords1( box, word, r, c );
	    }
    }
}

void getWords2( char box[6][6], string word, int x, int y )
{
  cout << "getWords2: " << word << endl;
  if( word.length( ) == 4 )
    {
      if( isWord( word ) )
	results2.push_back( word );
    }
  else if( word.length( ) == 0 )
    {
      char temp[6][6];
      for( int r = 0; r < 6; r++ )
	for( int c = 0; c < 6; c++ )
	  temp[r][c] = box[r][c];

      for( int r = 1; r < 5; r++ )
	for( int c = 1; c < 5; c++ )
	  {
	    word = temp[r][c];
	    temp[r][c] = ' ';
	    getWords2( temp, word, r, c );
	  }
    }
  else
    {
      for( int r = x-1; r <= x+1; x++ )
	for( int c = y-1; c <= y+1; y++ )
	  if( box[r][c] != ' ' )
	    {
	      word = word + box[r][c];
	      box[r][c] = ' ';
	      getWords2( box, word, r, c );
	    }
    }
}

bool isWord( string word )
{
  int vowel = 0;
  for( int i = 0; i < 4; i++ )
    if( word[i] == 'A' || word[i] == 'E' || word[i] == 'I' || word[i] == 'O'
	|| word[i] == 'U' || word[i] == 'Y' )
      vowel++;

  if( vowel == 2 )
    return true;
  return false;
}

