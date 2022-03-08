//AC
#include<bits/stdc++.h>
using namespace std;

int main()
{
    
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,cnt=0;
        cin>>a>>b>>c;
        if(a<b) swap(a,b);//优先使用最多的
        if(a<c) swap(a,c);
        if(b<c) swap(a,c);
        if(a) a--,cnt++;
        if(b) b--,cnt++;
        if(c) c--,cnt++;
        if(a and b) a--,b--,cnt++;
        if(a and c) a--,c--,cnt++;
        if(b and c) b--,c--,cnt++;
        if(a and b and c) cnt++;
        cout<<cnt<<endl;
    }
   // system("pause");
    return 0;
}
