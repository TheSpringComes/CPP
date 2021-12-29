#include"pattern.h"
#include<cstdlib>
int main()
{
	int n,a;
	cin>>n>>a;
	if(n==0){cout<<"error"<<endl;exit(0);}
	Pattern A(n,a);
	A.Generate();
	A.PrintOut();
	system("pause");
	return 0;
}
