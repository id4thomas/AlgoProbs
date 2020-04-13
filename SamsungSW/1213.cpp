#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	T=10;
	int ans=0,seq_len,target_len;
	int i,j,k;
	string seq;
	string target;
	string sub_seq;
	//char sen[1001];
	//char target[11];

	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin>>test_case;
		cin>>target;
		cin>>seq;
		//cout<<target<<endl;
		ans=0;
		seq_len=seq.length();
		target_len=target.length();
		for(i=0;i<(seq_len-target_len+1);i++){
			if(seq[i]==target[0]){
				sub_seq=seq.substr(i,target_len);
				if(sub_seq.compare(target)==0){
					ans++;
				}
			}
		}
		//cout<<"seq"<<seq_len<<endl;
		//cout<<endl;
		cout<<"#"<<test_case<<" "<<ans<<endl;
		//break;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
