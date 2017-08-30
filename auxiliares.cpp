#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void imprimirVector(std::vector<int> v);

bool esta(std::vector<int> v, int a);

int modulo(int a);
int signo(int a);

void normalizar(std::vector<std::vector<int> >& v);

void entradaManual(std::vector<std::vector<std::vector<int > > >& setDatos);



//

void imprimirVector(std::vector<int> v){
    if(v.size() != 0){
        std::cout << "{ ";
        for (int i = 0; i < v.size()-1; ++i){
            std::cout << v[i] << ", ";
        }
        std::cout << v[v.size()-1] << " }" << std::endl;
    } else {
        std::cout << "{ }" << std::endl;
    }
}


bool esta(std::vector<int> v, int a){
    bool res = false;
    for (int i = 0; i < v.size(); ++i){
        if (v[i] == a){
            res = true;
            break;
        }
    }
    return res;
}


int modulo(int a){
    int res = a;
    if (a < 0){res = -1*a;} 
    return res;
}

int signo(int a){
    int res = 1;
    if(a < 0){res = -1;}
    return res;
}

void normalizar(std::vector<std::vector<int> >& v){
    if(!v.empty()){
        for (int i = 0; i < v.size(); ++i){
            for (int j = 0; j < v[i].size(); ++j){
                if(!v[i].empty()){
                    v[i][j] = v[i][j] + 1;
                }
            }
        }
    }
}

void entradaManual(std::vector<std::vector<std::vector<int > > >& setDatos){

    int cantidadAgentes, cantidadVotos;
    std::cin >> cantidadAgentes >> cantidadVotos;

    if (cantidadAgentes == 0 && cantidadVotos == 0){
        //no hacemos nada, llegamos al final
    } else {
        //inicializo el vector de agentes
        std::vector<std::vector<int > > agentes(cantidadAgentes);
        for (int i = 0; i < cantidadAgentes; ++i){
            for (int j = 0; j < cantidadAgentes; ++j){
                agentes[i].push_back(0);
            }
        }

        for (int i = 0; i < cantidadVotos; ++i){

            int votante, voto;
            std::cin >> votante >> voto;

            if(agentes[votante-1][modulo(voto)-1] == 0){
            agentes[votante-1][modulo(voto)-1] = signo(voto);
            } else if(agentes[votante-1][modulo(voto)-1] != signo(voto)){
                agentes[votante-1][votante-1] = -1;
            }
        }

        setDatos.push_back(agentes);

        entradaManual(setDatos);
    }
}

