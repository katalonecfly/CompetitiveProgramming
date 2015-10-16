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

// SegmentTree class, answer range minimum queries(RMQ) in O(logN), without update
// code from Competitive programming 3 book 

class SegmentTree{
private:
	vector<int> st, A;
	int n;
	int left(int p){
		return p<<1;
	}
	int right(int p){
		return (p<<1)+1;
	}
	
	void build(int p, int L, int R){
		if(L==R){
			st[p]=L;
		}else{
			build(left(p), L, (L+R)/2);
			build(right(p), (L+R)/2+1, R);
			int p1=st[left(p)], p2=st[right(p)];
			st[p]= (A[p1]<=A[p2])  ? p1 : p2;
		}
	}
	
	int rmq(int p, int L, int R, int i, int j){
		if(i>R || j<L) return -1;
		if(L>=i && R<=j) return st[p];
		int p1=rmq(left(p), L, (L+R)/2, i, j);
		int p2=rmq(right(p), (L+R)/2+1, R, i, j);
		if(p1==-1) return p2;
		if(p2==-1) return p1;
		return (A[p1]<=A[p2]) ? p1 : p2;
	}
	
public:
	SegmentTree(const vector<int> & _A){
		A=_A;
		n=(int)A.size();
		st.assign(4*n, 0);
		build(1, 0, n-1);
	}
	int rmq(int i, int j){
		return rmq(1, 0, n-1, i, j);
	}
};

int main(){
	int a[]={18,17,13,19,15,11,20};
	vector<int> A(a, a+7);
	SegmentTree st(A);
	cout<<st.rmq(1,3)<<" "<<st.rmq(4,6);
	return 0;
} 