#ifndef data_h
#define data_h

struct Data
{
    Data() {}
    int N, // Heads count
        M, // Tails count
        S, // Position of flipping coins
        K, // Steps number
        L, // Heads remain
    
        A, // Coins sum number
        B, // Balance (>0 ~ need flip Heads, <0 ~ need flip Tails)
        H, // Already set Heads count
        T; // Already set Tails count

    void fill();
};

#endif
