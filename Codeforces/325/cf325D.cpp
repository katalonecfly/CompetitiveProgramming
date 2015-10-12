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

struct node {
	int row, col;
	node(int r, int c) {
		row=r;
		col=c;
	}
};

int main(){
	cin.sync_with_stdio(false);
	int T;
	cin>>T;
	for(int t=0; t<T; ++t){
		int n, k;
		vector<string> v;
		string s;
		cin>>n>>k;
		for(int i=0; i<3; ++i){
			cin>>s;
			v.push_back(s);
		}

		int startrow=-1;
		for(int i=0; i<3; ++i){
			v[i]+="$$$$$$";
			if(v[i][0]=='s'){
				startrow=i;
			}
		}

		queue<node> q;
		q.push(node(startrow, 0));

		bool found=0;
		bool visited[3][105]={ 0 };
		while(!q.empty()){
			node f=q.front();
			q.pop();
			//cout<<f.col<<" "<<f.row<<endl;

			if(visited[f.row][f.col]){
				continue;
			}
			visited[f.row][f.col]=1;

			if(v[f.row][f.col]=='$'){
				found=1;
				cout<<"YES"<<endl;
				break;
			}

			if(v[f.row][f.col+1]!='.'&&v[f.row][f.col+1]!='$'){
				continue;
			}

			for(int i=-1; i<=1; ++i){
				int newrow=f.row+i;
				if(0<=newrow && newrow<3){
					if(  (v[newrow][f.col+1]=='.'||v[newrow][f.col+1]=='$')&&
						 (v[newrow][f.col+2]=='.'||v[newrow][f.col+2]=='$')&&
						 (v[newrow][f.col+3]=='.'||v[newrow][f.col+3]=='$')){

						q.push(node(newrow, f.col+3));
					}
							 
				}
			}

		}

		if(!found){
			cout<<"NO"<<endl;
		}
	}
	return 0;
}