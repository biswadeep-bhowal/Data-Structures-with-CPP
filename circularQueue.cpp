// PROGRAM TO IMPLEMENT CIRCULAR QUEUE

#include<iostream>
using namespace std;

template< typename T >

class circularQueue
{
    private : 

        T* arr;
        int front, rear, capacity;

    public : 

        circularQueue()
        {
            front = rear = -1;

            cout << "\nEnter Capacity of the Circular Queue : ";
            cin >> capacity;

            while( capacity < 1 )
            {
                cout << "\nINVALID INPUT...Enter again : ";
                cin >> capacity;
            }

            arr = new T[ capacity ];        
        }

        ~circularQueue()
        {
            delete[] arr;
        }

        void enqueue()
        {
            if( rear == front - 1 || ( rear == capacity - 1 && front == 0 ) )
            {
                cout << "\nCircular Queue Status : Full.";
                return;
            }

            if( front == -1 )
                front = 0;

            rear = ( rear + 1 ) % capacity;

            cout << "\nEnter Data : ";
            cin >> arr[ rear ];
        }

        void dequeue()
        {
            if( front == -1 )
            {
                cout << "\nCircular Queue Status : Empty.";
                return;
            }

            cout << "\nElement Dequeued : " << arr[ front ];

            front = ( front + 1 ) % capacity;

            if( front == ( rear + 1 ) % capacity )
                front = rear = -1;       
        }

        friend ostream& operator << ( ostream& os, const circularQueue& cq )
        {   
            os << "\nCircular Queue Status : ";

            if( cq.front == -1 )
            {
                os << "Empty.";
                return os;
            }

            if( cq.front < cq.rear )  
                for( int i = cq.front ; i <= cq.rear ; cout << cq.arr[ i++ ] << ' ' );

            else
            {
                for( int i = cq.front ; i < cq.capacity ; cout << cq.arr[ i++ ] << ' ' );
                for( int i = 0 ; i <= cq.rear ; cout << cq.arr[ i++ ] << ' ' );
            }

            return os;
        }

        void initialise()
        {
            char ch;

            front = rear = -1;

            do
            {
                enqueue();  

                if( rear == front - 1 || ( rear == capacity - 1 && front == 0 ) )
                {
                    cout << "\nCircular Queue Status : Full.";
                    return;
                }

                fflush( stdin );
                cout << "\nContinue ? ( Y / N ) : ";
                cin >> ch;

            } while ( ch == 'y' || ch == 'Y' );
        }

};



int main()
{
    circularQueue< int > cq;
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
            case 1 : cq.initialise();    break;

            case 2 : cq.enqueue();       break;

            case 3 : cq.dequeue();       break;

            case 4 : cout << cq;         break;

            default : cout << "\nINVALID INPUT...";
        }

        fflush( stdin );
        cout << "\nContinue To Menu ? ( Y / N ) : ";
        cin >> ch;

    } while ( ch == 'y' || ch == 'Y' );
    
    cq.~circularQueue();
    return 0;
}