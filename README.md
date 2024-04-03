# 24a - AV1 - emb - LED RGB

> LEIA TODOS OS PASSOS ANTES DE SAIR FAZENDO, TENHA UMA VISÃO GERAL DO TODO ANTES DE COMECAR .

Prezado aluno:

- A prova é prática, com o objetivo de avaliar sua compreensão a cerca do conteúdo da disciplina. 
- É permitido consulta a todo material pessoal (suas anotações, códigos), lembre que você mas não pode consultar outros seres vivos!
- chatgpt / copilot/ ... liberados!
- Duração total: 2h 

Sobre a avaliacão:

1. Você deve satisfazer ambos os requisitos: funcional, estrutura de código e qualidade de código para ter o aceite na avaliação;
1. A avaliação de C deve ser feita em sala de aula por um dos membros da equipe (Professor ou Técnico);
1. A entrega do código deve ser realizada no git.
1. Realizar um commit a cada 15 minutos, vamos avisar vcs!

## Entrega

Nesta avaliação vocês irão desenvolver um protótipo de uma fechadura eletrônica!. 

> Video com a entrega esperada
>
> https://youtube.com/shorts/Sk_oOlHranI

O comportamento esperado é o seguinte: O sistema deve aguardar por uma sequência de 4 apertos dos botões e verificar se uma senha foi corretamente digitada, a cada vez que o usuário aperta o botão, o OLED deve exibir um novo `*`, ao completar 4 dígitos, o sistema deve verificar se a sequencia foi correta e então abrir a fechadura (girar o motor).

Ao detectar a senha correta (apenas o término dos 4 dígitos) exibir: OPEN no OLED, e ERROR caso contrário.

A senha padrão deve ser: 

- `1, 3, 2, 3`

Vocês devem desenvolver o firmware como indicado a seguir:

![](imgs/firmware.png)

Onde:

- `btn_callback`:
  - Callback dos botões da placa OLED
  
- `xQueueBTN`
    - Fila com informacoes de quais botões foram apertados
    
- `task_senha` 
    - Tarefa que faz a leitura dos botões, verifica a senha e ativa ou não o motor de passos (para abrir a fechadura)
    - Exibe no OLED o `****` referente a senha sendo digitada
    
- `xSemaphoreMotor`
    - Semáforo que define se o motor vai girar 180 graus

- `motor_task`
    - Task que faz o motor girar 180 graus quando semáforo liberado
    
## Rubrica

> Não possuir erro de qualidade de código detectado no github actions.

Segue as seguintes rubricas

- [ ] `senha_task` e `motor_task` implementadas
- [ ] Botões da OLED funcionando com interrupção (IRS)
- [ ] `xQueueBTN` usada para envio de qual botão foi apertado da IRS
- [ ] `xSemaphoreMotor` controla quando o motor vai girar
- [ ] `senha_task` verifica a senha e determina se motor deve ou não girar, a senha padrão deve ser `1, 3, 2, 3`
- [ ] `motor_task` quando semáforo liberado, rotaciona o motor em 180 graus
- [ ] `OLED` exibe o tamanho da senha digitada em `*`, deve limpar quando senha digitada
- [ ] Exibir `OPEN` se tentativa correta e `ERROR` caso contrário
- [ ] Limpar o display e possibilitar uma nova tentativa
