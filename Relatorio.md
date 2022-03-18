# Algoritmo de Smith Waterman
O algoritmo tem a finalidade de fazer alinhamento local de duas sequências de DNA. Ele utiliza como entrada as duas sequências e o tamanho delas. Sua saída é um arquivo .txt contendo a matriz com os valores, o maior valor encontrado e ambas as sequências alinhadas. 
A abordagem procura encontrar subsequências que maximizam os valores de pareamento. Para calcular a matriz de valores e obter o valor máximo, segue-se o seguinte algoritimo:

1. Inicializar H[i,0]=0, 0≤i≤n
2. Inicializar H[0,j]=0, 0≤j≤m
3. Para cada 1≤i≤n e 1≤j≤m:
4.     Calcular diagonal = H[i-1,j-1] + w(a[i],b[j]), onde w(a[i],b[j])=2 se houve match, 
                           w(a[i],b[j])= -1 se houve mismatch e  
                           w(a[i],b[j])= -1 se houve gap
5.     Calcular deleção  = H[i-1,j] - 1
6.     Calcular inserção = H[i,j-1] - 1
7.     Calcular H[i,j]=máximo (0, diagonal, deleção, inserção)
9. Retornar o máximo de H

Durante o calculo do máximo entre diagonal, deleção e inserção no passo 7, a origem do valor é guardada no H[i,j], ou seja, caso o máximo seja o da diagonal, então a origem guardada é um código referente a diagonal, caso seja de deleção, um código referente a deleção e caso seja de inserção, um código referente a inserção. Para obter as sequências alinhadas pode-se utilizar essas origens dos valores para gerar a sequência da frente para trás e invertê-la no final. 
