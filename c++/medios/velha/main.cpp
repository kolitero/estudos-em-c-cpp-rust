#include "velha.hpp"

//colors
const char* BLUE =  "\x1B[34m";
const char* GREEN = "\x1B[32m";
const char* RED  = "\x1B[31m";

class  ScreenInit{
    public:
        char x;
    //exibir a menu inicial
    void screenDraw(){
        std::cout << BLUE << LINE << '\n' << printComplete("jogo da velha") << '\n' << LINE << '\n';
        std::cout  << printLeft("opcoes:") << '\n';
        std::cout  << printLeft("[0] Player vs Player") << '\n';
        std::cout  << printLeft("[1] Player vs CPU") << '\n';
        std::cout  << printLeft("[2] sair") << '\n' << LINE << '\n';
        std::cout  << printLeft("digite uma opcao:") << '\n' << "|";
        std::cin >> x;
    }
    //rederecionar aos metodos corrrespondente presente no menu inicial 
    void screen(){
        do{
            system("clear");
            screenDraw();
            cont();
        }while(x < '0' || x > '2');
        if(x == '0'){
            playerXP();
        }else if(x == '1'){
            playerVsCPU();
        }else{
            exit(0);
        }
    }
    //exibir a pergunta de qual simbolo o player y vai usar
   void printChoice(){
    system("clear");
    std::cout << LINE << '\n';
    std::cout << printComplete("qual voce escolhe? ") << '\n' << LINE << '\n';
    std::cout << printLeft("[X]") << '\n';
    std::cout << printLeft("[O]") << '\n' << LINE << '\n' << '|';
   }
   //escolher os simbolos do player 1 e 
   void choiceVsPlayer(VelhaPXP *velha){
    char symbol;
    do{
    std::cout << LINE << '\n' << printComplete("player 1") << '\n' << LINE << '\n';
    printChoice();
    std::cin >> symbol;
    cont();
    }while(!(velha->setPlayer1(symbol)));
    do{
    std::cout << LINE << '\n' << printComplete("player 2") << '\n' << LINE << '\n';
    printChoice();
    std::cin >> symbol;
    cont();
    }while(!(velha->setPlayer2(symbol)));
   }
   void choiceVsCpu(VelhaCPU *velha){
    char symbol;
    do{
    printChoice();
    std::cin >> symbol;
    }while(!(velha->setPlayer1(symbol)));
   }
   void cont(){
    char a;
    std::cout << printLeft("espere para conrinuar:") << '\n';
    system("sleep 3");
    system("clear");
   }
   void playCPU(VelhaCPU *velha){
    int linha,coluna;
    do{
        cont();
        velha->draw();
        std::cout << "|linha:";
        std::cin >> linha;
        std::cout << "|coluna:";
        std::cin >> coluna;
    }
    while(!velha->play(velha->getPlayer(),linha,coluna));
   }
   void playPlayer1(VelhaPXP *velha){
    int linha,coluna;
    do{
        cont();
        std::string ask = "vez do player 1:";
        std::cout << LINE << '\n' << printComplete(ask.append(std::string{(char)velha->getPlayer1()})) << '\n';
        velha->draw();
        std::cout << "|linha:";
        std::cin >> linha;
        std::cout << "|coluna:";
        std::cin >> coluna;
    }
    while(!velha->play(velha->getPlayer1(),linha,coluna));
   }
   void playPlayer2(VelhaPXP *velha){
    int linha,coluna;
    do{
        cont();
        std::string ask = "vez do player 2:";
        std::cout << LINE << '\n' << printComplete(ask.append(std::string{(char)velha->getPlayer2()})) << '\n';
        velha->draw();
        std::cout << "|linha:";
        std::cin >> linha;
        std::cout << "|coluna:";
        std::cin >> coluna;
    }
    while(!velha->play(velha->getPlayer2(),linha,coluna));
   }
   void playerVsCPU(){
    VelhaCPU velha;
    int linha,coluna;
    std::cout << GREEN;
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
    std::cout << velha.check();
   }
   void playerXP(){
    printChoice();
    VelhaPXP velha;
    void (ScreenInit::*func1)(VelhaPXP*),(ScreenInit::*func2)(VelhaPXP*);
    int linha,coluna;
    std::cout << RED;
    choiceVsPlayer(&velha);
    if(velha.getPlayer1() == 'X'){
        func1 = &ScreenInit::playPlayer1;
        func2 = &ScreenInit::playPlayer2;;
    }else{
        func1 = &ScreenInit::playPlayer2;;
        func2 = &ScreenInit::playPlayer1;;
    }
    do{
        (this->*func1)(&velha);
        cont();
        velha.draw();
        if(velha.check() != 32 || velha.getPlays() == 9){
            break;
        }
        (this->*func2)(&velha);
        cont();
        velha.draw();
        cont();
    }while(velha.check() == 32  && velha.getPlays() != 9);
   }
};

int main(){
    ScreenInit inicio;
    inicio.screen();
    return 0;
}