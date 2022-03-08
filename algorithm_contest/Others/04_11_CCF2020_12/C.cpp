#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define x first
#define y second 
using namespace std;
using LL=long long;
using ULL=unsigned long long;
using LD=long double;
using P=pair<int,int>;
const int inf=0x3f3f3f3f;
const LL LLinf=0x3f3f3f3f3f3f3f3f;

using File = pair<string, size_t>;//普通文件，大小。
struct Filepath
{
    string pathname;
    size_t LDd,LRd;//目标、后代配额
    //LD是仅指当前目录下的，LR指的是当前目录+子目录的
    size_t LD_now,LR_now;//当前已经储存的大小
    vector<Filepath*> Subpath;
    vector<File> Normalfile;
    Filepath(string name="", size_t LD_size=0, size_t LR_size=0)
    {
        pathname=name;
        LDd=LD_size;
        LRd=LR_size;
        LD_now = LR_now=0;
    }
    ~Filepath()
    {
        for(auto i:Subpath)
            delete i;
    }
};

string cut_current_path(string& path)
{
    //从长路径中取出当前需要的路径，同时在path中删去取出的部分
    string current_path;
    path.erase(0,1);//切去开头的‘/’
    int it = path.find_first_of('/');
    if(it == string::npos){//已经是文件名了
        current_path=path;
        path.erase(path.begin(),path.end());
    }
    else{
        current_path = path.substr(0,it);
        path.erase(0,it);
    }
    return current_path;
}

Filepath *Root = new Filepath;//根目录

bool C(Filepath *&node, string path, size_t file_size)
{
    string current_path = cut_current_path(path);//取当前目录
    if(path.size()==0)
    {
        //在当前目录插入
        if(node->LDd==0 or node->LD_now + file_size <= node->LDd)
        {
            File file_insert = File(current_path, file_size);
            if(find(node->Normalfile.begin(), node->Normalfile.end(), file_insert)==node->Normalfile.end()){//当前目录没有
                node->Normalfile.push_back(file_insert);
                node->LD_now += file_size;
                node->LR_now += file_size;//后代配额包含目标配额，也会被占用
                return true;
            }
        }
        return false;
    }
    else
    {
        //在子目录插入
        if(node->LRd==0 or node->LR_now + file_size <= node->LRd)
        {
            //找到目标子路径
            Filepath *childpath=nullptr;
            for(auto st:node->Subpath)
            {
                if(st->pathname==current_path){
                    childpath = st;
                    break;
                }
            }
            if(childpath==nullptr){
                childpath = new Filepath(current_path);
                node->Subpath.push_back(childpath);
            }

            if(C(childpath, path, file_size)==true){
                node->LD_now += file_size;
                node->LR_now += file_size;
                return true;
            }
        }
        return false;
    }
}

size_t R(Filepath *&node, string path)//返回删除目录的大小。始终认为执行成功。
{
    string current_path = cut_current_path(path);//取当前目录
    if(path.size()==0)//在当前目录删除
    {   
        if(current_path[0]>='0' and current_path[0]<='9')//删除文件
        {
            auto it = node->Normalfile.end();
            for(auto st=node->Normalfile.begin(); st!=node->Normalfile.end(); st++)
            {
                if(st->first==current_path){
                    it = st;
                    break;
                }
            }
            if(it!=node->Normalfile.end())
            {
                size_t file_size = it->second;
                node->Normalfile.erase(it);
                node->LR_now-=file_size;
                node->LD_now-=file_size;
                return file_size;
            }
        }
        else//删除目录
        {
            auto it = node->Subpath.end();
            for(auto st=node->Subpath.begin(); st!=node->Subpath.end(); st++)
            {   
                if((*st)->pathname==current_path){
                    it = st;
                    break;
                }
            }
            if(it!=node->Subpath.end()){
                auto del = *it;
                node->Subpath.erase(it);
                size_t file_size = del->LR_now;
                delete del;
                return file_size;
            }
        }
    }
    else//在子目录删除,一定是目录，不会是文件。
    {
        auto it = node->Subpath.end();
        for(auto st=node->Subpath.begin(); st!=node->Subpath.end(); st++)
        {   
            if((*st)->pathname==current_path){
                it = st;
                break;
            }
        }
        if(it!=node->Subpath.end()){
            auto del = *it;
            size_t file_size = R(del, path);
            del->LR_now -= file_size;
            return file_size;
        }
    }
    return false;
}

bool Q(Filepath *&, size_t LR, size_t LD)
{


}

void solve()
{
    int n;
    cin>>n;
    while(n--)
    {
        char swit;
        string path;
        size_t file_size;
        size_t LR,LD;
        cin>>swit;
        if(swit=='C')
        {
            cin>>path>>file_size;
            if(C(Root, path, file_size)==true) cout<<"Y"<<endl;
            else cout<<"N"<<endl;
        }
        else if(swit=='R')
        {
            cin>>path;
            R(Root, path);
            cout<<"Y"<<endl;
        }
        else if(swit=='Q')
        {
            cin>>LR,LD;
            if(Q(Root, LR, LD)==true) cout<<"Y"<<endl;
            else cout<<"N"<<endl;
        }
    }

}
int main()
{
    IOS;
    
    #ifdef _DEBUG
    freopen("D:/CODE/algorithm_contest/out.txt","w",stdout);
    freopen("D:/CODE/algorithm_contest/in.txt","r",stdin);  
    #endif
    
    // cout<<C(Root, "/A/B/1", 100)<<endl;
    // cout<<R(Root, "/A/B/1")<<endl;
    // cout<<C(Root, "/A/B/1", 100)<<endl;

    solve();
    return 0;
}
