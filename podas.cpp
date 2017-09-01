#include "auxiliares.cpp"


//Podas

std::vector<std::vector<int> > confiablesSinPodas(std::vector< std::vector<int> >& agentes, std::vector<int>& restantes, std::vector<int>& elegidos);
void confiablesSinPodasAux(std::vector< std::vector<int> >& agentes, std::vector<int>& restantes, std::vector<int>& elegidos, std::vector<std::vector<int > >& finalistas, int& maximoActual);
std::vector<std::vector<int> > confiablesConPodas(std::vector< std::vector<int> >& agentes, std::vector<int>& restantes, std::vector<int>& elegidos);
void confiablesConPodasAux(std::vector< std::vector<int> >& agentes, std::vector<int>& restantes, std::vector<int>& elegidos, std::vector<std::vector<int > >& finalistas, int& maximoActual);

std::vector<std::vector<int> > confiablesConPodaMax(std::vector< std::vector<int> >& agentes, std::vector<int>& restantes, std::vector<int>& elegidos);
void confiablesConPodaMaxAux(std::vector< std::vector<int> >& agentes, std::vector<int>& restantes, std::vector<int>& elegidos, std::vector<std::vector<int > >& finalistas, int& maximoActual);
std::vector<std::vector<int> > confiablesConPodaFuturo(std::vector< std::vector<int> >& agentes, std::vector<int>& restantes, std::vector<int>& elegidos);
void confiablesConPodaFuturoAux(std::vector< std::vector<int> >& agentes, std::vector<int>& restantes, std::vector<int>& elegidos, std::vector<std::vector<int > >& finalistas, int& maximoActual);


//Auxiliares de podas

bool puedoAgregarlo(std::vector< std::vector<int> > agentes, std::vector<int>& elegidos, int actual);
bool puedoAgregarloConPoda(std::vector< std::vector<int> > agentes, std::vector<int>& elegidos, int actual);
bool puedoAgregarloConPoda(std::vector< std::vector<int> > agentes, std::vector<int>& elegidos, int actual);
bool valeLaPena(std::vector< std::vector<int> > agentes, std::vector<int>& restantes, std::vector<int>& elegidos, int actual);
bool habiaQueAgregarlo(std::vector< std::vector<int> >& agentes, std::vector<int>& elegidos, int actual);
bool estanTodosLosQueDeberian(std::vector<std::vector<int > >& agentes, std::vector<int>& elegidos);
bool pasoElMaximo(int restTam, int elegTam, int maximoActual);


//Implementación

bool puedoAgregarlo(std::vector< std::vector<int> > agentes, std::vector<int>& elegidos, int actual){
	//recorro todos los elegidos viendo que el elegido i-esimo no vote en contra de acutal, ni que actual
	//ni que actual vote en contra del i-esimo
    bool res = true;
    for (int i = 0; i < elegidos.size(); ++i){
        if (agentes[elegidos[i]][actual] == -1 || agentes[actual][elegidos[i]] == -1){res = false; break;}
    }
    return res;
}

bool puedoAgregarloConPoda(std::vector< std::vector<int> > agentes, std::vector<int>& elegidos, int actual){
	//hago lo mismo que en puedoAgregarlo, pero además, si es exitoso eso, me fijo que cada voto j-esimo de
	//cada elegido mas cada voto j-esimo de actual no de cero (esto significaría que uno voto 1 y el otro -1,
	//inconsistencia)
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
    //chequeo si el actual que no voy a agregar (caso de recusión) enrealidad debía agregarlo
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


//Implementación podas

bool pasoElMaximo(int restTam, int elegTam, int maximoActual){
    return restTam + elegTam > maximoActual;
}


std::vector<std::vector<int> > confiablesSinPodas(std::vector< std::vector<int> >& agentes, std::vector<int>& restantes, std::vector<int>& elegidos){
    //inicializo variables
    std::vector<std::vector<int > > finalistas;
    int maximoActual = 0;
    //llamo a la función que hace todo
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
            if(puedoAgregarloConPoda(agentes, elegidos, actual) && valeLaPena(agentes, restantes, elegidos, actual) && pasoElMaximo(restantes.size(), elegidos.size(), maximoActual)){
                                                                        //me fijo si puedo agregar o no al agente al conjunto actual
                confiablesConPodasAux(agentes, restantes, elegidos, finalistas, maximoActual);
            }

            if(elegidos.size() != 0){elegidos.pop_back();}              //sin el agente actual
            if(!habiaQueAgregarlo(agentes, elegidos, actual) && pasoElMaximo(restantes.size(), elegidos.size(), maximoActual)){          //si no hacia falta agregar al actual, seguimos
                confiablesConPodasAux(agentes, restantes, elegidos, finalistas, maximoActual);
            }

            restantes.insert(restantes.begin(), actual);
    }
}




//Implementación con podas separadas (es copy paste del código anterior, pero usando sólo un tipo de poda)

std::vector<std::vector<int> > confiablesConPodaMax(std::vector< std::vector<int> >& agentes, std::vector<int>& restantes, std::vector<int>& elegidos){
    std::vector<std::vector<int > > finalistas;
    int maximoActual = 0;
    confiablesConPodaMaxAux(agentes, restantes, elegidos, finalistas, maximoActual);

    std::cout << maximoActual;
    return finalistas;
}

void confiablesConPodaMaxAux(std::vector< std::vector<int> >& agentes, std::vector<int>& restantes, std::vector<int>& elegidos, std::vector<std::vector<int > >& finalistas, int& maximoActual){

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
            if(puedoAgregarlo(agentes, elegidos, actual) && pasoElMaximo(restantes.size(), elegidos.size(), maximoActual)){
                                                                        //me fijo si puedo agregar o no al agente al conjunto actual
                confiablesConPodaMaxAux(agentes, restantes, elegidos, finalistas, maximoActual);
            }

            if(elegidos.size() != 0){elegidos.pop_back();}              //sin el agente actual
            if(!habiaQueAgregarlo(agentes, elegidos, actual) && pasoElMaximo(restantes.size(), elegidos.size(), maximoActual)){          //si no hacia falta agregar al actual, seguimos
                confiablesConPodaMaxAux(agentes, restantes, elegidos, finalistas, maximoActual);
            }

            restantes.insert(restantes.begin(), actual);
    }
}


std::vector<std::vector<int> > confiablesConPodaFuturo(std::vector< std::vector<int> >& agentes, std::vector<int>& restantes, std::vector<int>& elegidos){
    std::vector<std::vector<int > > finalistas;
    int maximoActual = 0;
    confiablesConPodaFuturoAux(agentes, restantes, elegidos, finalistas, maximoActual);

    std::cout << maximoActual;
    return finalistas;
}

void confiablesConPodaFuturoAux(std::vector< std::vector<int> >& agentes, std::vector<int>& restantes, std::vector<int>& elegidos, std::vector<std::vector<int > >& finalistas, int& maximoActual){

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
                confiablesConPodaFuturoAux(agentes, restantes, elegidos, finalistas, maximoActual);
            }

            if(elegidos.size() != 0){elegidos.pop_back();}              //sin el agente actual
            if(!habiaQueAgregarlo(agentes, elegidos, actual)){          //si no hacia falta agregar al actual, seguimos
                confiablesConPodaFuturoAux(agentes, restantes, elegidos, finalistas, maximoActual);
            }

            restantes.insert(restantes.begin(), actual);
    }
}
