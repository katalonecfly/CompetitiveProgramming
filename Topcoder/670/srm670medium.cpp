#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

class Drbalance{
	public:
	int lesscng(string s, int k){
		int r=0, b=0;
		for(size_t i=0; i<s.size(); ++i){
			int c=0;
			for(size_t j=0; j<=i; ++j){
				if(s[j]=='+') ++c;
				else --c;
			}
			if(c<0) ++r;
		}
		
		while(r>k){
			r=0;
			for(size_t i=0; i<s.size(); ++i){
				if(s[i]=='-'){
					s[i]='+';
					break;
				}
			}
			b++;
			
			for(size_t i=0; i<s.size(); ++i){
				int c=0;
				for(size_t j=0; j<=i; ++j){
					if(s[j]=='+') ++c;
					else --c;
				}
				if(c<0) ++r;
			}
		}
		return b;
	}
};