#include<bits/stdc++.h>
using namespace std;
#define  m_k make_pair
#define   P  pair<int,int>
#define  V vector
typedef long long LL;
typedef unsigned long long ULL;
int main()
{
    //freopen("D:\\code_contest\\in.txt","w",stdout);
    //freopen("D:\\code_contest\\in.txt","r",stdin);    
    
    int t;cin>>t;
    while(t--)
    {
        int a,b,c,d;cin>>a>>b>>c>>d;
        P st,s1,s2;
        cin>>st.first>>st.second>>s1.first>>s1.second>>s2.first>>s2.second;
        bool flag=false;
        if(st.first-a+b>=s1.first and st.first-a+b<=s2.first)
            if(st.second-c+d>=s1.second and st.second-c+d<=s2.second)
                flag=true;
        //if(st.first==s1.first and a<b) flag=false;
        //if(st.first==s2.first and b>a) flag=false;
        //if(st.second==s1.second and c<d) flag=false; 
        //if(st.second==s2.second and d>c) flag=false;
        if(st.first==s1.first and s1.first==s2.first and (a or b)) flag=false;
        if(st.second==s2.second and s1.second==s2.second and (c or d)) flag=false;
        if(flag) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;



    }

    return 0;
}