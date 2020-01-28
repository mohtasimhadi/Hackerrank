#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, d;
    cin >> n >> d;
    int arr[n];

    for(int i=0; i<n; i++)
        cin >> arr[i];

    for(int i=d; i<n; i++)
        cout << arr[i] << " ";

    for(int i=0; i<=d-1; i++)
    {
        cout << arr[i];
        if(i<=d-1)
            cout << " ";
        else
            cout << endl;
    }
    return 0;
}
