// Author: Nurul Saiym
// Date: 2/21/2022
// Homework 2:

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

struct node{
    int data; // store int values
    node* next; // Pointer to next node in DLL
    node* prev; // in DLL, used as previous pointer. in matrix node, used as buttom pointer
};

class DLL//Double linked list
{
    public:
        DLL();//initializes initial values
        void create_DLL_Node(int data);//create and adds data to doubly linked list. ended up not using this function
        void pushRight(int data); //push data to the right of current row - used for matrix
        void nextRow(); //go to the next row when adding nodes to matrix
        node* head; // Pointer to head
        node* tail; // in DLL node, used as Pointer to tail. in Matrix node, used for keeping track of the last node added
        node* nextRow_tracker; // keeps track of the 1st node of a row in a matrix when adding nodes to matrix
        node* prevRow_tracker; // to connect old row nodes to new row nodes
        bool firstnode;
        bool firstrow;
        int row_col; //used in the main  program to keep track of number of row/column
        string temp_digitSize; //used for output formating
        int digitSize; //used for output formating
};

DLL::DLL(){
    head = nullptr;
    tail = nullptr;
    nextRow_tracker = nullptr;
    prevRow_tracker = nullptr;
    firstnode = true;
    firstrow = true;
    row_col = 0;
    temp_digitSize = "";
    digitSize = 0;
}

void DLL::create_DLL_Node(int data){
    node* newnode = new node;
    if(head==nullptr){
        head = newnode;
        head->data = data;
        head->prev = nullptr;
        head->next = nullptr;
        tail = head;
        //return head;
    }
    else{
        tail->next = newnode;
        newnode->data = data;
        newnode->prev = tail;
        newnode->next = nullptr;
        tail = newnode;
        //return newnode;
    }

}

void DLL::pushRight(int data){
    node* newnode = new node;
    if(nextRow_tracker==nullptr){
        nextRow_tracker = newnode;
        nextRow_tracker->data = data;
        nextRow_tracker->prev = nullptr;
        nextRow_tracker->next = nullptr;
        if (firstnode ){
            head = nextRow_tracker;
        }
        firstnode = false;
        if (!firstrow){
            prevRow_tracker->prev = nextRow_tracker;
            prevRow_tracker = prevRow_tracker->next;
        }
        tail = nextRow_tracker;
    }
    else{
        if(!firstrow){
            prevRow_tracker->prev = newnode;
            prevRow_tracker = prevRow_tracker->next;
        }
        tail->next = newnode;
        newnode->data = data;
        newnode->prev = nullptr;
        newnode->next = nullptr;
        tail = newnode;
    }

}

void DLL::nextRow(){
    prevRow_tracker = nextRow_tracker;
    nextRow_tracker = nextRow_tracker->prev;
    firstrow = false;
}

void PrintMatrix(DLL Matrix_1);

DLL addMatrices(DLL Matrix_1, DLL Matrix_2){ // Add two matricies
    node* treverse1 = Matrix_1.head;
    node* treverse1_row = Matrix_1.head;
    node* treverse2 = Matrix_2.head;
    node* treverse2_row = Matrix_2.head;
    DLL Result;
    int temp;
    for (int i = 0; i < Matrix_1.row_col; i++) {
        for(int j = 0;j<Matrix_1.row_col; j++){
            temp = treverse1->data + treverse2->data;
            Result.pushRight(temp);
            Result.temp_digitSize = to_string(temp);
            //cout << "length of " << temp << "is "<< Result.temp_digitSize.size()<< endl;
            if(Result.temp_digitSize.size()>Result.digitSize){
                Result.digitSize = Result.temp_digitSize.size();
            }
            treverse1 = treverse1->next;
            treverse2 = treverse2->next;
        }
        Result.nextRow();
        Result.row_col++;
        treverse1_row = treverse1_row->prev;
        treverse1 = treverse1_row;
        treverse2_row = treverse2_row->prev;
        treverse2 = treverse2_row;
    }
    //cout << "final Digitsize: " << Result.digitSize << endl;
    return Result;
}

DLL subMatrices(DLL Matrix_1, DLL Matrix_2){ // Subtract two matricies
    node* treverse1 = Matrix_1.head;
    node* treverse1_row = Matrix_1.head;
    node* treverse2 = Matrix_2.head;
    node* treverse2_row = Matrix_2.head;
    DLL Result;
    int temp;
    for (int i = 0; i < Matrix_1.row_col; i++) {
        for(int j = 0;j<Matrix_1.row_col; j++){
            temp = treverse1->data - treverse2->data;
            Result.pushRight(temp);
            Result.temp_digitSize = to_string(temp);
            //cout << "length of " << temp << "is "<< Result.temp_digitSize.size()<< endl;
            if(Result.temp_digitSize.size()>Result.digitSize){
                Result.digitSize = Result.temp_digitSize.size();
            }
            treverse1 = treverse1->next;
            treverse2 = treverse2->next;
        }
        Result.nextRow();
        Result.row_col++;
        treverse1_row = treverse1_row->prev;
        treverse1 = treverse1_row;
        treverse2_row = treverse2_row->prev;
        treverse2 = treverse2_row;
    }
    //cout << "final Digitsize: " << Result.digitSize << endl;
    return Result;
}

DLL mulMatrices(DLL Matrix_1, DLL Matrix_2){ // Multiply two matricies
    node* treverse1 = Matrix_1.head;
    node* treverse1_row = Matrix_1.head;
    node* treverse2 = Matrix_2.head;
    node* treverse2_row = Matrix_2.head;
    DLL Result;
    int temp = 0;
    for (int i = 0; i < Matrix_1.row_col; i++) {
        for(int j = 0;j<Matrix_1.row_col; j++){
            //treverse2 = treverse2_row;
            for(int k = 0;k<Matrix_1.row_col; k++){
                temp += treverse1->data * treverse2->data;
                treverse1 = treverse1->next;
                treverse2 = treverse2->prev;
            }
            Result.pushRight(temp);
            Result.temp_digitSize = to_string(temp);
            //cout << "length of " << temp << "is "<< Result.temp_digitSize.size()<< endl;
            if(Result.temp_digitSize.size()>Result.digitSize){
                Result.digitSize = Result.temp_digitSize.size();
            }
            temp = 0;
            treverse1 = treverse1_row;
            treverse2_row = treverse2_row->next;
            treverse2 = treverse2_row;
        }
        Result.nextRow();
        Result.row_col++;
        treverse1_row = treverse1_row->prev;
        treverse1 = treverse1_row;
        treverse2_row = Matrix_2.head;
        treverse2 = treverse2_row;
    }
    //cout << "final Digitsize: " << Result.digitSize << endl;
    return Result;
}

DLL transpose(DLL Matrix_1){ // transpose a matrix
    node* treverse1 = Matrix_1.head;
    node* treverse1_row = Matrix_1.head;
    DLL Result;
    int temp;
    for (int i = 0; i < Matrix_1.row_col; i++) {
        for(int j = 0;j<Matrix_1.row_col; j++){
            temp = treverse1->data;
            Result.pushRight(temp);
            Result.temp_digitSize = to_string(temp);
            //cout << "length of " << temp << "is "<< Result.temp_digitSize.size()<< endl;
            if(Result.temp_digitSize.size()>Result.digitSize){
                Result.digitSize = Result.temp_digitSize.size();
            }
            treverse1 = treverse1->prev;
        }
        Result.nextRow();
        Result.row_col++;
        treverse1_row = treverse1_row->next;
        treverse1 = treverse1_row;
    }
    //cout << "final Digitsize: " << Result.digitSize << endl;
    return Result;
}

node* create_sub_matrix(node* head, int row_col, int col){ // creates a submatrix - used for finding determinant
    node* treverse1 = head;
    node* treverse1_row = head;
    DLL temp;
    //cout << "row_col: "<< row_col << endl;
    for (int i = 0; i < row_col; i++) {
        for(int j = 0;j<row_col; j++){
            if(i==0 || j==col-1){
                treverse1 = treverse1->next;
            }
            else{
                temp.pushRight(treverse1->data);
                treverse1 = treverse1->next; 
            }
        }
        if(i!=0){
            temp.nextRow();
            temp.row_col++;
        }
        treverse1_row = treverse1_row->prev;
        treverse1 = treverse1_row;
    }
    //PrintMatrix(temp);
    //cout << temp.row_col << endl;
    return temp.head;
}

int determinant(node* head, int row_col){ // gets the determinant of a matrix
    node* treverse1 = head;
    node* treverse1_row = head;
    int temp_row_col = row_col;
    int Result = 0;
    int sign = -1;
    //row_col = 2;
    //cout << row_col << endl;
    if(row_col == 1 || row_col == 2){
        if(row_col ==1){
            Result = head->data;
            //cout << "result: " << Result << endl;
            return Result;
        }
        else{
            Result = (head->data * head->prev->next->data) - (head->next->data * head->prev->data);
            //cout << "row_col : 2 result: " << Result << endl;
            //cout <<"row_col: "<< row_col << endl;
            return Result;
        }
    }
    else{
        for(int i = 0; i<row_col; i++){
            sign = sign*-1;
            Result += (treverse1->data) * (sign) * determinant(create_sub_matrix(head, row_col,i+1), temp_row_col-1);
            //cout << "result = " << Result << endl;;
            temp_row_col = row_col;
            treverse1 = treverse1->next;
        }
    }
    //cout << "final result: " << Result << endl;
    return Result;
}


void PrintMatrix(DLL Matrix_1){ //prints matrix to stdout
    node* treverse = Matrix_1.head;
    node* treverse2 = Matrix_1.head;
    cout << fixed << setprecision(1);
    float temp;
    for (int i = 0; i < Matrix_1.row_col; i++) {
        for(int j = 0;j<Matrix_1.row_col; j++){
            temp = static_cast<float> (treverse->data);
            cout << temp << " ";
            treverse = treverse->next;
        }
        cout << endl;
        treverse2 = treverse2->prev;
        treverse = treverse2;
    }
    cout << endl;
}

void outputfile(string filename, DLL Matrix_1){ //outputs to file
    ofstream output(filename);
    node* treverse = Matrix_1.head;
    node* treverse2 = Matrix_1.head;
    output << fixed << setprecision(1);
    float temp;
    for (int i = 0; i < Matrix_1.row_col; i++) {
        for(int j = 0;j<Matrix_1.row_col; j++){
            temp = static_cast<float> (treverse->data);
            output <<setw(Matrix_1.digitSize+2) <<right << temp;
            if(j!=Matrix_1.row_col-1){
                output << " ";
            }
            treverse = treverse->next;
        }
        output << "\n";
        treverse2 = treverse2->prev;
        treverse = treverse2;
    }
    output.close();
}


int main(int argc, char *argv[]) {
    ifstream input1, input2;
     string operation = argv[1];
     string input1name = argv[2];
    //string operation = "det";
    //string input1name = "2_b.txt";
    string input2name;
    string filename;
    //filename = "outputdemo.txt";
    bool twoInputs;
    if(operation == "add"|| operation == "sub"|| operation == "mul"){
        string input2name = argv[3];
        //string input2name = "1_b.txt";
        //string filename = argv[4];
        input1.open(input1name);
        input2.open(input2name);
        twoInputs = true;
    }
    else{
        //string filename = argv[3];
        input1.open(input1name);
        twoInputs = false;
    }

    DLL Matrix_1;
    DLL Matrix_2;
    string line;
    int temp_num;
    while(getline(input1, line, '\n')){
        istringstream ss(line);
        while(ss>>temp_num){
            Matrix_1.pushRight(temp_num);
        }
        Matrix_1.nextRow();
        Matrix_1.row_col++;
    }
    if(twoInputs){
        while(getline(input2, line, '\n')){
            istringstream ss(line);
            while(ss>>temp_num){
                Matrix_2.pushRight(temp_num);
            }
            Matrix_2.nextRow();
            Matrix_2.row_col++;
        }
        input2.close();
    }
    input1.close();

    DLL result;
    int num;
    if(operation == "add"){
        result = addMatrices(Matrix_1, Matrix_2);
        outputfile(argv[4],result);
    }
    else if(operation == "sub"){
        result = subMatrices(Matrix_1, Matrix_2);
        outputfile(argv[4],result);
    }
    else if(operation == "mul"){
        result = mulMatrices(Matrix_1, Matrix_2);
        outputfile(argv[4],result);
    }
    else if(operation == "tra"){
        result = transpose(Matrix_1); 
        outputfile(argv[3],result);
    }
    else if(operation == "det"){
        num = determinant(Matrix_1.head, Matrix_1.row_col);
        result.pushRight(num);
        result.temp_digitSize = to_string(num);
        result.digitSize = result.temp_digitSize.size();
        result.row_col = 1;
        outputfile(argv[3],result);
    }
    return 0;
} 