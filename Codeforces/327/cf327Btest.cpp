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

bool med(bool a, bool b, bool c){
	if((a & b)||(a && c)||(b && c))return 1;
	return 0;
}

const int n=10001, k=5000;
bool a[k][n+7], b=0;
int main(){
	cin.sync_with_stdio(false);
	srand(time(0));

	for(int i=0; i<n; ++i){
		a[0][i]=rand()%2;
		//a[0][i]=b;
		b=!b;
	}

	int count=0;
	int maxl=1, curl=1;
	for(int i=1; i<n-1; ++i){
		int m=med(a[0][i-1], a[0][i], a[0][i+1]);
		if(a[0][i]!=m) count++;
		
		if(a[0][i]!=a[0][i-1]) curl++;
		else curl=1;
		maxl=max(curl, maxl);
	}
	cout<<count<<endl;
	cout<<maxl<<endl;

	int maxt=0, curt=0;
	for(int i=1; i<n-1; ++i){
		if((a[0][i-1]==0&&a[0][i]==1&&a[0][i+1]==0)||(a[0][i-1]==1&&a[0][i]==0&&a[0][i+1]==1))
			curt++;
		else
			curt=0;
		maxt=max(curt, maxt);
	}
	cout<<maxt<<endl;

	int c=0;
	while(true){
		if(c==k-2) break;

		c++;
		a[c][0]=a[c-1][0];
		a[c][n-1]=a[c-1][n-1];
		bool changed=false;
		for(int i=1; i<n-1; ++i){
			a[c][i]=med(a[c-1][i-1], a[c-1][i], a[c-1][i+1]);
			if(a[c][i]!=a[c-1][i]) changed=true;
		}

		if(!changed){
			break;
		}
	}

	cout<<c-1;
	return 0;
}