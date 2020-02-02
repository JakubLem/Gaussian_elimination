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
    for(int i = 0 ; i < len ; i++){
        cout<<endl<<i<<endl;
        if(matrix[i][i]!=1){
            cout<<"scaler";
            scaler = matrix[i][i];
            cout<<scaler<<endl;
            for(int y = i ; y < len - i ; y++){
                matrix[i][y] /= scaler;
            }
            writeMATRIX(matrix, len);
        }
        for(int j = i + 1  ; j < len - i ; j++){
            scaler = (-1*matrix[j][i])/matrix[i][i];
            cout<<endl<<"scaler: "<<scaler<<endl;

            for(int y = i ; y < len - i ; y++){

                matrix[j][y] = scaler * matrix[i][i] + matrix[j][i];
                writeMATRIX(matrix, len);
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
    cout<<"hello";

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
