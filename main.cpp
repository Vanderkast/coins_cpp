// 10
// По кругу расположено N монет лицом вниз и M монет лицом вверх. Проходя по часовой стрелке, начинаая с монеты лицом вверх, переворачивая каждую S монету. Указать расположение монет, при котором через K ходов останется L монет лицом вверх

#include <iostream>

#include "lib/data.h"
#include "lib/coin.h"
#include "lib/set.h"

using namespace std;

static char* ERROR_MESSAGE =
    (char*) "При заданных параметрах невозможно решить задачу";

void fill(const Data& data, bool*);
void proceed(Data& data, Entry<State>*, const bool*);
void pushCoinOnNeedFlip(Data&, Entry<State>** top);
void pushCoinOnNotNeedFlip(Data& data, Entry<State>** top);

int main(int argc, const char *argv[])
{
    Data data;
    data.fill();
    
    bool* needFlip = new bool[data.A];
    fill(data, needFlip);
    
    Entry<State>* begin = Set<State>::init(HEAD);

    try {
        proceed(data, begin, needFlip);
    } catch (char* msg){
        cout << msg;
        return 0;
    }
    
    Entry<State>* boxx = begin;
    do {
        cout << (boxx->data == HEAD ? "H " : "T ");
    } while((boxx = boxx->next) != NULL);
    
    Set<State>::free(begin);
    return 0;
}

void fill(const Data& data, bool* needFlip) {
    for(int i = 0; i < data.A; ++i)
        needFlip[i] = false;
    
    int box;
    if(data.S == 1) // т.к. (i * data.S - 1) % data.A ~ 0, при S = 1
        for (int i = 1; i <= data.K; ++i)
            needFlip[i] = i % data.A;
    else
        for (int i = 1; i <= data.K; ++i) {
            box = (i * data.S - 1) % data.A;
            needFlip[box] = !needFlip[box];
        }
}

void proceed(Data& data, Entry<State>* begin, bool* needFlip) {
    Entry<State>** top = new Entry<State>*();
    *top = begin;
    
    for(int i = 1; i < data.A; ++i){
        if(needFlip[i]){
            pushCoinOnNeedFlip(data, top);
        } else {
            pushCoinOnNotNeedFlip(data, top);
        }
    }
    
    delete top;
    
    if(data.B != 0)
        throw ERROR_MESSAGE;
}

void pushCoinOnNeedFlip(Data& data, Entry<State>** top) {
    if(data.B > 0){
        if(data.H++ == data.N)
            throw ERROR_MESSAGE;
        Set<State>::push(top, HEAD);
        data.B--;
    } else {
        if(data.T++ == data.M)
            throw ERROR_MESSAGE;
        Set<State>::push(top, TAIL);
        data.B++;
    }
}

void pushCoinOnNotNeedFlip(Data& data, Entry<State>** top){
    if(data.B > 0){
        if(data.T == data.M){
            Set<State>::push(top, HEAD);
            ++data.H;
        } else {
            Set<State>::push(top, TAIL);
            ++data.T;
        }
    } else {
        if(data.H == data.N){
            Set<State>::push(top, TAIL);
            ++data.T;
        } else {
            Set<State>::push(top, HEAD);
            ++data.H;
        }
    }
}
