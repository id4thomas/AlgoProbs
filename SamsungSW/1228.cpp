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
	int original[20];
	int bak[10];
	int inserts[10];
	char temp;
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
			cin>>temp;
			//cout<<temp<<endl;
			cin>>x;
			cin>>y;
			for(j=0;j<y;j++){
				cin>>inserts[j];
			}
			//backup
			for(j=x,bak_len=0;j<10;j++,bak_len++){
				bak[bak_len]=original[j];
				//cout<<bak[bak_len]<<" ";
			}
			//cout<<endl;
			//insert
			for(j=x,k=0;j<10;j++,k++){
				original[j]=inserts[k];
			}
			//restore
			for(k=0,j=x+y;j<10||k<bak_len;j++,k++){
				original[j]=bak[k];
			}
			/*
			cout<<"ha"<<endl;
			for(i=0;i<10;i++){
				cout<<original[i]<<" ";
			}
			cout<<endl;*/
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
