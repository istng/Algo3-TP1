#!/bin/bash

for i in {1..10..1}
	do 
		echo variando agentes con podas en $i
		python3 ./tests/corredorAgentes.py | ./agentes 1 > "./resultados/agentesVariados_conPodas/$i.csv"
		echo variando votos con podas en $i
		python3 ./tests/corredorVotos.py | ./agentes 1 > "./resultados/votosVariados_conPodas/$i.csv"
		echo variando agentes sin podas en $i
		python3 ./tests/corredorVotos.py | ./agentes 0 > "./resultados/votosVariados_sinPodas/$i.csv"
		echo variando votos sin podas en $i
		python3 ./tests/corredorAgentes.py | ./agentes 0 > "./resultados/agentesVariados_sinPodas/$i.csv"
done

for i in {11..20..1}
	do 
		echo variando agentes con podas en $i
		python3 ./tests/corredorAgentes.py | ./agentes 1 > "./resultados/agentesVariados_conPodas/$i.csv"
		echo variando votos con podas en $i
		python3 ./tests/corredorVotos.py | ./agentes 1 > "./resultados/votosVariados_conPodas/$i.csv"
		echo variando agentes sin podas en $i
		python3 ./tests/corredorVotos.py | ./agentes 0 > "./resultados/votosVariados_sinPodas/$i.csv"
		echo variando votos sin podas en $i
		python3 ./tests/corredorAgentes.py | ./agentes 0 > "./resultados/agentesVariados_sinPodas/$i.csv"
done

for i in {21..30..1}
	do 
		echo variando agentes con podas en $i
		python3 ./tests/corredorAgentes.py | ./agentes 1 > "./resultados/agentesVariados_conPodas/$i.csv"
		echo variando votos con podas en $i
		python3 ./tests/corredorVotos.py | ./agentes 1 > "./resultados/votosVariados_conPodas/$i.csv"
		echo variando agentes sin podas en $i
		python3 ./tests/corredorVotos.py | ./agentes 0 > "./resultados/votosVariados_sinPodas/$i.csv"
		echo variando votos sin podas en $i
		python3 ./tests/corredorAgentes.py | ./agentes 0 > "./resultados/agentesVariados_sinPodas/$i.csv"
done

for i in {31..40..1}
	do 
		echo variando agentes con podas en $i
		python3 ./tests/corredorAgentes.py | ./agentes 1 > "./resultados/agentesVariados_conPodas/$i.csv"
		echo variando votos con podas en $i
		python3 ./tests/corredorVotos.py | ./agentes 1 > "./resultados/votosVariados_conPodas/$i.csv"
		echo variando agentes sin podas en $i
		python3 ./tests/corredorVotos.py | ./agentes 0 > "./resultados/votosVariados_sinPodas/$i.csv"
		echo variando votos sin podas en $i
		python3 ./tests/corredorAgentes.py | ./agentes 0 > "./resultados/agentesVariados_sinPodas/$i.csv"
done

for i in {41..50..1}
	do 
		echo variando agentes con podas en $i
		python3 ./tests/corredorAgentes.py | ./agentes 1 > "./resultados/agentesVariados_conPodas/$i.csv"
		echo variando votos con podas en $i
		python3 ./tests/corredorVotos.py | ./agentes 1 > "./resultados/votosVariados_conPodas/$i.csv"
		echo variando agentes sin podas en $i
		python3 ./tests/corredorVotos.py | ./agentes 0 > "./resultados/votosVariados_sinPodas/$i.csv"
		echo variando votos sin podas en $i
		python3 ./tests/corredorAgentes.py | ./agentes 0 > "./resultados/agentesVariados_sinPodas/$i.csv"
done