#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	int ans=0;
    int b,n;
    int i,j,k,check_idx,b_len;
    char temp,largest;
    string board;
    string new_board;
    queue<string> pending_board;
    queue<int> pending_n;
    queue<int> pending_c;
    vector<string> finished;
    bool same_exists;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin>>b;
        cin>>n;
        board=to_string(b);
        b_len=board.length();

        pending_board.push(board);
        pending_n.push(n);
        pending_c.push(0);
        while(!pending_board.empty()){
            board=pending_board.front();
            i=pending_n.front();
            check_idx=pending_c.front();

            pending_board.pop();
            pending_n.pop();
            pending_c.pop();
            //cout<<"checking "<<board<<" "<<i<<endl;
            if(i==0){
                finished.push_back(board);
                continue;
            }
            if(check_idx<b_len){
                //cout<<"?? "<<endl;
                largest=board[check_idx];
                //target=check_idx;
                for(j=check_idx+1;j<b_len;j++){
                    if(board[j]>=largest){
                        //target=j;
                        largest=board[j];
                    }
                }
                if(board[check_idx]!=largest){
                    i--;
                    for(j=check_idx+1;j<b_len;j++){
                        if(board[j]==largest){
                            new_board=board;
                            new_board[j]=new_board[check_idx];
                            new_board[check_idx]=largest;

                            //cout<<"pushing "<<new_board<<endl;
                            pending_board.push(new_board);
                            pending_n.push(i);
                            pending_c.push(check_idx+1);
                        }
                    }
                }else{
                    pending_board.push(board);
                    pending_n.push(i);
                    pending_c.push(check_idx+1);
                }
            }else{
                same_exists=false;
                for(j=0;j<b_len;j++){
                    for(k=j+1;k<b_len;k++){
                        if(board[j]==board[k]){
                            same_exists=true;
                            break;
                        }
                    }
                }

                if((!same_exists)&&((i%2)!=0)){
                    temp=board[b_len-1];
                    board[b_len-1]=board[b_len-2];
                    board[b_len-2]=temp;
                }
                finished.push_back(board);
            }
        }
        ans=stoi(finished[0]);
        //cout<<finished[0]<<endl;
        for(i=1;i<finished.size();i++){
            j=stoi(finished[i]);
            if(ans<j){
                ans=j;
            }
         //  cout<<finished[i]<<endl;
        }
        finished.clear();
        //cout<<endl;
        cout<<"#"<<test_case<<" "<<ans<<endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
