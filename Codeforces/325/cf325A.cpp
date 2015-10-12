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

int main(){
	cin.sync_with_stdio(false);
	int n, a[105], res=0, firstone=-1, lastone=0;
	cin>>n;
	for(int i=0; i<n; ++i){
		cin>>a[i];
		if(firstone==-1&&a[i]==1) firstone=i;
		if(a[i]==1) y=i;
	}

	if(firstone==-1){
		cout<<0;
		return 0;
	} 

	for(int i=firstone; i<=lastone; ++i){
		if(a[i]==1){
			++res;
		} else{
			if(a[i+1]==0){
				while(i+1<=lastone){
					if(a[i+1]==0){
						++i;
					} else{
						break;
					}
				}
			} else{
				res++;
			}
		}
	}
	cout<<res;
	return 0;
}