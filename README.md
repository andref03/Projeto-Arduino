# Projeto Lixeira Inteligente

Este repositório contém uma implementação em micro Arduino para a automatização do processo de abrir/fechar lixeiras. A implementação pode ser vista, com comentários, no arquivo `projetoLixeiraInteligente.ino`.

## Motivação

Visando a acessibilidade, este projeto permite que a ação de abrir/fechar lixeiras possa ser feita de maneira higiênica para cadeirantes, ou quaisquer pessoas com dificuldades motoras, tornando desnecessário o uso das mãos.
Dessa forma, promove a saúde, o bem-estar e a acessibilidade para essa parcela da população.

## Hardwares utilizados

  1. Micro Arduino
  2. Sensor ultrassônico
  3. Micro Servo Motor

## Funcionalidade

Assim que o sensor ultrassônico detectar a presença de um objeto em até 20 cm, o micro servo motor - que está instalado no pedal da lixeira - irá acionar e, dessa forma, levantar a tampa da lixeira. Isso será feito de 30 em 30 graus, até que o motor atinja a angulação de 90 graus. Detalhe importante: essa ação de levantar a tampa acontece rapidamente, aumentando a angulação do motor a cada 0,5 segundo. Enquanto o sensor detectar a presença contínua deste objeto em um raio de 20 cm, a tampa permanecerá aberta. Assim que o sensor não captar mais o objeto no raio especificado, serão contabilizados 5 segundos e, então, o processo para fechar a tampa começará. A cada 1,5 segundo, o motor irá diminuir sua angulação em 10 graus. Ou seja, irá do grau 90 ao 0 de forma relativamente devagar.
