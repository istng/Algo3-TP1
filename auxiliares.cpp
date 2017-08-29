#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void imprimirVector(std::vector<int> v);

bool esta(std::vector<int> v, int a);

int modulo(int a);
int signo(int a);


void entradaManual(std::vector<std::vector<std::vector<int > > >& setDatos);
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

            agentes[votante-1][modulo(voto)-1] = signo(voto);
        }

        setDatos.push_back(agentes);

        entradaManual(setDatos);
    }
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

    if (std::stoi(&lineaActual[0]) == 0 && std::atoi(&lineaActual[2]) == 0){
        //no hacemos nada, llegamos al final
    } else {
        int cantidadAgentes = std::atoi(&lineaActual[0]);
        int cantidadVotos = std::atoi(&lineaActual[2]);

        std::vector<std::vector<int > > agentes(cantidadAgentes);
        for (int i = 0; i < cantidadAgentes; ++i){
            for (int j = 0; j < cantidadAgentes; ++j){
                agentes[i].push_back(0);
            }
        }

        for (int i = 0; i < cantidadVotos; ++i){
            getline(input, lineaActual);
            int votante = std::atoi(&lineaActual[0]);
            int voto = std::atoi(&lineaActual[2]);

            agentes[votante-1][modulo(voto)-1] = signo(voto);
        }

        setDatos.push_back(agentes);

        agregarAlSet(input, setDatos);
    }
}

