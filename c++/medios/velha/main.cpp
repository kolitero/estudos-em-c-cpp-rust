#include "velha.hpp"

using namespace std;


class  ScreenInit{
    public:
        char x;
    void screenDraw(){
        cout << BLUE << LINE << endl << printComplete("jogo da velha") << endl << LINE << endl;
        cout  << printLeft("opcoes:") << endl;
        cout  << printLeft("[0] Player vs Player") << endl;
        cout  << printLeft("[1] Player vs CPU") << endl;
        cout  << printLeft("[2] sair") << endl << LINE << endl;
        cout  << printLeft("digite uma opcao:") << endl << "|";
        cin >> x;
    }
    void screen(){
        do{
            system("clear");
            screenDraw();
        }while(x < '0' || x > '2');
        if(x == '0'){
            //chamar player vs player
        }else if(x == '1'){
            //chamar player vs Cpu
        }else{
            exit(0);
        }
    }
};

int main(){
    ScreenInit inicio;
    inicio.screen();
    Velha velha;
    velha.draw();
    return 0;
}