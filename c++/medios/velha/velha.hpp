#include "output.hpp"

//clase base para VelhaPXP e VelhaCPU

class Velha
{
protected:
    enum symbols{trash = ' ',circle = 'O',x = 'X'};
    symbols array[3][3];
    int jogadas;
    void resetGame(){
        for(int x = 0;x<3;x++){
            for(int y = 0;y<3;y++)
                array[x][y] = trash;
        }
        jogadas = 0;
    }
public:
    void play(symbols player,int l,int c){
            array[l][c] = player;
            jogadas++;
        }
    void draw(){
        //std::system("clear");
        std::cout << LINE << '\n';
        std::cout << printLeft("colunas:             0|1|2") << '\n';
        for(int x = 0;x<3;x++){
            std::cout  << "|linha:" << x << "              ";
            for(int y = 0;y<3;y++){
                std::cout <<  char(array[x][y]);
                if(y!=2){
                    std::cout << "|";
                }
            }
            std::cout << "                      |" << '\n';
        }
        std::cout << LINE << '\n';
    }
    Velha(){
        resetGame();
    }
    //checar se o jogo ja tem um vencedor e retorno o simbolo do vencedor
    symbols check(){
        for(int x = 0;x<3;x++){
            if(array[x][0] == array[x][1] && array[x][1] == array[x][2] && array[x][0] != trash){
                return array[x][0];
            }
        }
        for(int x = 0;x<3;x++){
            if(array[0][x] == array[1][x] && array[1][x] == array[2][x] && array[0][x] != trash){
                return array[x][0];
            }
        }
        if(array[0][0] == array[1][1] && array[1][1] == array[2][2] && array[1][1] != trash){
            return array[1][1];
        }
        if(array[0][2] == array[1][1] && array[1][1] == array[2][0]  && array[1][1] != trash){
            return array[1][1];
        }
        return trash;
    }
    
};

// classe para cotrolar o jogo da velha player vs computador

class VelhaCPU : public Velha{
    private:
        symbols player;
        symbols cpu;
        void reset(){
            resetGame();
            player = trash;
            cpu = trash;
        }
        //checar se alguem vai vencer e a ia jogar no espaco vencedor tanto para impedir a derrota como para vencer
        int playCompleteIA(symbols p){
            //horizontal
            for(int x = 0;x<3;x++){
                if(array[x][0] == trash && array[x][1] == p && array[x][2] == p){
                    play(cpu,x,0);
                    return 1;
                }
                if(array[x][0] == p && array[x][1] == trash && array[x][2] == p){
                    play(cpu,x,1);
                    return 1;
                }
                if(array[x][0] == p && array[x][1] == p && array[x][2] == trash){
                    play(cpu,x,2);
                    return 1;
                }
            }
            //vertical
            for(int x = 0;x<3;x++){
                if(array[0][x] == trash && array[1][x] == p && array[2][x] == p){
                    play(cpu,0,x);
                    return 1;
                }
                if(array[0][x] == p && array[1][x] == trash && array[2][x] == p){
                    play(cpu,1,x);
                    return 1;
                }
                if(array[0][x] == p && array[1][x] == p && array[2][x] == trash){
                    play(cpu,2,x);
                    return 1;
                }
            }
            // '\'
            if(array[0][0] == trash && array[1][1] == p && array[2][2] == p){
                 play(cpu,0,0);
                 return 1;
            }
            if(array[0][0] == p && array[1][1] == trash && array[2][2] == p){
                 play(cpu,1,1);
                 return 1;
            }
            if(array[0][0] == p && array[1][1] == p && array[2][2] == trash){
                 play(cpu,2,2);
                 return 1;
            }
            // '/'
            if(array[0][2] == trash && array[1][1] == p &&  array[2][0] == p){
                play(cpu,0,2);
                return 1;
            }
            if(array[0][2] == p && array[1][1] == trash &&  array[2][0] == p){
                play(cpu,1,1);
                return 1;
            }
            if(array[0][2] == p && array[1][1] == p &&  array[2][0] == trash){
                play(cpu,2,0);
                return 1;
            }
            return 0;
        }
        //primeira jogada da  
        int playFirstIa(){
            int p;
            int opt[4][2] {{0,0},{0,2},{2,0},{2,0}};
            while(true){
                p = std::rand() %4;
                if(array[opt[p][0]][opt[p][1]] == trash){
                    play(cpu,opt[p][0],opt[p][1]);
                    return 1;
                }
            }
        }
        int playRand(){
            int p;
            int opt[9][2] {{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2}};
            while(true){
                p = std::rand() %9;
                if(array[opt[p][0]][opt[p][1]] == trash){
                    play(cpu,opt[p][0],opt[p][1]);
                    return 1;
                }
            }
        }
    public:
        bool setPlayer1(char n){
            if(n == circle && n != cpu){
                player = circle;
                cpu = x;
                return true;
            }else if(n == x  && n != cpu){
                player = x;
                cpu = circle;
                return true;
            }
            return false;
        }
        symbols getPlayer(){
            return player;
        }
        symbols getCPU(){
            return cpu;
        }
        int playIa(){
            if(jogadas == 0 || jogadas == 1){
                playFirstIa();
                return 1;
            }
            else if(playCompleteIA(getCPU())){
                return 1;
            }
            else if(playCompleteIA(getPlayer())){
                return 1;
            }
            else{
                playRand();
                return 1;
            }
        }
        VelhaCPU(){
            reset();
        }
};

// classe para controlar o jogo da velha entre dois players

class VelhaPXP : public Velha{
    private:
        symbols player1;
        symbols player2;
        void reset(){
            resetGame();
            player1 = trash;
            player2 = trash;
        }
    public:
        symbols getPlayer1(){
            return player1;
        }
        symbols getPlayer2(){
            return player1;
        }
        bool setPlayer1(char n){
            if(n == circle && n != player2){
                player1 = circle;
                return true;
            }else if(n == x  && n != player2){
                player1 = x;
                return true;
            }
            return false;
        }
        bool setPlayer2(char n){
            if(n == circle && n != player1){
                player2 = circle;
                return true;
            }else if(n == x && n != player1){
                player2 = x;
                return true;
            }
            return false;
        }
        VelhaPXP(){
            reset();
        }
};