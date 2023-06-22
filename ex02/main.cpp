#include <iostream>

using namespace std;

#define tamMax 10

int main()
{
    setlocale(LC_ALL, "portuguese");

    int vetB[tamMax], vetC[tamMax] = {0};
    int posVetC = 0, valor, contRepetidos;

    cout <<endl<<"Prencha os dados do vetor "<<endl;
    for(int i=0; i<tamMax; i++){
        do{
            cout <<"Digite o "<<i+1<<"º valor: ";
            cin >> vetB[i];
            if(vetB[i]<0)
                cout <<"Valor inválido. Digite um inteiro e positivo."<<endl;
        }while(vetB[i]<0);
    }

    for(int i=0; i<tamMax; i++){
        valor = vetB[i];
        contRepetidos = 0;

        for (int j=0; j<tamMax; j++){
            if(valor == vetB[j])
               contRepetidos++;
        }

        if(contRepetidos==1){
            vetC[posVetC]= valor;
            posVetC++;
        }
    }

    if (posVetC>0){
        cout << endl << "*** Vetor C ***" << endl;
        for (int i=0; i<posVetC; i++){
            cout << "[" << vetC[i]<<"] ";
        }
    }else{
        cout << "Vetor C vazio!!!" << endl;
    }

    return 0;
}
