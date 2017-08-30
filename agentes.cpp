//#include "auxiliares.h"
#include "auxiliares.cpp"
#include <chrono>

#define now std::chrono::high_resolution_clock::now


bool puedoAgregarlo(std::vector< std::vector<int> > agentes, std::vector<int>& elegidos, int actual);
bool puedoAgregarloConPoda(std::vector< std::vector<int> > agentes, std::vector<int>& elegidos, int actual);
bool puedoAgregarloConPoda(std::vector< std::vector<int> > agentes, std::vector<int>& elegidos, int actual);
bool valeLaPena(std::vector< std::vector<int> > agentes, std::vector<int>& restantes, std::vector<int>& elegidos, int actual);
bool habiaQueAgregarlo(std::vector< std::vector<int> >& agentes, std::vector<int>& elegidos, int actual);
bool estanTodosLosQueDeberian(std::vector<std::vector<int > >& agentes, std::vector<int>& elegidos);
std::vector<std::vector<int> > confiablesSinPodas(std::vector< std::vector<int> >& agentes, std::vector<int>& restantes, std::vector<int>& elegidos);
void confiablesSinPodasAux(std::vector< std::vector<int> >& agentes, std::vector<int>& restantes, std::vector<int>& elegidos, std::vector<std::vector<int > >& finalistas, int& maximoActual);
std::vector<std::vector<int> > confiablesConPodas(std::vector< std::vector<int> >& agentes, std::vector<int>& restantes, std::vector<int>& elegidos);
void confiablesConPodasAux(std::vector< std::vector<int> >& agentes, std::vector<int>& restantes, std::vector<int>& elegidos, std::vector<std::vector<int > >& finalistas, int& maximoActual);

//


bool puedoAgregarlo(std::vector< std::vector<int> > agentes, std::vector<int>& elegidos, int actual){
    bool res = true;
    for (int i = 0; i < elegidos.size(); ++i){
        if (agentes[elegidos[i]][actual] == -1 || agentes[actual][elegidos[i]] == -1){res = false; break;}
    }
    return res;
}

bool puedoAgregarloConPoda(std::vector< std::vector<int> > agentes, std::vector<int>& elegidos, int actual){
    bool res = true;
    for (int i = 0; i < elegidos.size(); ++i){
        if (agentes[elegidos[i]][actual] == -1 || agentes[actual][elegidos[i]] == -1){res = false; break;}
        for (int j = 0; j < agentes.size(); ++j){
            if(agentes[elegidos[i]][j] + agentes[actual][j] == 0 && modulo(agentes[elegidos[i]][j]) > 0) {
                res = false;
                break;
            }
        }
    }
    return res;
}

bool valeLaPena(std::vector< std::vector<int> > agentes, std::vector<int>& restantes, std::vector<int>& elegidos, int actual){
    bool res = true;
    for (int i = 0; i < agentes.size(); ++i){
        //recorro todos los votos de actual
        if(agentes[actual][i] == 1){
            //cada vez que es un voto positivo, me fijo si este que debería agregar vota en contra a uno ya elegido
            for (int j = 0; j < elegidos.size(); ++j){
                if(agentes[i][elegidos[j]] == -1){res = false; break;}
            }
        }
    }
   return res;
}


bool habiaQueAgregarlo(std::vector< std::vector<int> >& agentes, std::vector<int>& elegidos, int actual){
    bool res = false;
    for (int i = 0; i < elegidos.size(); ++i){
        if (agentes[elegidos[i]][actual] == 1){res = true; break;}
    }

    return res;
}


bool estanTodosLosQueDeberian(std::vector<std::vector<int > >& agentes, std::vector<int>& elegidos){
    bool res = true;

    for (int i = 0; i < elegidos.size(); ++i){
        for (int j = 0; j < agentes.size(); ++j){
            if (agentes[elegidos[i]][j] == 1 && !esta(elegidos, j)){
                res = false;
                break;
            }
        }
    }
    return res;
}

std::vector<std::vector<int> > confiablesSinPodas(std::vector< std::vector<int> >& agentes, std::vector<int>& restantes, std::vector<int>& elegidos){
    std::vector<std::vector<int > > finalistas;
    int maximoActual = 0;
    confiablesSinPodasAux(agentes, restantes, elegidos, finalistas, maximoActual);

    std::cout << maximoActual;
    return finalistas;
}


void confiablesSinPodasAux(std::vector< std::vector<int> >& agentes, std::vector<int>& restantes, std::vector<int>& elegidos, std::vector<std::vector<int > >& finalistas, int& maximoActual){

    if(restantes.empty()){
        //llegué al final
        if (estanTodosLosQueDeberian(agentes, elegidos)){
            if (elegidos.size() == maximoActual){
                finalistas.push_back(elegidos);
            } else if (elegidos.size() > maximoActual){
                maximoActual = elegidos.size();
                if(finalistas.size() > 0){finalistas.empty();}
                finalistas.push_back(elegidos);
            }
        }

    } else {

            int actual = restantes[0];                                  //tomo el primero de los restantes restantes
            restantes.erase(restantes.begin());                         //lo quito, para no repetirlo en próximos llamados

            elegidos.push_back(actual);                                 //con el agente actual
            if(puedoAgregarlo(agentes, elegidos, actual)){              //me fijo si puedo agregar o no al agente al conjunto actual
                confiablesSinPodasAux(agentes, restantes, elegidos, finalistas, maximoActual);
            }

            if(elegidos.size() != 0){elegidos.pop_back();}              //sin el agente actual
            if(!habiaQueAgregarlo(agentes, elegidos, actual)){          //si no hacia falta agregar al actual, seguimos
                confiablesSinPodasAux(agentes, restantes, elegidos, finalistas, maximoActual);
            }


            restantes.insert(restantes.begin(), actual);
    }
}


std::vector<std::vector<int> > confiablesConPodas(std::vector< std::vector<int> >& agentes, std::vector<int>& restantes, std::vector<int>& elegidos){
    std::vector<std::vector<int > > finalistas;
    int maximoActual = 0;
    confiablesConPodasAux(agentes, restantes, elegidos, finalistas, maximoActual);

    std::cout << maximoActual;
    return finalistas;
}

void confiablesConPodasAux(std::vector< std::vector<int> >& agentes, std::vector<int>& restantes, std::vector<int>& elegidos, std::vector<std::vector<int > >& finalistas, int& maximoActual){

    if(restantes.empty()){
        //llegué al final
        if (estanTodosLosQueDeberian(agentes, elegidos)){
            if (elegidos.size() == maximoActual){
                finalistas.push_back(elegidos);
            } else if (elegidos.size() > maximoActual){
                maximoActual = elegidos.size();
                if(finalistas.size() > 0){finalistas.empty();}
                finalistas.push_back(elegidos);
            }
        }
    
    } else {

            int actual = restantes[0];                                  //tomo el primero de los restantes restantes
            restantes.erase(restantes.begin());                         //lo quito, para no repetirlo en próximos llamados

            elegidos.push_back(actual);                                 //con el agente actual
            if(puedoAgregarloConPoda(agentes, elegidos, actual) && valeLaPena(agentes, restantes, elegidos, actual)){
                                                                        //me fijo si puedo agregar o no al agente al conjunto actual
                confiablesConPodasAux(agentes, restantes, elegidos, finalistas, maximoActual);
            }

            if(elegidos.size() != 0){elegidos.pop_back();}              //sin el agente actual
            if(!habiaQueAgregarlo(agentes, elegidos, actual)){          //si no hacia falta agregar al actual, seguimos
                confiablesConPodasAux(agentes, restantes, elegidos, finalistas, maximoActual);
            }

            restantes.insert(restantes.begin(), actual);
    }
}


int main(int argc, char** argv){

    if (!(argc == 3 || argc == 2 || argc == 1)){
        std::cout << std::endl << "Error en los parametros de entrada. Los parametros correctos son:" << std::endl;
        std::cout << std::endl << "./agentes <activar podas> <datos.in>" << std::endl;
        std::cout << std::endl << "Activar podas: 1 para activarlas, 0 para desactivarlas." << std::endl;
        std::cout << "Si no se aclara, por defecto será 1." << std::endl;
        std::cout << "Si no se especifican datos de entrada, se utiliza entrada manual." << std::endl;
        return -1;
    }
    
    //cambiar che cambiar
    int poda = 0;
    if(argc > 1){poda = std::atoi(argv[1]);}
    std::string inputPath;
    if (argc == 3){inputPath = argv[2];}

    //elección entre entrada manual (stdin) o con un .in
    if (argc < 3){

        //parseo los datos pasados
        std::vector<std::vector<std::vector<int> > > setDatos;
        entradaManual(setDatos);

        for (int i = 0; i < setDatos.size(); ++i){
            //creamos restantes y elegidos
            std::vector<int> restantes;
            for (int j = 0; j < setDatos[i].size(); ++j){restantes.push_back(j);}
            std::vector<int> elegidos;

            std::chrono::high_resolution_clock::time_point t1;
            std::chrono::high_resolution_clock::time_point t2;
            std::chrono::duration<double> time_span;

            std::vector<std::vector<int > > finalistas;
            if(!poda){
                t1 = now();
                finalistas = confiablesSinPodas(setDatos[i], restantes, elegidos);
                t2 = now();
                time_span = std::chrono::duration_cast<std::chrono::duration<double> >(t2-t1);
                std::cout << " " << time_span.count() << std::endl;
            } else {
                t1 = now();
                finalistas = confiablesConPodas(setDatos[i], restantes, elegidos);
                t2 = now();
                time_span = std::chrono::duration_cast<std::chrono::duration<double> >(t2-t1);
                std::cout << " " << time_span.count() << std::endl;
            }

            normalizar(finalistas);
        }

    } else {

        //parseo los datos pasados
        std::vector<std::vector<std::vector<int> > > setDatos = parseador(inputPath);

        for (int i = 0; i < setDatos.size(); ++i){
            //creamos restantes y elegidos
            std::vector<int> restantes;
            for (int j = 0; j < setDatos[i].size(); ++j){restantes.push_back(j);}
            std::vector<int> elegidos;

            //chrono::high_resolution_clock::time_point t1;
            //chrono::high_resolution_clock::time_point t2;
            //chrono::duration<double> time_span;


            std::vector<std::vector<int > > finalistas;
            if(poda){
                //t1 = now();
                finalistas = confiablesSinPodas(setDatos[i], restantes, elegidos);
                //t2 = now();
                //time_span = chrono::duration_cast<chrono::duration<double>>(t2-t1);
                //std::cout << " " << time_span.count() << std::endl;
            } else {
                //t1 = now();
                finalistas = confiablesConPodas(setDatos[i], restantes, elegidos);
                //t2 = now();
                //time_span = chrono::duration_cast<chrono::duration<double>>(t2-t1);
                //std::cout << " " << time_span.count() << std::endl;
            }

            normalizar(finalistas);
        }

    }


    return 0;
}