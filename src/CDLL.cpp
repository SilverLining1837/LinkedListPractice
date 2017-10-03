#include "CDLL.h"
#include <iostream>
#include "LL.h"
using namespace std;
CDLL::CDLL()
{
    head = new Node;
    head->next = NULL;
    head->previous = NULL;
    head->title = "";
    head->journal = "";
    head->year = 0;
    size = 0;
}

CDLL::~CDLL()
{
    clear();
    delete head;
}
bool CDLL::isEmpty()
{
    return (size == 0) ? true : false;
}
int CDLL::getLength()
{
    return size;
}
bool CDLL::insert(int newPosition, string &newTitle, string &newJournal, int &newYear)
{

    bool done = false;

    if(newPosition >= 1 && newPosition <=size+1){
        if(newPosition == 1){

            if(size == 0){
                head->next = new Node;
                head->next->title = newTitle;
                head->next->journal = newJournal;
                head->next->year = newYear;
                head->next->previous = NULL;
                head->next->next=NULL;
            }
            else{

                Node* newNode = new Node;
                newNode->title = newTitle;
                newNode->journal = newJournal;
                newNode->year = newYear;
                newNode->next = head->next;
                newNode->previous = head->next->previous;
                head->next->previous->next = newNode;
                head->next->previous = newNode;
                head->next = newNode;
            }
            done = true;
            size++;

        }
        else if(newPosition == size+1){
            Node* newNode = new Node;
            newNode->title = newTitle;
            newNode->journal = newJournal;
            newNode->year = newYear;
            cout << "";
            if(size == 1){
                newNode->next = head->next;
                newNode->previous = head->next;
                head->next->next = newNode;
                head->next->previous = newNode;
            }
            else{
                newNode->next = head->next;
                newNode->previous = head->next->previous;
                head->next->previous->next = newNode;
                head->next->previous = newNode;
            }


            done = true;
            size++;
        }
        else{
            Node* newNode = new Node;
            newNode->title = newTitle;
            newNode->journal = newJournal;
            newNode->year = newYear;
            cout << "";
            newNode->next = find(newPosition);
            newNode->previous = find(newPosition-1);
            newNode->previous->next = newNode;
            newNode->next->previous = newNode;
            done = true;
            size++;
        }
    }
    return done;
}


bool CDLL::remove(int position, string &newTitle, string &newJournal, int &newYear)
{
    bool done = false;
    Node* temp;
    if(position >= 1 && position <= size){
        if(position == 1){
            newTitle = head->next->title;
            newJournal = head->next->journal;
            newYear = head->next->year;
            if(size == 1){
                temp = head->next;
                delete temp;
                temp = NULL;
            }
            else{
                temp = head->next;
                head->next->previous->next = head->next->next;
                head->next->next->previous = head->next->previous;
                head->next = head->next->next;
                delete temp;
                temp = NULL;
            }
            size--;
        }
        else{
            Node* found = find(position);
            newTitle = found->title;
            newJournal = found->journal;
            newYear = found->year;
            found->previous->next = found->next;
            found->next->previous = found->previous;
            delete found;
            found = NULL;
            size--;
        }
        done = true;
    }
    return done;
}
void CDLL::retrieve(int position, string &newTitle, string &newJournal, int &newYear)
{
    newTitle = find(position)->title;
    newJournal = find(position)->journal;
    newYear = find(position)->year;
}
void CDLL::clear()
{
    int temp = size;
    string a;
    string b;
    int c;
    for(int i = 1; i <= temp; i++)
    {
        remove(1, a, b, c);
    }
}
void CDLL::showAll()
{
    if(size == 0){
        cout << "---none---" << endl;
    }
    else{
        for(int i = 1; i <= size; i++){
            cout << find(i)->title << ", " << find(i)->journal << ", " << find(i)->year << endl;
        }
    }
}

void CDLL::checkJournal(string journalTitle)
{
    bool found = false;
    cout << journalTitle << endl;
    for(int i = 1; i <= size; i++){
        if(find(i)->journal.compare(journalTitle) == 0){
            found = true;
            cout << find(i)->title << ", " << find(i)->year << endl;
        }
    }
    if(!found){
        cout << "---none---" << endl;
    }
}

CDLL::Node* CDLL::find(int index){
    Node* temp = head->next;
    if(index >= 1 && index <= size){
        for(int i = 1; i < index; i++){
            temp = temp->next;
        }
    }
    return temp;
}
