#!/bin/bash

for i in {1..100..1}
	do 
		python3 ./tests/corredorAgentes5.py | ./agentes 0 > "./resultados/agentesVariados5_sinPodas/$i.csv"
		python3 ./tests/corredorAgentes5.py | ./agentes 1 > "./resultados/agentesVariados5_conPodas/$i.csv"
		python3 ./tests/corredorAgentes6.py | ./agentes 0 > "./resultados/agentesVariados6_sinPodas/$i.csv"
		python3 ./tests/corredorAgentes6.py | ./agentes 1 > "./resultados/agentesVariados6_conPodas/$i.csv"
		python3 ./tests/corredorAgentes7.py | ./agentes 0 > "./resultados/agentesVariados7_sinPodas/$i.csv"
		python3 ./tests/corredorAgentes7.py | ./agentes 1 > "./resultados/agentesVariados7_conPodas/$i.csv"
		python3 ./tests/corredorAgentes8.py | ./agentes 0 > "./resultados/agentesVariados8_sinPodas/$i.csv"
		python3 ./tests/corredorAgentes8.py | ./agentes 1 > "./resultados/agentesVariados8_conPodas/$i.csv"
		python3 ./tests/corredorAgentes9.py | ./agentes 0 > "./resultados/agentesVariados9_sinPodas/$i.csv"
		python3 ./tests/corredorAgentes9.py | ./agentes 1 > "./resultados/agentesVariados9_conPodas/$i.csv"
		python3 ./tests/corredorAgentes10.py | ./agentes 0 > "./resultados/agentesVariados10_sinPodas/$i.csv"
		python3 ./tests/corredorAgentes10.py | ./agentes 1 > "./resultados/agentesVariados10_conPodas/$i.csv"
		python3 ./tests/corredorVotos.py | ./agentes 0 > "./resultados/votosVariados_sinPodas/$i.csv"
		python3 ./tests/corredorVotos.py | ./agentes 1 > "./resultados/votosVariados_conPodas/$i.csv"
done