#include<conio2.h>
#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

struct TpDados
{
	int Processador;
	char NomeArq[40],Processo[40];
	int Execucao;
	TpDados *Ant, *Prox;
};

struct TpDescritor;

struct TpPont
{
	int Processador,NumT;
	TpPont *Ant, *Prox; 
	TpDescritor *FilaD; // FilaD = Fila Dados.
};

struct TpContador
{
	int Quatro,Tres,Dois,Um;
};

struct TpDescritor
{
	TpPont *Inicio,*Fim;
	TpDados *InicioD, *FimD;
};

void Inicializar(TpDescritor &Desc)
{
	Desc.Inicio=Desc.Fim=NULL;
}

TpPont *NovaCaixa(TpDados Reg)
{
	
	TpPont *Nc= new TpPont; 
	Nc->Processador=Reg.Processador; 
	Nc->NumT=0;
	Nc->Prox=Nc->Ant=NULL;
	Nc->FilaD=NULL;
	
	return Nc; 
}

TpDados *NovaCaixa2(TpDados Reg)
{
	TpDados *Nc= new TpDados; 
	
	Nc->Processador=Reg.Processador;
	strcpy(Nc->NomeArq,Reg.NomeArq);
	strcpy(Nc->Processo,Reg.Processo);
	Nc->Execucao=Reg.Execucao;
	Nc->Prox=Nc->Ant=NULL;
	
	return Nc; 
}

TpDescritor *NovaCaixa3()
{
	TpDescritor *Nc= new TpDescritor; 
	
	Nc->InicioD=Nc->FimD=NULL;

	return Nc; 
}

int Verificar(TpDescritor Descr, int P) // Verifica se tem o processador cadastrado.
{
	TpPont *Atual = Descr.Inicio;
	
	while(Atual!=NULL && Atual->Processador!=P) // Verificando se existe algum processador igual já cadastrado.
		Atual=Atual->Prox;

	if(Atual==NULL)
		return 1; // Se for igual a NULL andou até o final da fila e não achou nenhum processador igual.
	else
		return -1;
}

TpPont *EncontrarP(TpDescritor Descr, int P) // Retorna onde está o processador na Fila.
{
	TpPont *Atual = Descr.Inicio;
	
	while(Atual->Processador!=P) // não perguntei pelo null porque já fiz essa confirmação no verificar então eu sei que não vai chegar em NULL e vai achar o processador.
		Atual=Atual->Prox;
	
	return Atual; // não precisa perguntar se ele existe porque ele vai existir.
}

TpDados SalvaDados(TpDescritor &Descr,TpDados *A)
{
	TpDados R;
	
	R.Processador=A->Processador;
	strcpy(R.NomeArq,A->NomeArq);
	strcpy(R.Processo,A->Processo);
	R.Execucao=A->Execucao;
	
	return R;
}

void TrocaDados(TpDescritor &Descr,TpDados *Ant2, TpDados *Atual)
{
	Atual->Processador=Ant2->Processador;
	strcpy(Atual->NomeArq,Ant2->NomeArq);
	strcpy(Atual->Processo,Ant2->Processo);
	Atual->Execucao=Ant2->Execucao;
}

void TrocaDados2(TpDescritor &Descr,TpDados *Ant2, TpDados Reg)
{
	Ant2->Processador=Reg.Processador;
	strcpy(Ant2->NomeArq,Reg.NomeArq);
	strcpy(Ant2->Processo,Reg.Processo);
	Ant2->Execucao=Reg.Execucao;
}

void OrdenaDados(TpDescritor &Descr,int P)
{
	TpPont *Aux;
	
	TpDados *Ant2,*Atual,Reg;
	
	int Proc,Exec;
	char Nome[40],Process[40];
		
	Aux=EncontrarP(Descr,P);
	
	Atual=Aux->FilaD->FimD;
	
	while(Atual->Ant!=NULL && Atual->Ant!=Aux->FilaD->InicioD)
	{
		Ant2=Atual->Ant;
		
		if(Atual->Processo[0]=='G' && Atual->Processo[19]=='I')
		{
			if(Ant2->Processo[0]=='G' || Ant2->Processo[0]=='D' || Ant2->Processo[0]=='L' || Ant2->Processo[0]=='I')
			{
				Reg.Processador=Atual->Processador;
				strcpy(Reg.NomeArq,Atual->NomeArq);
				strcpy(Reg.Processo,Atual->Processo);
				Reg.Execucao=Atual->Execucao;
				
				Atual->Processador=Ant2->Processador;
				strcpy(Atual->NomeArq,Ant2->NomeArq);
				strcpy(Atual->Processo,Ant2->Processo);
				Atual->Execucao=Ant2->Execucao;
				
				Ant2->Processador=Reg.Processador;
				strcpy(Ant2->NomeArq,Reg.NomeArq);
				strcpy(Ant2->Processo,Reg.Processo);
				Ant2->Execucao=Reg.Execucao;	
			}
		}
		else
			if(Atual->Processo[0]=='G')
			{
				if(Ant2->Processo[0]=='D' || Ant2->Processo[0]=='L' || Ant2->Processo[0]=='I')
				{
					//Reg=SalvaDados(Atual);
					//TrocaDados(Descr,Atual,Ant2);
					//TrocaDados2(Ant2,Reg);
					Reg.Processador=Atual->Processador;
					strcpy(Reg.NomeArq,Atual->NomeArq);
					strcpy(Reg.Processo,Atual->Processo);
					Reg.Execucao=Atual->Execucao;
					
					Atual->Processador=Ant2->Processador;
					strcpy(Atual->NomeArq,Ant2->NomeArq);
					strcpy(Atual->Processo,Ant2->Processo);
					Atual->Execucao=Ant2->Execucao;
					
					Ant2->Processador=Reg.Processador;
					strcpy(Ant2->NomeArq,Reg.NomeArq);
					strcpy(Ant2->Processo,Reg.Processo);
					Ant2->Execucao=Reg.Execucao;
				}
			}
			else
				if(Atual->Processo[0]=='D')
				{
					if(Ant2->Processo[0]=='L' || Ant2->Processo[0]=='I')
					{
						Reg.Processador=Atual->Processador;
						strcpy(Reg.NomeArq,Atual->NomeArq);
						strcpy(Reg.Processo,Atual->Processo);
						Reg.Execucao=Atual->Execucao;
						
						Atual->Processador=Ant2->Processador;
						strcpy(Atual->NomeArq,Ant2->NomeArq);
						strcpy(Atual->Processo,Ant2->Processo);
						Atual->Execucao=Ant2->Execucao;
						
						Ant2->Processador=Reg.Processador;
						strcpy(Ant2->NomeArq,Reg.NomeArq);
						strcpy(Ant2->Processo,Reg.Processo);
						Ant2->Execucao=Reg.Execucao;
					}
				}
				else
					if(Atual->Processo[0]=='L')
					{
						if(Ant2->Processo[0]=='I')
						{		
							Reg.Processador=Atual->Processador;
							strcpy(Reg.NomeArq,Atual->NomeArq);
							strcpy(Reg.Processo,Atual->Processo);
							Reg.Execucao=Atual->Execucao;
							
							Atual->Processador=Ant2->Processador;
							strcpy(Atual->NomeArq,Ant2->NomeArq);
							strcpy(Atual->Processo,Ant2->Processo);
							Atual->Execucao=Ant2->Execucao;
							
							Ant2->Processador=Reg.Processador;
							strcpy(Ant2->NomeArq,Reg.NomeArq);
							strcpy(Ant2->Processo,Reg.Processo);
							Ant2->Execucao=Reg.Execucao;
						}
					}
		Atual=Atual->Ant;
	}	
}

void OrdenaProcessadores(TpDescritor &Descr)
{
	int P;
	
	TpDescritor *Dados;
	TpPont *Atual=Descr.Fim;
	
	P=Descr.Fim->Processador;
	Dados=Descr.Fim->FilaD;	
	
	while(Atual->Ant!=NULL && Atual->Ant->Processador>Atual->Processador)
	{
		Atual->Processador=Atual->Ant->Processador; // Faz com que o de tras venha para a frente.
		Atual->FilaD=Atual->Ant->FilaD;
			
		Atual=Atual->Ant; // pra andar
		
		Atual->Processador=P;
		Atual->FilaD=Dados;
	}
}

void DiminuirTempo(TpDescritor D)
{
	TpDados *Aux;
	
	while(D.Inicio!=NULL)
	{		
		if(D.Inicio->FilaD->InicioD!=NULL && D.Inicio->FilaD->InicioD->Execucao>0)
			D.Inicio->FilaD->InicioD->Execucao=D.Inicio->FilaD->InicioD->Execucao-1;
		
		Aux=D.Inicio->FilaD->InicioD;
		
		if(D.Inicio->FilaD->InicioD!=NULL && D.Inicio->FilaD->InicioD->Execucao==0)
		{
			if(D.Inicio->FilaD->InicioD->Prox!=NULL)
			{
				D.Inicio->FilaD->InicioD=D.Inicio->FilaD->InicioD->Prox;
				delete(D.Inicio->FilaD->InicioD->Ant);
				D.Inicio->FilaD->InicioD->Ant=NULL;
			}
			else
				if(D.Inicio->FilaD->InicioD->Prox==NULL)
				{
					Aux=D.Inicio->FilaD->InicioD;
					D.Inicio->FilaD->InicioD=D.Inicio->FilaD->FimD=NULL;
					delete(Aux);			
				}
			D.Inicio->NumT=D.Inicio->NumT+1;
		}	
		D.Inicio=D.Inicio->Prox;
	}
}

void Inserir(TpDescritor &Descr,TpDados Proc,TpContador &Reg)
{
	TpPont *C = new TpPont,*Aux;
	
	int Verif; 
	
	C=NovaCaixa(Proc);
	C->FilaD=NovaCaixa3();
	C->FilaD->InicioD=C->FilaD->FimD=NovaCaixa2(Proc);

	//C->FilaD=NovaCaixa2(Proc);
	
	if(Descr.Inicio==NULL)
		Descr.Inicio=Descr.Fim=C;
	else
		{
			// Verificar se o processador já esta cadastrado.
			Verif=Verificar(Descr,Proc.Processador);
			
			// Se Não existe o processador na fila, então aqui vai cadastrar.
			if(Verif==1)
			{	
				// Inserção na lista do tipo fila.	
				Descr.Fim->Prox=C;
				C->Ant=Descr.Fim;	
				Descr.Fim=C;
				// chamar a ordenação
			}
			else // Existe o Processador então não precisa cadastras, mas precisa acahar onde ele ta pra inserir o dado.
				{
					
					Aux=EncontrarP(Descr,Proc.Processador); // encontra onde o processador ta cadastrado
					
					if(Aux->FilaD->InicioD==NULL)
						Aux->FilaD->InicioD=Aux->FilaD->FimD=C->FilaD->FimD;
					else
						{
							Aux->FilaD->FimD->Prox=C->FilaD->FimD; // Ligar a fila que já existe no processador cadastrado, com as novas informações que estão vindo do mesmo tipo de processador.  pos prox
							C->FilaD->FimD->Ant=Aux->FilaD->FimD; // Ligar a informação que ta vindo na pos anterior com a informação já cadastrado no processador.
							Aux->FilaD->FimD=C->FilaD->FimD;	// Tornando o fim da lista a informação que acabou de chegar.
						}
				}		
		}
		
		OrdenaDados(Descr,Proc.Processador);
		OrdenaProcessadores(Descr);
		
//		if(Proc.Processador==4)
//			Reg.Quatro=Reg.Quatro+1;
//		else
//			if(Proc.Processador==3)
//				Reg.Tres=Reg.Tres+1;
//			else
//				if(Proc.Processador==2)
//					Reg.Dois=Reg.Dois+1;
//				else
//					if(Proc.Processador==1)
//						Reg.Um=Reg.Um+1;
}

void Exibir(TpDescritor D,int UT)
{
	TpDados *Aux;
	
	printf("\n\n**** Dados Cadastrados ****\n\n");
	while(D.Inicio!=NULL)
    {
    	printf("\nProcessador: %d\n",D.Inicio->Processador);
    	
    	Aux=D.Inicio->FilaD->InicioD;
    	
    	while(Aux!=NULL)//D.Inicio->FilaD->InicioD!=NULL)
    	{
    		printf("\nNome: %s Processo: %s Execucao: %d  | UT: %d\n\n",Aux->NomeArq,Aux->Processo,Aux->Execucao,UT);

    		//printf("\nProcessador: %d Nome: %s Processo: %s Execucao: %d\n\n",Aux->Processador,Aux->NomeArq,Aux->Processo,Aux->Execucao);
    		
			//printf("\nNome: %s Processo: %s Execucao: %d\n\n",D.Inicio->FilaD->InicioD->NomeArq,D.Inicio->FilaD->InicioD->Processo,D.Inicio->FilaD->InicioD->Execucao);
			Aux=Aux->Prox; 
			//D.Inicio->FilaD->InicioD=D.Inicio->FilaD->InicioD->Prox;			
		}
		
		printf("\n\n --------------------\n\n");

    	D.Inicio=D.Inicio->Prox;
	}
}


//void Exibir(TpDescritor D) // EXIBIR AO CONTRARIO
//{
//	
//	printf("\n\n**** Dados Cadastrados ****\n\n");
//	while(D.Inicio!=NULL)
//    {
//    	printf("\nProcessador: %d\n",D.Inicio->Processador);
//    	
//    	while(D.Inicio->FilaD->FimD!=NULL)
//    	{
//    		//printf("\nProcessador: %d Nome: %s Processo: %s Execucao: %d\n\n",D.Inicio->FilaD->InicioD->Processador,D.Inicio->FilaD->InicioD->NomeArq,D.Inicio->FilaD->InicioD->Processo,D.Inicio->FilaD->InicioD->Execucao);
//    		printf("\nNome: %s Processo: %s Execucao: %d\n\n",D.Inicio->FilaD->FimD->NomeArq,D.Inicio->FilaD->FimD->Processo,D.Inicio->FilaD->FimD->Execucao);
//			D.Inicio->FilaD->FimD=D.Inicio->FilaD->FimD->Ant;			
//		}
//		
//		printf("\n\n --------------------\n\n");
//
//    	D.Inicio=D.Inicio->Prox;
//	}
//}


void CriarArquivo(TpDescritor D)
{
	FILE *arqsalvar = fopen("ArquivoSalvar.txt","w");	
	FILE *arqresposta = fopen("ArquivoResposta.txt","w");
	
	TpDados *Aux;
	int num ;
	
	while(D.Inicio!=NULL)
    {
    	printf("\nProcessador: %d\n",D.Inicio->Processador);
    	
    	Aux=D.Inicio->FilaD->InicioD;
    	
    	while(Aux!=NULL)//D.Inicio->FilaD->InicioD!=NULL)
    	{
    		//printf("\nNome: %s Processo: %s Execucao: %d  | UT: %d\n\n",Aux->NomeArq,Aux->Processo,Aux->Execucao);
			
			fprintf(arqsalvar,"%d,%s,%s,%d\n",Aux->Processador,Aux->NomeArq,Aux->Processo,Aux->Execucao);
			
    		//printf("\nProcessador: %d Nome: %s Processo: %s Execucao: %d\n\n",Aux->Processador,Aux->NomeArq,Aux->Processo,Aux->Execucao);
    		
			//printf("\nNome: %s Processo: %s Execucao: %d\n\n",D.Inicio->FilaD->InicioD->NomeArq,D.Inicio->FilaD->InicioD->Processo,D.Inicio->FilaD->InicioD->Execucao);
			Aux=Aux->Prox; 
			
			//D.Inicio->FilaD->InicioD=D.Inicio->FilaD->InicioD->Prox;			
		}
		
		//printf("\n\n --------------------\n\n");

    	D.Inicio=D.Inicio->Prox;
	}
	
	num=1;
	fprintf(arqresposta,"%d",num);

	fclose(arqsalvar);
	fclose(arqresposta);
}

int main()
{
	TpDados Proc,*Aux;
	TpPont *Aux2,*Aux3;
	TpDescritor D;
	TpContador Reg;
	
	int UT=0,op=1,key,posicao,pos2,num=0,num2=0;
		
	Reg.Quatro=Reg.Tres=Reg.Dois=Reg.Um=0;
	
    FILE *arq = fopen("MudadoP.txt","r");
    FILE *arq2 = fopen("Posicao.txt","a+");
    FILE *arqsalvar = fopen("ArquivoSalvar.txt","r");
    FILE *arqresposta = fopen("ArquivoResposta.txt","r");

    Inicializar(D);
	
	if(arqsalvar!=NULL);
	{
		fscanf(arqresposta,"%d",&num);
		
		if(num==1)
		{
			
			fscanf(arqsalvar,"%d,%[^,],%[^,],%d\n",&Proc.Processador, &Proc.NomeArq, &Proc.Processo, &Proc.Execucao);
			Inserir(D,Proc,Reg);
			printf("P: %d Nome %s Processo %s Exec %d",Proc.Processador, Proc.NomeArq, Proc.Processo, Proc.Execucao);
			
			while(!feof(arqsalvar))
			{
				fscanf(arqsalvar,"%d,%[^,],%[^,],%d\n",&Proc.Processador, &Proc.NomeArq, &Proc.Processo, &Proc.Execucao);
				Inserir(D,Proc,Reg);
			}
		}

		fclose(arqsalvar);
		fclose(arqresposta);
	}
		
	if(arq2!=NULL && fscanf(arq2,"%d",&posicao)==1)
	{	
		while(!feof(arq2))
			fscanf(arq2,"%d",&posicao);
		
		fseek(arq,posicao,0);
	}	
	
	fscanf(arq,"%d,%[^,],%[^,],%d\n",&Proc.Processador, &Proc.NomeArq, &Proc.Processo, &Proc.Execucao);
	
	if(arq!=NULL && !feof(arq))
	{
	    
	    Inserir(D,Proc,Reg);
	    
	    while(!feof(arq) && op)
	    {
	    	clrscr();

			if(UT==2)
			{
				fscanf(arq,"%d,%[^,],%[^,],%d\n",&Proc.Processador, &Proc.NomeArq, &Proc.Processo, &Proc.Execucao);
				Inserir(D,Proc,Reg);
				UT=0;	
			}
			
			Exibir(D,UT); 
			DiminuirTempo(D);
			
			Sleep(1200);
	    	UT++;
	    	
	    	posicao=ftell(arq);		
				
	    	if(_kbhit())
	    		key = _getch();
			
			if(key==27)
				op=0;	
	    }

	    fprintf(arq2,"%d\n",posicao);
	    
	   	if(feof(arq))
		{
			fclose(arq2);
			fclose(arq);
			
			FILE *arq2 = fopen("Posicao.txt","w");
    		FILE *arq = fopen("MudadoP.txt","w");
			fclose(arq);
		}

	    fclose(arq);

	    if(arq2!=NULL)
	    	fclose(arq2);
    }
    //Inserir(D,Proc,Reg);
	
    clrscr();
    
    Aux2=D.Inicio;
    
    if(op!=0)
    {
    	
    	op=1;
    	
	    while(Aux2!=NULL)
	    {
	    	//printf("\nD inicio %d",D.Inicio->Processador);
	    	Aux=D.Inicio->FilaD->InicioD;
			
	    	while(Aux!=NULL && op)
	    	{
	    		DiminuirTempo(D);
	    		clrscr();
	    		Exibir(D,UT);
	    		Aux=D.Inicio->FilaD->InicioD;
	  			Sleep(1200);
				  		
		    	if(_kbhit())
		    		key = _getch();
				
				if(key==27)
					op=0;
			}
			Aux2=Aux2->Prox;		
		}
	}
	
	
	if(op==0)	
		CriarArquivo(D);	
	
   	clrscr();
   	
    Exibir(D,UT);

	getche();
	
	return 0;
}


