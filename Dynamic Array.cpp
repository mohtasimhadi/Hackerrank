#include<bits/stdc++.h>
using namespace std;
int last;
int n, q, i, j, k, l, m, x, y;
int main()
{

    cin>>n>>q;
    vector<int>v[n+1];
    while(q--)
    {
        cin>>k>>x>>y;
        l=(x^last)%n;
        if(k==1)
            v[l].push_back(y);
        else
        {
            int sz=v[l].size();
            if(sz!=0)
                m=y%sz;
            else
                continue;
            cout<<v[l][m]<<endl;
            last=v[l][m];
        }
    }
}
