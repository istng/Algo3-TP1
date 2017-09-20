#!/bin/bash

#python3 ./tests/corredorAgentes.py > setAgentes
#python3 ./tests/corredorVotos.py > setVotos
#python3 ./tests/corredorCeros.py > setCeros

for i in {1..50..1}
	do 
		echo variando agentes con podas en $i
		./agentes 1 1 < setAgentes2 > "./resultados/agentesVariados_conPodas/"$i+100".csv"
		./agentes 1 1 < setAgentes3 > "./resultados/agentesVariados_conPodas/"$i+200".csv"
		./agentes 1 1 < setAgentes4 > "./resultados/agentesVariados_conPodas/"$i+300".csv"
		./agentes 1 1 < setAgentes5 > "./resultados/agentesVariados_conPodas/"$i+400".csv"
done

for i in {1..50..1}
	do
		echo variando agentes sin podas en $i
		./agentes 0 1 < setAgentes2 > "./resultados/agentesVariados_sinPodas/"$i+100".csv"
		./agentes 0 1 < setAgentes3 > "./resultados/agentesVariados_sinPodas/"$i+200".csv"
		./agentes 0 1 < setAgentes4 > "./resultados/agentesVariados_sinPodas/"$i+300".csv"
		./agentes 0 1 < setAgentes5 > "./resultados/agentesVariados_sinPodas/"$i+400".csv"
done

for i in {1..50..1}
	do
		echo variando votos en $i con podas
		./agentes 1 1 < setVotos2 > "./resultados/votosVariados_conPodas/"$i+100".csv"
		./agentes 1 1 < setVotos3 > "./resultados/votosVariados_conPodas/"$i+200".csv"
		./agentes 1 1 < setVotos4 > "./resultados/votosVariados_conPodas/"$i+300".csv"
		./agentes 1 1 < setVotos5 > "./resultados/votosVariados_conPodas/"$i+400".csv"
done


for i in {1..50..1}
	do
		echo variando votos en $i con poda max
		./agentes 2 1 < setVotos2 > "./resultados/votosVariados_conPodaMax/"$i+100".csv"
		./agentes 2 1 < setVotos3 > "./resultados/votosVariados_conPodaMax/"$i+200".csv"
		./agentes 2 1 < setVotos4 > "./resultados/votosVariados_conPodaMax/"$i+300".csv"
		./agentes 2 1 < setVotos5 > "./resultados/votosVariados_conPodaMax/"$i+400".csv"
done


for i in {1..50..1}
	do
		echo variando ceros en $i sin podas
		./agentes 0 1 < setCeros2 > "./resultados/cerosVariados_sinPodas/"$i+100".csv"
		./agentes 0 1 < setCeros3 > "./resultados/cerosVariados_sinPodas/"$i+200".csv"
		./agentes 0 1 < setCeros4 > "./resultados/cerosVariados_sinPodas/"$i+300".csv"
		./agentes 0 1 < setCeros5 > "./resultados/cerosVariados_sinPodas/"$i+400".csv"
done

for i in {1..50..1}
	do 
		echo variando agentes en $i con poda max
		./agentes 2 1 < setAgentes2 > "./resultados/agentesVariados_conPodaMax/"$i+100".csv"
		./agentes 2 1 < setAgentes3 > "./resultados/agentesVariados_conPodaMax/"$i+200".csv"
		./agentes 2 1 < setAgentes4 > "./resultados/agentesVariados_conPodaMax/"$i+300".csv"
		./agentes 2 1 < setAgentes5 > "./resultados/agentesVariados_conPodaMax/"$i+400".csv"
done

for i in {1..50..1}
	do
		echo variando agentes en $i con poda futuro
		./agentes 3 1 < setAgentes2 > "./resultados/agentesVariados_conPodaFuturo/"$i+100".csv"
		./agentes 3 1 < setAgentes3 > "./resultados/agentesVariados_conPodaFuturo/"$i+200".csv"
		./agentes 3 1 < setAgentes4 > "./resultados/agentesVariados_conPodaFuturo/"$i+300".csv"
		./agentes 3 1 < setAgentes5 > "./resultados/agentesVariados_conPodaFuturo/"$i+400".csv"
done

for i in {1..50..1}
	do
		echo variando ceros en $i con podas
		./agentes 1 1 < setCeros2 > "./resultados/cerosVariados_conPodas/"$i+100".csv"
		./agentes 1 1 < setCeros3 > "./resultados/cerosVariados_conPodas/"$i+200".csv"
		./agentes 1 1 < setCeros4 > "./resultados/cerosVariados_conPodas/"$i+300".csv"
		./agentes 1 1 < setCeros5 > "./resultados/cerosVariados_conPodas/"$i+400".csv"
done

for i in {1..50..1}
	do
		echo variando votos en $i con poda futuro
		./agentes 3 1 < setVotos2 > "./resultados/votosVariados_conPodaFuturo/"$i+100".csv"
		./agentes 3 1 < setVotos3 > "./resultados/votosVariados_conPodaFuturo/"$i+200".csv"
		./agentes 3 1 < setVotos4 > "./resultados/votosVariados_conPodaFuturo/"$i+300".csv"
		./agentes 3 1 < setVotos5 > "./resultados/votosVariados_conPodaFuturo/"$i+400".csv"
done

for i in {1..50..1}
	do
		echo variando votos en $i sin podas
		./agentes 0 1 < setVotos2 > "./resultados/votosVariados_sinPodas/"$i+100".csv"
		./agentes 0 1 < setVotos3 > "./resultados/votosVariados_sinPodas/"$i+200".csv"
		./agentes 0 1 < setVotos4 > "./resultados/votosVariados_sinPodas/"$i+300".csv"
		./agentes 0 1 < setVotos5 > "./resultados/votosVariados_sinPodas/"$i+400".csv"
done

for i in {1..50..1}
	do 
		echo variando ceros en $i con poda futuro
		./agentes 3 1 < setCeros2 > "./resultados/cerosVariados_conPodaFuturo/"$i+100".csv"
		./agentes 3 1 < setCeros3 > "./resultados/cerosVariados_conPodaFuturo/"$i+200".csv"
		./agentes 3 1 < setCeros4 > "./resultados/cerosVariados_conPodaFuturo/"$i+300".csv"
		./agentes 3 1 < setCeros5 > "./resultados/cerosVariados_conPodaFuturo/"$i+400".csv"
done