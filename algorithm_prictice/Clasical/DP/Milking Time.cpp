#include<bits/stdc++.h>
using namespace std;
//���ĺ�AC��˼·��ȷ��
//��1����0��ʼ����� ��2�����ұϣ���ʵ��������ұգ�Ҳ�Ͳ�����1��
//�������˼·�����Ϊm^2��˼·���ռ䳣��С
/*
    ���˼·�������
    for(int i=1;i<=m;i++)//i����Ž�ȥ
        for(int j=1;j<i;j++){ǰ������i����ģ���һ��
            if(i.end>j.start)
                f[i]=max(f[i],f[j]+j.value);
        }
    for(1����m) max(f[i])=ans;
*/
struct num{
    int t;
    int v;
    num(int tt,int vv):t(tt),v(vv){};
    bool operator<(num a){
        return t<a.v;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,m,r;
    
    while(cin>>n>>m>>r)
    {
        //for(int i=0;i<=n;i++) f[i]=0;
        vector<int>f(n+r+2);
        vector<vector<num> > ma(n+r+2);
        for(int i=1;i<=m;i++){
            int a,b,c;  
            cin>>a>>b>>c;
            //a++;b++;
            num tmp(b+r-a,c);//��Ȼ�����ұյġ���
            ma[b+r].push_back(tmp);
        }
        int ans=0;
        for(int i=1;i<=n+r+1;i++)//ö�ٽ���ʱ��i
        {
            for(int j=0;j<ma[i].size();j++)
                if(i-ma[i][j].t>=0){
                    f[i]=max(f[i],f[i-ma[i][j].t]+ma[i][j].v);
            }
           f[i]=max(f[i],f[i-1]);
        }
        
        for(int i=1;i<=n+r+1;i++) ans=max(ans,f[i]);
        cout<<ans<<endl;
    }

    return 0;
}