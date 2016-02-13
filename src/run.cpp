#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include <ncurses.h>

// 매크로 선언
#define PAUSE() getchar()
#define DELETE(x) delete (x); (x) = NULL ;

class CStage {
    
    const char *name; // 문자열 상수 이용
    
    public:
        virtual void draw()
        {
            printf("-=%s=-\n" , name );
        }
        
    CStage():name("none"){}
    CStage(const char* _name): name(_name){}
    ~CStage(){}
};


class CMonster  {

    public:
    
    void draw(){
        puts("M : monster");
    }
    
    CMonster(){}
    ~CMonster(){}
};

class CPlayer  {
    
    public:
    
    void draw(){
        puts("P : player");
    }
    
    CPlayer(){}
    ~CPlayer(){}
};

int main(){

    puts("Hello World!");
    puts("Welcome to git world");
	puts("Welcome!"); // 서재영

    //
    int input = 0;
	
	// 초기화
    CStage  *anystage = new CStage("SEA") ;
    CMonster  *anymob = new CMonster();
    CPlayer  *newbie = new CPlayer();

    //
    while(1)    {
        puts("");

        anystage->draw();
        anymob->draw();
        newbie->draw();
        
        puts("1.사냥터 2.상점 3.창고. 0종료");
        if( '0' == (input = getchar()) )
            break;
            
        puts("사냥터입니다");
        
    }


    puts("종료됨");
    
    DELETE( anystage );
    DELETE( anymob );
    DELETE( newbie );
    return 0;
}