#include<bits/stdc++.h>
using namespace std;
//the thought is right,but don't have time.
//make up:AC
int main()
{
    #ifndef ONLINE_JUNGLE
    //freopen("D:\\code_contest\\in.txt","w",stdout);
    //freopen("D:\\code_contest\\in.txt","r",stdin);    
    #endif
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int st,ed,tmp,flag=-1;
        bool is_one=true;
        cin>>st; tmp=st;
        for(int i=2;i<=n;i++){
            cin>>ed;
            if(ed==tmp) flag=i;
            else is_one=false;
            tmp=ed;
        }

        if(is_one){//all same
            cout<<1<<endl;
            for(int i=1;i<=n;i++)
                cout<<1<<" ";
            cout<<endl;
            continue;
        }
        if(n%2==0 or st==ed){//colud  just 1 2 1 2……
            cout<<2<<endl;
            for(int i=1;i<=n;i++)
                cout<< (i&1?1:2)<<" ";
            cout<<endl;
            continue;
        }
        if(flag==-1){//should use 3
            cout<<3<<endl;
            for(int i=1;i<n;i++)
                cout<<(i&1?1:2)<<" ";
            cout<<3<<endl;
            continue;
        }
        //could 1 2 1 2……2 1 2 1 2
        cout<<2<<endl;
        for(int i=1;i<flag;i++)
            cout<<(i&1?1:2)<<" ";
        for(int i=flag;i<=n;i++)
            cout<<(i&1?2:1)<<" ";
        cout<<endl;
    }


    return 0;
}

//my self
/*
int main()
{
    #ifndef ONLINE_JUNGLE
    //freopen("D:\\code_contest\\in.txt","w",stdout);
    //freopen("D:\\code_contest\\in.txt","r",stdin);    
    #endif
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        vector<bool> sta(n+2);
        int i1;cin>>i1;
        int ia,ib;
        ia=i1;
        for(int i=2;i<=n;i++){
            cin>>ib;
            if(ia==ib)
                sta[i]=false;
            else sta[i]=true;
            ia=ib;
        }
        if(ib==i1)
            sta[1]=false;
        else sta[1]=true;
        bool flag=false;
        vector<int> ans(n+1);
        ans[1]=1;
        int k=1;
        for(int i=2;i<=n;i++)
        {
            
            if(sta[i]==true)//diff
                ans[i]= ans[i-1]==1?2:1;
            if(sta[i]==false)//same
            {
                if(flag==true){
                    ans[i]= ans[i-1]==1?2:1;
                    flag=false;
                }
                else ans[i]=ans[i-1];
            }
            if(k==1 and ans[i]==2) k=2;//原来昨天我就差一个检验了，时间啊，再有十分钟，b题忘记注释，醉了
        }
        if(sta[1]==true and ans[1]==ans[n]) flag=true;
        
        if(flag)
        for(int i=2;i<=n;i++)
        {
            if(sta[i]==true)//diff
                ans[i]= ans[i-1]==1?2:1;
            if(sta[i]==false)//same
            {
                if(flag==true){
                    ans[i]= ans[i-1]==1?2:1;
                    flag=false;
                }
                else ans[i]=ans[i-1];
            }
        }
        
        if(sta[1]==true and ans[1]==ans[n]) ans[n]=3,k++;
        cout<<k<<endl;
        for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }


    return 0;
}
*/