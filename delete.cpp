#include <bits/stdc++.h>
#include <fstream>
#include <process.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <direct.h>
#include <windows.h>
#include <time.h>
#include <algorithm>
using namespace std;

string search_word = "";
// unordered_map<string, vector<string>> dic_mp;
class DICTIONORY
{
public:
    unordered_map<string, vector<string>> mp;

    void add_word(string k, string v)
    {
        mp[k].push_back(v);
    }

    unordered_map<string, vector<string>> ret_word()
    {
        return mp;
    }

} DIC;

struct Node
{
    Node *links[26];
    // bool falg = false;
    vector<vector<string>> vec;
};
Node *root = new Node();
void add_to_trie(unordered_map<string, vector<string>> &dic_map)
{
    for (auto it = dic_map.begin(); it != dic_map.end(); it++)
    {
        string s = it->first;
        Node *temp = root;

        for (char ch : s)
        {
            if (temp->links[ch - 'a'] == NULL)
            {
                Node *node = new Node();
                temp->links[ch - 'a'] = node;
            }
            temp = temp->links[ch - 'a'];
            temp->vec.push_back(it->second);
        }
    }
}
void search_in_trie(string &searchWord)
{
    cout << "WORD-{" << searchWord << "}" << endl;
    // Node *root = new Node();
    Node *temp = root;
    int n = searchWord.size();
    // vector<vector<string>> vec(n);
    bool flag = true;
    for (char ch : searchWord)
    {
        if (temp->links[ch - 'a'] == NULL)
        {
            flag = false;
            break;
        }

        temp = temp->links[ch - 'a'];
    }
    if (flag)
    {
        cout << "{Means- ";
        vector<vector<string>> &res = temp->vec;
        for (vector<string> s : res)
        {
            for (string value : s)
                cout << value << " ";
            cout << "}" << endl;
        }
    }
    else
        cout << "word does not exist in dictionory" << endl;
}

void AddToDictionory()
{
    fstream c1;
    system("CLS");
    c1.open("dictionory.txt", ios::binary | ios::out | ios::app);
    string key, val;
    cout << "enter key" << endl;
    cin >> key;
    cout << "enter value" << endl;
    cin >> val;
    DIC.add_word(key, val);
    c1.write((char *)&DIC, sizeof(DICTIONORY));
    c1.close();
    getch();
    system("CLS");
}

void RemoveFromDictionory()
{
    cout << "Enter word to remove" << endl;
    string remove_word;
    cin >> remove_word;
    fstream f1, f2;
    f1.open("DICTIONORY.txt", ios::binary | ios::in);
    f2.open("TEMP.txt", ios::binary | ios::out);
    f1.seekg(0, ios::beg);
    while (f1.read((char *)&DIC, sizeof(DICTIONORY)))
    {
        // if (DIC.key != remove_word)
        // {
        //     f2.write((char *)&DIC, sizeof(DICTIONORY));
        // }
    }
    f2.close();
    f1.close();
    remove("dictionory.txt");
    rename("TEMP.txt", "dictionory.txt");
    getch();
    system("CLS");
}

void SearchInDictionory()
{
    unordered_map<string, vector<string>> dic_map;

    fstream c1;

    c1.open("dictionory.txt", ios::binary | ios::in);
    while (c1.read((char *)&DIC, sizeof(DICTIONORY)))
    {
        dic_map = DIC.ret_word();
    }
    c1.close();

    add_to_trie(dic_map);

    cout << "Enter search word" << endl;
    char ch;

    while (true)
    {
        if (kbhit())
        {
            ch = getch();
            if (ch != 13)
            {
                search_word += ch;
                system("CLS");
                // cout << " " << search_word << endl;
                search_in_trie(search_word);
            }
            else
            {
                system("CLS");
                search_in_trie(search_word);
            }
        }
    }
}
int main()
{
    bool yes = true;
    while (yes)
    {
        system("CLS");
        cout << "1.Search" << endl;
        cout << "2.Add" << endl;
        cout << "3.Remove" << endl;
        cout << "4.Exit" << endl;

        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            SearchInDictionory();
            break;

        case 2:
            AddToDictionory();
            break;

        case 3:
            RemoveFromDictionory();
            break;

        case 4:
            yes = false;
            break;
        }
    }
    return 0;
}