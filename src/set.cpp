//
//  set.cpp
//  Coins
//
//  Created by admin on 12/12/2019.
//  Copyright © 2019 vanderkast. All rights reserved.
//

#include <stdio.h>

#include "../lib/set.h"

template<typename T>
Entry<T>* Set<T>::init(T t){
    Entry<T>* box = new Entry<T>();
    box->data = t;
    box->next = NULL;
    return box;
}

template<typename T>
void Set<T>::push(Entry<T>** entry, T t){
    Entry<T>* box = new Entry<T>;
    box->data = t;
    box->next = entry->next;
    entry->next = box;
}

template<typename T>
void Set<T>::free(Entry<T>* from) {
    if(from->next != NULL)
        free(from->next);
    delete from;
}
