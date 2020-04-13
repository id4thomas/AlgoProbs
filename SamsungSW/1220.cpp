#include <iostream>

using namespace std;


int main(int argc, char** argv)
{
	int test_case;
	int T;
	T=10;

	int i,j;
	int table[100][100];
	int ans;
	bool n;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin>>i;
		for(i=0;i<100;i++){
			for(j=0;j<100;j++){
				cin>>table[i][j];
			}
		}
		ans=0;
		//1: n -> 밑으로
		//2: s -> 위로

		for(j=0;j<100;j++){
			n=true;
			for(i=0;i<100;i++){
				if(n){
					if(table[i][j]==1){
						n=false;
					}
				}else{
					if(table[i][j]==2){
						ans++;
						n=true;
					}
				}
			}
		}

		//cout<<endl;
		cout<<"#"<<test_case<<" "<<ans<<endl;
		//break;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
