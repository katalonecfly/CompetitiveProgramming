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
	int l, p, q;
	cin>>l>>p>>q;
	double res=( (double)(l*p) ) / ( (double)(p+q) );
	cout<<res;
	return 0;
}