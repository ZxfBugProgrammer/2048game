#include "Draw.h"
#include <iostream>
#include <iomanip>

void Draw::PrintNumAlignCenter(int num, int w) {
    int len=0,tnum=num;
    while(tnum)
    {
        tnum/=10;
        len++;
    }
    if(w<len)
    {
        std::cout<<"ERROR"<<std::endl;
        return;
    }
    w-=len;
    for(int i=0;i<w-w/2;i++)
        std::cout<<' ';
    std::cout<<num;
    for(int i=0;i<w/2;i++)
        std::cout<<' ';
}

void Draw::PrintUi() {
    int sorce = 10, best = 100;
    int a[4][4]={32768,2,4,16,64,128,1024,2048,32,4096,8192,16384,8,32,4,512};
    std::cout<<"            HAPPY!     SCORE: "<<std::setw(6)<<sorce<<"     BEST: "
    <<std::setw(6)<<best<<"     !HAPPY"<<std::endl;
    std::cout<<"            ----------------------------------------------------"<<std::endl;
    std::cout<<std::endl<<std::endl;
    std::cout<<"                       |------|------|------|------|"<<std::endl;

    for (int i = 0; i < 4; i ++) {
        std::cout<<"                       |";
        for(int j = 0; j < 4; j ++) {
            PrintNumAlignCenter(a[i][j],6);
            std::cout<<("|");
        }
        std::cout<<std::endl;
        std::cout<<"                       |------|------|------|------|"<<std::endl;
    }

    std::cout<<std::endl<<std::endl;
    std::cout<<"            ----------------------------------------------------"<<std::endl;
    std::cout<<"              [W]:UP  [S]:DOWN  [A]:LEFT  [D]:RIGHT  [Q]:EXIT"<<std::endl;
}

Draw::Draw() = default;
