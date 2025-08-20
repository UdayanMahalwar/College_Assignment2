#include<iostream>
using namespace std;

void printTriplet(int trip[20][3], int n){
    for(int i=0;i<n;i++){
        cout << trip[i][0] << " " << trip[i][1] << " " << trip[i][2] << endl;
    }
}

int main(){
    int r,c;
    cout << "Enter rows and cols: ";
    cin >> r >> c;

    int mat1[20][20], mat2[20][20];
    cout << "Enter Matrix A:" << endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> mat1[i][j];
        }
    }
    cout << "Enter Matrix B:" << endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> mat2[i][j];
        }
    }


    int A[20][3], aCount=1;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(mat1[i][j]!=0){
                A[aCount][0]=i;
                A[aCount][1]=j;
                A[aCount][2]=mat1[i][j];
                aCount++;
            }
        }
    }
    A[0][0]=r; A[0][1]=c; A[0][2]=aCount-1;


    int B[20][3], bCount=1;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(mat2[i][j]!=0){
                B[bCount][0]=i;
                B[bCount][1]=j;
                B[bCount][2]=mat2[i][j];
                bCount++;
            }
        }
    }
    B[0][0]=r; B[0][1]=c; B[0][2]=bCount-1;

    cout << "Triplet A:" << endl;
    printTriplet(A,aCount);
    cout << "Triplet B:" << endl;
    printTriplet(B,bCount);


    int C[40][3];
    C[0][0]=r; C[0][1]=c;
    int i=1,j=1,k=1;
    while(i<aCount && j<bCount){
        if(A[i][0]<B[j][0] || (A[i][0]==B[j][0] && A[i][1]<B[j][1])){
            C[k][0]=A[i][0];
            C[k][1]=A[i][1];
            C[k][2]=A[i][2];
            i++; k++;
        }
        else if(B[j][0]<A[i][0] || (A[i][0]==B[j][0] && B[j][1]<A[i][1])){
            C[k][0]=B[j][0];
            C[k][1]=B[j][1];
            C[k][2]=B[j][2];
            j++; k++;
        }
        else{ 
            int sum = A[i][2]+B[j][2];
            if(sum!=0){
                C[k][0]=A[i][0];
                C[k][1]=A[i][1];
                C[k][2]=sum;
                k++;
            }
            i++; j++;
        }
    }
    while(i<aCount){
        C[k][0]=A[i][0]; C[k][1]=A[i][1]; C[k][2]=A[i][2]; i++; k++;
    }
    while(j<bCount){
        C[k][0]=B[j][0]; C[k][1]=B[j][1]; C[k][2]=B[j][2]; j++; k++;
    }
    C[0][2]=k-1;

    cout << "Result (A+B) Triplet:" << endl;
    printTriplet(C,k);

    return 0;
}
