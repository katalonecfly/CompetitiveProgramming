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

const int MAXN=500007;
bool a[MAXN], b=0;
int main(){
	cin.sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=0; i<n; ++i){
		cin>>b;
		a[i]=b;
	}
	// find longest sequence with triplets 010/101
	int maxt=0, curt=0; 
	for(int i=1; i<n-1; ++i){
		if((a[i-1]==0&&a[i]==1&&a[i+1]==0)||(a[i-1]==1&&a[i]==0&&a[i+1]==1)){
			curt++;
		}else{
			curt=0;
		}
		maxt=max(curt, maxt);
	}
	
	//for each zig-zag seq find their first and last elements, and make changes between them  
	int first=0, last;
	for(int i=1; i<n-1; ++i){
		if(a[i]==a[first]){
			first++;
			continue;
		}
		else{
			while(a[i+1]!=a[i]){
				i++;
			}
			last=i;
			if(last==n) last--;

			if(a[first]==a[last]){
				for(int j=first; j<=last; ++j){
					a[j]=a[first];
				}
			} else{
				int x=first, y=last;
				while(x!=y-1){
					a[++x]=a[first];
					a[--y]=a[last];
				}
			}
		}
		first=last;
	}

	if(maxt%2==0){
		cout<<maxt/2;
	}
	else{
		cout<<(maxt+1)/2;
	}
	cout<<endl; 
	for(int i=0; i<n; ++i){
		cout<<a[i]<<" ";
	}
	return 0;
}