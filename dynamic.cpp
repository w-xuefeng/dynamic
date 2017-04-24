#include <stdio.h>
#include <stdlib.h>
#define N 5

typedef struct XF{

	int dataArray[N][N];

	int dir[N][N];	
	
}xf;

int a[N][N] = {{9,0,0,0,0},{12,15,0,0,0},{10,6,8,0,0},{2,18,9,5,0},{19,7,10,4,16}};
xf xuefeng;

xf maxFromTopToBottom(int,int,int);
void maxFromBottomToTop();
void linkArrayWay(int[N][N]);







int main(int argc, char* argv[]){

	xf data;

	printf("The source tree array is:\n");

	for (int q = 0; q < N; ++q){

		for (int p = 0; p <= q; ++p){
		
			printf("%d\t", a[q][p]);
		
		}

		printf("\n");

	}

	printf("\n\n");


	printf("the first method is FromTopToBottom,dataArray is: \n");

	for (int i = 0; i < N; ++i)	{

		for (int j = 0; j <= i; ++j)	{

			data.dataArray[i][j] = maxFromTopToBottom(i,j,N-1).dataArray[i][j];

			data.dir[i][j] = maxFromTopToBottom(i,j,N-1).dir[i][j];
			
			printf("%d\t",data.dataArray[i][j]);			

		}
		
		printf("\n");

	}

	printf("\n");

	printf("The max way sum = %d\n", data.dataArray[0][0]);

	printf("The max way is :");linkArrayWay(data.dataArray);



	printf("\n\n");

	printf("the second method is FromBottomToTop,dataArray is: \n");

	maxFromBottomToTop();


	return 0;
}




//FromTopToBottom
xf maxFromTopToBottom(int i, int j, int n){	

	int left,right;

	if ((i==n)||(j==n)) {

		xuefeng.dataArray[i][j] = a[i][j];	

		return xuefeng;
		

	}else if(xuefeng.dataArray[i][j] != 0 ) {

		return xuefeng;

	}

	left = maxFromTopToBottom(i+1,j,n).dataArray[i+1][j];

	right = maxFromTopToBottom(i+1,j+1,n).dataArray[i+1][j+1];

	xuefeng.dataArray[i][j] = (left>right)? (left+a[i][j]) : (right+a[i][j]);
	xuefeng.dir[i][j] = (left>right)? 0 : 1;	
	
	return xuefeng;

}


//FromBottomToTop
void maxFromBottomToTop() {	

	int left,right;

	for(int i=N-1; i>=0; i--) {

		for(int j=0; j<=i; j++) {

			if(i == N-1) {

				xuefeng.dataArray[i][j] = a[i][j];

			}else{

				left = xuefeng.dataArray[i+1][j];

				right = xuefeng.dataArray[i+1][j+1];
				
				if (left > right) {

					xuefeng.dataArray[i][j] = left + a[i][j];

					xuefeng.dir[i][j] = 0;

				}else{

					xuefeng.dataArray[i][j] = right + a[i][j];

					xuefeng.dir[i][j] = 1;
				}
			}
			
		}
	}


	for(i=0; i<N; i++) {

		for(int j=0; j<=i; j++) {

			printf("%d\t", xuefeng.dataArray[i][j]);

		}

		printf("\n");
	}

	printf("\n");	

	printf("The max way sum = %d\n", xuefeng.dataArray[0][0]);

	printf("The max way is :");linkArrayWay(xuefeng.dataArray);

	printf("\n\n");

}


void linkArrayWay(int way[N][N]){

	for (int i = 0,j=0; i < N-1;i++){

		if (way[i+1][j] > way[i+1][j+1]){

			printf("Left ");

		}else {

			printf("Right ");j++;		

		}

	}
	
}

