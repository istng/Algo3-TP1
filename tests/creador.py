#!/usr/bin/python

import random


def encuesta(cantidadAgentes, cantidadVotos):
    votosPosibles = []
    for i in range(1,cantidadAgentes+1):
    	for j in range(1,cantidadAgentes+1):
            votosPosibles.append((i,j))
            votosPosibles.append((i,-j))

    print(str(cantidadAgentes) + " " + str(cantidadVotos))
    
    for i in range(1,cantidadVotos+1):
        if(votosPosibles == []):
            break
        secure_random = random.SystemRandom()
        voto = secure_random.choice(votosPosibles)

        votosPosibles.remove(voto)
    
        print(str(voto[0]) + " " + str(voto[1]))


def variarAgentes(cantidadAgentes, cantidadVotos):
    for i in range(cantidadVotos, cantidadAgentes+1):
        encuesta(i, cantidadVotos)
    print("0 0")

def variarVotos(cantidadAgentes, cantidadVotos):
    for i in range(1, cantidadVotos+1):
        encuesta(cantidadAgentes, i)
    print("0 0")

def selector(tipo, cantidadAgentes, cantidadVotos):
    if(tipo == 1):
        variarAgentes(cantidadAgentes, cantidadVotos)
    elif(tipo == 0):
        variarVotos(cantidadAgentes, cantidadVotos)


if __name__ == '__main__':
    selector()