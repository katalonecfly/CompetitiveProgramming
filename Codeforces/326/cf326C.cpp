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

const int MAXN=1000000+1000;
int c[MAXN+10]={ 0 };
int main(){
	cin.sync_with_stdio(false);
	int n, w, res=0;
	cin>>n;
	for(int i=0; i<n; ++i){
		cin>>w;
		++c[w];
	}

	for(int i=0; i<MAXN; ++i){
		if(c[i]!=0){
			c[i+1]+=c[i]/2;
			c[i]%=2;
			res+=c[i];
		}
	}
	cout<<res;
	return 0;
}