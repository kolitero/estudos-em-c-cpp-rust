#include <iostream>

using namespace std;

void entrada();

//progarama para testar entrada e saida

int main(){
    entrada();
    return 0;
}

// recebe dois numeros na entrada e soltar a soma na saida

void entrada(){
    int x,y;
    cout << "digite dois numeros:" << endl;
    cin >> x >> y;
    cout << x+y << endl;
}