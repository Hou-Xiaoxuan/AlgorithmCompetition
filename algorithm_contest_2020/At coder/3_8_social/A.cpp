#include<bits/stdc++.h>
using namespace std;

int main()
{
    char s[100];
    bool flag=true;
    while(cin>>s)
    {
        int i;
        if(strlen(s)&1) flag=false;
        for(i=0;i<strlen(s);i+=2){

            if(s[i]=='h' and s[i+1]=='i') continue;
            else flag=false;
        }
        if(flag) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}