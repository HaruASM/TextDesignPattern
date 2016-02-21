#include "gamemodule.h"

int main(){
    
    srand((unsigned) time(NULL));

    CGameModule game;
    
    game.init(0);
    game.run();
    
    return 0;
}