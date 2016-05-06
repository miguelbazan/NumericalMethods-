//
//  main.cpp
//  InterpolacionUnica
//
//  Created by Miguel Bazán on 3/16/16.
//  CofPyright © 2016 Miguel Bazán. All rights reserved.

//  Yarely Mercado
//  Miguel Bazán

#include <iostream>
#include <math.h>
using namespace std;


int main(int argc, const char * argv[])
{
    int iN, iX, iY, iR, iJ, iA;
    
    float   iZ,
            iW,
            iPrueba,
            iYFin = 0;
    
    cout<<"Cantidad de pares a utilizar" << endl;
    
    cin>> iN;
    
    float fPx[iN],fPy[iN];
    float fMatA[iN][iN];
    float fMatB[iN][iN];
    float fAuxA[iN];
    float fAuxB[iN];
    
    for (iX = 0; iX < iN; iX++)
    {
        fAuxA[iX]=0;
        fAuxB[iX]=0;
    }
    for (iX = 0; iX < iN; iX++)
    {
        
        for(iY = 0; iY < iN; iY++)
        {
            fMatB[iX][iY]=0;
        }
        
        fMatB[iX][iX]=1;
    }
    cout<<"Ingrese los valores de x:"<<endl;
    
    for (iX = 0; iX < iN; iX++)
    {
        cout<< "x" <<iX<<" :";
        cin>>fPx[iX];
    }
    cout<<"Ingrese los valores de y:"<<endl;
    for (iX = 0; iX < iN; iX++)
    {
        cout<< "y " <<iX<<" :";
        
        cin>>fPy[iX];
    }
    cout<<"Ingrese punto a evaluar:"<<endl;
    cin>>iPrueba;
    
    for (iX = 0; iX<iN ; iX++)
    {
        for (iY = 0; iY<iN ; iY++)
        {
            fMatA[iX][iY]= pow(fPx[iX],iY);
        }
    }
    
    for (iX = 0; iX < iN; iX++)
    {
        if (fMatA[iX][iX] == 0)
        {
            for (iY = iX; iY < iN ; iY++)
            {
                if (fMatA[iY][iX] == 0)
                {
                    
                }
                else
                {
                    for (iA = 0; iA < iN; iA++)
                    {
                        fAuxA[iA]=fMatA[iY][iA];
                        fAuxB[iA]=fMatB[iY][iA];
                        fMatA[iY][iA]=fMatA[iX][iA];
                        fMatB[iY][iA]=fMatB[iX][iA];
                        fMatA[iX][iA]=fAuxA[iA];
                        fMatB[iX][iA]=fAuxB[iA];
                    }
                }
            }
        }
    }
    
    for (iX = 0; iX < iN; iX++)
    {
        iZ = fMatA[iX][iX];
        
        for (iY = 0; iY < iN; iY++)
        {
            fMatA[iX][iY] = fMatA[iX][iY] / iZ;
            fMatB[iX][iY] = fMatB[iX][iY] / iZ;
        }
        for (iR = 0;iR < iN; iR++)
        {
            if(iR == iX)
            {
                
            }
            else if (iR != iX)
            {
                iW = fMatA[iR][iX];
                
                for (iJ = 0 ; iJ < iN ; iJ++)
                {
                    fMatA[iR][iJ]= (fMatA[iR][iJ])-(iW * fMatA[iX][iJ]);
                    fMatB[iR][iJ]= (fMatB[iR][iJ])-(iW * fMatB[iX][iJ]);
                }
            }
        }
    }
    
    cout<< "Respuesta: "<<endl;
    
    for (iX = 0; iX < iN; iX++)
    {
        iW = 0;
        
        for (iY = 0; iY < iN; iY++)
        {
            
            iW = iW + (fPy[iY] * fMatB[iX][iY]);
        }
        
        cout<<"a"<<iX<<" = "<<iW<<endl;
        
        iYFin = iYFin + (iW * pow(iPrueba,iX));
    }
    
    cout<<"Y = ";
    cout<< iYFin;
    
    return 0;
}