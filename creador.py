#!/usr/bin/python

import random

cantidadAgentes = 10
cantidadVotos = 5
votosPosibles = []

for i in range(1,cantidadAgentes+1):
	for j in range(1,cantidadAgentes+1):
		votosPosibles.append(((i,j),(i,-j)))


for i in range(1,cantidadVotos+1):
    secure_random_votos = random.SystemRandom()
    votos = secure_random_votos.choice(votosPosibles)

    secure_random_voto = random.SystemRandom()
    voto = secure_random_voto.choice(votos)

    votosPosibles.remove(votos)

    print(voto)