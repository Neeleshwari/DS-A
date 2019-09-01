// Finds the first recurring character in a given string using hash_map.

#include "stdafx.h"
#include<iostream>
#include<string>
#include<hash_set>

using namespace stdext;
using namespace std;


using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	string str = "ABCKFCDBA";
	int key;

	hash_set<char> visitedmap;
	hash_set<char>::iterator hset_itr;
	

	for(int i=0;i<str.size();i++)
	{
		hset_itr = visitedmap.find(str.at(i));
		if ( hset_itr != visitedmap.end() )
		{
			cout<<"The first visited character is : "<<str.at(i);
			cout<<"\nRecurring position : "<<i;
			break;
		}
		visitedmap.insert(str.at(i));
	}
	return 0;
}
