<div style="display: inline-block;">
<img src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white"/> 
<img src="https://img.shields.io/badge/Visual_Studio_Code-0078D4?style=for-the-badge&logo=visual%20studio%20code&logoColor=white"/> 
<img src="https://img.shields.io/badge/Ubuntu-E95420?style=for-the-badge&logo=ubuntu&logoColor=white"/> 
</a> 
</div>

# Problema Proposto

<p>Uma estrutura baseada em fila tem por definição a regra de sempre remover do início e inserir
novos elementos no final. Sabendo-se disso, vamos praticar a utilização desse conceito nos
seguintes problemas:</p>

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; a) Escreva uma função que receba pares de filas, ambas de tanho n, divida ambas ao meio
e ligue as metadas para compor duas novas filas, as quais devem ser retornadas para o
usuário. Tais filas devem ser definidas como dinâmicas. 

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; b) Escreva uma função que aplica uma equação matemática qualquer aos n  ̃umeros de uma
fila. Essa equação tem por objetivo produzir um indexador para a fila dada como entrada,
logo, precisa ser retornado junto com a fila para o usuário.

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; c) Elabore uma função que receba um conjunto de filas, todas com valores de indexação
conforme item (b). Ordene esse grupo de filas pelo método da bolha e as retorne ao
usuário considerando o maior valor de indexação como cabeça dessa ordem.


## A Estrutura Fila Dinâmica

<div align="justify">
 Na estrutura fila dinâmica, lidamos com ponteiros, criamos blocos em memória, tratamos do acesso e navegação utilizando o ponteiro próximo ( prox ) e, com isso, definimos e manipulamos os ponteiros frente e fundo sob um modelo circular, como na imagem abaixo. 

<div align="center">
 <p> </p>
 <img src="img/fila.png" alt=RepresentaçãoFila>
 <p> </p>
</div>

  Para inserções, utilizamos sempre o ponteiro de fundo. Em contra partida, utilizamos o ponteiro de frente para as remoções. Essa característica torna esse modelo de estrutura em um modelo do tipo First In First Out - FIFO. Mesma regra encontrada em sua vertente estática [vide git](https://github.com/mpiress/linear_queue).

 Com relação às estruturas dinâmicas básicas de lista e pilha, há uma diferença sutil de construção que deve ser observado na fila, a ligação do último elemento inserido à "cabeça" da estrutura. Essa modificação fará com que a estrutura se comporte exatamente da mesma forma de sua variante estática,ou seja, de forma circular.
</div>

## Algoritimo

<p> O problema foi desenvolvido da seguinte maneira: </p>

1 - Foi solicitado ao usuário o tamanho da fila.

2 - Um menu aparece na tela, e nele, o usuário tem 3 opções: Inverter metade das filas (exercício 3a), Realizar um cálculo aos valores da fila e ordenar a fila baseado nele (exercício 3b e 3c) e por fim, sair do programa.

3 - Se solicitado para inverter metade das filas e conectá-las, o programa preenche duas fila com valores randômicos X vezes o tamanho da fila recebido como input pelo usuário.

4 - Após as filas estarem completamente preenchidas, a função SwapFilas é chamada, e nela é passada as duas filas e o tamanho delas como parâmetro. A fila é percorrida até a metade e seus valores são permutados, assim conectando metade das listas.

5 - Por fim, ambas as listas permutadas são mostradas na tela e o menu é chamado novamente para o usuário.

6 - Se solicitado para realizar um cálculo aos valores da fila e ordená-la, o programa preenche uma fila com valores randômicos X vezes o tamanho da fila recebido como input pelo usuário.

7 - Após as filas estarem completamente preenchidas, a função MetodoBolhaInterativo é chamada, e nela é passada a fila como parâmeto. O método consiste em comparar o primeiro e o último valor da lista e caso o último valor seja menor, os valores são permutados. Nesse processo, a cada interação, a fila é revisitada para os n - 1 valores restantes, o que faz com que o método seja executado até que se tenha 2 elementos ainda não visitados. 

8 - Por fim, a lista ordenada de forma descrescente é mostrada na tela, e o menu é chamado novamente para o usuário.

# Compilação e Execução

O algoritmo de listas disponibilizado possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:

<div>

| Comando                |  Função                                                                                           |
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |

</div>

# Contatos

<div style="display: inline-block;">
 <p align="justify"> Thaissa Vitória</p>
<a href="https://t.me/thaissadaldegan">
<img align="center" src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/> 
</a>

<a href="https://www.linkedin.com/in/thaissa-vitoria-daldegan-6a84b9153/">
<img align="center" src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white"/>
</a>

</div>


<div style="display: inline-block;">
 <p align="justify">Bárbara Gualberto</p>
<a href="https://t.me/barbrinas">
<img align="center" src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/> 
</a>

<a href="https://www.linkedin.com/in/barbara-gualberto/">
<img align="center" src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white"/>
</a>

</div>


 <div>
<p align="justify"> Gabriel Couto</p>
<a href="https://t.me/Couto1411">
<img align="center" src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/> 

<a href="https://www.linkedin.com/in/gabriel-couto-582060200">
<img align="center" src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white"/>
</a>
</div>
  
  <div>
<p align="justify"> Pablo Sousa</p>
<a href="https://t.me/Pabloss_07">
<img align="center" src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/> 

<a href="https://www.linkedin.com/in/pablo-silva-734b22202">
<img align="center" src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white"/>
</a>
</div>
