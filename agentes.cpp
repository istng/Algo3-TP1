#include <iostream>
#include <vector>
//#include "auxiliares.h"

//mover a auxiliares.h
void imprimirVector(std::vector<int> v){
    if(v.size() != 0){
        std::cout << "{ ";
        for (int i = 0; i < v.size()-1; ++i){
            std::cout << v[i] << ", ";
        }
        std::cout << v[v.size()-1] << " }" << std::endl;
    }
}


/*void confiables(){

}*/

//necesitamos tres estados para votos: confiable, no confiable, y no sabe no contesta, 1, -1 y 0 (enumerate...)
void confiablesAux(std::vector< std::vector<int> > votos, std::vector<int>& agentes, std::vector<int>& elegidos){

    if(agentes.size() == 0){
        //llegué al final

        //por ahora, muestro el conjunto resultante
        std::cout << "{ ";
        for (int i = 0; i < elegidos.size()-1; ++i){
            std::cout << elegidos[i] << ", ";
        }
        std::cout << elegidos[elegidos.size()-1] << " }" << std::endl;
    
    } else {

            int actual = agentes[0];                    //tomo el primero de los agentes restantes
            agentes.erase(agentes.begin());             //lo quito, para no repetirlo en próximos llamados


            //voy a llamarme con y sin el agente actual

            /*if(esUnaSolucion(votos, elegidos, actual)){                 //tengo A y B en elegidos. si A confia en C pero B no, entonces corto...
                                                                        //...osea, A y B no pueden estar juntos

                //OBS: podemos hacer "puedoAgregarlo" en "esUnaSolucion", devolviendo por parámetro el resultado que reemplaza a...
                //..."puedoAgregarlo", para ahorrar llamadas, total ese laburo lo hacemos ahi también
            */

                //NUEVA OBS: con respecto a instancias inconsistentes: puedoAgregarlo las va a evitar, ya que va a chequear todos...
                //...los votos de cada elegido vs el actual, así no agregandolo si es inconsistente con algún elegido (evitando...
                //...el caso propuesto de A,B y C mas arriba

            	//al final lo de arriba va porque mira mas a futuro: elimina mas cosas... o no... preguntar "versión de git"...

                if(puedoAgregarlo(votos, elegidos, actual)){            //me fijo si puedo agregar o no al agente al conjunto actual
                    if(valeLaPena(votos, elegidos, actual, masDatos)){  //utilizo mis condiciones de poda de soluciones válidas
    
                    elegidos.push_back(actual);             			//con el agente actual
                    confiablesAux(agentes, elegidos);
                    }
                }
    
                if(valeLaPena2(votos, elegidos, actual, masDatos)) {    //utilizo mis condiciones de poda de soluciones válidas
                    if(elegidos.size() != 0){elegidos.pop_back();}		//sin el agente actual
                    confiablesAux(agentes, elegidos);
                }
            //}

            agentes.insert(agentes.begin(), actual);
    }
}



int main(){

    std::vector<int> agentes;
    for (int i = 0; i < 5; ++i){
        agentes.push_back(i+1);
    }

    std::vector<int> elegidos;

    confiablesAux(agentes, elegidos);
}