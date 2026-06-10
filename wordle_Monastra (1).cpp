#include "lib.h"
#include <iostream>


using namespace std;

int main(){
     srand(time(NULL));
    vector<string>listado=cargar_listado("listado.txt");
    int x = 6; 
    int eleccion = rand() % listado.size()-1;
    string secreta = listado[eleccion];
    while(x>0){
        cout << "Ingrese una palabra, Tiene " <<x<< " intentos" <<endl;
        string palabra;
        cin >> palabra;
        if(intento_valido(palabra,secreta,listado)){
            vector<EstadoLetra> vec1 = evaluar_intento(palabra,secreta);
            string respu = respuesta_en_string(vec1);
            if(respu == "+++++"){
                cout<< "Correcto"<<endl;
                break;
            }
            else{
                cout<<"intente de nuevo"<<endl;
                x--;
                cout<<respu<<endl;
            }
        }
        else{
            cout<<"Intento no valido"<<endl;
        }
            


        }
        cout<<"No hay mas intentos"<<endl;







        }