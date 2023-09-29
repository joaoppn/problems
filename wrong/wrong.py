qnt = input()

for i in range(int(qnt)):
    conta = input()
    result = 0
    operacao = conta.split('=')[0]
    operacao = operacao.split(' ')
    if(operacao[1] == '+'):
        result = int(operacao[0]) + int(operacao[2])
    elif(operacao[1] == '-'):
        result = int(operacao[0]) - int(operacao[2])
    elif(operacao[1] == 'x'):
        result = int(operacao[0]) * int(operacao[2])
    elif(operacao[1] == '/'):
        result = int(operacao[0]) / int(operacao[2])
    r = abs(result-int(conta.split('=')[1]))
    print('E'+'r'*r+'ou!')
