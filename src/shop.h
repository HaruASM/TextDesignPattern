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
        int buyinput = -1;
        int answer;
        puts("==ㅇㅇ 상점==");

        while( input != 0) {
            
            puts("1.구매 2.판매  0.마을로");
            GETKEY(&input);
            
            if(input == 1)
            {
                puts("1.체력포션 2.마나포션 3.스테미나포션 4.음식 5.구매종료");
                GETKEY(&buyinput);
                switch(buyinput)
                {
                    case 1:
                    puts("체력포션을 구매하시겠습니까? (Y=0 / N=1)");
                    break;
                    
                    case 2:
                    puts("마나포션을 구매하시겠습니까? (Y=0 / N=1)");
                    break;
                    
                    case 3:
                    puts("스테미나포션을 구매하시겠습니까? (Y=0 / N=1)");
                    break;
                    
                    case 4:
                    puts("음식을 구매하시겠습니까? (Y=0 / N=1)");
                    break;
                    
                    case 5:
                    puts("구매를 종료하시겠습니까? (Y=0 / N=1)");
                    break;
                }
                
                GETKEY(&answer);
                
                if(answer == 0)
                {
                    puts("구매하셨습니다.");
                    answer = -1;
                    buyinput = -1;
                }
                
                else if(answer == 1)
                {
                    puts("거절하셧습니다.");
                    answer = -1;
                    buyinput = -1;
                }
            }
        }
        
    }
    
    CShop(){}
    ~CShop(){}
  
};


