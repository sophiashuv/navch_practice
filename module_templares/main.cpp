#include <iostream>
#include <fstream>
using  namespace std;
/*
 * Class for Node representation (based on Doubly linked list)
 */
template <class T>
struct Node {
    T x;
    Node *Next;
    Node *Prev;

    Node(T v) : x(v), Prev(nullptr), Next(nullptr) {}


    friend ostream& operator<<(ostream& out, Node<T>& a) {
        out << a.x ;
        return out;
    }
};

/*
 * Class for Stack representation (based on doubly Linked list)
 */
template <class T>
class Stack {
    Node<T> *Head;
    Node<T> *Tail;

public:
    Stack():Head(nullptr),Tail(nullptr){};

    ~Stack(){
        while (Head){
            Tail = Head->Next;
            delete Head;
            Head = Tail;
        }
    }

    friend ostream& operator<<(ostream& out, Stack<T>& Stack) {
        Node<T>* temp = Stack.Head;
        while (temp != nullptr) {
            out << *temp;
            temp = temp->Next;
        }
        out << endl;
        return out;
    }

    void push(T val) {
        Node<T>* curr = new Node<T>(val);
        if (Head == nullptr) {
            Head = Tail = curr;
        } else {
            curr->Prev = Tail;
            Tail->Next = curr;
            Tail = curr;
        }
    }

    void pop() {
        if (Head == nullptr) throw out_of_range("Empty stack exception\n");
        Node<T>* t = Tail->Prev;
        delete Tail;
        Tail = t;
        Tail->Next = nullptr;
    }

    void clear(){
        while (Head){
            Tail = Head->Next;
            delete Head;
            Head = Tail;
        }
    }
};


/*
 * The function fills Stack of chars with words letters,
 * putting at first letters, then digits in reversed order.
 */
void convertor(Stack<char> &str_stack, string &str){
    for (char letter: str)
        if (isalpha(letter)) str_stack.push(letter);
    reverse(str.begin(), str.end());
    for (char letter: str)
        if (!isalpha(letter)) str_stack.push(letter);
}


/*
 * The main function, requires "in.txt" filled with strings:
 * e.g. "in.txt":
 *          f6ghj57
 *          r4dtfyghj90
 *          fd6gh67
 *          xf6cg34
 */

void file_chacker(const string file_name){
    if(file_name.substr( file_name.length() - 3 ) == "txt") throw "Wrong file format exception";

}

int main() {
    Stack<char> str_stack;
    try {
//        ifstream in;
//        in.exceptions(ifstream::badbit | ifstream::failbit);
//        try {
//            in.open("in.txt");
//        }
//        catch (const ifstream::failure& ex) {
//            cout << "file opening error!\n";
//            cout << ex.what();
//            cout << ex.code();
//        }
        string file_name = "/Users/sophiyca/ClionProjects/module_templares/out.txt";
        string str;
        ifstream myfile("/Users/sophiyca/ClionProjects/module_templares/in.txt");
        ofstream myfile2 ("/Users/sophiyca/ClionProjects/module_templares/out.txt");
        if(file_name.substr( file_name.length() - 3 ) != "txt") throw "Wrong file format exception";
        if (myfile.is_open() && myfile2.is_open()) {
            while (myfile >> str) {
                convertor(str_stack, str);
                myfile2 << str_stack;
                str_stack.clear();
            }
            if (str.empty())  throw "Empty file exception";
            myfile.close();
            myfile2.close();
        } else throw "Unable to open file exception\n";
    } catch (const char* ms) {
        cout << ms;
    }
    system("pause>>void");
    return 0;
}
