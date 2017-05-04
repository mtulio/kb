# Ordering Algorithms

## Build it

`make`

## Custom output file

`make args='-o my_binary'`

## Interaction (Program Options)

1) Choose a Vector Size

```shell
**** MENU PRINCIPAL ***

Informe o Tamanho do Vetor:
1 - 100 <> 10^2
2 - 1.000 <> 10^3
3 - 10.000 <> 10^4
4 - 100.000 <> 10^5
5 - 1.000.000 <> 10^6
0 - SAIR
Digite a opcao:

```

2) Choose the Algorithm

```shell
*** Menu Escolha de Metodo ***

Tamanho do Vetor: 1000000

Informe o Metodo a ser calculado:
1 - InsertionSort
2 - SelectionSort
3 - QuickSort
4 - ShellSort
5 - HeapSort
0 - SAIR
Digite a opcao:

```
3) Choose the number of tests the program will do:

`Digite o numero de Repeticoes do Codigo (de 1 a 5 ):`

4) The result file (`{ALGORITHM}_{INTERACTION}_{SIZE}.txt`) will be generate at the same directory.

## Project Results

The project documentation is available [here](../docs/N1_-_Algoritmos_de_ordenacao-GRAFICOS.pdf)

## Complete Example using Algorithms

### Insertion

* Runtime for 100K

```
**** MENU PRINCIPAL ***

Informe o Tamanho do Vetor:
1 - 100 <> 10^2
2 - 1.000 <> 10^3
3 - 10.000 <> 10^4
4 - 100.000 <> 10^5
5 - 1.000.000 <> 10^6
0 - SAIR
Digite a opcao: 4

*** Menu Escolha de Metodo ***

Tamanho do Vetor: 100000

Informe o Metodo a ser calculado:
1 - InsertionSort
2 - SelectionSort
3 - QuickSort
4 - ShellSort
5 - HeapSort
0 - SAIR
Digite a opcao: 1
Digite o numero de Repeticoes do Codigo (de 1 a 5 ): 1


STATUS: "Processando InsertionSort"
Nro Repeticoes: 1
Repeticao Atual: 1
Complexidade: 100000
POR FAVOR AGUARDE...
Metodo InsertionSort processado e gravado no Arquivo:
 InsertionSort_1_100000.txt

CONCLUSAO: Processamento do Metodo InsertionSort concluido com sucesso!
        Consulte o Arquivo para mais detalhes!!!
```

* Output file for 100K

```shell
$ cat InsertionSort_1_100000.txt
*** METODO: InsertionSort ***
 TAMANHO DO VETOR: 100000
 Tempo de execucao:
7.86546e+06 microsegundos
7.86546 segundos

Sun.Dec.11.11:42:36.2016
```

### Selection

* Output for 100K

```shell
$ cat InsertionSort_1_100000.txt
*** METODO: InsertionSort ***
 TAMANHO DO VETOR: 100000
 Tempo de execucao:
7.86546e+06 microsegundos
7.86546 segundos

Sun.Dec.11.11:42:36.2016
```

### Quick

* Output for 100K

```shell
$ cat QuickSort_1_100000.txt
*** METODO: QuickSort ***
 TAMANHO DO VETOR: 100000
 Tempo de execucao:
45218 microsegundos
0.045218 segundos

Sun.Dec.11.11:52:56.2016
```

* Output for 1M

```shell
$ cat QuickSort_1_1000000.txt
*** METODO: QuickSort ***
 TAMANHO DO VETOR: 1000000
 Tempo de execucao:
203201 microsegundos
0.203201 segundos

Sun.Dec.11.11:56:09.2016
```

### Shell

* Output for 100K

```shell
$ cat ShellSort_1_100000.txt
*** METODO: ShellSort ***
 TAMANHO DO VETOR: 100000
 Tempo de execucao:
50817 microsegundos
0.050817 segundos

Sun.Dec.11.11:53:05.2016
```


* Output for 1M

```shell
$ cat ShellSort_1_1000000.txt
*** METODO: ShellSort ***
 TAMANHO DO VETOR: 1000000
 Tempo de execucao:
389158 microsegundos
0.389158 segundos

Sun.Dec.11.11:56:20.2016

```

### Heap

* Output for 100K

```shell
$ cat HeapSort_1_100000.txt
*** METODO: HeapSort ***
 TAMANHO DO VETOR: 100000
 Tempo de execucao:
49817 microsegundos
0.049817 segundos

Sun.Dec.11.11:53:14.2016
```


* Output for 1M

```shell
$ cat HeapSort_1_1000000.txt
*** METODO: HeapSort ***
 TAMANHO DO VETOR: 1000000
 Tempo de execucao:
312769 microsegundos
0.312769 segundos

Sun.Dec.11.11:56:31.2016
```

## TODO

* Translate to english
* Create non-interative runtime (full command lines)
* Add new Algorithms
