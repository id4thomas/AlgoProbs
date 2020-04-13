#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	T=10;
	int ans=0,seq_len;
	int i,j,k;
	char board[100][100];
	bool r_end,c_end;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin>>test_case;
		ans=1;
		for(i=0;i<100;i++){
			for(j=0;j<100;j++){
				cin>>board[i][j];
			}
		}
		for(i=0;i<100;i++){
			for(j=0;j<100;j++){
				seq_len=1;
				//odd
				r_end=false;
				c_end=false;
				for(k=1;;k++){
					if((i-k)<0||(i+k)>=100){
						r_end=true;
					}
					if((j-k)<0||(j+k)>=100){
						c_end=true;
					}

					if(!r_end){
						//cout<<i-k<<","<<i+k<<endl;
						if(board[i-k][j]==board[i+k][j]){

							//cout<<board[i-k][j]<<","<<board[i+k][j]<<endl;
							seq_len+=2;
						}else{
							r_end=true;
						}
					}
					if(!c_end){
						if(board[i][j-k]==board[i][j+k]){
							if(r_end){
								seq_len+=2;
							}
						}else{
							c_end=true;
						}
					}
					if(r_end&&c_end){
						break;
					}
				}
				//cout<<"seq"<<seq_len<<endl;
				if(ans<seq_len){
					//cout<<"seq"<<seq_len<<endl;
					ans=seq_len;
				}
			//	cout<<"ans"<<ans<<endl;
				if((i-1)>0){
					if(board[i-1][j]==board[i][j]){
						seq_len=2;
						for(k=1;;k++){
							if((i-k-1)<0||(i+k)>=100){
								break;
							}
							if(board[i-k-1][j]==board[i+k][j]){
								seq_len+=2;
							}else{
								break;
							}
						}
						if(ans<seq_len){
							ans=seq_len;
						}
					}
				}
				if((i+1)<100){
					if(board[i+1][j]==board[i][j]){
						seq_len=2;
						for(k=1;;k++){
							if((i-k)<0||(i+k+1)>=100){
								break;
							}
							if(board[i-k][j]==board[i+k+1][j]){
								seq_len+=2;
							}else{
								break;
							}
						}
						if(ans<seq_len){
							ans=seq_len;
						}
					}
				}
				if((j-1)>0){
					if(board[i][j-1]==board[i][j]){
						seq_len=2;
						for(k=1;;k++){
							if((j-k-1)<0||(j+k)>=100){
								break;
							}
							if(board[i][j-k-1]==board[i][j+k]){
								seq_len+=2;
							}else{
								break;
							}
						}
						if(ans<seq_len){
							ans=seq_len;
						}
					}
				}
				if((j+1)<1000){
					if(board[i][j+1]==board[i][j]){
						seq_len=2;
						for(k=1;;k++){
							if((j-k)<0||(j+k+1)>=100){
								break;
							}
							if(board[i][j-k]==board[i][j+k+1]){
								seq_len+=2;
							}else{
								break;
							}
						}
						if(ans<seq_len){
							ans=seq_len;
						}
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
