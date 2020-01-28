#include<bits/stdc++.h>
using namespace std;

int hourglassSum(int mat[6][6]);

int main()

{
    int arr[6][6];
    for (int i=0; i<6; i++)
        for(int j=0; j<6; j++)
            cin >> arr[i][j];
    cout << hourglassSum(arr);
    return 0;
}

int hourglassSum(int mat[6][6])
{
    int ans = -64;
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
        {
            ans = max(ans, mat[i][j]+mat[i][j+1]+mat[i][j+2]+mat[i+1][j+1]+mat[i+2][j]+mat[i+2][j+1]+mat[i+2][j+2]);
        }
    return ans;
}
