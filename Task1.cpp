#include <iostream>
#include <random>
using namespace std;

int main()
{

    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> dist(1, 100);
    int a = dist(gen);
    cout << a<< endl;

    while (true)
    {
        int num;
        cout << "guess the number.. : ";
        cin >> num;

        if (num > a)
        {
            cout << "Too Far" << endl;
        }
        else if (num == a)
        {
            cout << a<<endl;
            cout << "You Won the Game" << endl;
            break;
        }
        else
        {
            cout << "Too Low" << endl;
        }
    }

    return 0;
}

