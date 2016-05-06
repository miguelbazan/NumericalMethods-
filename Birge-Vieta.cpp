/*

 Miguel Bazán A. A01281010
 Yarely Mercado G. A01280668
 
 */
#include <iostream>
using namespace std;
#include <vector>
#include <math.h>
#include <stdlib.h>

double division (vector <double> vPolinomio, int iGrado, double dXi, bool bDivision)
{
    vector<double> vDerivada;
    double dFpx;
    double dFx = vPolinomio[iGrado];
    
    
    for (int iR = iGrado-1; iR >= 0; iR--)
    {
        dFx *= dXi;
        dFx += vPolinomio[iR];                      // Sacando el valor del polinomio evaluado en X.
        vDerivada.insert(vDerivada.begin(), dFx);
    }
    
    if (bDivision)
    {
        dFpx= vPolinomio[iGrado];
        
        for (int iR = iGrado - 1; iR >= 1; iR--)
        {                                               // Sacando el valor de la derivada del polinomio evaluado en X.
            dFpx *= dXi;
            dFpx += vDerivada[iR];
        }
        
        return dFx / dFpx;          // REtorna valor del polinomio evaluado en X sobre derivada evaluada en X
    }
    else
        return dFx;             // Retorna valor de polinomio evaluado en X.
}
int main(int argc, const char * argv[])
{
    int iNumero;
    double dError, dRaiz,dCoeficiente;      // creacion de variables
    int iGrado, iMaxIter;
    vector<double> vPolinomio;
    
    
    do{
        cout<<"Grado del polinomio: ";      // pedir grado del polinomio
        cin>> iGrado;
        
        for (int iR = iGrado; iR >= 0; iR--)
        {                                                       // Preguntar por coeficientes de cada grado
            cout<<"Coeficiente para el grado "<<iR<< ": ";
            cin>> dCoeficiente;
            
            vPolinomio.insert(vPolinomio.begin(), dCoeficiente);        // Agregar coeficientes al vector
        }
        
        cout<<"Epsilon: ";
        cin>> dError;               // Preguntar el margen de error
        cout<<"Numero maximo de iteraciones: ";
        cin>> iMaxIter;         //PReguntar numero de iteraciones
        
        int iRaiz = 1;
        
        while (iGrado > 0)
        {
            int iIteraciones = iMaxIter;
            
            dRaiz = rand()%100;     // Sacando nuermo aleatorio de X0.
            
            do{
                dRaiz = dRaiz - division(vPolinomio, iGrado, dRaiz, 1);         // Sacando raices del polinomio
                
            } while ((dError<fabs(division(vPolinomio, iGrado, dRaiz, 0))) && (0<-- iIteraciones));
            
            if (0 < iIteraciones)
            {
                cout<<"Raiz numero "<<iRaiz++ << " es "<< dRaiz << endl;        // desplegar raices
                
                double dY = vPolinomio[iGrado];
                
                for (int iR = iGrado-1; iR >= 1; iR--)
                {
                    dY *= dRaiz;
                    dY += vPolinomio[iR];
                    vPolinomio[iR] = dY;
                }
                vPolinomio.erase(vPolinomio.begin());
                iGrado--;
            }
            else
            {
                cout<<"No hay mas raices reales\n";
                break;
            }
        }
        
        vPolinomio.clear();     //Limpiar el vector
        
        cout<<"Otro polinomio ? 1.Si 2.No\n ";          // Preguntar si se desea hacer el proceso de nuevo con otro polinomio
        cin>>iNumero;
        
    } while(iNumero == 1);      // Si es 1 se queda si es 2 se sale
    
    return 0;
}
