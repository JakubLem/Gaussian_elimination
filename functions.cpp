#include "header.h"

#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

void randomMATRIX(int ** matrix, int len){
    srand( time( NULL ) );
    for(int i = 0 ; i < len ; i++){
        matrix[i] = new int[len];
        for(int j = 0 ; j < len ; j++){
            matrix[i][j] = (rand() % 10) + 1;
        }
    }
}

void randomRESULT(int * tab, int len){
    for(int i = 0 ; i < len ; i++){
        tab[i] = (rand() % 10) + 1;
    }
}

void writeMATRIX(int ** matrix, int len){
    for(int i = 0 ; i <len ; i++){
        for(int j = 0 ; j<len ; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

void calculate(int ** matrix, int len){

}

void finishApp(int ** matrix, int * res,int len){
    //destroy matrix
    for(int i = 0 ; i < len ; i++){
        delete [] matrix[i];
    }
    delete [] matrix;
    delete [] res;

}

void startApp(){
    int noe;
    system("cls");
    cout<<"enter number of elements: ";
    cin>>noe;
    int  ** matrix = new int * [noe];
    int * results = new int[noe];
    randomRESULT(results, noe);
    randomMATRIX(matrix, noe);
    //write
    writeMATRIX(matrix, noe);
    finishApp(matrix, results, noe);
}
