#include<bits/stdc++.h>
using namespace std;

const int N=1e2+5;
char s[N];
int kmp[N];
int main()
{
    int T=0;
    while(cin>>(s+1))
    {   T++;
        cout<<"Test Case #"<<T<<endl;
        kmp[1]=0;
        int j=0,len=strlen(s+1);
        for(int i=2;i<=len;i++){
            while(j>0 and s[j+1]!=s[i]) j=kmp[j];
            if(s[j+1]==s[i]) j++;
            kmp[i]=j;
            if(i%(i-j)==0 and i/(i-j)>1)
                cout<<i-j<<" "<<i/(i-j)<<endl;
        }
    }
    return 0;
}
/*
*当初代码不写注释，如今两行泪啊
*/