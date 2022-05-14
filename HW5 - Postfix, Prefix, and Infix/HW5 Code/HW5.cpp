#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <math.h>
#include <cmath>
#include<bits/stdc++.h>
using namespace std;


class Stack //stack for type char
{
    public:
        Stack();
        char top();
        char pop();
        void add(char data);
        int size();

    private:
        struct Node
        {
            char data;
            Node* Previous;
        };
        int Size;
        Node* Top;
};

Stack::Stack()
{
    Top = nullptr;
    Size = 0;
}

char Stack::top()
{
    if(Top != nullptr)
    {
        return Top->data;
    }
    else
    {
        return '`';
    }
}

char Stack::pop()
{
    if(Top != nullptr)
    {
        char data = Top->data;
        Top = Top->Previous;
        Size--;
        return data;
    }
    else
    {
        return '`';
    }
}

void Stack::add(char data)
{
    Node* newnode = new Node;
    newnode->Previous = Top;
    newnode->data = data;
    Size++;
    Top = newnode;

}

int Stack::size()
{
    return Size;
}


class Stack_float  //stack for type float
{
    public:
        Stack_float();
        float top();
        float pop();
        void add(float data);
        int size();

    private:
        struct Node
        {
            float data;
            Node* Previous;
        };
        int Size;
        Node* Top;
};

Stack_float::Stack_float()
{
    Top = nullptr;
    Size = 0;
}

float Stack_float::top()
{
    if(Top != nullptr)
    {
        return Top->data;
    }
    else
    {
        return -1;
    }
}

float Stack_float::pop()
{
    if(Top != nullptr)
    {
        float data = Top->data;
        Top = Top->Previous;
        Size--;
        return data;
    }
    else
    {
        return -1;
    }
}

void Stack_float::add(float data)
{
    Node* newnode = new Node;
    newnode->Previous = Top;
    newnode->data = data;
    Size++;
    Top = newnode;

}

int Stack_float::size()
{
    return Size;
}



int priority(char x)
{
    if (x == '^')
        return 3;
    else if (x == '*' || x == '/')
        return 2;
    else if (x == '+' || x == '-')
        return 1;
    else
        return -1;
}

bool isOperator(char x){
    if(x == '+' || x == '*' || x == '/' || x == '-' || x == '^')
        return true;
    else
        return false;
}

string infixToPostfix(string Infix)
{
    Stack Operators;
    string Postfix;
    for(int i = 0; i<Infix.length(); i++)
    {
        if(Infix[i] == '(')
        {
            Operators.add(Infix[i]);
        }
        else if(Infix[i] == ')')
        {
            while(Operators.top() != '(' && Operators.size() != 0)
            {
                Postfix += Operators.pop();
            }
            char remove = Operators.pop(); // removes the '('
        }
        else if(isOperator(Infix[i]))
        {
            while(Operators.size() != 0 && priority(Infix[i]) <= priority(Operators.top()))
            {
                Postfix += Operators.pop();
            }
            Operators.add(Infix[i]);
        }
        else
        {
            Postfix += Infix[i];
        }
    }

    while(Operators.size() != 0){
        Postfix += Operators.pop();
    }
    return Postfix;
}

float Calculate(float tempNum1, float tempNum2, char op, bool *isValid)
{
    float result;
    switch (op)
    {
        case '^':
            if((tempNum2 ==0 && tempNum1 < 0) || floorf(tempNum1) != tempNum1)
                *isValid = false;
            else
                result = pow(tempNum2, tempNum1);
            break;
        case '*':
            result = tempNum2*tempNum1;
            break;
        case '/':
            if(tempNum1 != 0)
                result = tempNum2/tempNum1;
            else
                *isValid = false;
            break;
        case '+':
            result = tempNum1+tempNum2;
            break;
        default:
            result = tempNum2-tempNum1;
    }
    return result;
}

float postfixEvaluation(string Postfix, bool* isValid)
{
    Stack_float Result;
    float finalResult = 0;
    bool lastElementIsOperator = isOperator(Postfix[Postfix.length()-1]);
    for(int i = 0; i<Postfix.length(); i++)
    {
        if(!isOperator(Postfix[i]) && *isValid && Postfix[i] != '('&& Postfix[i] != ')' &&  lastElementIsOperator)
        {
            float num = Postfix[i] - '0'; //convert char to float
            Result.add(num);
        }
        else
        {

            if(Result.size() >=2 && *isValid&& Postfix[i] != '('&& Postfix[i] != ')' &&  lastElementIsOperator)
            {
                float tempNum1 = Result.pop();
                float tempNum2 = Result.pop();
                Result.add(Calculate(tempNum1, tempNum2, Postfix[i], isValid));
            }
            else{
                *isValid = false;
                return -1;
            }
        }
    }
    finalResult = Result.pop();
    if(Result.size() != 0)
        *isValid = false;
    return finalResult;
}

int main(int argc, char** argv)
{
    string partNum = argv[1];
    string expression = argv[2];
    ofstream output(argv[3]);

    if(partNum == "2")
    {
        string x = infixToPostfix(expression);
        output << x << "\n";
    }
    else if(partNum == "3")
    {
        bool isValid = true;
        float y = postfixEvaluation(expression, &isValid);
        output << fixed << setprecision(1);
        if(isValid)
            output << round(10 * y) / 10 << "\n";
        else
            output << "nv" << "\n";
        return 0;
    }
    output.close();
    return 0;
}