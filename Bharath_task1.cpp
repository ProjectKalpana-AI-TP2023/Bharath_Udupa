#include <iostream>
#include <string>

using namespace std;

class TextEditor {
private:
    string text;
    int cursor;

public:
    TextEditor() {
        text = "";
        cursor = 0;
    }

    void addText(string text) {
        this->text.insert(cursor, text);
        cursor += text.length();
    }

    void deleteText(int k) {
        if(k>cursor){
            k = cursor;  
            text.erase(cursor-k, k);
            cursor = cursor -k; 
        }
        else{
            text.erase(cursor-k, k);
            cursor = cursor -k; 
        }
    }
    void backspace() {
        if (cursor > 0) {
            text.erase(cursor - 1, 1);
            cursor--;
        }
    }

    int findCursor() {
        return cursor;
    }

    void cursorLeft(int k) {
        if (k <= cursor
        ) {
            cursor -= k;
        } else {
            cursor = 0;
        }
    }

    void cursorRight(int k) {
        if (k <= text.length() - cursor) {
            cursor += k;
        } else {
            cursor = text.length();
        }
    }

    string fullText() {
        return text;
    }

    string showText(int k) {
        if (cursor + k <= text.length()) {
            return text.substr(cursor, k);
        } else {
            return text.substr(cursor);
        }
    }
};

int main() {
    TextEditor editor;
    string inputst; 
    string options = "The following operations are avaliable: \n1. Add text: 1 \n2. Delete Text: 2 \n3. Backspace: 3\n4. Find cursor: 4\n5. Cursor left: 5\n6. Cursor right: 6\n7. Return text: 7\n8. Show text sub string: 8\n9. Show options: 9\n Select an option.";
    cout<<"Enter a string: "<<endl;
    getline(cin, inputst); 
    editor.addText(inputst);
    cout<<"Enter a negative number to exit"<<endl;
    cout<<options<<endl;
    int n=1; 
    int m;
    string st1;
    cin>>n; 
    while(n>0){
        //cout<<"\ntest\n";
        if (n==1){
            cout<<"Enter the text to be added: "<<endl;
            cin.ignore();
            getline(cin, st1); 
            editor.addText(st1);
            cout<<"\nSelect another operation:"<<endl;
            cin>>n; 
        }
        else if (n==2){
            cout<<"Enter the number of characters to be deleted: "<<endl;
            cin>>m; 
            editor.deleteText(m);
            cout<<editor.fullText();
            cout<<"\nSelect another operation:"<<endl;
            cin>>n;  
        }
        else if (n==3){
            editor.backspace();
            cout<<editor.fullText();
            cout<<"\nSelect another operation:"<<endl;
            cin>>n; 
        }
        else if(n==4){
            cout<<editor.findCursor();
            cout<<"\nSelect another operation:"<<endl;
            cin>>n; 
        }
        else if(n==5){
            cout<<"Enter the number of spaces the cursor should move: "<<endl;
            cin>>m; 
            editor.cursorLeft(m);
            cout<<"\nSelect another operation:"<<endl;
            cin>>n;  
        }
        else if(n==6){
            cout<<"Enter the number of spaces the cursor should move: "<<endl;
            cin>>m; 
            editor.cursorRight(m);
            cout<<"\nSelect another operation:"<<endl;
            cin>>n;  
        }
        else if(n==7){
            cout<<editor.fullText();
            cout<<"\nSelect another operation:"<<endl;
            cin>>n;  
        }
        else if(n==8){
            cout<<"Enter the index after which you wish to view the text: "<<endl;
            cin>>m;
            cout<<editor.showText(m);
            cout<<"\nSelect another operation:"<<endl;
            cin>>n; 
        }
        else if(n==9){
            cout<<options<<endl;
            cout<<"\nSelect another operation:"<<endl;
            cin>>n; 
        }
        else if(n<0){
            break;
        }
        else {
            cout<<"Invalid option";
            cout<<"\nSelect another operation:"<<endl;
            cin>>n; 
        }
    }
    
  cout << editor.fullText() << endl;

    return 0;
}