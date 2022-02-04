// PROGRAM TO ILLUSTRATE THE STACK DATA STRUCTURE

#include<iostream>
using namespace  std;

template< typename T >
class stack
{
    private : 

        T* arr;
        int top, capacity;

    public : 

        stack()
        {
            top = -1;
            
            cout << "\nEnter capacity of the Stack : ";
            cin >> capacity;

            while( capacity < 1 )
            {
                cout << "\nINVALID INPUT...Enter again : ";
                cin >> capacity;
            }

            arr = new T[ 0 ];
        }

        ~stack()
        {
            delete[] arr;
        }

        void push()
        {
            if( top == capacity - 1 )
            {
                cout << "\nStack Overflow!";
                return;
            }

            arr = ( T* )realloc( arr, top + 2 );


            cout << "\nEnter data : ";
            cin >> arr[ ++top ];
        }

        void pop()
        {
            if( top == -1 )
            {
                cout << "Stack Underflow!";
                return;
            }

            cout << "\nELement Popped : " <<  arr[ top-- ];
            arr = ( T* )realloc( arr, top + 1 );
        }

        friend ostream& operator << ( ostream& os, const stack& s )
        {
            cout << "\nStack Status : ";

            if( s.top == -1 )
            {
                cout << "Empty";
                return os;
            }

            for( int i = 0 ; i <= s.top ; os << s.arr[ i++ ] << ' ' );

            return os;
        }

        int getTop(){       return top;         }

        int getSize(){      return top + 1;     }

        int getCapacity(){  return capacity;    }

        void initialise()
        {
            char ch;
            top = -1;

            do
            {
                push();

                if( top == capacity - 1 )
                {
                    cout << "\nStack is Full!";
                    break;
                }

                fflush( stdin );
                cout << "\nContinue ? ( Y / N ) : ";
                cin >> ch;

            }while( ch == 'y' || ch == 'Y' );
        }
};

int main()
{
    stack< float > s;
    int choice;
    char ch;

    do
    {
        cout << string( 50, '\n' );

        cout << "\t\tMENU" << endl;

        cout << "\n1) Initialise \n2) Push \n3) Pop \n4) Display";

        cout << "\nEnter your choice : ";
        cin >> choice;

        switch( choice )
        {
            case 1 : s.initialise();    break;
            
            case 2 : s.push();          break;

            case 3 : s.pop();           break;

            case 4 : cout << s;         break;

            default : cout << "\nINVALID INPUT...";
        }

        fflush( stdin );
        cout << "\nContinue To Menu ? ( Y / N ) : ";
        cin >> ch;

    }while( ch == 'y' || ch == 'Y' );
    
    s.~stack();
    return 0;
}