#include "header.h"

#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

void randomMATRIX(double ** matrix, int len){
    srand( time( NULL ) );
    for(int i = 0 ; i < len ; i++){
        matrix[i] = new double[len];
        for(int j = 0 ; j < len ; j++){
            matrix[i][j] = (rand() % 10) + 1;
        }
    }
}

void randomRESULT(double * tab, int len){
    for(int i = 0 ; i < len ; i++){
        tab[i] = (rand() % 10) + 1;
    }
}

void writeMATRIX(double ** matrix, int len){
    for(int i = 0 ; i <len ; i++){
        for(int j = 0 ; j<len ; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

void calculate(double ** matrix, int len){
    double scaler;
    cout<<"START"<<endl;
    int stop = len -1;
    for(int i = 0 ; i < stop ; i++){
        for(int j = i + 1 ; j < len - i ; j++){
            if(matrix[i][i]!=1){
                scaler = matrix[i][i];
                for(int y = i ; y < len ; y++){
                    matrix[y][j] /= scaler;
                }
                writeMATRIX(matrix, len);
            }
            scaler = (-1*matrix[i][i])/matrix[i][j];
            for(int y = j ; y < len ; y++){
                matrix[j][y] = scaler * matrix[j][i] + matrix[i][i];
            }
            writeMATRIX(matrix, len);

        }
        cout<< endl;
    }
}

void finishApp(double ** matrix, double * res,int len){
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
    double  ** matrix = new double * [noe];
    double * results = new double[noe];
    randomRESULT(results, noe);
    randomMATRIX(matrix, noe);
    //write
    writeMATRIX(matrix, noe);

    calculate(matrix, noe);

    finishApp(matrix, results, noe);
}
