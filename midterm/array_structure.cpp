#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int datain)
    {
        data = datain;
        cout << "d" << next << "bruh\n";
    }

    bool hasNext()
    {
        if (next == NULL)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};

class Array
{
public:
    vector<Node> nodes;

    Array(Node first_node)
    {
        createArray(first_node);
    }

    void createArray(Node firstNode)
    {
        Node snode = firstNode;
        while (snode.hasNext())
        {
            addNode(snode);
            snode = *snode.next;
        }
    }

    void addNode(Node node)
    {
        nodes.push_back(node);
    }

    Node get(int pos)
    {
        return nodes.at(pos);
    }
};

int main()
{
    // Create Three Nodes
    Node *n1 = new Node(5);
    Node *n2 = new Node(2);
    n1->next = n2;
    Node *n3 = new Node(6);
    n2->next = n3;

    cout << "hn" << n1->hasNext() << "\n";
    cout << "hn" << n3->hasNext() << "\n";

    // Array *a1 = new Array(*n1);

    // for (int i = 0; i < a1->nodes.size(); i++)
    // {
    //     cout << a1->get(i).data << "\n";
    // }

    return 0;
}