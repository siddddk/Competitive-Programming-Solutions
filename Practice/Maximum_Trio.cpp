#include <bits/stdc++.h>
using namespace std;
unsigned long long int solve(void)
{
    unsigned long long int N;
    cin >> N;
    unsigned long long int array[N];
    
    for(unsigned long long int i = 0; i < N; i++)
    {
        cin >> array[i];
    }
    
    unsigned long long int highestValue = *max_element(array, array + N);
    
    unsigned long long int highestValueCount = 0;
    for(unsigned long int i = 0; i < N; i++)
    {
        if(array[i] == highestValue)
        highestValueCount++;
    }
    
    unsigned long long int secondHighestValue = 0;
    for(unsigned long int i = 0; i < N; i++)
    {
        if(array[i] > secondHighestValue && array[i] != highestValue)
        secondHighestValue = array[i];
    }
    
    unsigned long long int lowestValue = *min_element(array, array + N);
    
    
    unsigned long long int answer;
    
    if(highestValueCount == 1)
    {
        answer = (highestValue - lowestValue)*secondHighestValue;
    }
    else
    {
        answer = (highestValue - lowestValue)*highestValue;
    }
    return answer;
}
int main() {
	// your code goes here
	int T;
	cin >> T;
	unsigned long long int answers[T];
	for(int i = 0; i < T; i++)
	{
	    answers[i] = solve();
	}
	for(int i = 0; i < T; i++)
	{
	    cout << answers[i] << endl;
	}
	
	return 0;
}
