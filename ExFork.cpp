#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
 
int main(int argc, char  *argv[])
{
   pid_t iPid;
 
   printf("\nDuplicando o processo\n");
 
   iPid = fork();
   if (iPid < 0)
   {
      perror(argv[0]);
      exit(errno);
   }
 
   if(iPid != 0)
   {
      /* este trecho de c�digo ser� executado apenas no pai */
      printf("\nCodigo executado no processo pai\n");
      printf("\nPAI -Processo pai.  PID:|%d|\n", getpid());
      printf("\nPAI -Processo filho.PID:|%d|\n", iPid);
   }
   else
   {
      printf("\nC�digo executado pelo filho");
   }
 
   /* este trecho de c�digo ser� executado apenas no filho, embora o comando if esteja dispon�vel tamb�m para o pai */
   if(iPid == 0)
   {
      printf("\nCodigo executado no processo filho\n");
      printf("\nFILHO-Processo pai.  PID:|%d|\n",getppid());
      printf("\nFILHO-Processo filho.PID:|%d|\n",getpid());
   }
   else
   {
      printf("\nC�digo executado pelo pai");
   }
 
   /* este c�digo est� dispon�vel no pai e no filho */
   printf("\nEste mensagem ser� impressa 2 vezes");
   return 0;
}

