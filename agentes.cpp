//#include "auxiliares.h"
#include "auxiliares.cpp"

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


bool habiaQueAgregarlo(std::vector< std::vector<int> > agentes, std::vector<int>& elegidos, int actual){
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


void confiablesSinPodasAux(std::vector< std::vector<int> > agentes, std::vector<int>& restantes, std::vector<int>& elegidos){

    if(restantes.size() == 0 && estanTodosLosQueDeberian(agentes, elegidos)){
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

    if(restantes.size() == 0 && estanTodosLosQueDeberian(agentes, elegidos)){
        //llegué al final

        //por ahora, muestro el conjunto resultante
        imprimirVector(elegidos);
    
    } else {

            int actual = restantes[0];                                  //tomo el primero de los restantes restantes
            restantes.erase(restantes.begin());                         //lo quito, para no repetirlo en próximos llamados

            elegidos.push_back(actual);                                 //con el agente actual
            if(puedoAgregarloConPoda(agentes, elegidos, actual) && valeLaPena(agentes, restantes, elegidos, actual)){
                                                                        //me fijo si puedo agregar o no al agente al conjunto actual
                confiablesConPodasAux(agentes, restantes, elegidos);
            }

            if(elegidos.size() != 0){elegidos.pop_back();}              //sin el agente actual
            if(!habiaQueAgregarlo(agentes, elegidos, actual)){          //si no hacia falta agregar al actual, seguimos
                confiablesConPodasAux(agentes, restantes, elegidos);
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

    bool poda = true;
    if(argc == 2 && argv[1] == "0"){poda = false;}
    std::string inputPath;
    if (argc == 3){inputPath = argv[2];}


    //elección entre entrada manual o con un .in
    if (argc < 3){
        std::vector<std::vector<int > > agentes = entradaManual();
        //creamos restantes y elegidos
        std::vector<int> restantes;
        for (int i = 0; i < agentes.size(); ++i){restantes.push_back(i);}
        std::vector<int> elegidos;

        if(poda){confiablesConPodasAux(agentes, restantes, elegidos);}
        else{confiablesSinPodasAux(agentes, restantes, elegidos);}

    }

    else{

        std::vector<std::vector<std::vector<int> > > setDatos = parseador(inputPath);

        for (int i = 0; i < setDatos.size(); ++i)
        {
            for (int j = 0; j < setDatos[i].size(); ++j)
            {
                imprimirVector(setDatos[i][j]);
            }
        }

    }


    return 0;
}