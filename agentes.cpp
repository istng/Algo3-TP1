#include <iostream>
#include <vector>
//#include "auxiliares.h"


/*void confiables(){

}*/

//necesitamos tres estados: confiable, no confiable, y no sabe no contesta, 1, -1 y 0 (enumerate...)
void confiablesAux(/*std::vector< std::vector<int> > votos,*/ std::vector<int>& agentes, std::vector<int>& elegidos){

    if(agentes.size() == 0){
        std::cout << "{ ";
        for (int i = 0; i < elegidos.size()-1; ++i){
            std::cout << elegidos[i] << ", ";
        }
        std::cout << elegidos[elegidos.size()-1] << " }" << std::endl;
    
    } else {

            int actual = agentes[0];
            agentes.erase(agentes.begin());

            elegidos.push_back(actual);
            confiablesAux(agentes, elegidos);

            elegidos.pop_back();
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