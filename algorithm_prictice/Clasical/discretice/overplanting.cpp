//https://www.luogu.com.cn/problem/P1884
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
//ɨ����ģ�壺��ɢ��+�߶���
//����r+1 and r-1�����⣺
//���������ɢ�� 1-6 2-13 3-80���Ҵ�6~80ͿĨ����ɢ�������1~3������ÿ�����ִ����ʱһ�����䣬1����6~13��2����13~80��
//���� ͿĨ1~3ʵ������ͿĨ�����飺1~2�飻���� ����ʱ��Ҫ r-1��
//����ʵ�ʾ����ʱ�򣬱���������ȷ�� 1~2����Ҫ����ģ����ǣ�ʵ�ʾ����� ��ɢ��ǰ�� 80 - 6����ha[2+1]=ha[1];
struct seg
{
    int l,r,h;
    int d;
    seg(int x1=0,int x2=0,int H=0,int c=0):l(x1),r(x2),h(H),d(c){};
    bool operator<(const seg &a) const{
        //if(h==a.h)
            //return d<a.d;
        return h<a.h;
    }
}s[2005];

int mark[2001<<2];//�ױ���
int sum[2001<<2];//�ױ߳���
int ha[2005];//��ɢ��ǰ
map<int,int> hmp;//��ɢ����

void upload(int n,int left,int right)
{
    if(mark[n]){
        sum[n]=ha[right+1]-ha[left];
        //sum[n]=ha[right]-ha[left]+1;
    }
    else if(left==right) sum[n]=0;
    else sum[n]=sum[n<<1]+sum[n<<1|1];
}
void update(int l,int r,int d,int n,int left,int right)
{
    if(l<=left and r>=right){
        mark[n]+=d;
        upload(n,left,right);//ÿ�θ��Ķ�����sum��ȷ��sum��ʵʱ��
        return;
    }
    int mid=left+right>>1;
    if(l<=mid) update(l,r,d,n<<1,left,mid);
    if(r>mid) update(l,r,d,n<<1|1,mid+1,right);
    upload(n,left,right);
}

int main()
{
    //freopen("D:\\CODE\\code_prictice\\in.txt","r",stdin);  
    int n;cin>>n;
    for(int i=1;i<=n;i++){//����
        int x1,x2,y1,y2;
        cin>>x1>>y2>>x2>>y1;
        ha[i*2-1]=x1; ha[i*2]=x2;
        s[i*2-1]=seg(x1,x2,y1,1);
        s[i*2]=seg(x1,x2,y2,-1);
    }
    sort(ha+1,ha+1+n*2);
    sort(s+1,s+1+n*2);
    int m=unique(ha+1,ha+1+n*2)-ha-1;
    for(int i=1;i<=m;i++)
        hmp[ha[i]]=i;//��ɢ��
    LL ans=0;
        // for(int i=1;i<=n*2;i++)
        //     printf("%d -> %d %d and %d\n",s[i].l,s[i].r,s[i].d,s[i].h);

    for(int i=1;i<n*2;i++)
    {   
        update(hmp[s[i].l],hmp[s[i].r]-1,s[i].d,1,1,m);
        ans+=sum[1]*LL(s[i+1].h-s[i].h);//��int
    //printf("%d :%d\n",i,sum[1]*(s[i+1].h-s[i].h));
    }
    cout<<ans<<endl;
    
    return 0;
}







/*
int con[1005][1005]={0};
��ѵ�� ��ά��ɢ��ʱ������������Ҫ�ֱ���ɢ�������ܷŵ�һ��
//��ɢ������Ϊ�㻯Ϊ���ӵ����⣬��Ҫ�����ˡ�
void show(int m)
{
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++)
            printf("%3d",con[i][j]);
        cout<<endl;
    }
    int t=10;
    while(t--) cout<<"--- ";
    cout<<endl;
}
int main()
{
    freopen("D:\\CODE\\code_prictice\\in.txt","r",stdin);  

    int n;cin>>n;
    vector< pair<P,P> > a(n+1);
    vector<int> a1(n*4+1);//before discretic
    for(int i=1;i<=n;i++)
    {
        cin>>a1[i*4-3]>>a1[i*4-2]>>a1[i*4-1]>>a1[i*4];
        a1[i*4-3]++;a1[i*4]++;
        a[i]=m_p( m_p(a1[i*4-3],a1[i*4-2]),m_p(a1[i*4-1],a1[i*4]) );
    }
    sort(a1.begin()+1,a1.end());
    int m=unique(a1.begin()+1,a1.end())-a1.begin()-1;
    map<int,int> mp,np;
    for(int i=1;i<=m;i++)
        mp[a1[i]]=i;//discretic
     mp[a1[m]+1]=m+1;
     mp[a1[1]-1]=0;
    for(auto i:mp) np[i.second]=i.first;
//     for(int i=1;i<=n;i++)
//     {
//         P st=a[i].first,ed=a[i].second;
//         swap(st.second,ed.second);

// //printf("(%d %d) -> (%d %d)\n",mp[st.first],mp[st.second],mp[ed.first],mp[ed.second]);
//         con[mp[st.first]][mp[st.second]]++;     
//         con[mp[st.first]][mp[ed.second]+1]--;
//         con[mp[ed.first+1]][mp[st.second]]--;
//         con[mp[ed.first]+1][mp[ed.second]+1]++;
// //show(m);
//     }

//     for(int i=1;i<=m;i++)
//         for(int j=1;j<=m;j++)
//             con[i][j]+=con[i][j-1]+con[i-1][j]-con[i-1][j-1];
//     LL ans=0;
//     for(int i=1;i<=m;i++)
//         for(int j=1;j<=m;j++)
//         {
//             if(con[i][j]){
//                 ans+=LL(np[i]-np[i-1])*LL(np[j]-np[j-1]);
// //cout<<i<<","<<j<<" "<<"+"<<LL(np[i]-np[i-1])*LL(np[j]-np[j-1])<<endl;
//             }
//         }
// //show(m);
//     cout<<ans<<endl;

    for(int i=1;i<=n;i++)
    {
        P s=a[i].first,e=a[i].second;
        swap(s.y,e.y);
        con[mp[s.x]][mp[s.y]]++;
        con[mp[s.x]][mp[e.y]+1]--;
        con[mp[e.x]+1][mp[s.y]]--;
        con[mp[e.x]+1][mp[e.y]+1]++;
    printf(" %d %d -> %d %d\n",s.x,s.y,e.x,e.y);
    }
    for(int i=1;i<=m+1;i++)
        for(int j=1;j<=m+1;j++)
            con[i][j]+=con[i][j-1]+con[i-1][j]-con[i-1][j-1];
    LL ans=0;
    for(int i=1;i<=m;i++)
    {
        int l=0;
        for(int j=1;j<=m+1;j++)
        {
            if(con[i][j])
            {
                if(l==0)
                    l=j;
                else continue;
            }
            else
            {
                if(l==0)
                    continue;
                else{
                    ans+=(np[j]-np[l])*(np[i]-np[i-1]);
            printf("%d->%d * %d-%d\n",np[j],np[l],np[i],np[i-1]);
                    l=0;
                }
            }
        }
    }
    show(m);
    cout<<ans<<endl;
    return 0;
}
*/