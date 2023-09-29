


nome = input()
atual = input()
born = input()

born_dia = int(born.split("/")[0])
atual_dia = int(atual.split("/")[0])

born_mes = int(born.split("/")[1])
atual_mes = int(atual.split("/")[1])

born_ano = int(born.split("/")[2])
atual_ano = int(atual.split("/")[2])

if(born_dia == atual_dia and born_mes == atual_mes):
    print("Feliz aniversario!")
    print(f"Voce tem {atual_ano - born_ano} anos {nome}.")

elif(atual_mes > born_mes):
    print(f"Voce tem {atual_ano - born_ano} anos {nome}.")

elif(atual_mes == born_mes):
    if(born_dia>atual_dia):
        print(f"Voce tem {atual_ano - born_ano-1} anos {nome}.")
    else:
        print(f"Voce tem {atual_ano - born_ano} anos {nome}.")
else:
    print(f"Voce tem {atual_ano - born_ano-1} anos {nome}.")

