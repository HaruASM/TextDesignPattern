#include "default.h"

// ## 창고 구현 ##
// # - 형민
// #

class CWarehouse{
    
    
    
    public:
    // 초기 세팅
    void init(){}
    
    // 창고에 진입시 호출됨, 동기화 로직
    void open(){
        
        int input = -1;
        
        puts("==ㅇㅇ 창고==");

        while( input != 0) {
            
            puts("1.  0.마을로");
            GETKEY(&input);
    
        }
        
    }
    
    CWarehouse(){}
    ~CWarehouse(){}
};