#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n;
    int d1=0, d2=0, sum;
    cin>>n;
    int arr[n][n];
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>arr[i][j];
    int j=n-1;
    for(int i=0; i<n; i++)
    {
        d1+=arr[i][i];
        d2+=arr[i][j];
        j--;
    }
    if(d1>d2)
        cout<<(d1-d2)<<endl;
    else
        cout<<(d2-d1)<<endl;
    
    return 0;
}
