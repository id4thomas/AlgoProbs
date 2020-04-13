#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	T=10;
	int ans,i,j,k;
	int l;
	char board[8][8];
	bool vert,horz;
	int s,e;
	int count;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin>>l;
		ans=0;
		for(i=0;i<8;i++){
			for(j=0;j<8;j++){
				cin>>board[i][j];
			}
		}
		if(l%2==0){
			//even
			s=(l/2-1);
			e=(8-(l/2));
			//cout<<s<<endl<<e<<endl;
			for(i=0;i<8;i++){
				for(j=0;j<8;j++){
					if(i>=s&&i<e){
						vert=true;
						for(k=0;k<(l/2);k++){
							if(board[i-k][j]!=board[i+k+1][j]){
								vert=false;

								break;
							}
						}
						if(vert){
							ans++;
						}
					}
					if(j>=s&&j<e){
						horz=true;
						for(k=0;k<(l/2);k++){
							if(board[i][j-k]!=board[i][j+k+1]){
								horz=false;
								break;
							}
						}
						if(horz){
							ans++;
						}
					}
				}
			}

		}else{
			//odd
			s=(l/2);
			e=(8-(l/2));
			//cout<<s<<endl<<e<<endl;
			for(i=0;i<8;i++){
				for(j=0;j<8;j++){
					if(i>=s&&i<e){
						vert=true;
						for(k=1;k<=(l/2);k++){
							if(board[i-k][j]!=board[i+k][j]){
								vert=false;
								break;
							}
						}
						if(vert){
							ans++;
						}
					}
					if(j>=s&&j<e){
						horz=true;
						for(k=1;k<=(l/2);k++){
							if(board[i][j-k]!=board[i][j+k]){
								horz=false;
								break;
							}
						}
						if(horz){
							ans++;
						}
					}
				}
			}

		}
		//cout<<endl;
		cout<<"#"<<test_case<<" "<<ans<<endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
