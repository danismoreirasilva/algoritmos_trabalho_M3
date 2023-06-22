#include <iostream>

using namespace std;

#define tamMax 10

int main()
{
    setlocale(LC_ALL, "portuguese");

    int vetB[tamMax] = {0}, x, p;

    for(int i=0; i<tamMax-1;i++){
        cout<<"Digite o "<<i+1<<"º valor: ";
        cin >>vetB[i];
    }

    cout << endl << "Digite um valor de x: ";
    cin>>x;

    do{
        cout<<"Digite a posição para inserir o valor de x: ";
        cin >>p;
        if(p<0||p>tamMax-2)cout<<"Posição inválida. O valor deve estar entre 0 e 8"<<endl;
    }while(p<0||p>tamMax-2);


    for(int i=8; i>=p; i--){
        vetB[i+1]=vetB[i];
    }

    vetB[p] = x;

    cout << endl<< "Vetor preenchido com valor de X ="<<x<<", na posição ["<< p<<"] "<<endl;
    for(int i=0; i<tamMax;i++){
        cout<<"["<<vetB[i]<<"] ";
    }


    return 0;
}
