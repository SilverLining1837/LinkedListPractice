#include "LL.h"
#include <iostream>
using namespace std;
LL::LL()
{
    head = new Node;
    head->coauthorFirstName = "";
    head->coauthorInstitution = "";
    head->coauthorLastName = "";
    head->paperTitle = "";
    head->year = 0;
    head->next = NULL;
    size = 0;
}

LL::~LL()
{
    clear();
    delete head;
}
bool LL::isEmpty()
{
    return (size == 0) ? true : false;
}
int LL::getLength()
{
    return size;
}
bool LL::insert(string &newCoauthorFirstName, string &newCoauthorLastName, string &newCoauthorInstitution, string &newPaperTitle, int &newYear)
{
    bool cont = false;
    for(int i = 1; i <= size; i++){
        cont = false;
        if(find(i+1) != NULL && find(i+1)->paperTitle.compare(newPaperTitle) == 0){
            cont = true;
        }
        if(find(i)->paperTitle.compare(newPaperTitle) == 0){
            if((find(i)->coauthorLastName.compare(newCoauthorLastName)  == 0 && find(i)->coauthorFirstName.compare(newCoauthorFirstName) == 0))
                return false;
            else{
                if(size == 0){
                    head->next = new Node;
                    head->next->coauthorFirstName = newCoauthorFirstName;
                    head->next->coauthorLastName = newCoauthorLastName;
                    head->next->coauthorInstitution = newCoauthorInstitution;
                    head->next->paperTitle = newPaperTitle;
                    head->next->year = newYear;
                    size++;
                    return true;
                }

                else if(!cont && find(i)->coauthorLastName.compare(newCoauthorLastName) > 0){
                    Node* newNode = new Node;
                    newNode->coauthorFirstName = newCoauthorFirstName;
                    newNode->coauthorLastName = newCoauthorLastName;
                    newNode->coauthorInstitution = newCoauthorInstitution;
                    newNode->paperTitle = newPaperTitle;
                    newNode->year = newYear;
                    newNode->next = find(i);
                    find(i-1)->next = newNode;
                    size++;
                    return true;
                }
                else if(!cont && find(i)->coauthorLastName.compare(newCoauthorLastName) == 0 && find(i)->coauthorFirstName.compare(newCoauthorFirstName) > 0){
                    Node* newNode = new Node;
                    newNode->coauthorFirstName = newCoauthorFirstName;
                    newNode->coauthorLastName = newCoauthorLastName;
                    newNode->coauthorInstitution = newCoauthorInstitution;
                    newNode->year = newYear;
                    newNode->paperTitle = newPaperTitle;
                    newNode->next = find(i);
                    find(i-1)->next = newNode;
                    size++;
                    return true;
                }
                else if(!cont){
                    Node* newNode = new Node;
                    newNode->coauthorFirstName = newCoauthorFirstName;
                    newNode->coauthorLastName = newCoauthorLastName;
                    newNode->coauthorInstitution = newCoauthorInstitution;
                    newNode->year = newYear;
                    newNode->paperTitle = newPaperTitle;
                    newNode->next = find(i+1);
                    find(i)->next = newNode;
                    size++;
                    return true;
                }

            }
        }
    }
    if(size == 0){
        head->next = new Node;
        head->next->coauthorFirstName = newCoauthorFirstName;
        head->next->coauthorLastName = newCoauthorLastName;
        head->next->year = newYear;
        head->next->coauthorInstitution = newCoauthorInstitution;
        head->next->paperTitle = newPaperTitle;
        head->next->year = newYear;
        size++;
        return true;
    }
    else{
        Node* newNode = new Node;
        newNode->coauthorFirstName = newCoauthorFirstName;
        newNode->year = newYear;
        newNode->coauthorLastName = newCoauthorLastName;
        newNode->coauthorInstitution = newCoauthorInstitution;
        newNode->paperTitle = newPaperTitle;
        find(size)->next = newNode;
        newNode->next = NULL;
        size++;
        return true;
    }
}
bool LL::remove(int position, string &newCoauthorFirstName, string &newCoauthorLastName, string &newCoauthorInstitution, string &newPaperTitle, int &newYear)
{
    Node* temp;
    bool done = false;
    if(position >= 1 && position <= size){
        if(position == 1){
            temp = head->next;
            newCoauthorFirstName = head->next->coauthorFirstName;
            newCoauthorLastName = head->next->coauthorLastName;
            newCoauthorInstitution = head->next->coauthorInstitution;
            newPaperTitle = head->next->paperTitle;
            newYear = head->next->year;
            head->next = head->next->next;
            delete temp;
            size--;
        }
        else{
            newCoauthorFirstName = find(position)->coauthorFirstName;
            newCoauthorLastName = find(position)->coauthorLastName;
            newCoauthorInstitution = find(position)->coauthorInstitution;
            temp = find(position);
            newPaperTitle = find(position)->paperTitle;
            newYear = find(position)->year;
            find(position-1)->next = find(position+1);
            delete temp;
            temp = NULL;
            size--;
        }
        done = true;
    }
    return done;
}
void LL::retrieve(int position, string &newCoauthorFirstName, string &newCoauthorLastName, string &newCoauthorInstitution, string &newPaperTitle, int &newYear)
{
    newCoauthorFirstName = find(position)->coauthorFirstName;
    newCoauthorLastName = find(position)->coauthorLastName;
    newCoauthorInstitution = find(position)->coauthorInstitution;
    newPaperTitle = find(position)->paperTitle;
    newYear = find(position)->year;
}
void LL::clear()
{
    int temp = size;
    string a;
    string b;
    string c;
    string d;
    int y;
    for(int i = 1; i <= temp; i++)
    {
        remove(1, a, b, c, d, y);
    }
}

bool LL::check(string newCoauthorFirstName, string newCoauthorLastName, string &institution, string &newPaperTitle)
{
    institution = "";
    bool found = false;
    for(int i = 1; i <= size; i++){
        if(find(i)->coauthorLastName.compare(newCoauthorLastName)  == 0 && find(i)->coauthorFirstName.compare(newCoauthorFirstName) == 0){
             cout << find(i)->coauthorInstitution << ", " << find(i)->paperTitle << ", " << find(i)->year << endl;
            found = true;
        }
    }
    return found;
}

LL::Node* LL::find(int index){
    Node* temp = head->next;
    if(index >= 1 && index <= size){
        for(int i = 1; i < index; i++){
            temp = temp->next;
        }
    }
    return temp;
}
