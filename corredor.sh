#!/bin/bash

python3 ./tests/corredorAgentes.py > setAgentes
python3 ./tests/corredorVotos.py > setVotos
python3 ./tests/corredorCeros.py > setCeros

for i in {1..100..1}
	do 
		echo variando agentes con podas en $i
		./agentes 1 1 < setAgentes > "./resultados/agentesVariados_conPodas/$i.csv"
done

for i in {1..100..1}
	do
		echo variando agentes sin podas en $i
		./agentes 0 1 < setAgentes > "./resultados/agentesVariados_sinPodas/$i.csv"
done

for i in {1..100..1}
	do
		echo variando votos en $i con podas
		./agentes 1 1 < setVotos > "./resultados/votosVariados_conPodas/$i.csv"
done


for i in {1..100..1}
	do
		echo variando votos en $i con poda max
		./agentes 2 1 < setVotos > "./resultados/votosVariados_conPodaMax/$i.csv"
done


for i in {1..100..1}
	do
		echo variando ceros en $i sin podas
		./agentes 0 1 < setCeros > "./resultados/cerosVariados_sinPodas/$i.csv"
done

for i in {1..100..1}
	do 
		echo variando agentes en $i con poda max
		./agentes 2 1 < setAgentes > "./resultados/agentesVariados_conPodaMax/$i.csv"
done

for i in {1..100..1}
	do
		echo variando agentes en $i con poda futuro
		./agentes 3 1 < setAgentes > "./resultados/agentesVariados_conPodaFuturo/$i.csv"
done

for i in {1..100..1}
	do
		echo variando ceros en $i con podas
		./agentes 1 1 < setCeros > "./resultados/cerosVariados_conPodas/$i.csv"
done

for i in {1..100..1}
	do
		echo variando votos en $i con poda futuro
		./agentes 3 1 < setVotos > "./resultados/votosVariados_conPodaFuturo/$i.csv"
done

for i in {1..100..1}
	do
		echo variando votos en $i sin podas
		./agentes 0 1 < setVotos > "./resultados/votosVariados_sinPodas/$i.csv"
done

for i in {1..100..1}
	do 
		echo variando ceros en $i con poda futuro
		./agentes 3 1 < setCeros > "./resultados/cerosVariados_conPodaFuturo/$i.csv"
done