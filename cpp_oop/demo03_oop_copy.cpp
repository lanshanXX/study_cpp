#include <iostream>

using namespace std;






//禁止使用memcpy realloc
class Queue
{
public:
    Queue(int size = 20)
    {
        _pQue = new int[size];
        _front = 0;
        _rear = 0;
        _size = size;
    }
    Queue(const Queue& que)
    {
        _size = que._size;
        _front = que._front;
        _rear = que._rear;
        _pQue = new int[_size];
        for (int i = _front; i != _rear; i = (i + 1) % _size)
        {
            _pQue[i] = que._pQue[i];
        }
    }
    Queue& operator=(const Queue& que)
    {
        if (this != &que)
        {
            delete[] _pQue;
            _size = que._size;
            _front = que._front;
            _rear = que._rear;
            _pQue = new int[_size];
            for (int i = _front; i != _rear; i = (i + 1) % _size)
            {
                _pQue[i] = que._pQue[i];
            }
        }else
        {
            return *this;
        }
        return *this;
    }
    ~Queue()
    {
        delete[] _pQue;
        _pQue = nullptr;
    }
    void addQue(int val)
    {
        if ((_rear + 1) % _size == _front)
        {
            cout << "队列已满" << endl;
            return;
        }
        _pQue[_rear] = val;
        _rear = (_rear + 1) % _size;
    }
    void pop()
    {
        if (empty())
        {
            cout << "队列为空" << endl;
            return;
        }
        _front = (_front + 1) % _size;
    }
    int getFront()
    {
        return _pQue[_front];
    }
    bool full()
    {
        return (_rear + 1) % _size == _front;
    }
    bool empty()
    {
        return _front == _rear;
    }
    void resize()
    {
        int *ptmp = new int[_size * 2];
        int index = 0;
        for(int i = _front; i != _rear; i = (i + 1) % _size)
        {
            ptmp[index++] = _pQue[i];
        }
        delete[] _pQue;
        _pQue = ptmp;
        _front = 0;
        _rear = index;
        _size *= 2;
    }
private:
    int* _pQue; //申请队列的数组空间
    int _front; //队头
    int _rear;  //队尾
    int _size;  //队列的大小

}