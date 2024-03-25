#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
	 string A,B;
	 cin>>A>>B;
	 int N;
	 cin>>N;
	  vector <string> C(N);
	 for(int j=0;j<N;j++)
	 {
	 cin>>C.at(j);    
	 }
	 string concat = "";
	 for(int k=0;k<N;k++)
	 {
	    concat+=C[k];
	 }
	 string AplusB= A+B;
	 int count1=0;
	 int count=0;
	for(int k=0;k<concat.length();k++)
	{
		count = 0;
	    for(int l=0;l<AplusB.length();l++)
	    {
	        if(AplusB.at(l)==concat.at(k));
	        {
	            AplusB[l] = 'A';
	            count++;
	            count1++;
	            break;
	        }	        
	    }
	    if(count==0)
	    {
	    cout<<"NO"<<endl;
		return 0;
	    }
	}
	if (count1==concat.length())
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout << "NO" << "\n";
	}
	
	}
	return 0;
}