#include "default.h"

// ## 상점 구현 ##
// # - 장희
// #

class CShop{
    
    
    
    public:
    // 초기 세팅
    void init(){}
    
    // 상점에 진입시 호출됨, 동기화 로직
    void open(){
        
        int input = -1;
        
        puts("==ㅇㅇ 상점==");

        while( input != 0) {
            
            puts("1.  0.마을로");
            GETKEY(&input);
    
        }
        
    }
    
    CShop(){}
    ~CShop(){}
};