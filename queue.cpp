// PROGRAM TO IMPLEMENT QUEUE

#include<iostream>
using namespace std;

template< typename T >

class queue
{
    private : 

        T* arr;
        int front, rear, capacity;

    public : 

        queue()
        {
            arr = new T[ 0 ];
            front = rear = -1;

            cout << "\nEnter Capacity of the Queue : ";
            cin >> capacity;

            while( capacity < 1 )
            {
                cout << "\nINVALID INPUT...Enter again : ";
                cin >> capacity;
            }
        }

        ~queue()
        {
            delete[] arr;
        }

        void enqueue()
        {
            if( rear == capacity -1 )
            {
                cout << "\nQueue is Full!";
                return;
            }

            arr = ( T* )realloc( arr, rear + 2 );

            if( front == -1 )
            {
                front = 0;
            }

            cout << "\nEnter Data : ";
            cin >> arr[ ++rear ];
        }

        void dequeue()
        {
            if( front == -1 )
            {
                cout << "\nQueue is Empty!";
                return;
            }

            cout << "\nElement Dequeued : " << arr[ front++ ];

            if( front > rear )
            {
                front = rear = -1;
            }
        }

        friend ostream& operator << ( ostream& os, const queue& q )
        {
            os << "Queue Status : ";
            
            if( q.front == -1 )
            {
                os << "Empty";
                return os;
            }

            for( int i = q.front ; i <= q.rear ; os << q.arr[ i++ ] << ' ' );

            return os;
        }
        
        void initialise()
        {
            char ch;

            arr = new T[ 0 ];
            front = rear = -1;

            do
            {
                enqueue();

                if( rear == capacity - 1 )
                {
                    cout << "\nQueue is Full!";
                    return;
                }

                fflush( stdin );
                cout << "\nContinue ? ( Y / N ) : ";
                cin >> ch;

            }while( ch == 'y' || ch == 'Y' );
        }
};

int main()
{
    queue< int > q;
    int choice;
    char ch;

    do
    {
        cout << string( 50, '\n' );

        cout << "\t\tMENU" << endl;

        cout << "\n1) Initialise \n2) Enqueue \n3) Dequeue \n4) Display" << endl;

        cout << "\nEnter your choice : ";
        cin >> choice;

        switch( choice )
        {
            case 1 : q.initialise();    break;

            case 2 : q.enqueue();       break;

            case 3 : q.dequeue();       break;

            case 4 : cout << q;         break;

            default : cout << "\nINVALID INPUT...";
        }

        fflush( stdin );
        cout << "\nContinue To Menu ? ( Y / N ) : ";
        cin >> ch;

    } while ( ch == 'y' || ch == 'Y' );
    
    q.~queue();
    return 0;
}