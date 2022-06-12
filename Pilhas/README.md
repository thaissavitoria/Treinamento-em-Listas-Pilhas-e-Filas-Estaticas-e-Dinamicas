<div style="display: inline-block;">
<img src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white"/> 
<img src="https://img.shields.io/badge/Visual_Studio_Code-0078D4?style=for-the-badge&logo=visual%20studio%20code&logoColor=white"/> 
<img src="https://img.shields.io/badge/Ubuntu-E95420?style=for-the-badge&logo=ubuntu&logoColor=white"/> 
</a> 
</div>

<h4><i>Todos os problemas propostos foram feitos utilizando a estrutura de pilha.</i></h4>

# Pilhas Lineares
<div align="justify">
A pilha possui uma regra básica que deve ser obedecida, essa se refere a forma como inserimos e removemos elementos dessa estrutura. Antes de iniciarmos essa discussão, observe um exemplo ilustrativo desse tipo de dados na figura abaixo.

<div align="center">
	<p> </p>
	<img src="img/pilha.png"/> 
	<p> </p>
</div>

Observe que nesse tipo de estrutura há apenas um <b>único ponteiro</b> chamado <b>Topo</b>. Os métodos associados ao tipo pilha, os quais impõem as regras, são chamados PUSH (i.e., empilhar) e POP (i.e., desempilhar).

>Logo, temos como regra básica dessa estrutura: 
> 1. O último elemento que entra sempre será o primeiro a ser removido. 

Como a pilha é definida a partir de um vetor, muitas das caracteristicas de implementação observadas no tipo lista são aproveitados para compor sua execução. A diferença está apenas na composição da regra de manipulação, o que as diferencia em termos de execução. 
</div>

# Pilhas Dinâmicas 
<p align="justify">
Para o desenvolvimento de um tipo pilha dinâmica, precisamos reservar memória para alocar nossos blocos de dados. Além disso, precisamos criar um bloco chamado "cabeça" para que nossos apontadores possam existir e manipular corretamente as regras da estrutura que estamos tratando.
</p>

<p align="justify">
Na pilha, é preciso definir apontadores para <b>fundo</b> e <b>topo</b> e esses são tratados da mesma forma que os ponteiros primeiro e ultimo de uma lista dinâmica [vide git](https://github.com/mpiress/dynamic_list). Também segue as mesmas regras de inserção e remoção de sua estrutura estática [vide git](https://github.com/mpiress/linear_stack). Vejamos uma representação gráfica da pilha dinâmica e como se comportam os blocos armazenados na memória.
</p>

<p align="center">
	<img src="img/pilha2.png"/> 
</p>

<p align="justify">
Em linhas gerais, a estrutura pilha é muito semelhante a uma lista dinâmica, exceto por inverter a forma como os ponteiros de inicialização são manipulados. Uma vez que, a pilha tem como regra o último que entra é o primeiro a sair, (do inglês, Last In First Out - LIFO), a lógica de manipulação dos ponteiros deve ser modificada para se adaptar a essa regra. Dessa forma,  um novo bloco é inserido utilizando o ponteiro de topo e esse novo bloco apontará para o último já inserido. Note que, ao contrário de fazer o ponteiro de topo (ou último em lista) apontar para o próximo, faz-se o ponteiro de próximo do novo bloco apontar para o topo e só depois atualizaremos o topo para a posição de memória do novo bloco. Vejamos a representação das funções de inicialização (FPVazia), inserção (Push) e remoção (Pop) de uma pilha dinâmica.
</p>

<p align="center">
	<img src="img/funcoes.png"/> 
</p>

# Problemas Propostos
<div align="justify">
É de nosso conhecimento que a estrutura do tipo pilha define regras de manipulação que não podem ser modificadas e que essas são comumente citadas como ações de PUSH (empilhar) e POP (desempilhar). Sabendo-se disso e mediante as regras de desenvolvimento já apresentadas faça:
 <p></p>
<b>a)</b> Escreva uma função que receba uma equação matemática qualquer e retorne duas pilhas. Uma contendo os operandos empilhados da esquerda para a direita e outra contendo os operadores seguindo mesma linha de leitura.
	<p></p>
	
<b>b)</b> Considerando a função elaborada no item (a), crite uma segunda função que apresente a operação matemática em notação prefixa e posfixa. Veja alguns exemplos na tabela abaixo (i.e., Tabela 1.)
  <p></p>
  <div align="center">
  <b>Figure 1: Exemplos de escrita infixa, prefixa e posfixa</b>
  <div>

|   Expressão Infinita   |   Expressão Prefixa   |   Expressão Posfixa   |  
| -----------------------|-----------------------|-----------------------| 
|     A + B * C + D      |    ++ A * B  C  D     |      A B C * + D +    | 
|   (A + B) * (C + D)    |    *+ A  B + C  D     |      A B + C D + *    | 
|     A * B + C * D      |    +* A  B * C  D     |      A B * C D * +    | 
|     A + B + C + D      |    +++ A  B  C  D     |      A B + C + D +    | 

 </div>
 </div>

<b>c)</b> Elabore uma função que receba uma pilha P1 com 20 posições preenchidas por números inteiros aleatórios entre 1 e 99. Para cada número da pilha, utilize a função totiente de Euler para encontrar para esse número os co-primos. Mostre-os na tela como resultado de sua execução.
  <p></p>
<b>d)</b> Crie uma função para realizar o calculo de fibonacci para um valor de N. Contudo, utilize uma pilha para armazenar os pré resultados, utilizando-os para outros calculos sempre que possível. Para tanto, considere manter no topo da pilha o cálculo para o valor de (n-1). Crie uma forma de identificar para qual n-1 o valor foi cálculado para não utilizar valores incorretos para calculos longos. Feito isso responda: Manter os cálculos em pilha pode ajudar a economizar computações? Quando seria melhor empregado?
</div>

# Algoritmo
1) No começo do programa, são criadas duas pilhas dinâmicas que serão usadas nos problemas c e d.
2) Depois, entramos em um looping que contem o seguinte menu (1-Recebe uma equção matemática e retorna duas pilhas, uma com os operadores e outra com os operandos.,2-Apresenta um equação matemática em notação prefixa e posfixa,3-Mostra primos entre si de cada valor de uma pilha aleatoriamente preenchida com valores de 0 a 99,4-Fibonacci usando pilha,0-Sair)    

- Caso opcao=1:
  - Neste problema a estrutura utlizada foi uma pilha linear por ser mais fácil de implementar e porque o problema não necessitava de grandes implementações mais complexas como alocação de memória.
  - A resolução consistiu em receber uma função matemática qualquer do usuário e empilhar cada termo (seja ele um número ou um operador matemático) em pilhas de seus respectivos tipos. A primeira pilha para operandos e a segunda para operadores, de modo que a ordem mostrada para o usuário é a mesma que ele a digitou.
<p align="center">
	<img src="img/Screenshot_1.png"/> 
</p>

- Caso opcao=3:
  - A função *PreencheP(&p1)* é chamada, nela, a pilha dinâmica 1 é preenchida por valores alatórios de 0 a 99, até que atinja seu tamanho máximo,ou seja,20 posições; 
  - A pilha é imprimida;
  - A função *AplicaTotientePilha(&p1)* é chamada, nela, para cada valor da pilha, é calculado quantos primos entre si ele tem e imprime eles;
  - Sai do case;
- Caso opcao=4:
  - Pede-se para que o usuário digitar um número incial do qual deseja saber o Fibonacci; 
  - Calcula-se e imprime-se o Fibonnaci desse número por meio da função *Fibonacci(num,&p2)*,nessa função, usando a própria estrutura pilha dinaâmica e suas funções de POP e PUSH, é calculado a sequência desse número;
  - Pergunta ao usuário se deseja saber o Fibonacci de outro número, se sim, ele digita 1, se não,0.   
    - Caso opcao=1:
      - Entra novamente na função *Fibonacci(num,&p2)* e compara-se se o número digitado é maior ou menor que o outro calculado:
        - Se é menor,busca na Pilha o valor do Fibonacci dele, se maior, calcula-se seu Fibonacci partindo do ponto onde o último parou;         
    - Caso opcao=0:
      - Sai do loop e do case;    
- Caso opcao=0:
  - Sai do programa e exibe-se uma mensagem de agradecimento; 

## Perguntas:

<div align="justify">
d)
<dl>
	<dt>Manter os cálculos em pilha pode ajudar a economizar computações?</dt>
	<dd> Sim!Calculado o Fibonacci de um valor inicial n, se depois for necessário calcular o valor de um outro valor a pilha seria aproveitada, poupando assim a necessidade de fazer os cáculos desde o início novamente. Sendo que, para valores menores que n, basta achar na pilha o Fibonacci correspondente e, para valores maiores que n, basta continuar o calculo a partir do Fibonacci de n.</dd>
	<dt>Quando seria melhor empregado?</dt>
	<dd> Em uma situação em que todos os Fibonaccis a serem calculados fossem menor do que n, assim, o algoritmo precisaria realizar o Fibonacci apenas uma vez e depois só teria que encontrar o restante dos Fibonaccis na pilha.</dd>	
</dl>
</div>


# Compilação e Execução

O algoritmo de pilhas disponibilizado possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:

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
