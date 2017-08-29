#include "auxiliares.h"


void partes(std::vector<int>& conjunto, std::vector<int>& parte){

    if(conjunto.size() == 0){
        imprimirVector(parte);
    } else {

            int actual = conjunto[0];
            conjunto.erase(conjunto.begin());

            parte.push_back(actual);
            partes(conjunto, parte);

            if(parte.size() != 0){parte.pop_back();}
            partes(conjunto, parte);

            conjunto.insert(conjunto.begin(), actual);

    }


}

int main(){

    std::vector<int> conjunto;
    for (int i = 0; i < 4; ++i){
        conjunto.push_back(i);
    }

    std::vector<int> parte;

    partes(conjunto, parte);
}