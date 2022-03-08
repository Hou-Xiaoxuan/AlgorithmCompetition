#include<bits/stdc++.h>
using namespace std;

int main()
{
    char s[4];
    while(cin>>s)
    {
        if(s[0]==s[1] and s[1]==s[2])
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;
    }
    return 0;
}