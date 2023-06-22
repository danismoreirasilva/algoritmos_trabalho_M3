#include <iostream>
#include <ctime>

using namespace std;

#define tamMax 5
#define tamVet 25

int main()
{

    setlocale(LC_ALL, "portuguese");

    int matM[tamMax][tamMax], m, n, num, maior, menor, somaImpares = 0, lMaior,cMaior,lMenor, cMenor;
    int vet[tamVet], contImpar = 0;


    do{
        cout << "Digite o valor de M entre 1 e 5: ";
        cin >> m;
        if (m<1||m>tamMax) cout <<endl<<"Valor inválido. Digite um valor entre 1 e 5."<<endl;
    }while(m<1||m>tamMax);

    do{
        cout << "Digite o valor de N entre 1 e 5: ";
        cin >> n;
        if (n<1||n>tamMax) cout <<endl<<"Valor inválido. Digite um valor entre 1 e 5."<<endl;
    }while(n<1||n>tamMax);

    srand(time(NULL));

    //leitura da matriz
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            num = rand()%10;
            matM[i][j] = num;
        }
    }

    //Soma ímpares:
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if(matM[i][j]%2==1){
                somaImpares+= matM[i][j];
                vet[contImpar] = matM[i][j];
                contImpar++;
            }
        }
    }

    //Pega coordenadas:
    maior = matM[0][0];
    menor = matM[0][0];
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if(matM[i][j]>=maior){
                lMaior = i;
                cMaior=j;
                maior = matM[i][j];
            }
            else{
                if (matM[i][j]<=menor){
                     lMenor = i;
                     cMenor = j;
                     menor = matM[i][j];
                }
            }
        }
    }

    //Saída da matriz gerada:
    cout << endl << "Matriz Ordem "<<m<<"X"<<n<<" com dados aleatórios " << endl;
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            cout<<"["<< matM[i][j]<<"]";
        }
        cout << endl;
    }

    cout << endl;

    cout <<"A soma de todos os números ímpares é: "<<somaImpares<<endl;
    cout <<"Os ímpares são: ";
    for(int i=0; i<contImpar; i++){
        cout<<"["<<vet[i]<<"] ";
    }
    cout << endl;
    cout <<"O maior elemento "<<maior<<" está na coordenada ("<<lMaior+1<<","<<cMaior+1<<")"<<endl;
    cout <<"O menor elemento "<<menor<<" está na coordenada ("<<lMenor+1<<","<<cMenor+1<<")"<<endl;
    return 0;
}
