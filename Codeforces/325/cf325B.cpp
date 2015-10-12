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

const int MAXN=106;

int main(){
	cin.sync_with_stdio(false);
	int n, a[2][MAXN], b[MAXN];
	cin>>n;
	for(int i=0; i<2; ++i){
		for(int j=0; j<n-1; ++j){
			cin>>a[i][j];
		}
	}

	for(int i=0; i<n; i++){
		cin>>b[i];
	}

	vector<int> res;
	for(int i=0; i<n; ++i){
		int r=b[i];
		for(int j=0; j<n-1; ++j){
			if(j<i){
				r+=a[0][j];		
			} else{
				r+=a[1][j];
			}
		}
		res.push_back(r);
	}

	sort(res.begin(), res.end());
	cout<<res[0]+res[1];
	return 0;
}