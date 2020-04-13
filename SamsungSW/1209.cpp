#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	T=10;
	int ans=0;
	int i,j;
	int val[100][100];
	int r_sum,c_sum,d1_sum,d2_sum;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin>>test_case;
		ans=0;
		//diag1
		d1_sum=0;
		//diag2
		d2_sum=0;
		//오른쪽으로 내려가는 대각선 + row sum들
		for(i=0;i<100;i++){
			r_sum=0;
			for(j=0;j<100;j++){
				cin>>val[i][j];
				r_sum+=val[i][j];
			}
			d1_sum+=val[i][i];
			if(ans<r_sum){
				ans=r_sum;
			}
		}
		if(ans<d1_sum){
			ans=d1_sum;
		}
		//왼쪽으로 내려가는 대각선 + column sum들
		for(i=0;i<100;i++){
			d2_sum+=val[i][99-i];
			c_sum=0;
			for(j=0;j<100;j++){
				c_sum+=val[j][i];
			}
			if(ans<c_sum){
				ans=c_sum;
			}
		}
		if(ans<d2_sum){
			ans=d2_sum;
		}
		//cout<<endl;
		cout<<"#"<<test_case<<" "<<ans<<endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
