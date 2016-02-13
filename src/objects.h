#include "default.h"

class CStage {
    
    const char *name; // 문자열 상수 이용
    
    public:
        virtual void draw()
        {
            printf("-=%s=-\n" , name );
            printf("%s가 보인다\n", "토끼");
            puts("1.친다 2.비켜간다 3.마을로");
            
            //1 전투
            //2 다음 몹 
            //3 == 마을 == 화면
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