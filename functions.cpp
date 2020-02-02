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
            matrix[i][j] = (rand() % 100) + 1;
        }
    }
}

void randomRESULT(double * tab, int len){
    for(int i = 0 ; i < len ; i++){
        tab[i] = (rand() % 100) + 1;
    }
}

void writeMATRIX(double ** matrix, double * results, int len){
    cout<<endl;
    for(int i = 0 ; i <len ; i++){
        for(int j = 0 ; j<len ; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<" | "<<results[i];
        cout<<endl;
    }
    cout<<endl;
}

void printRESULTS(double * tab, int len){
    cout<<endl<<"-----------------------------------------------"<<endl;
    cout<<endl<<"RESULTS: "<<endl;
    for(int i = 0 ; i < len ; i++){
        cout<<"x"<<i+1<<" = "<<tab[i]<<endl;
    }
    cout<<endl<<"-----------------------------------------------"<<endl;
}

void calculate(double ** matrix, double * results,int len){
    double scaler;
    //cout<<"START"<<endl;
    for(int i = 0 ; i < len ; i++){
        //cout<<endl<<"Pierwszy for "<<i<<endl<<"Matrix i i : "<<matrix[i][i]<<endl;
        if(matrix[i][i]!=1.0){
            //cout<<"scaler";
            scaler = matrix[i][i];
            //cout<<scaler<<endl;
            for(int y = i ; y < len ; y++){
                matrix[i][y] /= scaler;
            }
            results[i]/=scaler;
            //writeMATRIX(matrix, results, len);
        }
        for(int j = i + 1  ; j < len ; j++){
            //cout<<endl<<"taki tam for "<<j<<endl;
            scaler = (-1*matrix[j][i])/matrix[i][i];
            //cout<<endl<<"scaler: "<<scaler<<endl;

            for(int y = i ; y < len ; y++){
                //cout<<endl<<"Ostatni for j y = "<<matrix[j][y]<<endl;
                matrix[j][y] = scaler * matrix[i][y] + matrix[j][i];
                //writeMATRIX(matrix, results, len);
            }
            results[i] = scaler * results[0] + results[i];
            //writeMATRIX(matrix, results, len);

        }
        //writeMATRIX(matrix, results, len);
        //cout<< endl;
    }
    //---------- znajdowanie rozwiązan
    //writeMATRIX(matrix, results,len);
    double search;
    for(int i = len - 2 ; i >= 0 ; i--){
        search = 0;
        //cout<<endl<<"startlastfor"<<endl;
        for(int j = len - 1 ; j > i ; j--){
            //cout<<endl<<i<<" "<<j<<" "<<matrix[i][j]<<" ";
            search += matrix[i][j] * results[j];
            //cout<<search<<endl;

        }
        //cout<<"last search: "<<search<< " "<< results[i];
        //cout<<endl;
        results[i] = results[i] - search;
        //writeMATRIX(matrix, results, len);
    }

}

void finishApp(double ** matrix, double * res,int len){
    //destroy matrix
    for(int i = 0 ; i < len ; i++){
        delete [] matrix[i];
    }
    delete [] matrix;
    delete [] res;
    cout<<"//DONE";

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
    writeMATRIX(matrix, results, noe);
    calculate(matrix, results, noe);
    cout<<endl<<"DONE"<<endl;
    writeMATRIX(matrix, results, noe);
    printRESULTS(results, noe);
    finishApp(matrix, results, noe);
}
