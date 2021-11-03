#pragma once
#ifndef SDDS_SEARCHNLIST_H
#define SDDS_SEARCHNLIST_H
#include "Collection.h"
#include <iostream>
using namespace std;
namespace sdds {
    /*This template has two types because first is accepting the object, while the other is accepting character string or double or integer, therefore we need two types.*/
    template<typename T, typename K>
    bool search(Collection<T>& obj, const T* arr, int num, const K key) {
        bool ok = false;

        for (int i = 0; i < num; i++)
        {
            if (arr[i] == key) {
                ok = true;
                obj.add(arr[i]);
            }
        }

        return ok;
    }

    /*This template has only one type since the fucntion needs to accept just one object and it is not compared to anything, hence there is no need in more types in the template.*/
    template<typename T>
    void listArrayElements(const char* title, const T obj[], int num) {
        cout << title << endl;

        for (int i = 0; i < num; i++)
        {
            cout << i + 1 << ": " << obj[i] << endl;
        }
    }
}
#endif // !SDDS_SEARCHNLIST_H