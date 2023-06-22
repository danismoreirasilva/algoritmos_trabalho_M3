#include <iostream>

using namespace std;

#define tamMax 10

int main()
{
    setlocale(LC_ALL, "portuguese");

    int n = 0, vetIdade[tamMax], posMenor = 0, posIdoso = 0, menorIdade, maisIdoso, contMulheres = 0, somaIdadeF = 0;
    char vetSexo[tamMax], opcao;
    string vetNome[tamMax];
    bool temMaisVelho = false;

    do{
        do{
            cout << endl;
            cout << "====================== Menu ======================" << endl;
            cout << "(a) - Informar o valor de n e os dados das pessoas" <<endl;
            cout << "(b) - Consultar os dados da pessoa mais nova" <<endl;
            cout << "(c) - Consultar o nome e a idade do homem mais velho" <<endl;
            cout << "(d) - Consultar a média das idades das mulheres" <<endl;
            cout << "(e) - Sair" <<endl;
            cout << "==================================================" << endl;
            cout << "Escolha a opção desejada: ";
            opcao = tolower(cin.get());
            cin.ignore();
            if(opcao<'a'||opcao>'e')
                cout<<"Opção inválida! "<<"Selecione uma das opções abaixo."<<endl;
        }while(opcao<'a'||opcao>'e');

        switch(opcao){
        case 'a':
            do{
                cout <<"Digite a quantidade de pessoas (de 1 até 10): ";
                cin >> n;
                cin.ignore();
                if(n<1||n>10) cout<<"Valor inválido. Deve ser digitado um valor entre 1 e 10"<<endl;
            }while(n<1||n>10);

            for(int i=0; i<n; i++){
                cin.ignore();
                cout<<"Digite o "<<i+1<<"º nome: ";
                getline(cin, vetNome[i]);
                do{
                    cout << "Digite o sexo: ";
                    vetSexo[i] = tolower(cin.get());
                    cin.ignore();
                    if (vetSexo[i]!='f' && vetSexo[i]!='m') cout<<"Sexo inválido. Digite novamente."<<endl;
                }while(vetSexo[i]!='f' && vetSexo[i]!='m');

                do{
                    cout << "Digite a idade: ";
                    cin >> vetIdade[i];
                    cin.ignore();
                }while(vetIdade[i]<1||vetIdade[i]>120);

            }

            //reiniciando as variaveis caso seja escolhida a opção "a" dentro do menu após ;
            somaIdadeF = 0;
            contMulheres = 0;
            temMaisVelho = false;
            break;
        case 'b':
                if (n>0){
                    menorIdade = vetIdade[0];
                    for (int i=0; i<n; i++){
                        if(vetIdade[i] <= menorIdade){
                            posMenor = i;
                            menorIdade = vetIdade[i];
                        }
                    }
                    cout <<endl<<"Dados da pessoa mais nova: "<<endl;
                    cout <<"Nome: "<<vetNome[posMenor]<<"."<<endl;
                    cout <<"Sexo: "<<vetSexo[posMenor]<<"."<<endl;
                    cout <<"Idade: "<<vetIdade[posMenor]<<"."<<endl;
                    cout <<endl;
                }else{
                    cout << endl <<"Não há registros no vetor!"<<endl;
                }
            break;
        case 'c':
                if (n>0){
                    maisIdoso = vetIdade[0];
                    for (int i=0; i<n; i++){
                        if (vetSexo[i]=='m'){
                            if(vetIdade[i] >= maisIdoso){
                                posIdoso = i;
                                maisIdoso = vetIdade[i];
                                temMaisVelho = true;
                            }
                        }
                    }
                    if (temMaisVelho){
                        cout <<endl<<"Dados da Homem mais velho: "<<endl;
                        cout <<"Nome: "<<vetNome[posIdoso]<<"."<<endl;
                        cout <<"Idade: "<<vetIdade[posIdoso]<<"."<<endl;
                        cout <<endl;
                    }else{
                        cout <<endl<<"Não há dados de pessoas do sexo masculino."<<endl;
                    }

                }else{
                    cout << endl <<"Não há registros no vetor!"<<endl;
                }
            break;
        case 'd':
                if (n>0){
                    for (int i=0; i<n; i++){
                        if(vetSexo[i] == 'f'){
                            somaIdadeF += vetIdade[i];
                            contMulheres++;
                        }
                    }

                    if(contMulheres>0){
                        cout << "A média de idade das mulheres é de "<<float(somaIdadeF)/contMulheres<<" anos.";
                    }else{
                        cout << endl <<"Não há dados de pessoas do sexo feminino!"<<endl;
                    }
                }else{
                    cout << endl <<"Não há registros no vetor!"<<endl;
                }
            break;
        case 'e':
                cout<<"Você saiu do sistema!"<<endl;
                break;
        }

    }while(opcao!='e');

    return 0;
}


