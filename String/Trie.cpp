

#include <bits/stdc++.h>
using namespace std;

#define alphabet 26

class Trie
{
public:
    int cant_string;    // cantidad de string que terminan en el nodo
    int cant_string_me; // cantidad de string que pasan por el nodo
    int cant_node;      // numero de nodos en mi arbol
    char value;
    Trie *children[alphabet];

public:
    Trie(char a)
    {
        cant_string = 0;
        cant_node = 1;
        cant_string_me = 0;
        value = a;

        for (int i = 0; i < alphabet; i++)
        {
            children[i] = NULL;
        }
    }

    pair<Trie *, int> search(string s)
    {
        Trie *node = this;
        int i = 0;

        while (i < s.size() && node->children[s[i] - 'a'] != NULL)
        {
            node = node->children[s[i] - 'a'];
            i++;
        }

        return {node, i};
    }

    void insert(string s)
    {
        int q = s.size() - search(s).second;
        Trie *node = this;

        for (int i = 0; i < s.size(); i++)
        {
            node->cant_node += q;
            if (node->children[s[i] - 'a'] == NULL)
            {
                node->children[s[i] - 'a'] = new Trie(s[i]);
                q--;
            }

            node = node->children[s[i] - 'a'];
            node->cant_string_me++;
        }

        node->cant_string++;
    }

    void eliminate(string s)
    {

        if (!contains(s))
            return;

        Trie *node = this;

        int q = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (node->children[s[i] - 'a'] == NULL)
            {
                node->children[s[i] - 'a'] = new Trie(s[i]);
            }

            if (node->children[s[i] - 'a']->cant_string_me == 1)
            {
                node->children[s[i] - 'a'] = NULL;
                q = s.size() - 1;
                break;
            }

            node = node->children[s[i] - 'a'];
            node->cant_string_me--;

            if (i == s.size() - 1)
            {
                node->cant_string--;
            }
        }

        node = this;
        for (int i = 0; i < s.size() - q + 1; i++)
        {
            node->cant_node -= q;
            node = node->children[s[i] - 'a'];
        }
    }

    bool contains(string s)
    {
        auto q = search(s);
        return q.second == s.size() && q.first->cant_string >= 1;
    }

    
};


signed main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Trie *t = new Trie(' ');

    
    
}