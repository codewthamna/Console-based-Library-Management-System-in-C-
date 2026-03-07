#include<iostream>
#include<string>
using namespace std;
class Library{

    private:
    string name;
    int id;
    string available;

    public:
     Library() {
        cout << "Enter Book Name: ";
        getline(cin, name);
        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore();
        cout << "Is the book available? (yes/no): ";
        getline(cin, available);
     }

         void display() {
        cout << "Book Name: " << name << endl;
        cout << "Book ID: " << id << endl;
        cout << "Availability: " << available << endl;
        cout << "---------------------------" << endl;
    }

    bool checkId(int searchId){
        return id==searchId;
    }

    void update(){
        cin.ignore();
        cout<<" ENTER NEW BOOK NAME : "<<endl;
        getline(cin,name);
        cout<<" ENTER NEW ID : "<<endl;
        cin>>id;
        cin.ignore();
         cout << "Is the book available? (yes/no): ";
        getline(cin, available);

    }
  
};
//By using int &totalBooks, the decrement affects the actual totalBooks variable in main().
 void deleteBook(Library Books[], int &totalBooks) {
    int deleteId;
    cout << "Enter Book ID to delete: ";
    cin >> deleteId;
    bool found = false;
    
    for (int i = 0; i < totalBooks; i++) {
        if (Books[i].checkId(deleteId)) {
            // Shift all books after i to left
            for (int j = i; j < totalBooks - 1; j++) {
                Books[j] = Books[j + 1];
            }
            totalBooks--; // reduce total books
            cout << "Book deleted successfully.\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Book not found!\n";
    }
}
int main(){
     Library Books[100];
    int totalBooks=0;
    int choice;
    do{

        cout << "\n1. Add Book\n2. Display Books\n3. Search Book\n4. Update Book\n5. Delete Book\n6. Exit\n";
        cout<<" ENTER YOUR CHOICE :"<<endl;
        cin>>choice;
        cin.ignore();

        switch(choice){
            case 1:
            {
                int n;
                cout<<" How many books u want to enter .. "<<endl;
                cin>>n;
                cin.ignore();
                for(int i=totalBooks;i<totalBooks+n;i++){
                    Books[i]=Library();
                }
totalBooks+=n;
break;
            }
            case 2:{
                if(totalBooks==0){
                    cout<<" NO BOOKS AVAILABLE ....."<<endl;
                } else{
                    for(int i=0;i<totalBooks;i++){
                        Books[i].display();
                    }
                } break;
            }
      case 3:
      {
        int searchId;
        int updateID;
        cout<<" Enter book to search "<<endl;
        cin>>searchId;
        bool found=false;
        for(int i=0;i<totalBooks;i++){
            if(Books[i].checkId(searchId)){
                cout<<" book found "<<endl;
                Books[i].display();
                found = true;
                break;
            }
        } if(!found)
        cout<<" NOT FOUND "<<endl;
        break;
      }
      case 4:
{
    int updateId;
    cout << "Enter Book ID to update: ";
    cin >> updateId;
    bool found = false;

    for(int i = 0; i < totalBooks; i++) {
        if(Books[i].checkId(updateId)) {
            Books[i].update();
            found = true;
            break;
        }
    }

    if(!found) {
        cout << "Book not found!\n";
    }
    break;
}

      case 5:
      {
         deleteBook(Books, totalBooks);
         break;
      }

         case 6:
                cout << "Exiting...\n";
                break;
                default:
                cout<<" invalid choice ......."<<endl;
        }
    }while(choice!=6);



    return 0;
}