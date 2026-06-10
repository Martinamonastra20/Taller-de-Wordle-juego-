#include "lib.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

vector<string> cargar_listado(const string & nombre_archivo){
    
    string filename = nombre_archivo;
    ifstream file(filename);
    if (file.good() == false) {
        cout << "Error al abrir el archivo" << filename << endl;
        exit(1);
    }
    vector<string> listado;
    string palabra;
    while (!file.eof()) {
        file >> palabra;
        listado.push_back(palabra);
    }
    if(listado[0]==""){
        listado = {};
    }



    return listado;
}

int len(const string palabra){
    int i = 0;
    while (palabra[i] != '\0'){
        i++;
    }
    return i;
}

bool intento_valido(const string & intento, const string & palabra_secreta, const vector<string> &listado){
            if (len(intento) != len(palabra_secreta)){
                return false;
            }
            int i = 0;
            int tamaño = listado.size();
            while (i < tamaño){
                if (listado[i] == intento){
                    return true;
                }
                i++;
          
            }
            return false;
}

vector<EstadoLetra> evaluar_intento(const string & intento, const string & palabra_secreta){
    vector <EstadoLetra> respuesta;
    int i = 0;
    while (i < len(palabra_secreta)){
        if (intento[i] == palabra_secreta[i]){
            respuesta.push_back(EstadoLetra::LugarCorrecto);
        }
        else{
            int j = 0;
            while (j < len(palabra_secreta)){
                if (intento[i] == palabra_secreta[j]){
                    respuesta.push_back(EstadoLetra::LugarIncorrecto);
                    break;
                }
                j++;
            }
            if (j == len(palabra_secreta)){
                respuesta.push_back(EstadoLetra::NoPresente);
            }

        }
        i++;
    }

    return respuesta;
}

string respuesta_en_string(const vector<EstadoLetra> & respuesta){
    string rta;
    int i = respuesta.size();
    int j=0;
    while(j<i){
        if (respuesta[j] == EstadoLetra::LugarCorrecto){
            rta= rta+'+';
        }
        else if(respuesta[j] == EstadoLetra::LugarIncorrecto){
            rta=rta+'-';
        }
        else{
            rta=rta+'X';

        }
        j++;

    }
    return rta;
}

