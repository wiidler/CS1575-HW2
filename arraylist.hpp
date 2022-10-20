// Programmer: Will Weidler
// Section: 101

#include <iostream>

using namespace std;

template <typename T>
void ArrayList<T>::grow()
{
    int maxSize = m_max * 2;
    T *tmp = new T[maxSize];
    for (int i = 0; i < m_max; i++)
    {
        tmp[i] = m_data[i];
    }
    delete[] m_data;
    m_data = tmp;
    tmp = NULL;
    m_max = maxSize;
    return;
}

template <typename T>
void ArrayList<T>::shrink()
{
    int maxSize = m_max / 2;
    T *tmp = new T[maxSize];
    for (int i = 0; i < maxSize; i++)
    {
        tmp[i] = m_data[i];
    }
    delete[] m_data;
    m_data = tmp;
    m_max = maxSize;
    tmp = NULL;
}

template <typename T>
ArrayList<T>::ArrayList(int s, const T &x)
{
    m_size = s;
    m_max = s;
    m_data = new T[m_max];
    for (int i = 0; i < m_max; i++)
    {
        m_data[i] = x;
    }
}

template <typename T>
ArrayList<T>::~ArrayList()
{
    m_size = 0;
    m_max = 0;
    delete[] m_data;
    m_data = NULL;
}

template <typename T>
ArrayList<T> &ArrayList<T>::operator=(const ArrayList<T> &rhs)
{
    m_size = rhs.m_size;
    m_max = rhs.m_max;
    delete[] m_data;
    m_data = new T[m_max];
    for (int i = 0; i < m_max; i++)
    {
        m_data[i] = rhs.m_data[i];
    }
    return *this;
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T> &cpy)
{
    m_size = cpy.m_size;
    m_max = cpy.m_max;
    m_data = new T[m_max];
    for (int i = 0; i < m_size; i++)
    {
        m_data[i] = cpy.m_data[i];
    }
}

template <typename T>
int ArrayList<T>::size() const
{
    return m_size;
}

template <typename T>
const T &ArrayList<T>::first() const
{
    if (m_size == 0)
    {
        cout << "!!! ERROR : PANIC in ARRAYLIST !!!.first()  (List is empty)" << endl;
        return m_errobj;
    }
    else
    {
        return m_data[0];
    }
}

template <typename T>
T &ArrayList<T>::operator[](int i)
{
    if ((i >= m_size) || (i < 0))
    {
        cout << "!!! ERROR : PANIC in ARRAYLIST !!!.[]  (index out of bounds)" << endl;
        return m_errobj;
    }
    else
    {
        return m_data[i];
    }
}

template <typename T>
const T &ArrayList<T>::operator[](int i) const
{
    if ((i >= m_size) || (i < 0))
    {
        cout << "!!! ERROR : PANIC in ARRAYLIST !!!" << endl
             << "The given index is outside the scope of the seleced array." << endl;
        return m_errobj;
    }
    else
    {
        return m_data[i];
    }
}

template <typename T>
int ArrayList<T>::search(const T &x) const
{
    for (int k = 0; k < m_size; k++)
    {
        if (m_data[k] == x)
            return k;
    }
    return -1;
}

template <typename T>
void ArrayList<T>::clear()
{
    delete[] m_data;
    m_max = 4;
    m_size = 0;
    m_data = new T[m_max];
}

template <typename T>
void ArrayList<T>::insert_back(const T &x)
{
    if (m_size == m_max)
    {
        this->grow();
    }
    m_data[m_size] = x;
    m_size++;
}
template <typename T>
void ArrayList<T>::insert(const T &x, int i)
{
    if (m_size == m_max)
    {
        this->grow();
    }
    if (0 <= i && i < m_size)
    {
        for (int k = m_size; k > i; k--)
        {
            m_data[k] = m_data[k - 1];
        }
        m_data[i] = x;
        m_size++;
        return;
    }
    else
    {
        cout << "!!! ERROR : PANIC in ARRAYLIST !!!.insert()  (index out of bounds)" << endl;
    }
}

template <typename T>
void ArrayList<T>::remove(int i)
{
    if (0 <= i && i < m_size)
    {
        if (m_size < (m_max / 4))
        {
            this->shrink();
        }
        for (int k = i; k < m_size - 1; k++)
        {
            m_data[k] = m_data[k + 1];
        }
        m_size--;
        return;
    }
    else
    {
        cout << "!!! ERROR : PANIC in ARRAYLIST !!!.remove()  (index out of bounds)" << endl;
        return;
    }
}

template <typename T>
void ArrayList<T>::swap(int i, int k)
{
    if (0 <= i && i < m_size && 0 <= k && k < m_size)
    {
        T tmp;
        tmp = m_data[i];
        m_data[i] = m_data[k];
        m_data[k] = tmp;
        return;
    }
    else
    {
        cout << "!!! ERROR : PANIC in ARRAYLIST !!!.swap()  (index out of bounds)" << endl;
    }
}

template <typename T>
void ArrayList<T>::purge()
{
    for (int i = 0; i < m_size; ++i)
        for (int j = i + 1; j < m_size;)
        {
            if (m_data[i] == m_data[j])
            {
                for (int k = j; k < m_size - 1; ++k)
                    m_data[k] = m_data[k + 1];
                --m_size;
            }
            else
                ++j;
        }
}

template <typename T>
void ArrayList<T>::reverse()
{
    int temp;
    for (int i = 0; i < m_size / 2; i++)
    {
        temp = m_data[i];
        m_data[i] = m_data[m_size - i - 1];
        m_data[m_size - i - 1] = temp;
    }
}