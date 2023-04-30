# Pixeon-image-viewer

[English](./README-en.md)

## TODO:
- não estou contente com insertWidgetItem(filenames);
- gostaria de tentar outro angulo para rotação (estou com 90), mas parece quebrar a aplicação em qualquer outro valor;
- aparentemente todos os requisitos foram atingidos, mas não estou contente com a solução;
- melhorar os algoritmos de transformação de imagem;
- criar relatório sobre o problema;

## Sobre este repositório
Este projeto consistiu no desafio para a vaga de Analista Desenvolvedor C++ da Pixeon. Foi requerido desenvolver na linguagem de programação C++ e no ambiente QT, uma aplicação que compreendia em um visualizador de imagens. Com seleção, visualização e transformações de imagens, como: zoom, deslocamento, rotação e brilho.

**/Image-viewer/** contém os arquivos .cpp, .hpp, .ui e cmake deste projeto,
**/Images/** contém três arquivos de imagens .bmp .jpeg e .png para testes deste projeto.

Ainda, o repositório contém duas branchs, **dev** que apresenta todo o histórico de implementação, e **main** que contém a última versão atual deste projeto.

## Metodologia
Iniciou-se um projeto *Qt Widgets Application* pela IDE *Qt Creator*, na linguagem de programação C++ 17. Utilizando do *Qt Design* (que está incluído no ambiente de desenvolvimento), elaborou-se a interface de usuário da aplicação, do qual contém botão para seleção de uma ou mais imagens, uma lista de nomes das imagens selecionadas e uma *label* para exibição da imagem indicada.

Adiante, seguiu-se com a implementação para seleção de imagens, utilizando da classe *QFileDialog* e de seu método *getOpenFileNames*, restringindo á somente aceitar arquivos .bmp .jpeg e .png, conforme foi estabelecido como requisito.  Usou-se da classe *ListWiget* e de seus itens para controlar a seleção das imagens, e apresenta-lá na aplicação com as classes *QLabel* e *QPixmap*.

Seguidamente, implementaram-se atalhos no teclado para poderem realizar transformações na imagem exibida. Com a classe *QShortcut*, os atalhos foram conectados com *slots* que chamavam suas funções quando o sinal da tecla era ativado. As transformações de imagem (zoom, deslocamento, rotação e brilho) foram implementadas separadas em um arquivo (graphicsmanager.hpp), do qual era responsável pelos diferentes tratamentos da imagem que vinha da *QLabel*.

## Dificuldades


## Melhorias futuras
rotação em menor grau, com melhor suavização.

## Avaliação do resultado 

## Ambiente
* Qt Creator
* C++ 17
* Arch Linux

