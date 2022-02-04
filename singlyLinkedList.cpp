// PROGRAM TO IMPLEMENT SINGLY LINKED LIST

#include<iostream>
using namespace std;

class Node        
{       
    private : 
    
        friend class singlyLinkedList;    // FRIEND CLASS TO ACCESS MEMBERS OF THE NODE CLASS.

        int data;
        Node* next;
        
    public : 

        Node()      // DEFAULT CONSTRUCTOR
        {   
            cout << "\nEnter data for the new node : ";
            cin >> this -> data;

            this -> next = NULL;
        }

        Node( int data )        // PARAMETERISED CONSTRUCTOR
        {
            this -> data = data;
            this -> next = NULL;
        }

        int getData()               // GETTER FUNCITON
        {
            return this -> data;
        }

        Node* getNext()         // GETTER FUNCTION
        {
            return this -> next;
        }

        friend ostream& operator << ( ostream& os, Node* &node )    // OPERATOR OVERLOADING
        {
            os << node -> getData() << ' ';                         // GETTER FUNCTION NOT NECESSARY HERE.
            return os;
        }
};



class singlyLinkedList              // A CLASS TO WORK WITH SINGLY LINKED LISTS
{
    protected :                 // TO GRANT ACCESS TO DERIVED CLASSES AS WELL. NOT POSSIBLE IN CASE OF PRIVATE 

        Node* head;             // PRIVATE MEMBERS OF SLL
        int length;

    public : 

        singlyLinkedList()          // Default Constructor
        {
            head = NULL;
            length = 0;
        }

        Node* getHead()
        {
            return head;
        }

        void insertAtHead()         // FUNCTION TO INSERT NODE AT THE FRONT OF THE LINKED LIST
        {
            if( head == NULL )
            {
                head = new Node();
                length = 1;
                return;
            }

            Node* newNode = new Node();

            newNode -> next = head;
            head = newNode;

            length++;
        }

        void insertAtMiddle()       // FUNCTION TO INSERT NODE IN BETWEEN.
        {
            if( head == NULL )
            {
                head = new Node();
                length = 1;
                return;
            }

            Node* temp;
            int position;

            cout << "\nEnter a middle position : ";
            cin >> position;

            while( position < 1 || position > length + 1 )
            {
                cout << "\nINVALID POSITION...Enter again : ";
                cin >> position;
            }

            if( position == 1 || head == NULL )
            {
                insertAtHead();
                return;
            }

            if( position == length + 1 )
            {
                insertAtEnd();
                return;
            }

            for( temp = head ; position - 2 > 0 && temp != NULL ; position--, temp = temp -> next );

            Node* newNode = new Node();
            newNode -> next = temp -> next;
            temp -> next = newNode;

            length++;
        }

        void insertAtEnd()              // FUNCTION TO APPEND A NODE.
        {
            if( head == NULL )
            {
                head = new Node();
                length = 1;
                return;
            }

            Node* temp;

            for( temp = head ; temp -> next != NULL ; temp = temp -> next );

            Node* newNode = new Node();
            temp -> next = newNode;

            length++;
        }

        int getLength()             // FUNCTION TO GET LENGTH OF THE SINGLY LINKED LIST.
        {
            return length;
        }

        void initialise()           // FUNCTION TO INITIALISE A SINGLY LINKED LIST.
        {
            Node* temp = NULL;
            char ch = 'y';

            length = 1;
            head = new Node();
            temp = head;
            
            fflush( stdin );
            cout << "\nCOntinue ? ( Y / N ) : ";
            cin >> ch;                        

            while( ch == 'y' || ch == 'Y' )
            {
                Node* newNode = new Node();
                
                temp -> next = newNode;
                temp = temp -> next;
                
                length++;

                fflush( stdin );
                cout << "\nCOntinue ? ( Y / N ) : ";
                cin >> ch;
            }
            
        }

        friend ostream& operator << ( ostream& os, const singlyLinkedList& sll )    // OPERATOR OVERLOADING
        {
            os << "\nSingly Linked List Status : ";

            if( sll.head == NULL )
            {
                os << "Empty";
                return os;
            }

            for( Node* temp = sll.head ; temp != NULL ; temp = temp -> getNext() )      // getNext() FUNCTION IS USED BECAUSE FRIEND FUNCTION OF SLL IS NOT THE FRIEND OF NODE.
            {
                os << temp;
            }

            return os;
        }

        void deleteAtHead()
        {
            if( head == NULL )
            {
                cout << "\nSingly Linked List Status : Empty";
                return;
            }

            Node* temp = head;
            head = head -> next;
            delete temp;

            length--;
        }

        void deleteAtMiddle()
        {
            if( head == NULL )
            {
                cout << "\nSingly Linked List Status : Empty";
                return;
            }

            int position;

            cout << "\nEnter a valid posiiton for deletion : ";
            cin >> position;

            while( position < 1 || position > length )
            {
                cout << "\nINVALID POSITION...Enter again : ";
                cin >> position;
            }

            if( position == 1 )
            {
                deleteAtHead();
                return;
            }

            if( position == length )
            {
                deleteAtEnd();
                return;
            }

            Node *t = NULL, *temp = NULL;
            for( temp = head ; position - 2 > 0 ; position--, temp = temp -> next );

            t = temp -> next;
            temp -> next = temp -> next -> next;
            delete t;

            length--;
        }

        void deleteAtEnd()
        {
            if( head == NULL )
            {
                cout << "\nSingly Linked List Status : Empty";
                return;
            }

            if( head -> next == NULL )
            {
                Node* temp = head;
                head = head -> next;
                
                delete temp;
                length--;
                
                return;
            }

            Node* temp = NULL;
            for( temp = head ; temp -> next -> next != NULL ; temp = temp -> next );

            delete temp -> next;
            temp -> next = NULL;

            length--;
        }

        ~singlyLinkedList()
        {
            while( head != NULL )
            {
                Node* temp = head;
                head = head -> next;

                delete temp;
            }

            delete head;
        }
};

int main()          // DRIVER PROGRAM, MENU DRIVEN.
{
    singlyLinkedList sll;
    int choice;
    char ch;

    do
    {
        cout << string( 50, '\n' );

        cout << "\t\tMENU\n\n" << endl;

        cout << "1) Initialise \n2) Insert At Head \n3) Insert At Middle \n4) Insert At End \n5) Display \n6) Delete At Head \n7) Delete At Middle \n8) Delete At End";

        cout << "\n\nEnter your choice : ";
        cin >> choice;

        switch( choice )
        {
            case 1 : sll.initialise();      break;          // -> NOT USED HERE SINCE sll IS NOT A POINTER TO AN OBJECT.

            case 2 : sll.insertAtHead();    break;

            case 3 : sll.insertAtMiddle();  break;

            case 4 : sll.insertAtEnd();     break;

            case 5 : cout << sll;           break;          // OPERATOR OVERLOADING

            case 6 : sll.deleteAtHead();    break;

            case 7 : sll.deleteAtMiddle();  break;

            case 8 : sll.deleteAtEnd();     break;

            default : cout << "\nINVLAID INPUT...";
        }

        fflush( stdin );
        cout << "\nContinue to Menu ? ( Y / N ) : ";
        cin >> ch;        

    }while( ch == 'y' || ch == 'Y' );

    sll.~singlyLinkedList();        // EXPLICITLY CALLING DESTRUCTOR.
    return 0;
}