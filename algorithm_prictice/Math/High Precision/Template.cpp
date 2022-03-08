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
/*
*高精度模板
*默认初始化的时候字符串都是正的，符号另外给参数
*累……就这样吧，不想去封装和重载了
*/
class HighP
{
private:
// 从1开始倒着存，0存符号位
    static const int N=20005;
    int s[N];
    int size;
    static inline bool compair(const int *a,int lena,int const *b,int lenb);
public:
    HighP(const char *a="",bool sign=true);
    HighP(const int *a,int len=0,bool sign=true);
    void print();
    int ss(int x){return s[x];};
    static HighP Add(const HighP &a,const HighP &b);
    static HighP Sub(const HighP &a,const HighP &b);
    static HighP Muti(const HighP &a,const HighP &b);
    static HighP Divi(const HighP &a,const long long &b);
    static HighP Divi(const HighP &a,const HighP &b);
};
HighP R;//存放余数
HighP::HighP(const char *a,bool sign)
{
    // 构造函数，反向赋值
    if(a==NULL) return;
    memset(s,0,sizeof(s));
    int len=strlen(a);
    for(int i=1;i<=len;i++)
        s[i]=a[len-i]-'0';
    size=len;
    if(sign==false) s[0]=-1;
    else s[0]=1;
}
HighP::HighP(const int *a,int len,bool sign)
{
    // 这个构造函数 是正向赋值的
    if(len==0)
        s[1]=0;
    
    memset(s,0,sizeof(s));
    for(int i=0;i<len;i++)
        s[i+1]=a[i];
    size=len;
    if(sign==false) s[0]=-1;
    else s[0]=1;
}
void HighP::print()
{
    if(s[0]==-1) cout<<'-';
    for(int i=size;i>=1;i--) cout<<s[i];
}
HighP HighP::Add(const HighP &a,const HighP &b)
{
    if(a.s[0]<0 and b.s[0]>0) return Sub(b,a);
    else if(a.s[0]>0 and b.s[0]<0) return Sub(a,b);

    HighP ans;
    ans.s[0]=a.s[0];
    int c=0;
    int len=max(a.size,b.size);
    for(int i=1;i<=len;i++){
        c+=a.s[i]+b.s[i];
        ans.s[i]=c%10;
        c/=10;
    }
    if(c!=0){
        ans.s[++len]=c;
    }
    ans.size=len;
    return ans;
}
HighP HighP::Sub(const HighP &a,const HighP &b)
{
    if(a.s[0]<0 and b.s[0]<0) return Sub(b,a);
    else if(a.s[0]<0 and b.s[0]>0){
        HighP tmp=a;
        tmp.s[0]=1;
        HighP ans=Add(tmp,b);
        ans.s[0]=-1;
        return ans;
    }
    else if(a.s[0]>0 and b.s[0]<0){
        HighP tmp=b;
        tmp.s[0]=1;
        HighP ans=Add(a,tmp);
        ans.s[0]=-1;
        return ans;
    }
    HighP ans;
    int sig;
    // 判断符号
    if(a.size>b.size) sig=1;
    else if(a.size<b.size) sig=-1;
    else
    {
        for(int i=a.size;i>=1;i--)
        {
            if(a.s[i]>=b.s[i]) continue;
            else {
                sig=-1;
                break;
            }
        }
        if(sig!=-1) sig=1;
    }
    ans.s[0]=sig;
    int len=max(a.size,b.size);
    for(int i=1;i<=len;i++)
        ans.s[i]=(sig==1?1:-1)*(a.s[i]-b.s[i]);
    for(int i=1;i<=len;i++)
        if(ans.s[i]<0){
            ans.s[i]+=10;
            ans.s[i+1]--;
        }
        
    
    while(ans.s[len]==0) len--;
    if(len==0) len=1;
    ans.size=len;
    return ans;
}
HighP HighP::Muti(const HighP &a,const HighP &b)
{
    HighP ans;
    int sig=a.s[0]*b.s[0];
    for(int i=1;i<=a.size;i++)
        for(int j=1;j<=b.size;j++)
            ans.s[i+j-1]+=a.s[i]*b.s[j];
    for(int i=1;i<=a.size+b.size;i++){
        ans.s[i+1]+=ans.s[i]/10;
        ans.s[i]%=10;
    }    
    ans.s[0]=sig;
    int len=a.size+b.size+2;
    while(len>1 and ans.s[len]==0) len--;
    ans.size=len;
    return ans;

}
HighP HighP::Divi(const HighP &a,const long long &b)
{
    // 高精度除低精度
    // 没有余数，忽略了
    HighP ans;
    ans.s[0]=a.s[0];
    LL c=0;
    for(int i=a.size;i>=1;i--)
    {
        c=c*10+a.s[i];
        ans.s[i]=c/b;
        c%=b;
    }
    int len=a.size;
    while(len>1 and ans.s[len]==0) len--;
    ans.size=len;
    return ans;
}
inline bool HighP::compair(const int *a,int lena,const int *b,int lenb)
{
    // 小于返回treu
    if(lena!=lenb) return lena<lenb;
    for(int i=lena;i>=1;i--)
        if(a[i]!=b[i]) return a[i]<b[i];
    return true;
}
HighP HighP::Divi(const HighP &a,const HighP &b)
{
    int *as=new int[N],*d=new int[N];
    // int as[N],bs[N],d[N];
    int lena=a.size,lenb=b.size;
    int len=max(lena,lenb);

    memset(as,0,sizeof(int)*N);
    for(int i=1;i<=len;i++)
        as[i]=a.s[i];
       
    HighP ans;
    ans.s[0]=a.s[0]*b.s[0];
    // 特判
    for(int i=lena-lenb+1;i>=1;i--)
    {
        // 将b扩充到与a位数相同，每次循环位数减1
        memset(d,0,sizeof(int)*N);
        for(int j=1;j<=lenb;j++)
            d[j+i-1]=b.s[j];
        while(compair(d,lenb+i-1,as,lena))
        {
            ans.s[i]++;
            for(int i=1;i<=lena;i++)
            {   
                as[i]-=d[i];
                if(as[i]<0){
                    as[i+1]--;
                    as[i]+=10;
                }
            }
            while(lena>=1 and as[lena]==0) lena--;
        }
    }
    len=max(a.size-b.size+1,1);//防止size为负数
    while(len>1 and ans.s[len]==0) len--;
    ans.size=len;
    // as中剩余的就是余数，需要的话引用传递回去
    R=HighP(as+1,lena);//构造函数需要从0开始
    delete[]as; delete[]d;
    return ans;
}


int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_prictice\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_prictice\\in.txt","r",stdin); 
    #endif
    
    return 0;
}