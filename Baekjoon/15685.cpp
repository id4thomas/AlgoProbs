#include <iostream>



using namespace std;
int main(){
    int r,c,tm;
    cin>>r;
    cin>>c;
    cin>>tm;
    int i,j,t;
    int room[r+2][c+2];
    int ac=-1;
    int spread;
    int left,temp;
    int dif[r+2][c+2];
    for(i=1;i<r+1;i++){
        for(j=1;j<c+1;j++){
            cin>>room[i][j];
        }
        //find ac location
        if(ac==-1&&room[i][1]==-1){
            ac=i;
        }
    }
    //make boundary
    for(i=0;i<r+2;i++){
        room[i][0]=-2;
        room[i][c+1]=-2;
    }
    for(j=0;j<c+2;j++){
        room[0][j]=-2;
        room[r+1][j]=-2;
    }

    //start loop
    for(t=0;t<tm;t++){
        //1-spread
        //init dif
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                dif[i][j]=0;
            }
        }
				//make difference
        for(i=1;i<r+1;i++){
            for(j=1;j<c+1;j++){
                if(room[i][j]>4){
                    spread=(room[i][j])/5;
                    //spread 4 directions
                    if(room[i-1][j]>=0){
                        dif[i-2][j-1]+=spread;
                        dif[i-1][j-1]-=spread;
                    }
                    if(room[i+1][j]>=0){
                        dif[i][j-1]+=spread;
                        dif[i-1][j-1]-=spread;
                    }
                    if(room[i][j-1]>=0){
                        dif[i-1][j-2]+=spread;
                        dif[i-1][j-1]-=spread;
                    }
                    if(room[i][j+1]>=0){
                        dif[i-1][j]+=spread;
                        dif[i-1][j-1]-=spread;
                    }
                }
            }
        }
        //apply
        for(i=1;i<r+1;i++){
            for(j=1;j<c+1;j++){
                room[i][j]+=dif[i-1][j-1];
            }
        }

        //2- spin
        //upper part
        //row -> (right)
        left=room[ac][2];
        room[ac][2]=0;
        for(j=3;j<c+1;j++){
            temp=room[ac][j];
            room[ac][j]=left;
            left=temp;
        }
        //col up
        for(i=ac-1;i>=1;i--){
            temp=room[i][c];
            room[i][c]=left;
            left=temp;
        }
        //row left
        for(j=c-1;j>=1;j--){
            temp=room[1][j];
            room[1][j]=left;
            left=temp;
        }

        //col down
        for(i=2;i<=ac-1;i++){
            temp=room[i][1];
            room[i][1]=left;
            left=temp;
        }

        //lower part
        //row -> (right)
        left=room[ac+1][2];
        room[ac+1][2]=0;
        for(j=3;j<c+1;j++){
            temp=room[ac+1][j];
            room[ac+1][j]=left;
            left=temp;
        }
        //col (down)
        for(i=ac+2;i<r+1;i++){
            temp=room[i][c];
            room[i][c]=left;
            left=temp;
        }
        //row (left)
        for(j=c-1;j>=1;j--){
            temp=room[r][j];
            room[r][j]=left;
            left=temp;
        }
        //col (up)
        for(i=r-1;i>ac+1;i--){
            temp=room[i][1];
            room[i][1]=left;
            left=temp;
        }
    }
		//collect all remaining dust
    int ans=0;
    for(i=1;i<r+1;i++){
        for(j=1;j<c+1;j++){
            if(room[i][j]>0){
                ans+=room[i][j];
            }
        }
    }
    printf("%d",ans);

}
