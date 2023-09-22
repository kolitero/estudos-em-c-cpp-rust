#include "output.hpp"

class Velha
{
protected:
    enum symbols{trash = ' ',circle = 'O',x = 'X'};
    symbols array[3][3];
    int jogadas;
    void reset(){
        for(int x = 0;x<3;x++){
            for(int y = 0;y<3;y++)
                array[x][y] = trash;
        }
        jogadas = 0;
    }
public:
    void draw(){
        std::system("clear");
        std::cout << LINE << '\n';
        for(int x = 0;x<3;x++){
            std::cout  << "|                     ";
            for(int y = 0;y<3;y++){
                std::cout << char(array[x][y]) << '|';
            }
            std::cout << "                     |" << '\n';
        }
        std::cout << LINE << '\n';
    }
    Velha(){
        reset();
    }
    symbols check(){
        for(int x = 0;x<3;x++){
            if(array[x][0] == array[x][1] && array[x][1] == array[x][2]){
                return array[x][0];
            }
        }
        for(int x = 0;x<3;x++){
            if(array[0][x] == array[1][x] && array[1][x] == array[2][x]){
                return array[x][0];
            }
        }
        if(array[0][0] == array[1][1] && array[1][1] == array[2][2]){
            return array[0][0];
        }
        if(array[0][2] == array[1][1] && array[1][1] == array[2][0]){
            return array[0][0];
        }
        return trash;
    }
    
};

class VelhaCPU : public Velha{
    private:
        symbols player;
        symbols cpu;
};

class VelhaPXP : public Velha{
    private:
        symbols player1;
        symbols player2;
};


