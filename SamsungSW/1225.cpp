#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	T=10;
	int ans=0;
	int dec;
	int i,idx;
	int nums[8];
	int vals[5]={1,2,3,4,5};
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin>>test_case;
		for(i=0;i<8;i++){
			cin>>nums[i];
		}
		for(i=0;;i++){
			dec=vals[i%5];
			if(nums[i%8]<=dec){
				nums[i%8]=0;
				i++;
				break;
			}else{
				nums[i%8]-=dec;
			}
		}
		//cout<<endl;
		cout<<"#"<<test_case<<" ";
		idx=i;
		for(i=0;i<8;i++){
			cout<<nums[(idx+i)%8]<<" ";
		}
		cout<<endl;

		//break;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
