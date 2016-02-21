#include "default.h"

// ## 패스워드 ##
// # - 형민
// #


class CPass{
    
    int pass = 0;
    int failcnt = 3;
    
    public:
    
        bool isMatch(int o_pass,int i_pass){
            if(o_pass == i_pass) return true;
            return false;
        }
        
        int getFailCnt(){
           return failcnt; 
        }
    
        void setPW(int o_pass,int i_pass){
            int pw;
            if(pass != 0){
                
                if(isMatch(o_pass,i_pass)){
                    GETKEY(&pw);
                    pass = pw;
                }else{
                    
            }
            } else {
                 pass = i_pass;
            }
        
        }
        
        
        
    private:
        void cntDown(){
            failcnt--;
        }
        
    public:
  CPass(){}
    ~CPass(){}
};