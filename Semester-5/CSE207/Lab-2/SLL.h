#include <iostream>
#include "Node.h"
using namespace std;

class SLL
{
private:
    Node *head = NULL, *ref;
    int length = 0;

public:
    SLL() {}

    void add(int value)
    {
        ref = new Node(value);
        if (head == NULL)
        {
            head = ref;
            length++;
        }
        else
        {
            Node *temp = head;
            while (temp->ref != NULL)
            {
                temp = temp->ref;
            }
            temp->ref = ref;
            length++;
        }
    }

    void addBeginning(int value)
    {
        Node *neue = new Node(value);
        if (head == NULL)
        {
            head = neue;
            length++;
        }
        else
        {
            Node *temp = head;
            head = neue;
            neue->ref = temp;
            length++;
        }
    }

    void addTo(int position, int value)
    {
        try
        {
            if (position == 0)
                this->addBeginning(value);
            else if (position < length - 1)
            {
                Node *neue = new Node(value);
                Node *prev = head, *current = head;

                for (int i = 1; i <= position; i++)
                {
                    prev = current;
                    current = current->ref;
                }
                prev->ref = neue;
                neue->ref = current;
                length++;
            }
            else if (position == (length))
                this->add(value);
            else
                throw invalid_argument("Query length is 'Out of bound'.");
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << "\n\t\t\t";
        }
    }

    bool contains(int value)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->item == value)
            {
                return true;
            }
            else
            {
                temp = temp->ref;
            }
        }
        return false;
    }

    int size()
    {
        return length;
    }

    bool isEmpty()
    {
        return length == 0;
    }

    int get(int position)
    {
        int res;
        if (!((length == 0) && (position >= length)))
        {
            Node *temp = head;
            for (int i = 1; i <= position; i++)
            {
                temp = temp->ref;
            }
            res = temp->item;
            return res;
        }
        else
            throw invalid_argument("No Item fond at the provided index: " + position);
    }

    int indexOf(int value)
    {
        Node *temp = head;
        int indx = 0;
        bool found = false;
        while (temp != NULL)
        {
            if (temp->item == value)
            {
                found = true;
                break;
            }
            else
            {
                indx++;
                temp = temp->ref;
            }
        }
        if (found)
            return indx;
        else
            throw invalid_argument("Item not found");
    }

    void removeFirst()
    {
        try
        {
            if (head != NULL)
            {
                head = head->ref;
                this->length--;
            }
            else
                throw invalid_argument("No data found to remove");
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    void removeLast()
    {
        try
        {
            if (head != NULL)
            {
                if (length == 1)
                {
                    head = NULL;
                    this->length--;
                }
                else
                {
                    Node *temp = head;
                    Node *last;
                    while (temp->ref != NULL)
                    {
                        last = temp;
                        temp = temp->ref;
                    }
                    last->ref = NULL;
                    this->length--;
                }
            }
            else
                throw invalid_argument("No data found to remove");
        }
        catch (const exception &e)
        {
            cerr << e.what() << '\n';
        }
    }

    void remove(int position)
    {
        try
        {
            if (head != NULL && (position < length))
            {
                if (position == 0)
                {
                    head = NULL;
                    this->length--;
                }
                else if (position == length - 1)
                {
                    this->removeLast();
                }
                else
                {
                    Node *temp = head;
                    for (int i = 1; i < position; i++)
                    {
                        temp = temp->ref;
                    }
                    Node *next = temp->ref->ref;
                    temp->ref = next;
                    this->length--;
                }
            }
            else
                throw invalid_argument("No data found to remove");
        }
        catch (const exception &e)
        {
            cerr << e.what() << '\n';
        }
    }

    void reverse()
    {
        if (length > 0)
        {
            SLL *sll = new SLL();
            for (int i = length - 1; i >= 0; i--)
            {
                sll->add(this->get(i));
            }
            this->length = 0;
            this->head = NULL;
            for (int i = 0; i < sll->length; i++)
            {
                int x = sll->get(i);
                this->add(x);
            }
        }
        else
            cerr << "Add some element first to do reverse operation";
    }

    void sort()
    {
        for (int i = 0; i < this->length - 1; i++)
        {
            Node *current = this->head, *next = this->head->ref;
            for (int j = 0; j < this->length - i - 1; j++)
            {
                if (current->item > next->item)
                {
                    int tem = current->item;
                    current->item = next->item;
                    next->item = tem;
                }
                current = next;
                next = next->ref;
            }
        }
    }

    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->item << "\t";
            temp = temp->ref;
        }
        cout << endl;
    }
};