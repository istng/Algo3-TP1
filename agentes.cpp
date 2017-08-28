#include "auxiliares.h"


bool puedoAgregarlo(std::vector< std::vector<int> > agentes, std::vector<int>& elegidos, int actual){
    bool res = true;
    for (int i = 0; i < elegidos.size(); ++i){
        if (agentes[elegidos[i]][actual] == -1 || agentes[actual][elegidos[i]] == -1){res = false;}
    }
    return res;
}

bool puedoAgregarloConPoda(std::vector< std::vector<int> > agentes, std::vector<int>& elegidos, int actual){
    bool res = true;
    for (int i = 0; i < elegidos.size(); ++i){
        for (int j = 0; j < agentes.size(); ++j){
            if(agentes[i][j] == -1 || agentes[actual][j] == -1) {res = false;}
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
                if(agentes[i][j] == -1){res = false;}
            }
        }
    }
   return res;
}


bool habiaQueAgregarlo(std::vector< std::vector<int> > agentes, std::vector<int>& elegidos, int actual){
    bool res = false;
    for (int i = 0; i < elegidos.size(); ++i){
        if (agentes[i][actual] == 1){res = true;}
    }

    return res;
}


bool esConsistente(std::vector<std::vector<int > >& agentes, std::vector<int>& elegidos){
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


void confiablesSinPodasAux(std::vector< std::vector<int> > agentes, std::vector<int>& restantes, std::vector<int>& elegidos){

    if(restantes.size() == 0 && esConsistente(agentes, elegidos)){
        //llegué al final

        //por ahora, muestro el conjunto resultante
        imprimirVector(elegidos);
    
    } else {

            int actual = restantes[0];                                  //tomo el primero de los restantes restantes
            restantes.erase(restantes.begin());                         //lo quito, para no repetirlo en próximos llamados

            elegidos.push_back(actual);                                 //con el agente actual
            if(puedoAgregarlo(agentes, elegidos, actual)){              //me fijo si puedo agregar o no al agente al conjunto actual
                confiablesSinPodasAux(agentes, restantes, elegidos);
            }
    
            if(elegidos.size() != 0){elegidos.pop_back();}              //sin el agente actual
            if(!habiaQueAgregarlo(agentes, elegidos, actual)){          //si no hacia falta agregar al actual, seguimos
                confiablesSinPodasAux(agentes, restantes, elegidos);
            }

            
            restantes.insert(restantes.begin(), actual);
    }
}


void confiablesConPodasAux(std::vector< std::vector<int> > agentes, std::vector<int>& restantes, std::vector<int>& elegidos){

    if(restantes.size() == 0){
        //llegué al final

        //por ahora, muestro el conjunto resultante
        imprimirVector(elegidos);
    
    } else {

            int actual = restantes[0];                                  //tomo el primero de los restantes restantes
            restantes.erase(restantes.begin());                         //lo quito, para no repetirlo en próximos llamados


            if(puedoAgregarloConPoda(agentes, elegidos, actual)){       //me fijo si puedo agregar o no al agente al conjunto actual
                if(valeLaPena(agentes, restantes, elegidos, actual)){    //utilizo mis condiciones de poda de soluciones válidas
                    elegidos.push_back(actual);             			//con el agente actual
                    confiablesConPodasAux(agentes, restantes, elegidos);
                }
            }
    
            if(habiaQueAgregarlo(agentes, elegidos, actual)){           //si algun elegido lo necesitaba, cortamos aca porque la instancia sería invalida
                if(elegidos.size() != 0){elegidos.pop_back();}		    //sin el agente actual
                confiablesConPodasAux(agentes, restantes, elegidos);
            }

            restantes.insert(restantes.begin(), actual);
    }
}



int main(int argc, char** argv){

    if (!(argc == 2 || argc == 1)){
        std::cout << std::endl << "Error en los parametros de entrada. Los parametros correctos son:" << std::endl;
        std::cout << std::endl << "./main <activar podas>" << std::endl;
        std::cout << std::endl << "Activar podas: 1 para activarlas, 0 para desactivarlas." << std::endl;
        std::cout << "Si no se aclara, por defecto será 1." << std::endl;
        return -1;
    }

    //cambiar en cuanto este bien lo de python
    bool poda = false;
    if(argc == 2 && argv[1] == "0"){poda = false;}


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

    std::cout << std::endl << "Ingrese todos los votantes con cada voto:" << std::endl;
    for (int i = 0; i < cantidadVotos; ++i){
        int votante;
        std::cin >> votante;
        int voto;
        std::cin >> voto;
        agentes[votante-1][modulo(voto)-1] = signo(voto);
    }

    //creamos restantes y elegidos
    std::vector<int> restantes;
    for (int i = 0; i < cantidadAgentes; ++i){
        restantes.push_back(i);
    }
    std::vector<int> elegidos;

    if(poda){confiablesConPodasAux(agentes, restantes, elegidos);}
    else{confiablesSinPodasAux(agentes, restantes, elegidos);}

}