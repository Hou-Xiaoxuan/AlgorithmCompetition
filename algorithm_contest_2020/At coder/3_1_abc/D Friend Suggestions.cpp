#include<bits/stdc++.h>
//����
using namespace std;
const int N=1e5+5;
int pa[N],cnt[N],fr[N];
 int n,m,k;
 //�����ɵ�ƣ�search������д��һ��ֵ:: pa[x]==x?x:search(x);
int search(int x){
    //if(pa[x]!=pa[pa[x]]) pa[x]=search(pa[x]);//*��һ���ٶȾ�Ȼ�ܲ� 50������
    return pa[x]==x?pa[x]:pa[x]=search(pa[x]);
    
}
inline void uion(int x,int y){//*��ֹ��һ�䣬����������д�ں���������Ļ����ʹ���
    int a=search(x);
    int b=search(y);
    if(a!=b){
        pa[a]=b;
        cnt[b]+=cnt[a];   
     }
}
int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(cin>>n>>m>>k)
    { 
        for(int i=1;i<=n;i++){
            pa[i]=i; cnt[i]=1; fr[i]=0;
        }
        int x,y;
        while(m--) {
            cin>>x>>y;
            fr[x]++;fr[y]++;
            uion(x,y);
        }
        for(int i=1;i<=n;i++){
            cnt[i]=cnt[search(i)];
        }
        while(k--)
        {
            cin>>x>>y;
            int a=search(x);
            int b=search(y);
            if(a==b){
                cnt[x]--; cnt[y]--;
            }
        }
        for(int i=1;i<=n;i++)
            cout<<cnt[i]-fr[i]-1<<' ';
        cout<<endl;
    
    }

    return 0;
}