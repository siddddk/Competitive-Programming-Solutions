#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;

int sieveArr[1000000+1] = {0};

//Sieve of Eratosthenes (O(NLogLogN))
void sieve(){
	for(long long i=2; i<=1000000; i++){
		//mark non primes as 1
		if(sieveArr[i]==0){
			//marking all multiples of i (prime) as non-prime
			for(long long j= i*i; j<=1000000+1; j+=i){
				sieveArr[j] = 1; //non-prime
			}
		}
	}
}

void solve(void)
{
    ll n;
    cin >> n;     

    ll counter = 0;

    for(ll i = 2; i <= n-2; i++)
    {
        if(sieveArr[i] == 0)
        {
            counter++;
        }
    }
    
    cout << counter << "\n";

    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    ll T;
    cin >> T;
    while(T--)
    {
        solve();
    }
    return 0;
}