#ifndef coin_h
#define coin_h

enum State {
    HEAD,
    TAIL,
};

struct Coin {
    State state;
    
    Coin();
    
    Coin(State);
    
    void flip();
};

#endif
