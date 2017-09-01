#include "podas.cpp"
#include <chrono>

#define now std::chrono::high_resolution_clock::now



int main(int argc, char** argv){

    if (!(argc == 3 || argc == 2 || argc == 1)){
        std::cout << std::endl << "Error en los parametros de entrada. Los parametros correctos son:" << std::endl;
        std::cout << std::endl << "./agentes <activar podas> <salida detallada>" << std::endl;
        std::cout << std::endl << "Activar podas: 1 para activarlas, 0 para desactivarlas." << std::endl;
        std::cout << "2 para poda pasoElMaximo, 3 para poda aFuturo.";
        std::cout << "Si no se aclara, por defecto será 1." << std::endl;
        std::cout << std::endl;
        std::cout << "Salida detallada: 1 para activarlo, 0 para desactivarlo." << std::endl;
        std::cout << "Si no se aclara, por defecto será 0." << std::endl;
        std::cout << std::endl;
        return -1;
    }
    
    int poda = 1;
    if(argc > 1){poda = std::atoi(argv[1]);}
    int detalles = 0;
    if(argc > 2){detalles = std::atoi(argv[2]);}


    //parseo los datos pasados
    std::vector<std::vector<std::vector<int> > > setDatos;
    std::vector<int> votosPorSet;
    entradaManual(setDatos, votosPorSet);

    if(detalles == 1){std::cout << "tam,tiempo,agentes,votos" << std::endl;}

    for (int i = 0; i < setDatos.size(); ++i){
        //creamos restantes, elegidos y finalistas
        std::vector<int> restantes;
        for (int j = 0; j < setDatos[i].size(); ++j){restantes.push_back(j);}
        std::vector<int> elegidos;        
        std::vector<std::vector<int > > finalistas;        

        //inicializo las variables para medir el tiempo
        std::chrono::high_resolution_clock::time_point t1;
        std::chrono::high_resolution_clock::time_point t2;
        std::chrono::duration<double> time_span;
       

        if(poda == 0){
            
            t1 = now();
            finalistas = confiablesSinPodas(setDatos[i], restantes, elegidos);
            t2 = now();
            
            time_span = std::chrono::duration_cast<std::chrono::duration<double> >(t2-t1);
            
            if(detalles == 1){std::cout << "," << time_span.count() << "," << setDatos[i].size() << "," << votosPorSet[i] << std::endl;}
            else{std::cout << std::endl;}

        } else if(poda == 1) {
            t1 = now();
            finalistas = confiablesConPodas(setDatos[i], restantes, elegidos);
            t2 = now();
            
            time_span = std::chrono::duration_cast<std::chrono::duration<double> >(t2-t1);
            
            if(detalles == 1){std::cout << "," << time_span.count() << "," << setDatos[i].size() << "," << votosPorSet[i] << std::endl;}
            else{std::cout << std::endl;}

        } else if(poda == 2) {
            
            t1 = now();
            finalistas = confiablesConPodaMax(setDatos[i], restantes, elegidos);
            t2 = now();
            
            time_span = std::chrono::duration_cast<std::chrono::duration<double> >(t2-t1);
            
            if(detalles == 1){std::cout << "," << time_span.count() << "," << setDatos[i].size() << "," << votosPorSet[i] << std::endl;}
            else{std::cout << std::endl;}

        } else if(poda == 3) {
            t1 = now();
            finalistas = confiablesConPodaFuturo(setDatos[i], restantes, elegidos);
            t2 = now();
            
            time_span = std::chrono::duration_cast<std::chrono::duration<double> >(t2-t1);

            if(detalles == 1){std::cout << "," << time_span.count() << "," << setDatos[i].size() << "," << votosPorSet[i] << std::endl;}
            else{std::cout << std::endl;}

        }

        //esto lo usé sólo para imprimir los conjuntos resultantes y chequear consistencia, debugear, y armar ejemplos
        //normalizar(finalistas);

    }


    return 0;
}