#include <iostream>

using namespace std;

#define tamMax 10

int main()
{
    setlocale(LC_ALL, "portuguese");

    int matM[tamMax][tamMax], n, contL0, contL1, contC0, contC1, contLC;

    do{
        cout << "Digite o valor de n entre 1 e 10: ";
        cin >> n;
        if (n<1||n>tamMax) cout <<endl<<"Valor inválido. Digite um valor entre 1 e 10."<<endl;
    }while(n<1||n>tamMax);

    //leitura a matriz
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout<<"Digite o valor ("<<i+1<<","<<j+1<<"): ";
            cin >> matM[i][j];
        }
    }

    //analisando a matriz
    for (int i=0; i<n; i++){
      contL0 = 0;
      contL1 = 0;
      contC0 = 0;
      contC1 = 0;
        for (int j=0; j<n; j++){
            if(matM[i][j]==0)contL0++;
            else if(matM[i][j]==1)contL1++;

            if (matM[j][i]==0)contC0++;
            else if(matM[j][i]==1) contC1++;

        }

        //se a linha a coluna estiverem atendendo a regra incrementa 1;
        if ((contL0==n-1)&&(contL1==1)&&(contC0==n-1)&&(contC1==1)){
            contLC++;
        }
    }

     //saída da matriz
    cout<<endl<<"Saída da matriz M"<<endl;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout<<"["<<matM[i][j]<<"]";
        }
        cout<<endl;
    }

    //a quantidade de linhas e colunas atendendo a regra deve ser igual a ordem da matriz;
    if(contLC==n) cout<<"A Matriz M é de permutação!"<<endl;
    else cout<<"A Matriz M não é de permutação!"<<endl;

    return 0;
}
