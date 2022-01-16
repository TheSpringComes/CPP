#include<iostream>
using namespace std;
const int MAX = 400;
const int MAXFAC = 600;

class NUMBER{
	private:
		int num[MAX];
		int total;
	public:
		NUMBER();
		NUMBER(int a);
		~NUMBER();
		NUMBER(const NUMBER & n);
		friend NUMBER operator * (const NUMBER & a,const NUMBER & b);
		friend ostream & operator << (ostream & o,const NUMBER & n);
};
NUMBER::NUMBER()
{
	for(int i = 0;i < MAX; ++ i)
		num[i] = 0;
	total = 0;
}
NUMBER::NUMBER(int a)
{
	for(int i = 0;i < MAX; ++ i)
		num[i] = 0;
	total = 0;
	for(int i = 0;a != 0; ++ i)
	{
		num[MAX-1-i] = a % 10;
		a = a/10;
		total++;
	}
}
NUMBER::NUMBER(const NUMBER & n)
{
	for(int i = 0;i < MAX; ++ i)
		this->num[i] = n.num[i];
	total=n.total;
}
NUMBER::~NUMBER()
{
	
}
NUMBER operator * (const NUMBER & a,const NUMBER & b)
{
	NUMBER tmp;
	int flag = 0;
	for(int i=1;i<=a.total+1;++i)
	{
		flag=0;
		for(int j=1;j<=b.total+1;++j)
		{
			tmp.num[MAX+1-i-j]+=((a.num[MAX-i]*b.num[MAX-j])%10+flag);
			flag=(a.num[MAX-i]*b.num[MAX-j])/10;
			if(tmp.num[MAX+1-i-j]>9){
				tmp.num[MAX+1-i-j]-=10;
				tmp.num[MAX-i-j]+=1;
			}
			
		}
	}
	int tot=MAX;
	for(int i=0;tmp.num[i]==0;++i)
		tot--;
	tmp.total=tot;
	return tmp;
}
ostream & operator << (ostream & o,const NUMBER & n)
{
	for(int i=n.total;i>=1;--i)
		o<<n.num[MAX-i];
	return o;
}
int main()
{
	int n;
	cin>>n;
	NUMBER a[MAXFAC];
	a[0]=1,a[1]=1;
	for(int i=2;i<=n;++i)
		a[i]=a[i-1]*i;
	cout<<a[n]<<endl;
	return 0;
}
