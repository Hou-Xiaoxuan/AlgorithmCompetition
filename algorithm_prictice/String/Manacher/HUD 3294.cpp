#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define   P  pair<int,int>
#define x first
#define y second 
typedef long long LL;
typedef unsigned long long ULL;
const int inf=0x3f3f3f3f;

void maxLcsplenth(string &str)
{
    if(str.length()==0) return;
    int len=str.length()*2+1;
    vector<int> p(len+5);
    vector<char> s(len+5);
    int index=0;
    for(int i=1;i<=len;i++)
        s[i]=(i&1)?'#':str[index++];
    
    int C=-1,R=-1;
    int ans=0;
    int id;
    for(int i=1;i<=len;i++)
    {
        p[i]=i>R?1:min(R-i,p[2*C-i]);
        while(i+p[i]<=len and i-p[i]>=1)
        {
            if(s[i+p[i]]==s[i-p[i]]) p[i]++;
            else break;
        }

        if(i+p[i]>R){
            R=i+p[i];
            C=i;
        }
        if(p[i]-1>ans){
            id=i;
            ans=p[i]-1;
        }
    }
    if(ans==1) cout<<"No solution!"<<endl;
    else
    {
        int l=id-p[id]+1,r=id+p[id]-1;
        if(l&1) l++;
        if(r&1) r--;
        cout<<l/2-1<<" "<<r/2-1<<endl;
        for(int i=l;i<=r;i++)
            if((i&1)==0) cout<<s[i];
        cout<<endl;
    }
}

int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin); 
    #endif
    

    char ch;
    while(cin>>ch)
    {
        string str;
        cin>>str;
        int k=ch-'a';
        for(int i=0;i<str.length();i++)
        {
            str[i]-=k;
            if(str[i]<'a')
                str[i]+=26;
        }
        // cout<<str<<endl;
        maxLcsplenth(str);
    }
    return 0;
}
