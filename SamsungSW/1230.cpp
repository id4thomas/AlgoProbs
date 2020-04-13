#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	T=10;
	int ans=0;
	int o_len,c_len;
	int i,j,k,bak_len;
	int c;
	int original[4000];
	int bak[4000];
	int inserts[4000];
	char cmd;
	int x,y;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin>>o_len;
		for(i=0;i<o_len;i++){
			cin>>original[i];
		}
		/*
		for(i=0;i<10;i++){
			cout<<original[i]<<" ";
		}
		cout<<endl;*/
		cin>>c_len;
		//cout<<c_len<<endl;
		for(c=0;c<c_len;c++){
			cin>>cmd;
			if(cmd=='I'){
				cin>>x;
				cin>>y;
				for(j=0;j<y;j++){
					cin>>inserts[j];
				}
				//backup
				for(j=x,bak_len=0;j<4000;j++,bak_len++){
					bak[bak_len]=original[j];
					//cout<<bak[bak_len]<<" ";
				}
				//cout<<endl;
				//insert
				for(j=x,k=0;k<y;j++,k++){
					original[j]=inserts[k];
				}
				//restore
				for(k=0,j=x+y;j<4000||k<bak_len;j++,k++){
					original[j]=bak[k];
				}
				o_len+=y;
			}else if(cmd=='D'){
				cin>>x;
				cin>>y;
				for(j=x;(j+y)<o_len;j++){
					original[j]=original[j+y];
				}
				o_len-=y;
			}else{
				cin>>y;
				for(j=0;j<y;j++){
					cin>>inserts[j];
				}
				//append
				for(j=o_len,k=0;j<4000||k<y;j++,k++){
					original[j]=inserts[k];
				}
			}
		}

		//cout<<endl;
		cout<<"#"<<test_case<<" ";
		for(i=0;i<10;i++){
			cout<<original[i]<<" ";
		}
		cout<<endl;
		//break;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
