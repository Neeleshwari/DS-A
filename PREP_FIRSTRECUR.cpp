// PREP_FIRSTRECUR.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	string str = "ABBCACDGD",visitedstr;
	int pos;

	for(int i=0;i<str.size();i++)
	{
		pos = visitedstr.find(str.at(i));
		if ( pos != string::npos )
		{
			cout<<"The first visited character is : "<<str.at(i);
			cout<<"\nOriginal position : "<<pos<<"\nRecurring position : "<<i;
			break;
		}
		visitedstr = visitedstr + str.at(i);
	}
	return 0;
}

