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
	int n, curmin=107, res=0, a, p;
	cin>>n;
	for(int i=0; i<n; ++i){
		cin>>a>>p;
		curmin=min(curmin, p);
		res+=curmin*a;
	}
	cout<<res;
	return 0;
}