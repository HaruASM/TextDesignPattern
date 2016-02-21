#include "default.h"
#include "pass.h"
// ## 창고 구현 ##
// # - 형민
// #

// - 형민이 이후 작업 
//  패스워드 처리 부분 클래스로 모듈화
// pass.h pass.cpp 싱글톤 적용 


class CWarehouse{
    
    
    
    public:
    // 초기 세팅
    void init(){
        
    }
    
    // 창고에 진입시 호출됨, 동기화 로직
    void open(){
        CPass pw;
        int input = -1;
        int sinput  = -1;
        int pass = 0;
        int product = 0;
        int comparepass = 0;
        int failcount = 3;
        puts("==창고==");

        while( input != 0) {
            
            puts("1.보관 2.찾기 3.PW변경 0.마을로");
            GETKEY(&input);
    
    
        }
        
    }
    
    CWarehouse(){}
    ~CWarehouse(){}
};