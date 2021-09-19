#include <iostream>
#include <map>

using namespace std;
int main()
{
    map<int, string> m;

    m[1] = "madhurjya";
    m[2] = "sarma";
    m[23] = "arjun";

    m.insert({5, "bheem"});

    cout << "before erase-> " << endl;
    for (auto i : m)
    {
        cout << i.first << " " << i.second << endl;
    }

    cout << "finding 23-> " << m.count(23) << endl;
    m.erase(23);

    cout << "after erase-> " << endl;
    for (auto i : m)
    {
        cout << i.first << " " << i.second << endl;
    }

    auto it = m.find(5);

    for (auto i = it; i != m.end(); i++)
    {
        cout << (*i).first << endl;
    }
}

//insert,erase,find,count complexity in Map is O(logn) in ordered Map; this is is implemented from Red black tree or balanced tree
//unordered map implementaion is from hash table and there search complexity is O(n)