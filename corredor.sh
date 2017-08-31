#!/bin/bash

for i in {1..100..1}
	do 
		echo variando agentes con podas en $i
		python3 ./tests/corredorAgentes.py | ./agentes 1 > "./resultados/agentesVariados_conPodas/$i.csv"
done

for i in {1..100..1}
	do
		echo variando agentes sin podas en $i
		python3 ./tests/corredorAgentes.py | ./agentes 0 > "./resultados/agentesVariados_sinPodas/$i.csv"
done