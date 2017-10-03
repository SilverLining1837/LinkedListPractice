#ifndef LL_H
#define LL_H
#include <iostream>
using namespace std;

class LL
{
    public:
        LL();
        virtual ~LL();
        bool isEmpty() ;
        int getLength() ;
        bool insert(string &newCoauthorFirstName, string &newCoauthorLastName, string &newCoauthorInstitution, string &newPaperTitle, int &newYear);
        bool remove(int position, string &newCoauthorFirstName, string &newCoauthorLastName, string &newCoauthorInstitution, string &newPaperTitle, int &newYear);
        void retrieve(int position, string &newCoauthorFirstName, string &newCoauthorLastName, string &newCoauthorInstitution, string &newPaperTitle, int &newYear);
        void clear();
        bool check(string coauthorFirstName, string coauthorLastName, string &institution, string &newPaperTitle);
    protected:
    private:

        struct Node{
            Node *next;
            string coauthorFirstName;
            string coauthorLastName;
            string coauthorInstitution;
            string paperTitle;
            int year;

        };
        int size;
        Node *find(int index);
        Node *head;
};

#endif // LL_H
