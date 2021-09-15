// #include <iostream>
// using namespace std;

// class stack
// {
//     int size;
//     int top;
//     int *array;

// public:
//     stack(int n)
//     {
//         size = n;
//         array = new int[n];
//         top = -1;
//     }

//     bool isEmpty()
//     {
//         if (top == -1)
//             return 1;
//         else
//             return 0;
//     }
//     bool isFull()
//     {
//         if (top == size)
//             return 1;
//         else
//             return 0;
//     }
//     void push(int val)
//     {
//         if (top == (size -1 ))
//         {
//             cout << "overflow condition" << endl;
//         }
//         else
//         {
//             *(array + (++top)) = val;
//         }
//     }
//     int peek()
//     {
//         if(top < 0)
//            cout<<"NO peek"<<endl;
//            else
//         return *(array + top);
//     }
//     void pop()
//     {
//         if(top<0)
//          cout<<"underflow condition"<<endl;
//          else
//         top--;
//     }
//     void show()
//     {
//         int c = top;
//         while (c >= 0)
//         {
//             printf("%d ", *(array + c));
//             c--;
//         }
//         printf("\n");
//     }
// };

// int main()
// {
//     int n;
//     cout << "Enter the size of the array" << endl;
//     cin >> n;
//     stack s(n);
//     s.push(5);
//     s.push(1);
//     s.push(3);
//     s.show();
//     return 0;
// }

///      Stack by linked list

#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *link;
};

class linklist
{

    node *cur, *head, *temp;

public:
    linklist()
    {
        head = NULL;
    }
    void push(int val)
    {
        temp = new node[sizeof(node)];
        temp->data = val;
        temp->link = NULL;
        if (head == NULL)
        {
            head = temp;
            cur = temp;
        }
        else
        {
            cur->link = temp;
            cur = temp;
        }
    }

    void show()
    {
        node *c = head;
        while (c != NULL)
        {
            cout << c->data << " ";
            c = c->link;
        }
        cout << endl;
    }
    node *head_ref()
    {
        return head;
    }
};

class stack
{

    node *cur, *top;

public:
    stack()
    {
        top = NULL;
    }
    bool isEmpty()
    {
        if (top == NULL)
            return 1;
        else
            return 0;
    }
    void push(int val)
    {
        cur = new node[sizeof(node)];
        cur->data = val;
        cur->link = top;
        top = cur;
    }
    void pop()
    {
        if (top != NULL)
        {
            node *del = top;
            top = top->link;
            delete del;
        }
        else
            cout << "Stack is empty" << endl;
    }
    int peek()
    {
        if (top != NULL)
        {
            return top->data;
        }
        else
        {
            return -1;
        }
           
    }
    void show()
    {
        node *c = top;
        while (c != NULL)
        {
            cout << c->data << " ";
            c = c->link;
        }
        cout << endl;
    }
};

stack s;
linklist list;

void pallindrome(node *head)
{
    if (head != NULL)
    {
        if (head->data == s.peek())
            s.pop();
        pallindrome(head->link);
       
    }
    
}
int main()
{
    int n, temp;

    cout << "Enter the size of the number  : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        list.push(temp);
        s.push(temp);
    }
    list.show();
    pallindrome(list.head_ref());
    if(s.isEmpty())
      cout<<"pallindrome";
      else
      cout<<"not pallindrome";
    return 0;
}
