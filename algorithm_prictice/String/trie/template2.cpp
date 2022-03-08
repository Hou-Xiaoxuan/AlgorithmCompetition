//字典树变式模板题：链表
//http://acm.hdu.edu.cn/showproblem.php?pid=1251
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define   Pii  pair<int,int>
#define x first
#define y second 
typedef long long LL;
typedef unsigned long long ULL;
const int inf=0x3f3f3f3f;

struct Trie
{
    static const int Max=26;
    int num=0;
    Trie *next[Trie::Max];
    
    void insert(Trie *root,char *s)
    {
        if(root==NULL or *s=='\0') return;
        Trie *p=root;
        while(*s!='\0')
        {
            if(p->next[*s-'a']==NULL){
                p->next[*s-'a']=new Trie;
                for(int i=0;i<Max;i++)
                    p->next[*s-'a']->next[i]=NULL;
            }
            p->next[*s-'a']->num++;
            p=p->next[*s-'a'];
            s++;
        }
    }
    int count(Trie *root,char*s)
    {
        if(root==NULL or *s=='\0') return 0;
        Trie*p=root;
        int ans=0;
        while(*s!='\0')
        {
            if(p->next[*s-'a']==NULL) return 0;
            ans=p->next[*s-'a']->num;
            p=p->next[*s-'a'];
            s++;
        }
        return ans;
    }
    void del()//未检验正确性
    {
        for(int i=0;i<26;i++)
            if(next[i]!=NULL){
                next[i]->del();
                delete next[i];
        }
    }
}T;




int main()
{
    //IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\code_prictice\\out.txt","w",stdout);
    freopen("D:\\CODE\\code_prictice\\in.txt","r",stdin);  
    #endif
    char s[20];
    cin.getline(s,20);
    while(strlen(s)>0){
        T.insert(&T,s);
    // cout<<s<<endl;
        cin.getline(s,20);
    }
    
    while(cin.getline(s,20)){
        //printf("%d\n",T.count(&T,s));
        cout<<T.count(&T,s)<<endl;
    }
    return 0;
}