#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> P;
const LL inf=0x3f3f3f3f3f3f3f3f;
#define x first
#define y second

//服务器设置 
size_t N, Tdef, Tmax, Tmin;
string H;

/*标志每个ip的状态
  0：未占用
  1：待分配 
  2：占用 
  3：过期 
*/ 
struct Info
{
	string last="";
	size_t state=0;
	size_t ddltime=0;
}Pools[1005];
//表示每个报文 
struct Datagram
{
	string from;
	string to;
	string type;
	size_t ip=0;
	size_t ddltime;	
};
int main()
{
	cin>>N>>Tdef>>Tmax>>Tmin>>H;
	//cout<<N<<" "<<Tdef<<" "<<Tmax<<" "<<Tmin<<" "<<H<<endl;
	int T;	cin>>T;
	int t;
	while(T--)
	{
		cin>>t;
		
		//处理过期问题 
		for(size_t i=1;i<=N;i++)
		{
			Info &st = Pools[i];
			if(st.ddltime!=0 and st.ddltime<t)
			{ 
				if(st.state==1){ 
					st.state=0;
					st.last="";
				} 
				else if(st.state==2){
					st.state=3;
				}
				st.ddltime=0;
			} 
		}
		
		Datagram data, tar;

		cin>>data.from>>data.to>>data.type>>data.ip>>data.ddltime;
		tar.from=H;
		tar.to=data.from;
		if(data.to=="*" or data.to==H)
		{
			if(data.type=="DIS" and data.to=="*")
			{
				//检查是否有占用者为发送主机的 IP 地址
				for(size_t i=1;i<=N and tar.ip==0;i++)
				{
					Info &st=Pools[i];
					if(st.last==data.from)
						tar.ip=i;	
				} 
				//若没有，则选取最小的状态为未分配的 IP 地址；
				for(size_t i=1; i<=N and tar.ip==0;i++)
				{
					Info &st=Pools[i];
					if(st.state==0)
						tar.ip=i;
				}
				//若没有，则选取最小的状态为过期的 IP 地址；
				for(size_t i=1; i<=N and tar.ip==0;i++)
				{
					Info &st=Pools[i];
					if(st.state==3)
						tar.ip=i;
				}
				if(tar.ip!=0)
				{
					Pools[tar.ip].state=1;
					Pools[tar.ip].last=data.from;
					if(data.ddltime==0) tar.ddltime=t+Tdef;
					else if(t+Tmin>=data.ddltime) tar.ddltime=t+Tmin;
					else if(t+Tmax<=data.ddltime) tar.ddltime=t+Tmax;
					else tar.ddltime=data.ddltime;
					Pools[tar.ip].ddltime=tar.ddltime;
					tar.type="OFR";
					cout<< tar.from<<" "<<tar.to<<" "<<tar.type<<" "<<tar.ip<<" "<<tar.ddltime<<endl;
				}
			}
			// above is OK. 
			else if(data.type=="REQ" and data.to==H)
			{
				for(size_t i=1; i<=N and tar.ip==0;i++)
				{
					Info &st=Pools[i];
					if(data.ip<=N and data.ip>=1 and Pools[data.ip].last==data.from){
						tar.ip=data.ip;					
					}
				}
				
				if(tar.ip!=0)
				{
					Pools[tar.ip].state=2;
					if(data.ddltime==0) tar.ddltime=t+Tdef;
					else if(t+Tmin>=data.ddltime) tar.ddltime=t+Tmin;
					else if(t+Tmax<=data.ddltime) tar.ddltime=t+Tmax;
					else tar.ddltime=data.ddltime;
					Pools[tar.ip].ddltime-tar.ddltime;
					tar.type="ACK";
					cout<< tar.from<<" "<<tar.to<<" "<<tar.type<<" "<<tar.ip<<" "<<tar.ddltime<<endl;
				}
				else
				{
					tar.type="NAK";
					tar.ddltime=0;
					tar.ip=data.ip;
					cout<< tar.from<<" "<<tar.to<<" "<<tar.type<<" "<<tar.ip<<" "<<tar.ddltime<<endl;
				}
			}
		}
		else if(data.type=="REQ")
		{
			for(size_t i=1; i<=N;i++)
				{
					Info &st=Pools[i];
					if(st.last==data.from and st.state==1)
					{
						st.last="";
						st.state=0;
						st.ddltime=0;
					}
				}	
		}
		t++;
	}
	return 0;
}
