> :construction: Projeto em construção :construction:

# :clipboard: Kanban
#### Gerenciador de Tarefas de Metodologia Ágil com Método Kanban: Desenvolva um aplicativo de gerenciamento de tarefas com recursos do quadro do Método Kanban como adicionar tarefas, definir prioridades, agendar datas e classificar as tarefas usando algoritmos de ordenação.

<p align="center">
  <img src="imgs/quadro.png" alt="Exemplo de Quadro Kanban">
</p>


# :hammer: Funcionalidades do projeto
- 
-
-



# :file_folder: Estruta do projeto
- /bin:
    Arquivos binários do projeto;

- /build:
    Arquivos gerados e os arquivos objetos (.o);

- /docs:
    Documentação gerada em HTML, Latex e RTF, via Doxygen, incluindo o doxyfile;

- /imgs:
    Imagens utilizada para a documentação;

- /include:
    Arquivos cabeçalhos de extensão (.hpp) e (.h);

- /src:
    Código fonte do projeto de arquivos (.cpp);

- /tests:
    Códigos para testes unitários de testes de funções (.cpp);

- gitignore:
    Arquivo do Git para ignorar arquivos no contro  le de versão;

- Makefile:
    Comandos de compilação;

- README.md:
    Todas as intruções sobre o projeto.


# :computer: Técnicas e tecnologias utilizadas
<img src="imgs/cpplogo.png" alt="Logo C++"  height="80"/><br>
- C++;
- Programação Orientada a Objetos; <br>
- Doxygen;<br>
- Git e Github;<br>
- Testes unitários;<br>

## Estruturas de TADs (Tipos Abstratos de Dados)
Este assunto é implementado no arquivo [estruturas_tads.hpp](include/estruturas_tads.hpp). Consulte esse arquivo para obter mais detalhes e implementação relacionada.

- **Lista encadeada:** <br>
- 

## Templates
Este assunto é implementado no arquivo [templates.hpp](include/templates.hpp). Consulte esse arquivo para obter mais detalhes e implementação relacionada.
### 1. Algoritmos de Ordenação

- **Selection Sort:** <br>
O Selection Sort é um algoritmo de ordenação simples e intuitivo. Ele funciona selecionando repetidamente o elemento de menor valor da lista não ordenada e colocando-o no início da lista ordenada. Esse processo é repetido até que toda a lista esteja ordenada. O Selection Sort é eficiente para listas de tamanho pequeno a moderado, mas possui uma complexidade de tempo quadrática **O(n²)**, o que o torna menos eficiente em grandes conjuntos de dados. No entanto, sua simplicidade e facilidade de implementação o tornam uma opção viável em certos cenários.

- **Bubble Sort:** <br>
O Bubble Sort é um algoritmo de ordenação simples que percorre repetidamente a lista a ser ordenada, comparando pares de elementos adjacentes e realizando trocas se estiverem fora de ordem. Esse processo de comparação e troca é repetido até que a lista esteja completamente ordenada. O Bubble Sort possui uma complexidade de tempo de execução quadrática, ou seja, **O(n²)**, onde "n" é o tamanho da lista. Isso significa que o tempo de execução do algoritmo aumenta rapidamente à medida que o tamanho da lista aumenta. 

- **Merge Sort:** <br>
O Merge Sort é um algoritmo de ordenação eficiente e baseado no princípio "dividir para conquistar". Ele divide a lista não ordenada em sublistas menores, recursivamente ordena cada sublista e, em seguida, combina as sublistas ordenadas para obter a lista final ordenada. O processo de combinação envolve mesclar duas sublistas ordenadas em uma única lista ordenada. O Merge Sort possui uma complexidade de tempo de **O(n log n)**, tornando-o adequado para lidar com grandes conjuntos de dados. Sua eficiência e estabilidade tornam o Merge Sort uma opção popular em muitas aplicações de ordenação.


### 2. Algoritmo de busca binária
A busca binária é um algoritmo eficiente para encontrar um elemento em uma lista ordenada. Ele divide repetidamente a lista ao meio e compara o elemento buscado com o elemento do meio. Se forem iguais, a busca é concluída. Caso contrário, a busca continua na metade superior ou inferior da lista, dependendo da comparação. Esse processo é repetido até encontrar o elemento ou reduzir a lista a zero. A busca binária tem uma complexidade de tempo de **O(log n)**, tornando-a mais rápida que a busca linear para listas grandes. No entanto, requer uma lista ordenada para funcionar corretamente.

# :wrench: Como compilar?
O projeto utiliza um Makefile para automatizar o processo de compilação e criação do executável. O Makefile define o compilador, as opções de compilação e os diretórios para os arquivos objeto e executável. 

### Para compilar o projeto, siga os passos abaixo:

1. Certifique-se de que você possui o compilador GCC instalado em seu sistema.
2. Abra o terminal e navegue até o diretório raiz do projeto.
3. Execute o seguinte comando para compilar o programa: <br>
**`make`** <br> 
Isso irá utilizar o Makefile fornecido para compilar o código fonte e gerar o arquivo executável na pasta "/bin" e os arquivos objetos (.o) na pasta "/build".<br>

- Após a conclusão da compilação, você pode executar o programa usando o seguinte comando: <br>
**`make run`** <br>
Isso irá executar o programa compilado.<br>

- Para limpar os arquivos gerados durante a compilação, você pode executar o seguinte comando: <br>
**`make clean`** <br>
Isso irá remover os arquivos objeto e o executável do projeto.






# :busts_in_silhouette: Autores

| [<img src="https://avatars.githubusercontent.com/u/129897959?v=4" width=115><br><sub>Isabela Gomes</sub>](https://github.com/cyberisa) |  [<img src="https://avatars.githubusercontent.com/u/102569695?s=400&u=f20bbb53cc46ec2bae01f8d60a28492bfdccbdd5&v=4" width=115><br><sub>Matheus Vidal</sub>](https://github.com/matheusvidal21) |
| :---: | :---: | 

