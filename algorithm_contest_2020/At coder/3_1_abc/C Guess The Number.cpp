#include<bits/stdc++.h>
using namespace std;
//ֻҪ�������������ˣ����û�����������λ���Գ�ʼ��Ϊ1
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        vector<int> a(n+1),vis(n+1);    
        for(int i=1;i<=n;i++) a[i]=0,vis[i]=false;
        int x,y;
        bool flag=true;
        if(n>1) a[1]=1;//Ϊ����һ�䣬������һ��Сʱ
        for(int i=1;i<=m;i++)
        {
            cin>>x>>y;
            if(vis[x]==true and a[x]!=y)
                flag=false;
            else{
                a[x]=y; 
                vis[x]=true;
            }
        }
        if(n!=1 and a[1]==0) flag=false;
        if(flag)
            for(int i=1;i<=n;i++)
                cout<<a[i];
        else
            cout<<-1;       
        cout<<endl;
    }
    return 0;
}
