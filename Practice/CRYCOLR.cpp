#include <iostream>
using namespace std;
void solve(void)
{
    int N;
    cin >> N;
    
    int R[3], G[3], B[3];
    cin >> R[0] >> G[0] >> B[0];
    cin >> R[1] >> G[1] >> B[1];
    cin >> R[2] >> G[2] >> B[2];
    
    int switches = 0;
    if(R[0] != N)
    {
        if(R[1] != 0)
        {
            switches += R[1];
            R[0] += R[1];
            G[0] -= R[1];
            G[1] += R[1];
            R[1] = 0;
        }
        if(R[2] != 0)
        {
            switches += R[2];
            R[0] += R[2];
            B[0] -= R[2];
            B[2] += R[2];
            R[2] = 0;
        }
    }
    if(G[1] != 0)
    {
        if(G[2] != 0)
        {
            switches += G[2];
            G[1] += G[2];
            B[1] -= G[2];
            B[2] += G[2];
            G[2] = 0;
        }
    }
    
    cout << switches << endl;
}
int main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
	    solve();
	}
	return 0;
}
