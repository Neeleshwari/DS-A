#include<iostream>
#include<stdexcept>
#include<vector>
#include<map>

using namespace std;

class Graph
{
	vector<int> starts;
	vector<int> ends;
	map< int,vector<int> > adjlist;
	
public:
	Graph(const vector<int> &starts, const vector<int> &ends)
	{
		if ( starts.size() != ends.size() )
			throw invalid_argument("\nsize of starts and ends vector didn't match");

		for(int i=0;i<starts.size();++i)
		{
			this->starts.push_back(starts[i]);
		}

		for(int i=0;i<ends.size();++i)
		{
			this->ends.push_back(ends[i]);
		}

		int key=0;
		vector<int> temp;

		key = starts[0];
		for(int i=0;i<starts.size();++i)
		{
			if ( key == starts[i] )
			{
				temp.push_back(ends[i]);
			}
			else
			{
				adjlist.insert(pair< int,vector<int> >(key,temp));
				key = starts[i];
				temp.clear();
				temp.push_back(ends[i]);
			}
		}
		adjlist.insert(pair< int,vector<int> >(key,temp));
	}
	int numOutgoing(const int nodeID ) const
	{
		if ( adjlist.find(nodeID) != adjlist.end() )
			return(adjlist.find(nodeID)->second.size());	
		else
		{
			throw invalid_argument("nodeID not found in map");
		}
	}
	const vector<int> adjacent(const int nodeID) const 
	{
		vector<int> vec;
		if ( adjlist.find(nodeID) != adjlist.end() )
		{
			vec = adjlist.find(nodeID)->second;
			return(vec);
		}
		else
		{
			throw invalid_argument("nodeID not found in map");
		}
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(1);
	v1.push_back(1);
	v1.push_back(5);
	v1.push_back(5);
	v1.push_back(4);
	vector<int> v2;
	v2.push_back(2);
	v2.push_back(3);
	v2.push_back(4);
	v2.push_back(4);
	v2.push_back(2);
	v2.push_back(2);

	try{
		Graph g(v1,v2);
		try{
		cout<<g.numOutgoing(2);
		}catch(const invalid_argument &a)
		{
			cerr<<"Invalid argument : "<<a.what() <<"\n";
		}
		cout<<g.adjacent(5).size();
	}catch(const invalid_argument &a)
	{
		cerr<<"Invalid argument : "<<a.what() <<"\n";
	}
	
	return 0;
}
