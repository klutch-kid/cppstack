#include <iostream>
#include <string>
// Depending on compiler
//#include <cstdlib>

using namespace std;


struct Node // Node structure
{
    string data;
    Node *next;
};


class Stack 
{
    public:
        Stack(); // Constructor
        ~Stack(); // Deconstructor
        void push(string d); // Push node to top of the stack
        string pop();// Pop the top node off top of the stack
        string toString(); // Display stack contents from top to bottom
        
        bool isEmpty(); // Determine if stack is empty
    private:
        Node *top; // Top of the stack
};


Stack::Stack() // Init empty stack
{
    top = NULL;
}


Stack::~Stack() // Deconstructor to delete dynamic variables
{
    while (!isEmpty())
        pop();
}


void Stack::push(string d) // Push data
{
    Node*temp = new Node; // Build the node
    temp->data = d;
    temp->next = top;
    
    top = temp; // Point to to the new top of the stack
}


string Stack::pop() // Pop data
{
    if (!isEmpty())
    {
        string value = top->data;
        Node *oldtop = top;
        top = oldtop->next;
        delete oldtop;
        return value;
    } 
    else 
    {
        cout << "Can't pop an empty stack!" << endl;
        exit(1);
    }
    return "empty";
}


string Stack::toString() // Display the stack contents
{
    string result = "(top) ->";
    if (isEmpty())
    {
        result = result + "empty";
        return result;
    } else {
        Node *current = top;
        while (current != NULL)
        {
            result = result + current->data + "->";
            current = current->next;
        }
        result = result + "(end)";
        return result;
    }
}


bool Stack::isEmpty() // Check if stack is empty
{
    return (top == NULL);
}


int main() 
{
    Stack *newStack = new Stack();
    cout << "Output if empty: " << endl
        << newStack->toString() << endl;
    newStack->push("Nut Brown Ale");
    newStack->push("Apple Wine");
    newStack->push("IPA");
//    newStack->pop();
    cout << "Output if not empty: " << endl
        << newStack->toString() << endl;
    
    delete newStack;
    return 0;
}
