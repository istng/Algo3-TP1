#include "auxiliares.h"




bool puedoAgregarloConPoda(std::vector< std::vector<int> > agentes, std::vector<int>& restantes, std::vector<int>& elegidos, int actual){
    bool res = true;
    for (int i = 0; i < elegidos.size(); ++i){
        for (int j = 0; j < agentes.size(); ++j){
            if(agentes[i][j] + agentes[actual][j] == 0) {res = false;}
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
    res = false;
    for (int i = 0; i < elegidos.size(); ++i){
        if (elegidos[i][actual] == 1){res = true;}
    }

    return res;
}



//necesitamos tres estados para agentes: confiable, no confiable, y no sabe no contesta, 1, -1 y 0 (enumerate...)
void confiablesConPodasAux(std::vector< std::vector<int> > agentes, std::vector<int>& restantes, std::vector<int>& elegidos){

    //restantes tiene que empezar en 0 y no en 1 IMPORTANTE PARA EL PARSEO

    if(restantes.size() == 0){
        //llegué al final

        //por ahora, muestro el conjunto resultante
        imprimirVector(elegidos);
    
    } else {

            int actual = restantes[0];                                  //tomo el primero de los restantes restantes
            restantes.erase(restantes.begin());                         //lo quito, para no repetirlo en próximos llamados


            if(puedoAgregarloConPoda(agentes, elegidos, actual)){       //me fijo si puedo agregar o no al agente al conjunto actual
                if(valeLaPena(agentes, elegidos, actual, masDatos)){    //utilizo mis condiciones de poda de soluciones válidas
                    elegidos.push_back(actual);             			//con el agente actual
                    confiablesConPodasAux(restantes, elegidos);
                }
            }
    
            if(habiaQueAgregarlo(agentes, elegidos, actual)){           //si algun elegido lo necesitaba, cortamos aca porque la instancia sería invalida
                if(elegidos.size() != 0){elegidos.pop_back();}		    //sin el agente actual
                confiablesConPodasAux(restantes, elegidos);
            }

            restantes.insert(restantes.begin(), actual);
    }
}



int main(){

    std::vector<int> restantes;
    for (int i = 0; i < 5; ++i){
        restantes.push_back(i+1);
    }

    std::vector<int> elegidos;

    confiablesConPodasAux(restantes, elegidos);
}