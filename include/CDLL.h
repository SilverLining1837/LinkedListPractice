#ifndef CDLL_H
#define CDLL_H
#include "LL.h"
#include <iostream>
using namespace std;
class CDLL
{
    public:
        CDLL();
        virtual ~CDLL();
        bool isEmpty();
        int getLength();
        bool insert(int newPosition, string &newTitle, string &newJournal, int &newYear);
        bool remove(int position, string &newTitle, string &newJournal, int &newYear);
        void retrieve(int position, string &newTitle, string &newJournal, int &newYear);
        void clear();
        //bool insertCoauthors(int position, string &coauthorFirstName, string &coauthorLastName, string &coauthorInstitution);
        //bool removeCoauthors(int position, string &coauthorFirstName, string &coauthorLastName);
        void showAll();
        //bool showCoauthors(string coauthorFirstName, string coauthorLastName);
        void checkJournal(string journalTitle);
    protected:
    private:

        struct Node{
            Node *next;
            Node *previous;
            string title;
            string journal;
            int year;
        };
        int size;
        Node *find(int index);
        Node *head;
};

#endif // CDLL_H
