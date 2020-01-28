#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    string s;
    int i,j,n,l,f;
    cin>>n;

    getchar();
    while(n--)
    {

        getline(cin,s);
        l=s.length();
        stack<char>q;
        f=0;

        for(i=0; i<l; i++)
        {
            if(s[i]=='('||s[i]=='['||s[i]=='{')
                q.push(s[i]);
            else if(!q.empty()&&s[i]==')'&&q.top()=='(')
                q.pop();
            else if(!q.empty()&&s[i]==']'&&q.top()=='[')
                q.pop();
            else if(!q.empty()&&s[i]=='}'&&q.top()=='{')
                q.pop();
            else
                q.push(s[i]);
        }

        if(q.empty())
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;

    }

    return 0;
}
