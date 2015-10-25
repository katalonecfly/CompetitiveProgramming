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
	int n, m;
	cin>>n>>m;
	string s;
	cin>>s;
	int ch[30];
	for(int i=0; i<26; ++i){
		ch[i]=i;
	}
	char c1, c2;
	for(int i=0; i<m; ++i){
		cin>>c1>>c2;
		for(int j=0; j<26; ++j){
			if(ch[j]==c1-'a'){
				ch[j]=c2-'a';
				continue;
			}
			if(ch[j]==c2-'a'){
				ch[j]=c1-'a';
			}
		}

	}
	for(int i=0; i<n; ++i){
		cout<<(char)(ch[s[i]-'a']+'a');
	}
	return 0;
}