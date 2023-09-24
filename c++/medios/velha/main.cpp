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
            playerVsCPU();
        }else{
            exit(0);
        }
    }
   void printChoice(){
    system("clear");
    cout << LINE << endl;
    cout << printComplete("qual voce escolhe? ") << endl << LINE << endl;
    cout << printLeft("[X]") << endl;
    cout << printLeft("[O]") << endl << LINE << endl << '|';
   }
   void choiceVsPlayer(VelhaPXP *velha){
    char symbol;
    do{
    printChoice();
    cin >> symbol;
    }while(!(velha->setPlayer1(symbol)));
    do{
    printChoice();
    cin >> symbol;
    }while(!(velha->setPlayer1(symbol)));
   }
   void choiceVsCpu(VelhaCPU *velha){
    char symbol;
    do{
    printChoice();
    cin >> symbol;
    }while(!(velha->setPlayer1(symbol)));
   }
   void cont(){
    char a;
    cout << printLeft("espere para conrinuar:") << endl;
    system("sleep 3");
    system("clear");
   }
   void playCPU(VelhaCPU *velha){
    int linha,coluna;
    do{
        cont();
        velha->draw();
        cin >> linha;
        cin >> coluna;
    }
    while(!velha->play(velha->getPlayer(),linha,coluna));
   }
   void playerVsCPU(){
    VelhaCPU velha;
    int linha,coluna;
    cout << GREEN;
    choiceVsCpu(&velha);
    velha.draw();
    if(velha.getCPU() == 'X'){
        do{
            cont();
            velha.playIa();
            velha.draw();
            if(velha.check() != 32 || velha.getPlays() == 9){
                break;
            }
            playCPU(&velha);
            cont();
            velha.draw();
        }while(velha.check() == 32  && velha.getPlays() != 9);

    }
    else if(velha.getPlayer() == 'X'){
        do{
            playCPU(&velha);
            cont();
            velha.draw();
            cont();
            if(velha.check() != 32 || velha.getPlays() == 9){
                break;
            }
            velha.playIa();
            velha.draw();
        }while(velha.check() == 32 && velha.getPlays() != 9);
    }
    velha.draw();
    cout << velha.check();
   }
};

int main(){
    ScreenInit inicio;
    inicio.screen();
    return 0;
}