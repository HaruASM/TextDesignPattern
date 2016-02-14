#include "default.h"
#include "objects.h"
#include "shop.h"
#include "warehouse.h"

// ##  CGameModule 
// # - 이후 모듈의 확장을 대비해 각 기능별 로직을 FSM으로 나눔
// # 멤버인 state값의 변경으로 모듈 로직 분기시킴
// # 종료도 직접 하지 말고 state값을 4로 변경
// # changeModule() 메소드로 state 변경 

class CGameModule{

        // 0. 타이틀 1.메뉴 2.게임내 3.사망 4.종료
        int state; 
        
        void runner()  // 상태에따라 로직 분기
        {
            switch(state){
                case 0:
                  title();
                  changeModule(1); // 메뉴로
                  break;
                case 1:
                  menu();
                  break;
                case 2:
                  progress();
                  break;
                case 3:
                  die();
                  break;
                default: // 상태값 오류
                 puts("state 예외");
                 printf("%d\n", state);
            }   
            
        }

        void title()
        {
            puts("Hello World!");
            puts("Welcome to git world");
            puts("빰빰빠밤~~");
        }
        
        void menu () // 메인메뉴 셀렉트
        {
            int input;
            
            puts("====메뉴====");
            puts("1. 게임시작");
            puts("0. 종료");
            puts("============");
            
            GETKEY(&input); 
            
            if( 0 == input )
             changeModule(4);
            else if( 1 == input)
             changeModule(2);

        }
        
        //## 마을 구현 부분 
        //#  사용 변수 여기 선언해 놓음
        CStage *selectField ; // 필드
        CShop  *shop ; // 상점
        CWarehouse *warehouse ; // 창고
        
        //#  주요 분기 로직 담당
        //# - 상점은 shop.h : 장희
        //# - 창고는 warehouse.h : 형민이
        
        void progress () // 게임 진행
        {
            int input;
            
            puts("====마을====");
            puts("...");
            puts("============");
            
            puts("1.사냥터 2.상점 3.창고. 0종료");
            
            if( selectField ) // 필드 출력. 
                selectField->draw();
            
            // 상점, 창고 생성, 및 초기화    
            shop = new CShop();
            shop->init();
            warehouse = new CWarehouse();
            warehouse->init();
             
            GETKEY(&input);

            if( input == 0)// 0종료
              changeModule( 4 );
            else if( input == 1) { // 사냥터 
                selectField = new CStage("사막");
            }

            else if( input == 2){ // 상점
                shop->open();
            }
             
            else if( input == 3){ // 창고
               warehouse->open();
            }
             

          
        }
        
        void die() //캐릭 사망시
        {
            //
        }
        
        void exitGame() //게임 종료
        {
            // 메모리 해제는 소멸자에서 

            puts("종료됨");
        }
        
        void changeModule(int _input)
        {
            if( this->state != _input )
                 this->state = _input;
        }
public:
        void init(int _state = 0) // 게임 초기화
        {
            this->state = _state;
        }
        
        void run()
        {

            while(state != 4){ 
                
                runner();
            }
            
            exitGame();
        }

    CGameModule(){
        selectField = NULL;
        shop = NULL;
        warehouse = NULL;
    }
    ~ CGameModule(){
            DELETE(selectField);
            DELETE(shop);
            DELETE(warehouse);
    }
};