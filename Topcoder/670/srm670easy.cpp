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

class Cdgame{
	public:
	int rescount(vector <int> a, vector <int> b){
		int s1=0, s2=0;
		set<int> res;
		for(size_t i=0; i<a.size(); ++i){
			s1+=a[i];
			s2+=b[i];
		}
		
		for(size_t i=0; i< a.size(); ++i){
			for(size_t j=0; j< a.size(); ++j){
				res.insert((s1-a[i]+b[j])*(s2-b[j]+a[i]));
			}
		}
		return res.size();
	}
};