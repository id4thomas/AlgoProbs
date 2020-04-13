#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int test_case;
    int T;
    int ans;
    int i,j,n;
    int h[100];
    int l_idx,r_idx,l,r;
    T=10;
    for(test_case=1;test_case<=T;++test_case){
        ans=0;
        cin>>n;
        //cout<<"n:"<<n<<endl;
        //input loop
        for(i=0;i<100;i++){
            cin>>h[i];
        }
        sort(h,h+100);
        l_idx=0;
        r_idx=99;
        for(i=0;i<n;){
            //flatten loop
            l_idx=0;
            r_idx=99;
            while(h[l_idx]==h[l_idx+1]&&l_idx<99){
                l_idx++;
            }
            while(h[r_idx]==h[r_idx-1]&&r_idx>1){
                r_idx--;
            }
            //cout<<l_idx<<","<<h[l_idx]<<","<<r_idx<<","<<h[r_idx]<<endl;
            if((l_idx>=r_idx)||(l_idx+1==r_idx)){
                //cout<<"exit"<<endl;
                break;
                //all flattened
            }
            for(l=l_idx,r=r_idx;(l>=0)&&(r<100)&&(i<n);l--,r++,i++){
                h[l]++;
                h[r]--;
            }
        }
        ans=h[99]-h[0];
        cout<<"#"<<test_case<<" "<<ans<<endl;
    }
    return 0;
}
