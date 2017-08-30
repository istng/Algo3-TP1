#!/bin/bash

for i in {1..100..1}
  do 
     python3 ./tests/corredorAgentes5.py > "./resultados/agentesVariados$i.csv"
     python3 ./tests/corredorAgentes6.py > "./resultados/agentesVariados$i.csv"
     python3 ./tests/corredorAgentes7.py > "./resultados/agentesVariados$i.csv"
     python3 ./tests/corredorAgentes8.py > "./resultados/agentesVariados$i.csv"
     python3 ./tests/corredorAgentes9.py > "./resultados/agentesVariados$i.csv"
     python3 ./tests/corredorAgentes10.py > "./resultados/agentesVariados$i.csv"
     python3 ./tests/corredorVotos.py > "./resultados/votosVariados$i.csv"
 done