// PROGRAM TO IMPLEMENT SINGLY LINKED LIST

#include<iostream>
using namespace std;

class Node        
{       
    private : 
    
        friend class singlyLinkedList;          // FRIEND CLASS TO ACCESS MEMBERS OF THE NODE CLASS.
        friend class circularSinglyLinkedList;

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

        /*
        int getData()               // GETTER FUNCITON
        {
            return this -> data;
        }
        */
        Node* getNext()         // GETTER FUNCTION
        {
            return this -> next;
        }

        friend ostream& operator << ( ostream& os, Node* &node )    // OPERATOR OVERLOADING
        {
            os << node -> data << ' ';
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



class circularSinglyLinkedList : protected singlyLinkedList
{
    private : Node* tail;

    public : 

        circularSinglyLinkedList()
        {
            tail = NULL;
            length = 0;
        }

        void insertAtHead()
        {
            Node* newNode = new Node;

            if( head == NULL )
            {
                head = tail = newNode;
                head -> next = tail -> next = head;
            }

            else
            {
                newNode -> next = head;
                tail -> next = newNode;
                head = newNode;
            }
            
            length++;
        }

        void insertAtMiddle()
        {
            Node* temp = NULL;
            int position;

            cout << "\nEnter a valid position for insertion : ";
            cin >> position;

            while( position < 1 || position > length + 1 )
            {
                cout << "\nINVALID INPUT...Enter again : ";
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

            for( temp = head ; position - 2 > 0 ; position--, temp = temp -> next );

            Node* newNode = new Node;

            newNode -> next = temp -> next;
            temp -> next = newNode;

            length++;

        }

        void insertAtTail()
        {
            Node* newNode = new Node;

            if( head == NULL )
            {
                head = tail = newNode;
                head -> next = tail -> next = head;
            }

            else
            {
                newNode -> next = head;
                tail -> next = newNode;
            }

            length++;
        }

        void initialise()
        {
            char ch;

            head = tail = new Node;
            head -> next = tail -> next = head;
            length = 1;

            fflush( stdin );
            cout << "\nContinue ? ( Y / N ) : ";
            cin >> ch;

            while( ch == 'y' || ch == 'Y' )
            {
                Node* newNode = new Node;
                
                newNode -> next = head;
                tail -> next = newNode;
                tail = tail -> next;

                length++;
                
                fflush( stdin );
                cout << "\nContinue ? ( Y / N ) : ";
                cin >> ch;
            }
        }

        friend ostream& operator << ( ostream& os, const circularSinglyLinkedList& csll )
        {
            Node* temp = csll.head;

            os << "Circular Linked List Status : ";

            if( temp == NULL )
            {
                os << "Empty.";
                return os;
            }

            do
            { 
                os << temp;
                temp = temp -> getNext();

            }while( temp != csll.head );
            
            return os;
        }

        void deleteAtHead()     // FUNCTION OVERRIDING
        {
            if( head == NULL )
            {
                cout << "\nCircular Linked List Status : Empty";
                return;
            }

            if( length == 1 )
            {
                Node* temp = head;
                head = tail = NULL;
                delete temp;
                length = 0;

                return;
            }

            Node* temp = head;
            head = head -> next;
            tail -> next = head;

            length--;
            delete temp;
        }

        void deleteAtMiddle()       // FUNCTION OVERRIDIING
        {
            if( head == NULL )
            {
                cout << "\nCircular Linked List Status : Empty";
                return;                
            }

            int position;

            cout << "\nEnter a valid position for deletion : ";
            cin >> position;

            while( position < 1 || position > length )
            {
                cout << "\nINVALID INPUT...Enter again : ";
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

            t = temp;
            temp -> next = temp -> next -> next;
            delete t;
            
            length--;
        }

        ~circularSinglyLinkedList()
        {
            if( head == NULL )
                return;

            tail -> next = NULL;

            do
            {
                Node* temp = head;
                head = head -> next;

                delete temp;
            }while( head != NULL );
            
            length = 0;
        }
};



int main()          // DRIVER PROGRAM, MENU DRIVEN.
{
    circularSinglyLinkedList csll;
    int choice;
    char ch;

    do
    {
        cout << string( 50, '\n' );     // CLRSCR

        cout << "\t\tMENU\n\n" << endl;

        cout << "1) Initialise \n2) Insert At Head \n3) Insert At Middle \n4) Insert At End \n5) Display";

        cout << "\n\nEnter your choice : ";
        cin >> choice;

        switch( choice )
        {
            case 1 : csll.initialise();      break;          // -> NOT USED HERE SINCE sll IS NOT A POINTER TO AN OBJECT.

            case 2 : csll.insertAtHead();    break;

            case 3 : csll.insertAtMiddle();  break;

            case 4 : csll.insertAtTail();     break;

            case 5 : cout << csll;           break;          // OPERATOR OVERLOADING

            default : cout << "\nINVLAID INPUT...";
        }

        fflush( stdin );
        cout << "\nContinue to Menu ? ( Y / N ) : ";
        cin >> ch;        

    }while( ch == 'y' || ch == 'Y' );

    csll.~circularSinglyLinkedList();        // EXPLICITLY CALLING DESTRUCTOR.
    return 0;
}