#include <iostream>
#include <deque>
using namespace std;

int main()
{

    deque<int> d;

    d.push_back(1);
    d.push_front(2);

    for (int i : d)
    {
        cout << i << " ";
    }
    //d.pop_front();
    cout << endl;

    cout << "print first index element " << d.at(1) << endl;

    cout << "front" << d.front() << endl;
    cout << "back" << d.back() << endl;

    cout << "empty or not " << d.empty() << endl;

    cout << "before erase " << d.size() << endl;
    d.erase(d.begin(), d.begin() + 1);  //we have to mention what element or range to delete
    cout << "after erase " << d.size() << endl;
    for (int i : d)
    {
        cout << i << endl;
    }
}       //size becomes 0 after deletion BUT max_size stays same from start to end