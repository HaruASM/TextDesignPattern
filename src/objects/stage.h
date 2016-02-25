
#include "../default.h"
#include "monster.h"

using namespace monster;

class CStage {
    
    protected :
     const char *name; // 문자열 상수 이용
    
    //이 enum은 상속받는 애들만 사용가능
     enum  {
        MAXSIZE_MONDB = 3,
        MAXSIZE_MON = 5
     };
    
     CMonster* monDB[MAXSIZE_MONDB]; // flyweight
     CMonster* monInStage[MAXSIZE_MON];

    public:
        const char* getname(){
            return name;
        }
        virtual void draw() 
        {
            printf("-=%s=-\n" , name );
            
            for( int i = 0 ; i < MAXSIZE_MON ; ++i)
            monInStage[i]->say();
            puts("보인다");

            //puts("1.친다 2.비켜간다 3.마을로");
            
            //1 전투
            //2 다음 몹 
            //3 == 마을 == 화면
            
            

        }
        
  
        
        void innerStage(){
            
            int input = -1;
            while(input){
                
                draw();
                inputkey(input);
                update();
                
            }

        }
        virtual void open(){}; 
        virtual void init() = 0;
        virtual void inputkey(int& input) {
            
            GETKEY(&input);
            
        }
        virtual void update() = 0;
        
        
    CStage():name("none"){}
    CStage(const char* _name): name(_name){}
    virtual ~CStage(){
        
        for(int i = 0 ; i < MAXSIZE_MON ; ++i)
          if( monInStage[i] ){
            delete monInStage[i];    
             monInStage[i] = NULL;
         }
          
    }
};


// 사막
class CDesertStage : public CStage {
  
  
  
    public :
        virtual void init() {

          // 몬스터 할당 
          for( int i = 0 ; i < MAXSIZE_MON ; ++i){
            
            // DB 위치는?
            //monInStage[i] =  monDB[ rand()%MAXSIZE_MONDB ];
            
          }
        
        }
        virtual void update() {}
        
        
  
  CDesertStage(const char* _name): CStage(_name){}
  CDesertStage():CStage("사막"){
      
  }
  ~ CDesertStage(){}
};



//Base - 멥 선택, 매니저 역활
class CBaseStage : public CStage {
    
    enum {
        DESERT,
        PLAIN,
        SEA,
        SIZE_BASE,
    };
    CStage* base[SIZE_BASE];
    
    public :

    virtual void draw(){
        
        for( int i = 0; i < SIZE_BASE ; ++i)
        printf( "%d %s ", i, base[i]->getname() );
        
        monster::DB.ok();
        
    }
    
    virtual void init() {
        // CStage 형제 할당 
          
        base[DESERT] = new CDesertStage();
        base[PLAIN] = new CDesertStage("초원");
        base[SEA] = new CDesertStage("바다");
    }
    
    virtual void update() {}
    
    void open(){
        int input;
        
        draw();
        puts("\n사냥터 선택"); 
        //input();
        GETKEY(&input);
        puts("유료결제하세요");
        GETKEY(&input);
    }
    
    CBaseStage():CStage("베이스") {}
    ~CBaseStage() {
            for( int i=0; i < SIZE_BASE; ++i ){
                DELETE(base[i]);
            }

    }
};
