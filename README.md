# INE5645 - PROGRAMAÇÃO PARALELA E DISTRIBUIDA (UFSC)

## pthreads-speedup-efficiency

Este repositório foi criado para solucionar, em linguagem C e individualmente, um problema proposto na disciplina de Programação Paralela e Distribuída, que faz parte do currículo da graduação de Bacharelado em Sistemas de Informação pela Universidade Federal de Santa Catarina (UFSC). 

## Conteúdos

Neste repositório você encontra o software simples, implementado em linguagem C, para observar o paralelismo de threads e seus desempenhos. Este código serviu de substância para a geração de tabela de dados e gráficos que compôs o relatório final para esta atividade. 

## Na prática

Esse é um programa para estimar o 'speedup' e a 'eficiência' das threads trabalhando em cima de uma mesma palavra. Isso é feito ao medir o tempo de execução do programa e aplicando matemática para chegar nas medidas mencionadas.

1. Primeiro, dentro do códgo, você precisa definir o número de threads que deseja criar (`NUM_THREADS`). 
2. Segundo, você precisa compilar o código no terminal.
3. Terceiro, você precisa rodar o código adicionando o tamanho da palavra sobre a qual as threads irão atuar.

Então, por exemplo, se a palavra tem o tamanho de um milhão de caracteres... rode o programa com 1 thread (pra começar!). Uma thread significa que a execução é de modo sequencial. Esse valor é necessário para calcular 'speedup' e 'eficiência'. Guarde isso. 

Para rodar o programa você deve fazer (no terminal): `time .reproduz_texto_paralelo.c`. Guarde esse resultado do tempo de execução. Mude o número de threads e rode de novo. Pegue o resultado do tempo de novo.

Faça isso com quantas threads desejar. 


Guarde o tempo de exeução para cada vez que rodar com um número de threads diferente. 

Você vai criar uma tabela de tempo para aquele tamanho de palavra rodando com números diferentes de threads. Com essa informação, você pode chegar no speedup e eficiência para cada número de thread. Repita a mesma coisa até agora mas com um número diferente de tamanho de palavra (dobre esse valor!). Você vai conseguir plotar um gráfico e averiguar as medidas de speedup e eficiência em tamanhos diferentes de palavras com quantidades diferentes de threads. 

Boa sorte.

B.

# EN: INE5645 - PROGRAMAÇÃO PARALELA E DISTRIBUIDA (UFSC)

## pthreads-speedup-efficiency

This repository was created to solve, in C language and individually, a problem proposed in the discipline of Parallel and Distributed Programming, which is part of the undergraduate curriculum of Bachelor of Information Systems at the Federal University of Santa Catarina (UFSC).

## Contents

In this repository you will find simple software, implemented in C language, to observe the parallelism of threads and their performance. This code served as substance for the generation of the data table and graphs that composed the final report for this activity.

## In practice

This is a program to estimate the 'speedup' and 'efficiency' of threads working on the same word. This is done by measuring the execution time and applying the math to get both data.

1. First, inside the code, you have to define the number of threads you wish to create (`NUM_THREADS`).
2. Second, you have to compile the code on the terminal.
3. Third, you need to run this code by adding the size of the word onto which the threads will work in. 

So, for example, if the word size is one million chars... run the program with 1 thread (to start!). One thread means the execution is in sequence mode. This value is fundamental to calculate 'speedup' and 'efficiency'. Keep it.

To run the program, you should type (on terminal): `time .reproduz_texto_paralelo2.c`. Grab the time result. Change the number of threads, and run it again. Grab the time result again.

Do this with as many threads as you wish.


Keep the time result for each time you run on different number of threads.

You will create a time table for that word size running with different number of threads. With this information, you can reach the speedup and efficiency values for each number of threads. Repeat the same thing but with a different word size (double it!). You can plot the graph and check out the speedup and efficiency measures on different word sizes with different number of threads.

Good luck.

B.
