#include<iostream>
#include<vector>
#include<stdexcept>
#include<map>
#include<algorithm>
using namespace std;

class Graph
{
	multimap<int,vector<int>> edges;
	multimap<int,vector<int>> spt;

public:
	Graph(const vector<int> &starts,const vector<int> &ends, const vector<int> &wei)
	{
		vector<int> temp;
		if ( (starts.size() != ends.size()) && ( starts.size()!= wei.size()) )
			throw invalid_argument("\nsize of starts, ends and weight vector didn't match");

		for(int i=0;i<starts.size();++i)
		{
			temp.push_back(ends[i]);
			temp.push_back(wei[i]);
			edges.insert(pair<int,vector<int>>(starts[i],temp));
			temp.clear();
		}
	}
	
	void findSPT()
	{
		multimap<int,vector<int>> temp;
		typedef multimap<int, vector<int>>::iterator MAPIt;
		int i=0,min,weight = 0;
		pair<MAPIt,MAPIt> itr;
		MAPIt it;
		while( i != -1)
		{
			itr = edges.equal_range(i);

			for ( it = itr.first; it != itr.second; it++)
			{	
				if ( !findInSPT(it->second.at(0)) )
				{
					it->second.at(1) = it->second.at(1) + weight;
					temp.insert(pair<int,vector<int>>(it->first,it->second));
				}
			}
			it = temp.begin();
			MAPIt minit = temp.begin();
			min = temp.begin()->second.at(1);// weight	
			for( ;it!=temp.end();it++)
			{
				if ( it->second.at(1) < min )
				{
					min = it->second.at(1);
					minit = it;
				}
			}
			spt.insert(pair<int,vector<int>>(minit->first,minit->second));
			i = minit->second.at(0);
			weight = minit->second.at(1);
			
			MAPIt tempItr = temp.end();
			for( it = temp.begin();it!=temp.end();it++)
			{
				if ( it->second.at(1) == minit->second.at(1))
				{
					tempItr = it;
					break;
				}
			}
			if ( tempItr != temp.end() )
				temp.erase(tempItr);
			tempItr = temp.end();
			
			it = temp.begin();
			while(it!=temp.end())
			{
				if ( findInSPT(it->second.at(0)) )
				{
					tempItr = it;
					it++;
					temp.erase(tempItr);
					continue;
				}
				it++;
			}
			itr = edges.equal_range(i);
			it = itr.first;
			if ( temp.empty() && it == itr.second )
				i=-1;
		}
	}
	bool findInSPT(int n)
	{
		multimap<int, vector<int>>::iterator it;
		bool found = false;
		for( it = spt.begin();it!=spt.end();it++)
		{
			if ( it->second.at(0) == n)
			{
				found = true;
				break;
			}
		}
		return(found);
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> start,end,wei;
	start.push_back(0);
	end.push_back(1);
	wei.push_back(4);
	start.push_back(0);
	end.push_back(7);
	wei.push_back(8);
	start.push_back(1);
	end.push_back(7);
	wei.push_back(11);
	start.push_back(1);
	end.push_back(2);
	wei.push_back(8);
	start.push_back(7);
	end.push_back(8);
	wei.push_back(7);
	start.push_back(2);
	end.push_back(8);
	wei.push_back(2);
	start.push_back(7);
	end.push_back(6);
	wei.push_back(1);
	start.push_back(6);
	end.push_back(8);
	wei.push_back(6);
	start.push_back(2);
	end.push_back(5);
	wei.push_back(4);
	start.push_back(2);
	end.push_back(3);
	wei.push_back(7);
	start.push_back(3);
	end.push_back(4);
	wei.push_back(9);
	start.push_back(3);
	end.push_back(5);
	wei.push_back(14);
	start.push_back(6);
	end.push_back(5);
	wei.push_back(2);
	start.push_back(5);
	end.push_back(4);
	wei.push_back(10);

	Graph g(start,end,wei);
	g.findSPT();
	return 0;
}

