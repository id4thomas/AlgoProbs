#include <iostream>

using namespace std;

int main(){
    int n,l;
    cin>>n;
    cin>>l;
    int i,j;
    int mp[n][n];
    //get input
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin>>mp[i][j];
            //cout<<mp[i][j];
        }
    }
    int ans=0;
    //row
    //bool ramp[n];
    int lvl;
    int freespace;
	//row loop
    for(i=0;i<n;i++){
        //fill(ramp,ramp+n,0);
        lvl=mp[i][0];
        freespace=1;
	//path
        for(j=1;j<n;j++){
            if(mp[i][j]==lvl){
                freespace++;
            }else if(mp[i][j]<lvl){
		//height dif >=2
                if(lvl-mp[i][j]>1){
                    break;
                }
                //descent
		// 32211 l=2
		// 1,-1,0,-1,0

		//322211
		//1,-2,-1,0,-2,-1
		//3,2,
                if(freespace<0){
                    break;
                }else{
                    freespace=-l+1;
                    lvl=mp[i][j];//level update!!!
                }
            }else{
                if(mp[i][j]-lvl>1){
                    break;
                }
                //ascent
		//2211 1122
		//1,2,-1,0,1,2,1,2
                if(freespace<l){
                    break;
                }else{
                    freespace=1;
                    lvl=mp[i][j];
                }
            }
        }
        if(j==n&&freespace>=0){
            //success
            ans++;
        }
    }
    //col
    for(j=0;j<n;j++){
        lvl=mp[0][j];
        freespace=1;
        for(i=1;i<n;i++){
            if(mp[i][j]==lvl){
                freespace++;
            }else if(mp[i][j]<lvl){
                if(lvl-mp[i][j]>1){
                    break;
                }
                //descent
                if(freespace<0){
                    break;
                }else{
                    freespace=-l+1;
                    lvl=mp[i][j];
                }
            }else{
                if(mp[i][j]-lvl>1){
                    break;
                }
                //ascent
                if(freespace<l){
                    break;
                }else{
                    freespace=1;
                    lvl=mp[i][j];
                }
            }
        }
        if(i==n&&freespace>=0){
            //success
            ans++;
        }
    }
    cout<<ans;
}
