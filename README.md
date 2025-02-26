
## Sistema de Gerenciamento de Sobreviventes e Recursos
Centro Federal de Educação Tecnológica de Minas Gerais - CEFET-MG
Aluno: João Paulo Cruz de Faria

---

# 1. Introdução

🔎 *Objetivo:* Este trabalho tem como objetivo aplicar conhecimentos de Programação Orientada a Objetos (POO), Listas Dinâmicas, Algoritmos de busca(BFS), tratamento de arquivos e Exceptions.

Nesse trabalho eu desenvolvi um projeto de resgate de sobreviventes ('S') dentro de uma matriz de char, optando sempre pelo menor caminho possível. Além disso foi necessário desenvolver também uma forma de Listar esses astronautas resgatados dentro de listas, dividas entre resgatados e não resgatados, onde no final do programa ele gera arquivos .txt com o registro de todos os astronautas.

---

# 2. Decisões de Implementação

### Principais desafios:

1. *Organização do código para respeitar os princípios de POO:*

   - O primeiro desafio foi justamente a implementação de métodos presente em diversas classes, e também o encapsulamento de atributos das classes.

2. *Algoritmo de Busca:*

   - Para implementar o robô da forma correta, foi necessária inserir dentro do código um algoritmo de busca que fosse eficiente e rápido, para que todos os astronautas fossem resgatados.
  
3. *Leitura e Escrita de Arquivos:*

   - Como ultimo desafio do programa, ele deveria extrair todas as informações da matriz e dos astronautas direto de um arquivo .txt, e no final da sua execução ele precisava gerar outro arquivo .txt que listava o numero de astronautas resgatados e não resgatados e a lista de nomes + atributos.

---

# 3. Análise dos Resultados

🔬 *Resultados alcançados:* O sistema no geral cumpriu seus objetivos, demonstrando eficiência na aplicação de conceitos de POO, nos algoritmos de busca e na leitura/escrita em arquivos.

### Pontos de melhoria:

1. Alteração do bfs, para implementar o problema do caixeiro viajante.
2. Implementar interface gráfica para melhorar a experiência do usuário.
3. Escrever também no arquivo final, o caminho percorrido pelo robô, ao invés de somente exibir isso no terminal.
