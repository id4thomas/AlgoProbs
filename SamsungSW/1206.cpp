#include <iostream>

using namespace std;

int main(){
    int test_case;
    int T;
    int ans;
    int n,i,j,k,max_t,cur_h;
    int temp_h[5];
    int h[1000];
    cin>>T;
    for(test_case=1;test_case<=T;++test_case){
        ans=0;
        cin>>n;
        //cout<<"n:"<<n<<endl;
        //input loop
        for(i=0;i<n;i++){
            cin>>h[i];
        }
        //check loop
        k=0;
        temp_h[0]=0;
        temp_h[1]=0;
        temp_h[2]=h[2];
        temp_h[3]=h[3];
        //r_2=0;
        for(i=4;i<n;i++,k++){
            temp_h[(k+4)%5]=h[i];
            //cmp
            max_t=0;
            cur_h=temp_h[(k+2)%5];
            for(j=k+3;j<(k+7);j++){
                if(max_t<temp_h[(j)%5]){
                    max_t=temp_h[(j)%5];
                }
            }
            if(cur_h>max_t){
                ans+=cur_h-max_t;
            }
        }
        cout<<"#"<<test_case<<" "<<ans<<endl;
    }
    return 0;
}
