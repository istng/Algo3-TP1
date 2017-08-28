#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void imprimirVector(std::vector<int> v);

bool esta(std::vector<int> v, int a);

int modulo(int a);
int signo(int a);


std::vector<std::vector<int > > entradaManual();
std::vector<std::vector<std::vector<int> > > parseador(std::string inputPath);
void agregarAlSet(std::ifstream& input, std::vector<std::vector<std::vector<int> > >& setDatos);


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


std::vector<std::vector<int > > entradaManual(){
    std::cout << std::endl << "Ingrese la cantidad de agentes:" << std::endl;
    int cantidadAgentes = 0;
    std::cin >> cantidadAgentes;
    //creamos el vector de vectores de agentes, todo en cero
    std::vector<std::vector<int > > agentes(cantidadAgentes);
    for (int i = 0; i < cantidadAgentes; ++i){
        for (int j = 0; j < cantidadAgentes; ++j){
            agentes[i].push_back(0);
        }
    }

    std::cout << std::endl << "Ingrese la cantidad de votos:" << std::endl;
    int cantidadVotos;
    std::cin >> cantidadVotos;

    for (int i = 0; i < cantidadAgentes; ++i){
        for (int j = 0; j < cantidadAgentes; ++j){
            agentes[i].push_back(0);
        }
    }

    std::cout << std::endl << "Ingrese todos los votantes con cada voto:" << std::endl;
    for (int i = 0; i < cantidadVotos; ++i){
        int votante;
        std::cin >> votante;
        int voto;
        std::cin >> voto;
        agentes[votante-1][modulo(voto)-1] = signo(voto);
    }

    return agentes;
}

std::vector<std::vector<std::vector<int> > > parseador(std::string inputPath){
    std::vector<std::vector<std::vector<int> > > setDatos;

    std::ifstream input( inputPath, std::ifstream::in );
    
    agregarAlSet(input, setDatos);
    
    return setDatos;
}

void agregarAlSet(std::ifstream& input, std::vector<std::vector<std::vector<int> > >& setDatos){

    std::string lineaActual;
    getline(input, lineaActual);

    if (lineaActual[0] == 0 && lineaActual[2] == 0){
        //no hacemos nada, llegamos al final
        return;
    } else {
        int cantidadAgentes = lineaActual[0] - '0';
        int cantidadVotos = lineaActual[2] - '0';

        std::vector<std::vector<int > > agentes(cantidadAgentes);
        for (int i = 0; i < cantidadAgentes; ++i){
            for (int j = 0; j < cantidadAgentes; ++j){
                agentes[i].push_back(0);
            }
        }

        for (int i = 0; i < cantidadVotos; ++i){
            getline(input, lineaActual);
            int votante = lineaActual[0] - '0';
            int voto = lineaActual[2] - '0';

            agentes[votante-1][modulo(voto)-1] = signo(voto);
        }


        for (int i = 0; i < agentes.size(); ++i)
        {
            imprimirVector(agentes[i]);
        }


        setDatos.push_back(agentes);

        agregarAlSet(input, setDatos);
    }
}