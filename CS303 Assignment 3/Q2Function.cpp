/*
#include "Q2Function.h"

//Function definition - find the last occurence of the target in the vector
int linear_search(vector<int>& items, int target, size_t pos_last) {
    if (pos_last == size_t(-1))
        return -1;

    if (items[pos_last] == target)
        return pos_last;

    return linear_search(items, target, pos_last - 1);
}
*/