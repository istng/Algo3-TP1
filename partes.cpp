#include <iostream>
#include <vector>
//#include "auxiliares.h"


/*void confiables(){

}*/

void imprimirVector(std::vector<int> v){
    if(v.size() != 0){
        std::cout << "{ ";
        for (int i = 0; i < v.size()-1; ++i){
            std::cout << v[i] << ", ";
        }
        std::cout << v[v.size()-1] << " }" << std::endl;
    }
}

//necesitamos tres estados: confiable, no confiable, y no sabe no contesta, 1, -1 y 0 (enumerate...)
void confiablesAux(/*std::vector< std::vector<int> > votos,*/ std::vector<int>& agentes, std::vector<int>& elegidos){

    if(agentes.size() == 0){
        imprimirVector(elegidos);
    } else {

            int actual = agentes[0];
            agentes.erase(agentes.begin());

            elegidos.push_back(actual);
            confiablesAux(agentes, elegidos);

            if(elegidos.size() != 0){elegidos.pop_back();}
            confiablesAux(agentes, elegidos);

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