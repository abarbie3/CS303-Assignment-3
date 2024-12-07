#include "Q3Function.h"

//Sort list using insertion sort
void insertion_sort(list<int>& vals) {

//Checks if list is empty
    if (vals.empty()) {
        cout << "The list is empty." << endl;
    }
    else {
        //Display if list only has one value
        if (vals.size() == 1) {
            cout << "The sorted list is: " << vals.front() << endl;
        }
        else {
            //Create iterator
            cout << "The sorted list is: " << endl;
            list<int>::iterator iter1, iter2;
            int key;
            bool insertionNeeded;

            //Iterate through list
            for (iter2 = next(vals.begin()); iter2 != vals.end(); ++iter2) {
                key = *iter2; //Store the value to be sorted
                insertionNeeded = false;

                //Find the right position for the key
                for (iter1 = prev(iter2); iter1 != vals.begin(); iter1--) {
                    if (key < *iter1) {
                        *next(iter1) = *iter1;
                        insertionNeeded = true;
                    } else {
                        break;
                    }
                }
                //Insert key at the right position
                if (insertionNeeded) {
                    *next(iter1) = key;
                } 
            }
            //Display the sorted list
            for (int val : vals) {
                cout << val << " ";
            }
            cout << endl;
        }
    }
}
