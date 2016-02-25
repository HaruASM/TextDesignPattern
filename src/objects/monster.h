#pragma once

// 네임스페이스로 나눌 것인가 


namespace monster {
    


    // 데이터만 다룰때 구조체
    struct tMonStatus{
      char* name;
      int maxhp;
      int hp;
      int ap;
      int dp ;
    };
    
        
    
  class CMonster{

    tMonStatus status ; // has a
   
    public: 
    
    void say(){
        
        printf("%s", this->status.name  );
        
    }
    
    CMonster(){}
    CMonster(tMonStatus _status){
        this->status = _status ;
    }
    ~ CMonster(){}
    
    }; 
    
    
    // 현재 클래스 CMonsterDB의 인스턴스 1개만 필요
    // 싱클톤 쓸까? 
    //  static 영역에 인스턴스 1개 생성, 네임스페이스로 접근 
    //  monster::DB 
    //  다른 인스턴스 생성제한은 이름 없는네임스페이스(anonymous namespace) 로 
    
     namespace {
        
        class CMonsterDB{

        public:
        void ok(){
            puts("ok DB ");
            
        }
        
    
        CMonsterDB(){
            
            
        }
        ~CMonsterDB(){}

        };
        
     } // 익명 

     static CMonsterDB DB;  // monster::DB.메소드  사용
      
}// monster
