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
	long long n, t, res=1;
	cin>>n;
	t=n;
	for(long long i=2; i*i<=t; ++i){
		if(t%i==0){
			res*=i;
			while(t%i==0){
				t/=i;
			}
		}
	}
	cout<<res*t;
	return 0;
}