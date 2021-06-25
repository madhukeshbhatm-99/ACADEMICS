#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int key;
    node **forward;
    node(int k, int level)
    {
        key = k;
        forward = new node *[level + 1];
        memset(forward, 0, sizeof(node *) * (level + 1));
    }
};

class skiplist
{
    int maxlvl;
    int lvl;
    float p;
    node *header;

public:
    skiplist(int mlvl, float po)
    {
        maxlvl = mlvl;
        p = po;
        lvl = 0;
        header = new node(-1, maxlvl);
    }
    int randomlvl()
    {
        float r = (float)rand() / RAND_MAX;
        int levl = 0;
        while (levl < maxlvl && r < p)
        {
            levl++;
            r = (float)rand() / RAND_MAX;
        }
        return levl;
    }
    node *create(int k, int lvl)
    {
        node *n = new node(k, lvl);
        return n;
    }
    void insert(int k)
    {
        node *curr = header;
        node *updte[maxlvl + 1];
        memset(updte, 0, sizeof(node *) * (maxlvl + 1));
        for (int i = lvl; i >= 0; i--)
        {
            while (curr->forward[i] != NULL && curr->forward[i]->key < k)
                curr = curr->forward[i];
            updte[i] = curr;
        }
        curr = curr->forward[0];
        if (curr == NULL || curr->key != k)
        {
            int rlvl = randomlvl();
            if (rlvl > lvl)
            {
                for (int i = lvl + 1; i < rlvl + 1; i++)
                {
                    updte[i] = header;
                }
                lvl = rlvl;
            }
            node *n = create(k, rlvl);
            for (int i = 0; i <= rlvl; i++)
            {
                n->forward[i] = updte[i]->forward[i];
                updte[i]->forward[i] = n;
            }
        }
    }
    void delet(int k)
    {
        node *curr = header;
        node *updte[maxlvl + 1];
        memset(updte, 0, sizeof(node *) * (maxlvl + 1));
        for (int i = lvl; i >= 0; i--)
        {
            while (curr->forward[i] != NULL && curr->forward[i]->key < k)
                curr = curr->forward[i];
            updte[i] = curr;
        }
        curr = curr->forward[0];
        if (curr == NULL || curr->key == k)
        {
            for (int i = 0; i <= lvl; i++)
            {
                if (updte[i]->forward[i] != curr)
                    break;
                updte[i]->forward[i] = curr->forward[i];
            }
            while (lvl > 0 && header->forward[0] == NULL)
                lvl--;
            delete curr;
        }
        else
            cout << "Element not present\n";
    }
    void search(int k)
    {
        node *curr = header;
        for (int i = lvl; i >= 0; i--)
        {
            while (curr->forward[i] != NULL && curr->forward[i]->key < k)
                curr = curr->forward[i];
        }
        curr = curr->forward[0];
        if (curr == NULL || curr->key == k)
            cout << "Element found!" << endl;
        else
            cout << "Element not found!" << endl;
    }
    void display()
    {
        cout << "The Skip List elements are: " << endl;
        for (int i = 0; i <= lvl; i++)
        {
            cout << "Level " << i << ": ";
            node *n = header->forward[i];
            while (n)
            {
                cout << n->key << " ";
                n = n->forward[i];
            }
            cout << endl;
        }
    }
};

int main()
{
    int n, ele, x;
    srand((unsigned)time(0));
    skiplist lst(3, 0.5);
    cout << "Enter the number of elements to be inserted: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        lst.insert(x);
    }
    lst.display();
    cout << "Enter the element to be deleted: ";
    cin >> ele;
    lst.delet(ele);
    lst.display();
    cout << "Enter the element to be searched: ";
    cin >> ele;
    lst.search(ele);
    return 0;
}
