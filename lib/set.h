#ifndef set_h
#define set_h

template<typename T>
struct Entry {
    T data;
    Entry<T>* next;
};

template<typename T>
class Set {
public:
    static Entry<T>* init(T t){
        Entry<T>* box = new Entry<T>();
        box->data = t;
        box->next = NULL;
        return box;
    }
  
    static void push(Entry<T>** entry, T t){
        Entry<T>* box = new Entry<T>;
        box->data = t;
        box->next = (*entry)->next;
        (*entry)->next = box;
    }

    
    static void free(Entry<T>* from) {
        if(from->next != NULL)
            free(from->next);
        delete from;
    }
};

#endif
