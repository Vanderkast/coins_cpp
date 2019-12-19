//
//  coin.cpp
//  Coins
//
//  Created by admin on 12/12/2019.
//  Copyright © 2019 vanderkast. All rights reserved.
//

#include <stdio.h>

#include "../lib/coin.h"

Coin::Coin(){
    this->state = HEAD;
}

Coin::Coin(State state){
    this->state = state;
}

void Coin::flip(){
    this->state = this->state == HEAD ? TAIL : HEAD;
}
