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

const int MAXN=4007;

int main(){
	cin.sync_with_stdio(false);
	int n, v[MAXN], d[MAXN], p[MAXN];
	bool b[MAXN]={ 0 };
	vector<int> res;
	cin>>n;

	for(int i=1; i<=n; ++i){
		cin>>v[i]>>d[i]>>p[i];
	}

	for(int i=1; i<=n; ++i){
		if(b[i]) continue;

		res.push_back(i);
		long long vv=v[i], dd=0;
		for(int j=i+1; j<=n; j++){
			p[j]-=max(0, vv);
			p[j]-=dd;
			if(!b[j]) vv--;
			if(p[j]<0 && !b[j]){
				b[j]=1;
				dd+=d[j];
			}
		}
	}

	cout<<res.size()<<endl;
	for(size_t i=0; i<res.size(); ++i){
		cout<<res[i]<<" ";
	}
	return 0;
}