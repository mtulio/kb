ARQUIVO VOLTADO PARA RASCUNHO 
QUE PODE SER APROVEITADO FUTURAMENTE


//RASCUNHO PRINCIPAL.CPP:
//cout<<" teste de criação da fila: ";
    /*if(fila==0) cout<<"Fila não criada"<<endl;
    else cout<<" Fila criada"<<endl;*/

    if(fila==0){
                fila = new Fila();
                if(fila) cout<<"  Fila criada"<<endl;
                else cout<<"Fila não criada"<<endl;
    }
    else cout<<" Fila ja esta criada"<<endl;
    
    
    //Adicionar
    cout<<endl<<"----------------------"<<endl;
    cout<<"  TESTE ADICIONAR"<<endl;
      
    bool id=false;
    while(!id){
       NoRequisicao *cliente = new NoRequisicao();
       cout<<" Digite o nome: ";
       string nome;
       cin>>nome;
       
       //cliente->nome_cli=nome;
       cout<<"  ID: ";
       cin>>id;
       cliente->atribuirNome(nome);
       if(fila->adicionar(cliente)) cout<<"\t\tADD"<<endl;
       
    }
    
    //recuperando
    //cout<<"  RECUPERANDO "<<endl;
    /*for(; !fila->estaVazio(); ){
          NoRequisicao *cliente = new NoRequisicao();
          fila->retirar(cliente);
          cout<<" nome: "<<cliente->nome_cli<<endl;
          cout<<"  ID: "<<cliente->identificadorInicio<<endl;
                  
    }*/
    cout<<endl<<"----------------------"<<endl;
    //testando  a busca na fila
    cout<<"  TESTE DE BUSCA" <<endl;
    //NoRequisicao *cliente = new NoRequisicao();
    cout<<"  Digite o nome pra procurar: ";
    string nome;
    cin>>nome;
    
    //ControleFila ctrl;
    NoRequisicao *cliente = new NoRequisicao();
    if(ControleFila::busca(nome, fila, cliente )){
       //fila->retirar(cliente);
       cout<<" NOme encontrado: "<<cliente->obterNome()<<endl;
    }
    else cout<<" nome nao encontrado"<<endl;                      
    
    
    //delete cliente;
    
    
    if(fila->estaVazio()) cout<<" \n\t FILA VAZIA"<<endl;
    
