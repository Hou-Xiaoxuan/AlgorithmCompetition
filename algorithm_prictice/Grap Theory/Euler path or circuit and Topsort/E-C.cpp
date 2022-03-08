//#include<bits/stdc++.h>
//���Ѿ�Ҫ�����ˣ�����������
//�ҵ��׻���ʲô���⣿����
#include<queue>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
const int N=27;
bool road[N][N],way[N][N];
int in[N],pa[N],out[N];
char s[1000][10];
queue<int> ans;
bool check(const int n)//����Ƿ���ڽ�
{
    int d1[N],d2[N];
    bool vis[N];
    for(int i=1;i<=n;i++) d1[i]=in[i],d2[i]=out[i],vis[i]=false;//��ֹ�ı� ��
    queue<int> que;
    int cnt=0,cnt2=0;  
    for(int i=1;i<=n;i++){//����Ƿ����㾭 һ�������Ϊ0 �� һ�������Ϊ0
        if(d1[i]==0) que.push(i),cnt++;
        if(d2[i]==0) cnt2++;
    }
    if(cnt!=1 or cnt2!=1) return false;
    while(!ans.empty()) ans.pop();
    
    while(!que.empty())
    {
        
        int s=que.front(); que.pop();
        vis[s]=true;
        ans.push(s);
        for(int i=1;i<=n;i++)
            if(way[s][i])
                d1[i]--;
        cnt=0;
        for(int i=1;i<=n;i++)
            if(d1[i]==0 and vis[i]==false) que.push(i),cnt++;
        if(cnt!=1 and ans.size()!=n) return false;//cnt==1 ������ ��״

    }
    if(ans.size()==unsigned(n))
        return true;
    return false;
}
void solve(const int n)
{
    for(int k=1;k<=n;k++)//��road ����¶��е�֮��Ĺ�ϵ
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(road[i][k] and road[k][j])
                    road[i][j]=true;
}
int main()
{
    freopen("D:\\code\\in.txt","r",stdin);
    int n,m;
    while(cin>>n>>m)
    {
        if(n==0) break;
        int flag=-1;//�����״̬
        for(int i=1;i<=N;i++){//��ʼ��
            pa[i]=i; in[i]=0,out[i]=0;
            for(int j=1;j<=N;j++)
                road[i][j]=false;
        }
        for(int i=1;i<=m;i++)
            cin>>s[i];
        int k=-1;
        for(int i=1;i<=m;i++)
        {
            int x=s[i][0]-'A'+1,y=s[i][2]-'A'+1;
            if(road[y][x]==true){//����Ƿ��г�ͻ
                flag=1;
                cout<<"Inconsistency found after "<<i<<" relations."<<endl;
                break;
            }
            if(road[x][y]==false) in[y]++; out[x]++;//����������Ķ�
            road[x][y]=way[x][y]=true;
            solve(n);
            int cnt=0;
            for(int i=1;i<=n;i++) if(in[i]==0) cnt++;
            if(flag==-1 and check(n))//����Ƿ��н⡣����н⣬�ȱ��棬��������г�ͻ
            {
                flag=2;
                k=i;
            }
        }
        if(flag==-1)//���û�г�ͻ��Ҳû�н�
            cout<<"Sorted sequence cannot be determined."<<endl;
        else if(flag==2)//�н� �� ����ͻ
        {
            cout<<"Sorted sequence determined after "<<k<<" relations: ";
                while(!ans.empty()){
                    cout<<char(ans.front()+'A'-1);
                    ans.pop();
                }
                cout<<"."<<endl;
        }
    }
    return 0;
}