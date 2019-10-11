/*#include <stdio.h>
#include <stdlib.h>
int res;
int mid(int arr[], int n) {
	if (n%2 == 0)
		return arr[n/2 -1];
	else
		return arr[(n+1)/2 -1];
}
void find(int A[], int B[], int n) {
//	cout<<n<<endl;
	int nam = mid(A,n);
//	cout<<"nam="<<nam<<endl;
	int nbm = mid(B,n);
//	cout<<"nbm="<<nbm<<endl;
	//return 0;
	if (n == 1) {
		res = A[0] < B[0] ? A[0] : B[0];
//		cout<<"A[nam] ="<<A[nam]<<endl;
		return;
	}
	if (n == 2) {
	//	cout<<A[0]<<" "<<A[1]<<endl;
	//	cout<<B[0]<<" "<<B[1]<<endl;
		int m1 = A[0] < B[0] ? B[0] : A[0];
		int m2 = A[1] < B[1] ? A[1] : B[1];
		res = m1 < m2 ? m1 : m2;
		return;

	}
	if (nam == nbm) {
		res = nam;
		return;
	}
	else if(nam < nbm)
		find(A + (n-1)/2, B, n/2+1);
	else
		find(B + (n-1)/2, A, n/2+1);
	return;
}


int main() {
	int n;
	scanf("%d",&n);
	int *A = (int *)malloc(sizeof(int) * n);
	int *B = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d",&A[i]);
	for (int i = 0; i < n; i++)
		scanf("%d",&B[i]);
		
	find(A,B,n);

	printf("%d\n",res);

	printf("%d\n",n);
	for (int i = 0; i < n; i++)
		printf("%d ",A[i]);
	printf("\n");
	for (int i = 0; i < n; i++)
		printf("%d ",B[i]);
	printf("\n");
}*/




/*#include <stdio.h>  
#include <stdlib.h>  
  

int find(int *A, int *B, int n, int s, int t)  
{  
    int  p, c;  
  
    c = (2*n-1)/2; 
    p = (s+t)/2;  
  
    if (s > t) {  
        return find(B, A, n, 0, n-1);  
    }  
  
    if (A[p] >= B[c-p-1] && A[p] <= B[c-p]) {  
        return A[p];  
    }  
  
    if (A[p] < B[c-p-1]) {  
        return find(A, B, n, p+1, t);  
    }  

    return find(A, B, n, s, p-1);  
}  
  
int main()  
{  
	int n;
	scanf("%d",&n);
	int *A = new int[n];
	int *B = new int[n];
	for (int i = 0; i < n; i++)
		scanf("%d",&A[i]);
	for (int i = 0; i < n; i++)
		scanf("%d",&B[i]);

	int result = find(A, B, n, 0, n-1);


	printf("%d\n",result);*/

/*	printf("%d\n",n);
	for (int i = 0; i < n; i++)
		printf("%d ",A[i]);
	printf("\n");
	for (int i = 0; i < n; i++)
		printf("%d ",B[i]);
	printf("\n");*/
    
  
    
  
 //   return 0;  
//} 