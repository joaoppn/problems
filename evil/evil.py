# Função para calcular o número de regiões a partir do número de linhas
def calcular_regioes(n):
    return n * (n + 1) // 2 + 1

# Leitura do número de instâncias
t = int(input())

# Loop para cada instância
for _ in range(t):
    n = int(input())  # Leitura do número de linhas na instância
    regioes = calcular_regioes(n)  # Cálculo do número de regiões
    print(regioes)  # Impressão do resultado
