#include <iostream>

using namespace std;

int pow(int n, int m){
	if(m==0){
		return 1;
	}
	return pow(n,m-1)*n;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	T=10;
	int ans=0,seq_len;
	int n,m;
	bool r_end,c_end;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin>>test_case;
		cin>>n;
		cin>>m;
		ans=pow(n,m);
		//cout<<endl;
		cout<<"#"<<test_case<<" "<<ans<<endl;
		//break;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
