#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "auxiliares.cpp"

void imprimirVector(std::vector<int> v);

bool esta(std::vector<int> v, int a);

int modulo(int a);
int signo(int a);


std::vector<std::vector<int > > entradaManual();
std::vector<std::vector<std::vector<int> > > parseador(std::string inputPath);
void agregarAlSet(std::ifstream& input, std::vector<std::vector<std::vector<int> > >& setDatos);