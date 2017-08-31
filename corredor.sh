#!/bin/bash

for i in {1..100..1}
	do 
		echo comenzo el $i
		python3 ./tests/corredorAgentes.py | ./agentes 1 > "./resultados/agentesVariados_conPodas/$i.csv"
		python3 ./tests/corredorVotos.py | ./agentes 1 > "./resultados/votosVariados_conPodas/$i.csv"
		python3 ./tests/corredorVotos.py | ./agentes 0 > "./resultados/votosVariados_sinPodas/$i.csv"
		python3 ./tests/corredorAgentes.py | ./agentes 0 > "./resultados/agentesVariados_sinPodas/$i.csv"
done