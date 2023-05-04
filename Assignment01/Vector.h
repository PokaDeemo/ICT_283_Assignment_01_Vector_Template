#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

/**
   * @class Vector
   * @brief Vector Class is created as a vector template to store the data inside into
   * @brief into a vector array. With our own vector function that we created.
   * @author Tan Hong Rui Freeman
   * @version 01
   * @date 6/10/2022 Freeman Tan, Started
   *
   */

using namespace std;

template <class T>
class Vector
{
public:
    Vector(); //default constructor
    /**
    * @brief Default Constructor for Vector
    * An default constructor that is calling the realloc() function at private.
    */

    ~Vector(); //destructor
    /**
    * @brief destructor for the vector
    * An destructor that is use to call Clear() and delete to release the memory or vector memory.
    */

    void realloc(int newCapacity); //moving of elements in vector for push back
    /**
    * @brief realloc function
    * @param Is use to moving of the elements in the vector for the PushBack() function
    * @post moving the element at the vector
    */

    void PushBack(const T& value); //add element to vector
    /**
    * @brief PushBack function at vector.
    * @param Is to Add elements into the vector and increase their size of it.
    * @post m_size++ is increased.
    */

    void popBack(); //remove one element from vector
    /**
    * @brief PopBack function at vector.
    * @param to remove one element from the vector and it will decrease the size of it.
    * @post m_size++ is decrease.
    */

    void Clear(); //to clear all memory from vector
    /**
    * @brief Clear function at vector
    * @param Is to clear all memory from the vector and release it. So m_size will be empty.
    * @post m_size++ is empty.
    */

    T At(int i) const; //find location of item
    /**
    * @brief at function at vector
    * @param Is to find an location of the item or data inside the vector.
    * @post return the item into m_list.
    */

    Vector<T>& operator[](int index) const; //return size of array (constant)
    /**
    * @brief T& operator[] function.
    * @param Is to return the size of the array but with constant.
    * @post return the size of the array to m_list[index].
    */

    Vector<T>& operator[](int index); //return size of array
    /**
    * @brief T& operator[] function.
    * @param Is to return the size of the array but without the constant.
    * @post return the size of the array to m_list[index].
    */

    int Size() const;
    /**
    * @brief size function
    * @param to return the size of the vector m_size
    * @post return the m_size size
    */

    Vector<T>& operator=(const Vector<T>& copyVec); //copy constructor
    /**
    * @brief Copy Constructor function
    * @param It is responsible for deep copy when the copy constructor is declare and being used
    * @post Copy the vector element to another vector element
    */

    void printList() const;
    /**
    * @brief print vector function
    * @param It is responsible for printing out the vector element when the function is called.
    * @post printing the vector and each of the elements inside the vector.
    */


private:
    T *m_list = nullptr;
    int m_size=0;
    int m_capacity=0;
};

template <class T>
void Vector<T>:: realloc(int newCapacity) // realloc method It will keep realloc the memory to the new capacity. It is also to check if there is any capacity for it.
{
    T* newArray = new T[newCapacity];

    if (newCapacity < m_size)
    {
        m_size = newCapacity;
    }

    for(int i =0; i< m_size; i++)
    {
        newArray[i]  = (m_list[i]);
    }
    delete[] m_list;
    m_list = newArray;
    m_capacity = newCapacity;
}

template <class T>
Vector<T>::Vector()
{
    realloc(5);
}

template <class T>
Vector<T>::~Vector()
{
    Clear();
    delete[] m_list;
    m_list = nullptr;
}

template <class T>
void Vector<T>::Clear()
{
    for(int i = 0; i < m_size; i++)
    {
        m_list[i].~T();
    }
    m_size = 0;
    delete[] m_list;
}

template <class T>
void Vector<T>::PushBack(const T& value)
{
    if(m_size >= m_capacity)
    {
        realloc(m_capacity + m_capacity/2);
    }
    m_list[m_size] = value;
    m_size++;
}

template <class T>
void Vector<T>::popBack()
{
    if(m_size > 0)
    {
        m_size--;
        m_list[m_size].~T();
    }
}

template <class T>
T Vector<T>::At(int i) const
{
    if((i >= 0) && (i<m_size))
    {
        return m_list[i];
    }
}

template <class T>
int Vector<T>::Size() const
{
    return m_size;
}

template <class T>
Vector<T>& Vector<T>::operator[](int index) const //return size of array (constant)
{
    return m_list[index];
}

template <class T>
Vector<T>& Vector<T>::operator[](int index) //return size of array
{
    return m_list[index];
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& copyVec)
{
    if(this != &copyVec)
    {
        //~Vector();
        m_size = copyVec.m_size;
        m_capacity = copyVec.m_capacity;
        m_list = new T[m_capacity];
        for(int i =0; i<m_size; i++)
        {
            m_list[i] = copyVec.m_list[i];
        }
    }
    return *this;
}

template <class T>
void Vector<T>::printList() const
{
    for(int i=0; i<m_capacity; i++)
    {
        cout << m_list[i] << endl;
    }
}
#endif // Vector_H
