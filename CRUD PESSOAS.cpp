//INCLUSÃO DAS BIBLIOTECAS
#include<iostream>
#include<stdlib.h>
using namespace std;

//DECLARAÇÃO DA CLASSE PESSOA
class Pessoa
{
 int id;
 char nome[20];
 char email[20];
 char telefone[20];
 char idade[20];

 //PEGAR DADOS DIGITADOS PELO USUARIO
 public:
 	int Insert(Pessoa *p,int n)
	{
	 cout<<"Digite o id: ";
	cin>>p[n].id;
	cout<<"Digite o nome: ";
	cin>> p[n].nome;
	cout<< "Digite o e-mail: ";
	cin>> p[n].email;
	cout<<"Digite o telefone: ";
	cin>> p[n].telefone;
    cout<<"Digite a idade: ";
	cin>> p[n].idade;
	cout<<"\nDados registrados...\n";
	n++;
	return n;
	}

	//METODO DE PESQUISA DE PESSOA
	void Search(Pessoa *p,int id,int n)
	{
	int i=0;
	for( i=0;i<n;i++)
	{
	   if(p[i].id==id)
    		{
		cout<<"ID\n Nome\tEmail\tTelefone\tIdade\n==============================================\n";
	    	cout<<id<<"\t"<<nome<<"\t"<<email<<"\t"<<telefone<<"\t"<<idade<<"\n";
		break;
    		}
	}
	if(p[i].id!=id)
	{
	cout<<"\nREGISTRO NÃO ENCONTRADO.\n";
	}

    }

	//METODO PARA EXIBIR O LAYOUT
	void Display(){
	cout<<id<<"\t"<<nome<<"\t"<<email<<"\t"<<telefone<<"\t"<<idade<<"\n";
	}

	//METODO PARA DELETER UM REGISTRO
	int Del(Pessoa *p,int n,int id)
	{
		int j=0,k,flag=0;
		for(j=0;j<n;j++)
		{
			if(p[j].id==id)
            {
                flag=1; //USADO FLAG PARA SINALIZAR QUANDO FOR PRECISO PARA PARAR O FOR
                break;
            }
		}
        if(flag==1)
        {
            for(k=j;k<n;k++)
            {
            p[k]=p[k+1];
            }
            cout<<"\n Registro Deletado.\n";
            return n-1;
        }
			else
			{
				cout<<"\nRegistro nao econtrado\n";
				return n;
			}
	}

	//METODO PARA ALTERAR UM REGISTRO
	int Update(Pessoa *p,int id,int n)
	{
		int i,op_menu1;
		for(i=0;i<n;i++)
		{
		if(p[i].id==id)
    		{
    			while(1){
    			cout<<"\n!!===O QUE DESEJA ALTERAR ?===!!\n";
    			cout<<"\n 1. Alterar email";
    			cout<<"\n 2. Alterar telefone";
   				cout<<"\n 3. Alterar Os dois itens acima";
   				cout<<"\n 4. Retornar ao Menu";
   				cout<<"\n\n Digite uma opcao:";
   				cin>>op_menu1;    				
				switch(op_menu1){
    				case 1: cout<<"Email:";
    						cin>>p[i].email;
    						cout<<"Email Alterado...\n";
    						break;
   					case 2: cout<<"Telefone:\t";
   							cin>>p[i].telefone;
   							cout<<"Telefone Alterado...\n";
   							break; 					
					case 3: cout<<"Email:";
							cin>>p[i].email;
							cout<<"Telefone:\t";
							cin>>p[i].telefone;
							cout<<"Telefone e Email alterado...\n";
							break;
					case 4: return n;
					default: cout<<"!! Opcao invalida !!";
							break;
					}
				}
			break;
    		}
		}
    		if(p[i].id!=id)
		{
    		cout<<"\nRegistro nao encontrado\n\n";
		}
	}
};

//MAIN QUE EXIBE O MENU PRINCIPAL DO CRUD
int main()
{
 Pessoa o[10];
 int i=0,op_menu,j,id;
 while(1)
  {
   cout<<"\n!!===CRUD DE PESSOAS===!!";
   cout<<"\n";
   cout<< "\n 1.Registrar pessoa";
   cout<< "\n 2.Procurar";
   cout<< "\n 3.Listar";
   cout<< "\n 4.Apagar";
   cout<< "\n 5.Atualizar";
   cout<< "\n 6.Sair";
   cout<< "\n\n Digite uma opcao:";
   cin>> op_menu; //CIN PEGA O DADO DIGITADO PELO USUARIO

   switch(op_menu){
     case 1: i=o[0].Insert(o,i);
               break;
     case 3: cout<<"id\tNOME\tEMAIL\tTELEFONE\tIDADE\n==============================================\n";
		for(j=0;j<i;j++){
		o[j].Display();
		}
		break;
     case 2:
		cout<<"Digite o ID que deseja procurar:";
		cin>> id;

		o[0].Search(o,id,i);

		break;
	 case 4:
		cout<<"Didige o ID que deseja apaga :";
		cin>> id;
		i=o[0].Del(o,i,id);
		break;
	 case 5:
	 	cout<<"Digite o ID que deseja atualizar:";
		cin>> id;
		i=o[0].Update(o,id,i);
		break;
	 default: cout<<"Opcao invalida!!";
	 		break;
     case 6: exit(0);
    }
  }

 }