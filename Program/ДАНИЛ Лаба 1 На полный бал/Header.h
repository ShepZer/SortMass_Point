#pragma once

#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>
template <typename T>
class Array {

private:

    T* array;
    size_t capacity;
    size_t CAP;

public:

    Array();
    ~Array();
    Array(const Array& a);
    Array& operator=(const Array& v);
    Array& operator[](size_t index);

    void set();
    void get();
    void size();
    T at(size_t index);
    void erase(size_t index);
    void push();
    void sorted_array(size_t capacity);
    void error(size_t index);

};


template <typename T>
Array<T>::Array() {

    capacity = 10;
    CAP = 0;
    array = new T[capacity];

}


template <typename T>
Array<T>::Array(const Array& a) {

    capacity = a.capacity;
    array = new T[capacity];

    for (int i = 0; i < capacity; i++) {
        array[i] = a.array[i];
    }

}


template <typename T>
Array<T>& Array<T>:: operator=(const Array& v) {

    if (this == v) {
        return *this;
    }

    capacity = v.capacity;
    array = new T[capacity];

    for (int i = 0; i < capacity; i++) {
        array[i] = v.array[i];
    }

    return *this;

}


template <typename T>
Array<T>& Array<T>::operator[](size_t index) {

    return array[index];

}


template <typename T>
void Array<T>::sorted_array(size_t capacity) {

    for (int i = 0; i < capacity - 1; ++i) {

        int min = i;

        for (int j = i + 1; j < capacity; ++j) {
            if (array[j] < array[min]) {
                min = j;
            }
        }
        swap(array[i], array[min]);
    }

}


template <typename T>
void Array<T>::push() {

    T NewEl;

    if (CAP < capacity) {

        cout << "Enter a new element: ";
        cin >> NewEl;

        array[CAP++] = NewEl;

        cout << "Array after adding element: ";

        sorted_array(CAP);
        get();

    }
    else {
        cout << "Unable to add item (array overflowed)" << endl << endl;
        throw (1);
    }
}


template <typename T>
void Array<T>::size() {

    int MemorySize = CAP * sizeof(T);

    cout << "Memory occupied: " << MemorySize << endl << endl;

}


template <typename T>
void Array<T>::erase(size_t index) {

    error(index);

    for (int j = index; j < capacity - 1; j++) {
        array[j] = array[j + 1];
    }

    CAP--;
    cout << "Array after deletion: ";
    get();

}


template <typename T>
T Array<T>::at(size_t index) {

    error(index);
    return(array[index]);

}


template <typename T>
void Array<T>::error(size_t index) {

    if (index > CAP || index < 0) {
        cout << "ERROR" << endl;
        throw (1);
    }
}


template <typename T>
void Array<T>::get() {

    for (int i = 0; i < CAP; i++) {
        cout << " " << array[i];
    }

    cout << endl; cout << endl;

}


template <typename T>
void Array<T>::set() {

    T a;
    cout << "How many elements do you want to enter (the number must not exceed capacity (" << capacity << "): ";
    cin >> CAP;

    while (CAP > capacity) {
        cout << "   ERROR  \nThe entered value is greater than capacity or is negative" << endl;
        cout << "Try again: ";
        cin >> CAP;
    }

    cout << endl;
    cout << "Enter the elements of the array: ";

    for (int i = 0; i < CAP; i++) {
        cin >> a;
        array[i] = a;
    }

    sorted_array(CAP);

    cout << "\nArray: ";
    get();
}


template <typename T>
Array<T>::~Array() {

    delete[] array;

}


struct point {

    int x = 0;
    int y = 0;
    int z = 0;

    point() {
        int x = 0;
        int y = 0;
        int z = 0;
    }

    friend ostream& operator<<(ostream& Cout, const point& point) {
        Cout << "point (" << point.x << ", " << point.y << ", " << point.z << ")" << endl;
        return Cout;
    }

    friend istream& operator>>(istream& Cin, point& point) {
        cout << "x = ";
        Cin >> point.x;

        cout << "y = ";
        Cin >> point.y;

        cout << "z = ";
        Cin >> point.z;
        cout << endl;
        return Cin;
    }

    friend bool operator<(const point& p1, const point& p2) {
        
        if (p1.x < p2.x) {
            return p1.x < p2.x;
        }
        else {
            if (p1.y < p2.y) {
                return p1.y < p2.y;
            }
            else {
                return p1.z < p2.z;
            }
        }
    }

    int operator=(const int a) {
        this->x = a;
        this->y = a;
        this->z = a;
    }

};

