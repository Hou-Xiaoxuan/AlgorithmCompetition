#include<bits/stdc++.h>
using namespace std;
//уп
const int inf=2147483647;
int main()
{
    char s[1005],ans[1005];
    cin>>s;
    strcpy(ans,s);
    for(int i=1;i<strlen(s);i++)
        if(strcmp(ans,s+i)<0)
            strcpy(ans,s+i);
    cout<<ans<<endl;
    return 0;
}