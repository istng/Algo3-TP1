#!/bin/bash

#for i in {1..100..1}
#	do 
#		echo variando agentes con podas en $i
#		python3 ./tests/corredorAgentes.py | ./agentes 1 > "./resultados/agentesVariados_conPodas/$i.csv"
#done
#
#for i in {1..100..1}
#	do
#		echo variando agentes sin podas en $i
#		python3 ./tests/corredorAgentes.py | ./agentes 0 > "./resultados/agentesVariados_sinPodas/$i.csv"
#done

for i in {1..100..1}
	do
		echo variando votos en $i con podas
		python3 ./tests/corredorVotos.py | ./agentes 1 > "./resultados/votosVariados_conPodas/$i.csv"
done


for i in {1..100..1}
	do
		echo variando votos en $i con poda max
		python3 ./tests/corredorVotos.py | ./agentes 2 > "./resultados/votosVariados_conPodaMax/$i.csv"
done


for i in {1..100..1}
	do
		echo variando ceros en $i sin podas
		python3 ./tests/corredorCeros.py | ./agentes 0 > "./resultados/cerosVariados_sinPodas/$i.csv"
done

for i in {1..100..1}
	do 
		echo variando agentes en $i con poda max
		python3 ./tests/corredorAgentes.py | ./agentes 2 > "./resultados/agentesVariados_conPodaMax/$i.csv"
done

for i in {1..100..1}
	do
		echo variando agentes en $i con poda futuro
		python3 ./tests/corredorAgentes.py | ./agentes 3 > "./resultados/agentesVariados_conPodaFuturo/$i.csv"
done

for i in {1..100..1}
	do
		echo variando ceros en $i con podas
		python3 ./tests/corredorCeros.py | ./agentes 1 > "./resultados/cerosVariados_conPodas/$i.csv"
done

for i in {1..100..1}
	do
		echo variando votos en $i con poda futuro
		python3 ./tests/corredorVotos.py | ./agentes 3 > "./resultados/votosVariados_conPodaFuturo/$i.csv"
done

for i in {1..100..1}
	do
		echo variando votos en $i sin podas
		python3 ./tests/corredorVotos.py | ./agentes 0 > "./resultados/votosVariados_sinPodas/$i.csv"
done