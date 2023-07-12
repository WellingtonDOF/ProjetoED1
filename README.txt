

Essa é uma atividade feita como trabalho para faculdade.(3º termo, BSI, ED1)

A atividade passada era basicamente o que está descrito abaixo.

-----------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------

Implemente um programa que simule e exiba a execução de tarefas solicitadas a
um “processador”. As tarefas que este pode executar são:

 Deletar.
 Gravar em dispositivo externo;
 Gravar em dispositivo interno;
 Imprimir;
 Ler;

-----------------------------------------------------------------------------------------------------------------

Observações:

Deve-se implementar uma interface que facilite o entendimento da
simulação, mostrando a Fila e quem está sendo executado no momento;

Ut Unidades de tempo;

A cada 2 ut uma tarefa é solicitada (uma leitura é realizada no arquivo
disponibilizado) e a prioridade deve ser seguida nesta ordem:

Gravar em dispositivo interno (maior prioridade);
Gravar em dispositivo externo;
Deletar;
Ler;
Imprimir (menor prioridade);

As tarefas executadas, após o tempo determinado, deverão deixar a Fila do
Processador em questão;

A Simulação deve ser finalizada quando o arquivo texto for, totalmente, consumido.

Caso haja a interrupção da simulação, ao se pressionar a tecla "" ESC "", os dados necessários
deverão ser armazenados em um arquivo texto para posterior retomada da simulação;

-----------------------------------------------------------------------------------------------------------------

A atividade foi proposta na matéria Estrutura de Dados 1 (ED1).

Para realização da atividade usei ponteiros (descritor, fila, buscas, ordenação), structs,
também foi necessário manipulação de arquivos como,leitura, escrita e exclusão tendo uma
base de dados .csv separados por vírgulas.

-----------------------------------------------------------------------------------------------------------------

! O arquivo padrão para "ativação" da atividade é o MudadoP.txt, porém, após a finalização do programa
ele será consumido, tendo que posteriormente adicionar novas linhas de dados no mesmo. então disponibilizei
o arquivo Processos.txt, assim, é só copiar os dados do Processos.txt para o MudadoP.txt para testar o programa.

FILE *arq = fopen("MudadoP.txt","r"); esse é o arquivo aberto para teste do programa.
Caso queira mudar e testar com outro é só colocar o nome do seu arquivo nesse local (localizado no main).

-----------------------------------------------------------------------------------------------------------------

E-mail: wellington05092003@gmail.com

~ Wellington F.