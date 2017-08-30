#!/bin/bash

for i in {1..100..1}
	do 
		python3 ./tests/corredorAgentes5.py | ./agentes 0 #> "./resultados/agentesVariados$i.csv"
		python3 ./tests/corredorAgentes5.py | ./agentes 1 #> "./resultados/agentesVariados$i.csv"
		python3 ./tests/corredorAgentes6.py | ./agentes 0 #> "./resultados/agentesVariados$i.csv"
		python3 ./tests/corredorAgentes6.py | ./agentes 1 #> "./resultados/agentesVariados$i.csv"
		python3 ./tests/corredorAgentes7.py | ./agentes 0 #> "./resultados/agentesVariados$i.csv"
		python3 ./tests/corredorAgentes7.py | ./agentes 1 #> "./resultados/agentesVariados$i.csv"
		python3 ./tests/corredorAgentes8.py | ./agentes 0 #> "./resultados/agentesVariados$i.csv"
		python3 ./tests/corredorAgentes8.py | ./agentes 1 #> "./resultados/agentesVariados$i.csv"
		python3 ./tests/corredorAgentes9.py | ./agentes 0 #> "./resultados/agentesVariados$i.csv"
		python3 ./tests/corredorAgentes9.py | ./agentes 1 #> "./resultados/agentesVariados$i.csv"
		python3 ./tests/corredorAgentes10.py | ./agentes 0 #> "./resultados/agentesVariados$i.csv"
		python3 ./tests/corredorAgentes10.py | ./agentes 1 #> "./resultados/agentesVariados$i.csv"
		python3 ./tests/corredorVotos.py | ./agentes 0 #> "./resultados/votosVariados$i.csv"
		python3 ./tests/corredorVotos.py | ./agentes 1 #> "./resultados/votosVariados$i.csv"
done