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

int gcd(int a, int b){
	return b==0 ? a : gcd(b, a%b);
}

int lcm(int a, int b){
	return a*(b/gcd(a, b));
}

long long sieve_size;
bitset<10000010> bs;
vector<int> primes;

//sieve if Eratosthenes
void sieve(long long upperbound){
	sieve_size=upperbound+1;
	bs.set(); //set all bits in bs to 1
	bs[0]=bs[1]=0;
	for(long long i=2; i<=sieve_size; ++i){
		for(long long j=i*i; j<=sieve_size; j+=i){
			bs[j]=0;
		}
		primes.push_back((int)i);
	}
}

//check if number is prime, need sieve() called
bool isPrime(long long N){
	if(N<=sieve_size){
		return bs[N];
	}
	for(int i=0; i<(int)primes.size(); ++i){
		if(N%primes[i]==0){
			return false;
		}
	}
	return true;
}

//call sieve before using this function
//if N > 32bit, then need to change factors to long long vector
vector<int> primeFactors(long long N){ 
	vector<int> factors;
	long long PF_idx=0, PF=primes[PF_idx]; 
	while(PF*PF<=N){
		while(N%PF==0){
			N/=PF;
			factors.push_back(PF);
		}
		PF=primes[++PF_idx];
	}
	if(N!=1){
		factors.push_back(N);
	}
	return factors;
}

//count number of prime factors of N(with repetitions)
long long numPF(long long N){
	long long PF_idx=0, PF=primes[PF_idx], ans=0;
	while(PF*PF<=N){
		while(N%PF==0){
			N/=PF;
			ans++;
		}
		PF=primes[++PF_idx];
	}
	if(N!=1) ans++;
	return ans;
}

//count number of divisors of N
long long numDiv(long long N){
	long long PF_idx=0, PF=primes[PF_idx], ans=1;
	while(PF*PF<=N){
		long long power=0;
		while(N%PF==0){
			N/=PF;
			power++;
		}
		ans*=(power+1);
		PF=primes[++PF_idx];
	}
	if(N!=1) ans*=2;
	return ans;
}

//euler phi function of N (totient)
long long eulerPhi(long long N){
	long long PF_idx=0, PF=primes[PF_idx], ans=N;
	while(PF*PF<=N){
		if(N%PF==0){
			ans-=ans/PF;
		}
		while(N%PF==0){
			N/=PF;
		}
		PF=primes[++PF_idx];		
	}
	if(N!=1) ans-=ans/N;
	return ans;
}	

//extended euclid, solve 25x+18y=839, extendedEuclid(25, 18)
int x, y, d;
void extendedEuclid(int a, int b){
	if(b==0){
		x=1;
		y=0; 
		d=a;
		return;
	}
	extendedEuclid(b, a%b);
	int x1=y;
	int y1=x-(a/b)*y;
	x=x1;
	y=y1;
}

int main(){
	sieve(10000000);
	cout<<isPrime(1000000007)<<endl;
	
	vector<int> r=primeFactors(2147483647); //slow, big prime
	for(vector<int>::iterator i=r.begin(); i!=r.end(); ++i){
		cout<<(*i);
	}
	cout<<endl;
	
	cout<<numPF(123456)<<endl;
	cout<<numDiv(123456)<<endl;
	cout<<eulerPhi(123456)<<endl;
	
}
