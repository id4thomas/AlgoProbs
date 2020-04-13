#include <iostream>
#include <string>
using namespace std;


int main(int argc, char** argv)
{
	int test_case;
	int T;
	//T=10;
	int n;
	int i,j;
	cin>>T;
	char nums[4];
	string num;
	char temp;
	int counts[10];
	nums[3]='\0';
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin>>temp;
		cin>>i;
		//cout<<i<<endl;
		cin>>n;
		for(i=0;i<10;i++){
			counts[i]=0;
		}
		for(i=0;i<n;i++){
			cin>>nums[0];
			cin>>nums[1];
			cin>>nums[2];
			//cin>>temp;
			num=nums;
			//cout<<num<<endl;
			if(num.compare("ZRO")==0){
				counts[0]++;
			}else if(num.compare("ONE")==0){
				counts[1]++;
			}else if(num.compare("TWO")==0){
				counts[2]++;
			}else if(num.compare("THR")==0){
				counts[3]++;
			}else if(num.compare("FOR")==0){
				counts[4]++;
			}else if(num.compare("FIV")==0){
				counts[5]++;
			}else if(num.compare("SIX")==0){
				counts[6]++;
			}else if(num.compare("SVN")==0){
				counts[7]++;
			}else if(num.compare("EGT")==0){
				counts[8]++;
			}else if(num.compare("NIN")==0){
				counts[9]++;
			}
		}
		//break;

		//cout<<endl;
		cout<<"#"<<test_case<<endl;
		for(i=0;i<counts[0];i++){
			cout<<"ZRO ";
		}
		for(i=0;i<counts[1];i++){
			cout<<"ONE ";
		}
		for(i=0;i<counts[2];i++){
			cout<<"TWO ";
		}
		for(i=0;i<counts[3];i++){
			cout<<"THR ";
		}
		for(i=0;i<counts[4];i++){
			cout<<"FOR ";
		}
		for(i=0;i<counts[5];i++){
			cout<<"FIV ";
		}
		for(i=0;i<counts[6];i++){
			cout<<"SIX ";
		}
		for(i=0;i<counts[7];i++){
			cout<<"SVN ";
		}
		for(i=0;i<counts[8];i++){
			cout<<"EGT ";
		}
		for(i=0;i<counts[9];i++){
			cout<<"NIN ";
		}
		cout<<endl;
		//break;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
