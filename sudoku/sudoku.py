import copy


def linhas_check(aux):
    for i in range(9):
        aux[i].sort()
        if(aux[i] == [1,2,3,4,5,6,7,8,9]):
            continue
        else:
            #print(f"deu ruim na linha{i} - > {matriz[i]}")
            return False
    return True

def col_check(aux):
    col=[]
    for i in range(9):
        for j in range(9):
            col.append(aux[j][i])
        #print(f"coluna antes: {col}\n")
        col.sort()
        if(col == [1,2,3,4,5,6,7,8,9]):
        #    print(f"deu certo col -> {col}")
            col = []
        else:
                #print(f"deu ruim na coluna{i} -> {col}")
            return False 
    return True

def blocks_check(matriz):
    min_matriz =[]
    for j in range(3):
        for k in range(3):
            for x in range(3):
                for y in range(3):
                    x_ = x+(j*3)
                    y_ = y+(k*3)
                    #print(f"\n x = {x_}")
                    #print(f"\n y = {y_}")
                    min_matriz.append(matriz[x_][y_])   
            min_matriz.sort()
            if(min_matriz == [1, 2, 3, 4, 5, 6, 7, 8, 9]):
                min_matriz = []
            else:
                #print(min_matriz)
                #print(f"deu ruim no bloco{j*3 + k}")
                return False
    return True

qnt  = input()
for l in range(int(qnt)):
    matriz = []
    i = 0
    for i in range(9):
        linha = input()
        sub_matriz = []
        for num in linha.replace(" ",""):
            sub_matriz.append(int(num))
        matriz.append(sub_matriz)
    aux = copy.deepcopy(matriz) 
    aux_2 = copy.deepcopy(matriz)
    
    
    if(linhas_check(aux) and col_check(aux_2) and blocks_check(matriz)):
        print(f"Instancia {l+1}")
        print("SIM\n")
        #print (f"Essa é a matriz: {matriz}\n")
    else:
        print(f"Instancia {l+1}")
        print("NAO\n")
        #print (f"Essa é a matriz: {matriz}\n")