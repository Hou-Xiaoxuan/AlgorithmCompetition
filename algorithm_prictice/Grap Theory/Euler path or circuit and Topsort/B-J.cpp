#include<bits/stdc++.h>
using namespace std;

//1，忘记用并查集判断图的连通性（dif也可以：只要欧拉回路存在，从任意起点开始，都能遍历所有点（存成无向图）
//2，一共就26个字母，int[27]就存下了，不用开map
//3，正解，将每个字母看成点，每个单词就是一条路。
//int read[27][27];
int pa[27],in[27],out[27];
bool vis[27];
int search(int x){
    return x==pa[x]?pa[x]:pa[x]=search(pa[x]);
}
void combin(int x,int y)
{
    int a=search(x),b=search(y);
    pa[a]=b;
}
int main()
{
    int T;cin>>T;
    while(T--)
    {
        int n;cin>>n;
        for(int i=1;i<=26;i++) pa[i]=i,vis[i]=false,in[i]=out[i]=0;
        char s[1005];
        for(int i=1;i<=n;i++){
            cin>>s;
            int x=s[0]-'a'+1,y=s[strlen(s)-1]-'a'+1;
            out[x]++,in[y]++;
            vis[x]=vis[y]=true;
            combin(x,y);
        }
        int sum=0;
        for(int i=1;i<=26;i++)
            if(vis[i] and pa[i]==i) sum++;
        if(sum>1){
            cout<<"The door cannot be opened."<<endl;
            continue;
        }
        int sum1=0,sum2=0;
        for(int i=1;i<=26;i++)
            if(in[i]==out[i]) continue;
            else if(in[i]==out[i]+1) sum1++;
            else if(in[i]+1==out[i]) sum2++;
            else sum1=sum2=10;
        /*if sum1==1,then the sum2 must be 1 too.*/
        if(sum1<2 and sum1==sum2)   cout<<"Ordering is possible."<<endl;
        else                    cout<<"The door cannot be opened."<<endl;    
    }


    return 0;
}
/*
int main()
{
    int T;cin>>T;
    while(T--)
    {
        int n; cin>>n;
        map<char,int> in,out,vis;
        char s[1005];
        for(int i=1;i<=n;i++){
            cin>>s;
            in[s[0]]++; 
            in[s[strlen(s)-1]]+=0;
            out[s[strlen(s)-1]]++; 
            out[s[0]]+=0;
        }
        
        map<char,int>::iterator i;
        int cnt=0;
        for(i=out.begin();i!=out.end();i++)
            if(abs(i->second-in[i->first])==1) 
            cnt++;
            else if(abs(i->second-in[i->first])>=2){
                cnt=10;break;
            }
        
       
        if(cnt<=2) cout<<"Ordering is possible."<<endl;
        else  cout<<"The door cannot be opened."<<endl;
    }


    return 0;
}
*/