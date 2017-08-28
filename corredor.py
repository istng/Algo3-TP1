import subprocess

process = subprocess.Popen('./agentes', stdin=subprocess.PIPE)
process.stdin.write('4\n5\n1\n2\n1\n-4\n2\n-3\n3\n1\n3\n4')
process.communicate()