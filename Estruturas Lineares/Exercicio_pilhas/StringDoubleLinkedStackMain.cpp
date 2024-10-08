#include <iostream>
#include "StringDoubleLinkedStack.hpp"
using namespace std;

int main(){
    int vmax;
    cout << "Stack size: " << endl;
    cin >> vmax;
    StringDoubleLinkedStack stack(vmax);
    bool runner = true;

    while(runner){
        int option;
        cout << " What do you want to do with your name stack?" << endl << endl; 
        cout << "1) Check emptyness;" << endl;
        cout << "2) Check Fullness;" << endl;
        cout << "3) Add item;" << endl;
        cout << "4) Remove item" << endl;
        cout << "5) See top item;" << endl; 
        cout << "6) See size now;" << endl;
        cout << "7) See maximum size;" << endl;
        cout << "8) Clear stack;" << endl;
        cout << "9) See full stack;" << endl;
        cout << "10) End program;" << endl;
        cin >> option;

        string e = "";

        switch(option) {
            case 1: 
                if(stack.isEmpty()) cout << "You got a empty stack" << endl;
                else{cout << "Your stack is not empty yet" << endl;}
                break;

            case 2:
                if(stack.isFull()) cout << "You got a full stack" << endl;
                else {cout << "Your stack is not full yet" << endl;}
                break;

            case 3:
                cout << "What item?" << endl;
                cin >> e;
                stack.push(e);
                cout << "You put " << e << " in the stack" << endl;
                break;
            
            case 4:
                stack.pop(e);
                cout << "You removed  \'" << e << "\' of the stack" << endl; 
                break;

            case 5:
                stack.top(e);
                cout << "The top item is \'" << e << "\'" << endl;
                break;

            case 6:
                cout << "The size of the stack now is " << stack.size() << endl;
                break;

            case 7:
                cout << "The maximum size is " << stack.maxSize() << "." << endl;
                break;

            case 8:
                stack.clear();
                cout << "cleaning stack..." << endl;
                break;

            case 9:
                break;
            case 10:
                cout <<" Ending..." << endl;
                stack.clear();
                runner = false;
                break;

            default:
                cout << "You have to enter a valid number" << endl;
        }
    }
    return 0;
}