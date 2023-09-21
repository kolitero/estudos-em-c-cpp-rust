#include "output.hpp"

using namespace std;

void screen();

int main(){
    screen();
    return 0;
}

void screen(){
    cout << MAGEN << LINE << endl << printComplete("jogo da velha") << endl << LINE << endl;
    cout  << printLeft("opcoes:") << endl;
    cout  << printLeft("[0] player vs player") << endl;
    cout  << printLeft("[1] opcoes") << endl << LINE << endl;

}
