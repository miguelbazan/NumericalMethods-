//
//  main.cpp
//  ExamenPractivo1_Q2
//
//  Created by Miguel Bazán on 3/1/16.
//  Copyright © 2016 Miguel Bazán. All rights reserved.
//

// Yarely Mercado A0120664
// Miguel Bazan A01281010
#include <iostream>

using namespace std;

const int iTam = 11;
bool debug = false;
double dMat[iTam][iTam];
double dSol[iTam];
int iCol;
int iRen;
bool bSinSolucion= false;
bool bSolInf = false;
int iA = 0;
double dPivAnt = 1;
double dPivAct;

//convertir a ceros todo antes del indice donde este menos la diagonal principal
void hacerCeros()
{
    for(int iR = 0; iR<iRen; iR++){
        for(int iC = 0; iC<=iA; iC++){
            if(iR!=iC)
                dMat[iR][iC] = 0;
            else
                dMat[iR][iC] = dPivAct;
        }
    }
}

void operCuadranteI()
{
    //uso la matriz, el indice en el que me encuentro k,,el  pivote actual y anterior
    for(int iR = 0; iR<iA; iR++){
        for(int iC = iA+1; iC<iCol; iC++){
            dMat[iR][iC] = (-1)*( dMat[iR][iA]*dMat[iA][iC] - dMat[iR][iC]*dPivAct ) / dPivAnt;
        }
    }
}
void operCuadranteII()
{
    for(int f = iA+1; f<iRen; f++){
        for(int c = iA+1; c<iCol; c++){
            dMat[f][c] = ( dPivAct*dMat[f][c] - dMat[iA][c]*dMat[f][iA] ) / dPivAnt;
        }
    }
}

void modificarRen(int iRen1, int iRen2)
{
    double dAux;
    for(int iC = 0; iC<iCol; iC++){
        dAux = dMat[iRen2][iC];
        dMat[iRen2][iC] = dMat[iRen1][iC];
        dMat[iRen1][iC] = dAux;
    }
}

void calcularSoluciones()
{
    int iCont=1;
    int iDeterminante = dMat[0][0];
    for(int iR = 0; iR<iRen; iR++){
        cout<<"X"<<iCont<<": "<< dMat[iR][iCol-1] << '/' << iDeterminante << ' '<<endl;
        iCont++;
    }
    cout<<endl;
}

void cambiarNegAPos()
{
    //cambia de signo los renglones que sean negativos para facilitar comparacion

    for(int iR = iA; iR<iRen; iR++){        //recorre la matriz cambiando el signo de los renglones que son todos negativos
        
        if(dMat[iR][iA+1]<=0){          //checa si el primer valor de la columna despuÈs de k es menor a 0
            int iC = iA+1;
            while(iC<iCol && dMat[iR][iC]<=0){
                iC++;
            }
            if(iC==iCol && dMat[iR][iC]<=0){
                //multiplico todo el renglÛn por -1
                for(int iK = iA+1; iK<iCol; iK++){
                    dMat[iR][iK] *= -1;
                }
            }
        }
        
    }
    
}
void compararRen()
{
    //compara los renglones restantes de la matriz para ver si no tiene solucion o tiene soluciones infinitas

    int iR,iC = iA+1;
    while(!bSinSolucion && iC<iCol)
    {
        iR = iA;
        while(!bSinSolucion && iR<(iRen-1))
        {

            //si una columna no es igual, se sale
            if(dMat[iR][iC]!=dMat[iR+1][iC])
            {
                bSinSolucion = true;
            }
            iR++;
        }
        iC++;
    }
    if(!bSinSolucion)
        bSolInf = true;
}

void metFinal(){
    
    while(!bSinSolucion && !bSolInf && iA<iRen)
    {
        dPivAct = dMat[iA][iA];
        
        operCuadranteI();
        operCuadranteII();
        hacerCeros();

        dPivAnt = dPivAct;
        iA++;
        int iSigRen = iA;
        while(dMat[iSigRen][iA]==0 && iSigRen<iRen)
        {
            iSigRen++;
        }
        if(dMat[iSigRen][iA]==0 && iA<iRen)
        {
            cambiarNegAPos();
            compararRen();

        }
        else
        {
            if(iSigRen != iA)
            modificarRen(iSigRen, iA);
        }
        
    }
}

void limpiarMat()
{
    for(int f = 0; f<iRen; f++){
        for(int c = 0; c<iCol;  c++){
            dMat[f][c] = 0;
        }
    }
}

int main(int argc, const char * argv[])
{
    int iVar, iEcuaciones;
    cout<< "Numero de ecuaciones: ";
    cin>>iVar;
    while(iVar!=0)
    {
        iEcuaciones = iVar;
        
        double dAux;
        limpiarMat();
        iA = 0;
        dPivAnt = 1;
        
        iRen = iEcuaciones;
        iCol = iVar+1;

        for(int f = 0; f<iEcuaciones; f++){
            
            for(int c = 0; c<iVar+1;  c++){
                cout<< "Da el coeficiente "<<c+1<<" de la ecuacion "<<f+1<<": ";
                cin>>dAux;
                dMat[f][c] = dAux;
            }
            
        }
        
        metFinal();

        if(bSinSolucion){
            cout<<"Solucion no unica"<<endl;
            bSinSolucion = false;
        }else{
            if(bSolInf){
                cout<<"Solucion no unica"<<endl;
                bSolInf = false;
            }else{
                calcularSoluciones();
            }
        }

        cin>>iVar;
        
    }
    
    
    return 0;
}