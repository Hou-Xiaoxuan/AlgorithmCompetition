#include<bits/stdc++.h>
using namespace std;
//补题：n取值这么小就是用来枚举多有情况的
//优化：用二进制来代替 ，i< 1<<n中的每个数都是有0，1组成的
string s[30];
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int n,m,a,b;
    while(t--){
        cin>>n>>m>>a>>b;
        bool flag=false;
        for(int i=1;i<=n;i++) cin>>s[i];
        vector<int> sta(n+1);
        for(int i=1;i<=a;i++) sta[n-i+1]=1;
        do
        {   
            int cnt=0;
            for(int j=0;j<m;j++)
                for(int i=1;i<=n;i++)
                    if(sta[i]==0 and s[i][j]=='*'){
                        cnt++;break;
                    }
            if(cnt<=b)
                flag=true;     
        }while(flag==false and next_permutation(sta.begin()+1,sta.end()));

        if(flag) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    
    return 0;
}




//该代码的错误原因时 行和列搞混了
int maain()
{
    int t;cin>>t;
    while(t--)
    {   
        int n,m,a,b;
        cin>>n>>m>>a>>b;
        vector<int> is(n+1);
        for(int i=1;i<=a;i++) is[n-i+1]=1;//这里应该时逆序，next_permutation 是递增的，不是递减的
        vector<vector<char> > ch(n+1);
        for(int i=1;i<=n;i++){
            ch[i].push_back('\0');
            for(int j=1;j<=m;j++){
                char cc;cin>>cc;
                ch[i].push_back(cc);
            }
        }

        bool flag=false;
        vector<int> cnt;
        do
        {
            
            for(int i=1;i<=n;i++)
            {
                if(is[i]==1) continue;
                else{
                    for(int j=1;j<=m;j++)
                        if(ch[i][j]=='*')
                            cnt.push_back(j);
                }
            }
            sort(cnt.begin(),cnt.end());
            int tmp=unique(cnt.begin(),cnt.end())-cnt.begin();
            if(tmp<=b) flag=true;
            cnt.clear();
        } while (next_permutation(is.begin()+1,is.end()) and flag==false);
        if(flag==true)
            cout<<"yes"<<endl;
        else cout<<"no"<<endl;
        
    }
 
    return 0;
}
