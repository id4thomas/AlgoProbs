#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	int ans=0;
    int code_val[8];
    int r,c,i,j,code_idx,z_count,end_idx;
    char temp;
    char code[62];
    char code_digit[8];
    bool found;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin>>r;
        cin>>c;
        //cout<<"r "<<r<<"c "<<c<<endl;
        code_idx=0;
        code[0]='0';
        code[1]='0';
        code[2]='0';
        z_count=0;
        found=false;
        //read
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                cin>>temp;
                if(temp=='1'){
                    if(!found){
                        found=true;
                        code_idx=3;
                    }
                    z_count=0;
                }else{
                    z_count++;
                }
                if(code_idx>0){
                    //cout<<"writing "<<code_idx<<endl;
                    if(z_count>3){
                        //code finished
                        end_idx=code_idx-4;
                        code_idx=0;
                    }else{
                        code[code_idx]=temp;
                        code_idx++;
                    }
                }
            }
        }
        //check
        for(i=end_idx-55,j=0;i<=end_idx;j++){
            //strncpy(code_digit,code+i,sizeof(char)*7);
            for(code_idx=0;code_idx<7;code_idx++,i++){
                code_digit[code_idx]=code[i];
            }
            code_digit[7]=0;
            if(strcmp(code_digit,"0001101")==0){
                //0
                code_val[j]=0;
            }else if(strcmp(code_digit,"0011001")==0){
                //1
                code_val[j]=1;
            }else if(strcmp(code_digit,"0010011")==0){
                //2
                code_val[j]=2;
            }else if(strcmp(code_digit,"0111101")==0){
                //3
                code_val[j]=3;
            }else if(strcmp(code_digit,"0100011")==0){
                //4
                code_val[j]=4;
            }else if(strcmp(code_digit,"0110001")==0){
                //5
                code_val[j]=5;
            }else if(strcmp(code_digit,"0101111")==0){
                //6
                code_val[j]=6;
            }else if(strcmp(code_digit,"0111011")==0){
                //7
                code_val[j]=7;
            }else if(strcmp(code_digit,"0110111")==0){
                //8
                code_val[j]=8;
            }else if(strcmp(code_digit,"0001011")==0){
                //9
                code_val[j]=9;
            }
            //cout<<code_val[j]<<endl;
        }
        i=(code_val[0]+code_val[2]+code_val[4]+code_val[6])*3;
        i+=code_val[1]+code_val[3]+code_val[5];
        i+=code_val[7];
        ans=0;
        if(i%10==0){
            for(i=0;i<8;i++){
                ans+=code_val[i];
            }
        }
        //cout<<endl;
        cout<<"#"<<test_case<<" "<<ans<<endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
