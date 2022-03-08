#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> P;
#define k_p make_pair


int main()
{
    char s[10];
    while(cin>>s+1)
    {
        if(s[3]==s[4] and s[5]==s[6])
            cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
