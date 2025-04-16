#include<iostream>
using namespace std;

class Stack
{
    int size; 
    int top;
    int *s;

    public:
    Stack(int size)
    {
        this->size = size;
        top = -1;
        s = new int[size];
    }

    void push(int x);
    int pop();
    int peek(int index);
    int isEmpty();
    int isFull();
    int stackTop();

    ~Stack()
    {
        delete []s;
    }
};

void Stack::push(int x)
{
    if (top == size - 1)
    {
        cout<<"Stack OVerflow"<<endl;
    }
    else{
        top++;
        s[top] = x;
    }
}

int Stack::pop()
{
    if (top == -1)
    {
        cout<<"Stack Underflow"<<endl;
    }
    else
    {
        cout<<s[top]<<" popped out"<<endl;
        top--;
    }
    return s[top + 1];
    
}

int Stack::peek(int index)
{
    if (top - index + 1 < 0)
    {
        return -1;
    }
    else 
    {
         return s[top - index + 1];
    }
}

int Stack::isEmpty()
{
    return top == -1;
}

int Stack::isFull()
{
    return top == size - 1;
}

int Stack::stackTop()
{
    if (top == -1)
    {
        return -1;
    }
    else
    {
        return s[top];
    }
}


int main()
{
    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    cout<<st.pop()<<endl;
    cout<<st.peek(2)<<endl;
    cout<<st.isEmpty()<<endl;
    cout<<st.isFull()<<endl;
    cout<<st.stackTop()<<endl;
    
    return 0;
}