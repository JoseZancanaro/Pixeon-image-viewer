# Pixeon-image-viewer

[Inglês](./README-en.md)

## Sobre este repositório
Este projeto consistiu no desafio para a vaga de Analista Desenvolvedor C++ da Pixeon. Foi requerido desenvolver na linguagem de programação C++ e no ambiente QT, uma aplicação que compreendia em um visualizador de imagens. Com seleção, visualização e transformações de imagens, como: zoom, deslocamento, rotação e brilho.

**/Image-viewer/** contém os arquivos .cpp, .hpp, .ui e cmake deste projeto,
**/Images/** contém três arquivos de imagens .bmp .jpeg e .png para testes deste projeto.

Ainda, o repositório contém duas branchs, **dev** que apresenta todo o histórico de implementação, e **main** que contém a última versão atual deste projeto.

## Controles da aplicação
| tecla | ação                         |
|-------|------------------------------|
| +     | mais zoom                    |
| -     | menos zoom                   |
| W     | descolamento para cima       |
| D     | descolamento para direita    |
| S     | descolamento para baixo      |
| A     | descolamento para esquerda   |
| R     | rotação para direita         |
| E     | rotação para esquerda        |
| →     | mais brilho                  |
| ←     | menos brilho                 |


## Metodologia
Iniciou-se um projeto *Qt Widgets Application* pela IDE *Qt Creator*, na linguagem de programação C++ 17. Utilizando do *Qt Design* (que está incluído no ambiente de desenvolvimento), elaborou-se a interface de usuário da aplicação, do qual contém botão para seleção de uma ou mais imagens, uma lista de nomes das imagens selecionadas e uma *label* para exibição da imagem indicada.

Adiante, seguiu-se com a implementação para seleção de imagens, utilizando da classe *QFileDialog* e de seu método *getOpenFileNames*, restringindo á somente aceitar arquivos .bmp .jpeg e .png, conforme foi estabelecido como requisito.  Usou-se da classe *ListWiget* e de seus itens para controlar a seleção das imagens, e apresenta-lá na aplicação com as classes *QLabel* e *QPixmap*.

Seguidamente, implementaram-se atalhos no teclado para poderem realizar transformações na imagem exibida. Com a classe *QShortcut*, os atalhos foram conectados com *slots* que chamavam suas funções quando o sinal da tecla era ativado. As transformações de imagem (zoom, deslocamento, rotação e brilho) foram implementadas separadas em um arquivo (graphicsmanager.hpp), do qual era responsável pelos diferentes tratamentos da imagem que vinha da *QLabel*.

## Dificuldades
As principais dificuldades que encontrei foram relacionadas às boas práticas de desenvolvimento para a linguagem de programação C++ e para o ambiente Qt. Durante um tempo, eu estava trabalhando principalmente em desenvolvimento web e análise de dados. Tornou-se necessário para mim lembrar de vários bons comportamentos de desenvolvimento em C ++, mas posso ter escorregado em algum momento e feito algo não muito recomendado.

## Melhorias futuras
Para este projeto de visualizador de imagens, e principalmente para as aplicações de transformações nas imagens, destaco algumas possíveis implementações futuras:
* **editor**: maior controle sobre as imagens. Permitindo que seja salvo/carregado no aplicativo.
* **rotação**: menor valor de ângulo, com rotação mais suave e precisa na imagem.
* **zoom**: limites estabelecidos para ampliação. Aplicar menos zoom intensamente, consome muita memória da aplicação.
* **deslocamento**: no momento, a aplicação não está mantendo a nova posição da imagem. Aplicação realiza o deslocamento, mas não guarda a posição caso outra transformação seja chamada.
* **brilho**: limites estabelecidos para intensidade de brilho. Assim, se chegar ao nível muito alto/baixo, não perderá o conteúdo da imagem original.

## Resultado
O projeto do visualizador de imagens em C++ com o ambiente Qt foi uma experiência curiosa e desafiadora.
Durante o desenvolvimento, algumas questões sobre boas práticas surgiram, mas com pesquisa e consultas na comunidade, acredito ter chegado em uma solução interessante. Eu considero ter atendido a todos os requisitos estabelecidos para esse desafio, apesar de que, muitas melhorias futuras podem ser feitas, para melhor a aplicação e deixa-la mais robusta e mais agradável.

## Ambiente
* Qt Creator
* C++ 17
* Arch Linux

