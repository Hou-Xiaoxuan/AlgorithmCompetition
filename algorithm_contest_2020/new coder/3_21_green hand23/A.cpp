#include<bits/stdc++.h>
using namespace std;
//���⣺nȡֵ��ôС��������ö�ٶ��������
//�Ż����ö����������� ��i< 1<<n�е�ÿ����������0��1��ɵ�
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




//�ô���Ĵ���ԭ��ʱ �к��и����
int maain()
{
    int t;cin>>t;
    while(t--)
    {   
        int n,m,a,b;
        cin>>n>>m>>a>>b;
        vector<int> is(n+1);
        for(int i=1;i<=a;i++) is[n-i+1]=1;//����Ӧ��ʱ����next_permutation �ǵ����ģ����ǵݼ���
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
