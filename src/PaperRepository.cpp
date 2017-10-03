#include "PaperRepository.h"
#include <iostream>
using namespace std;
PaperRepository::PaperRepository()
{

}

PaperRepository::~PaperRepository()
{
   // dList.clear();
}
void PaperRepository::addPaper( string paperTitle, string journalTitle, int publicationYear )
{
    string t;
    string j;
    int y;

    for(int i = 1; i <= dList.getLength(); i++){
        if(dList.getLength() != 0){
            dList.retrieve(i, t, j, y);

            if(paperTitle.compare(t) == 0){
                cout << "ERROR: Paper " << paperTitle << " already exists" << endl;
                return;
            }
        }
    }
    cout << "INFO: " << paperTitle <<" has been added" << endl;
    dList.insert(dList.getLength()+1, paperTitle, journalTitle, publicationYear);

}
void PaperRepository::removePaper( string paperTitle )
{
    string t;
    string j;
    int y;
    for(int i = 1; i <= dList.getLength(); i++){
        dList.retrieve(i, t, j, y);
        if(paperTitle.compare(t) == 0){
            dList.remove(i, t, j, y);
            cout << "INFO: Paper " << paperTitle << " has been deleted" << endl;
            return;
        }
    }
    cout << "ERROR: Paper " <<  paperTitle << " does not exist" << endl;
}
void PaperRepository::addCoauthor( string paperTitle, string coauthorFirstName, string coauthorLastName, string coauthorInstitution)
{
    string t;
    string j;
    string k;
    int y = 0;
    int year = 0;
    bool found = false;
    for(int i = 1; i <= dList.getLength(); i++){
        dList.retrieve(i, t, j, y);
        if(t.compare(paperTitle) == 0){
            found = true;
            year = y;
        }

    }
     if(!found){
        cout << "ERROR: Paper " << paperTitle << " does not exist" << endl;
        return;
    }

    if(!sList.insert(coauthorFirstName, coauthorLastName, coauthorInstitution, paperTitle, year)){
        cout << "ERROR: Coauthor "<< coauthorFirstName << " " << coauthorLastName << " already is in Paper " << paperTitle << endl;
        return;
    }
    else{
         cout << "INFO: Coauthor " << coauthorFirstName << " " << coauthorLastName << " has been added to Paper " << paperTitle << endl;
         found = true;
    }

}
void PaperRepository::removeCoauthor ( string coauthorFirstName, string coauthorLastName)
{
    string f, l, ins, title, a, b, c, d;
    bool removed = false;
    int y;
    for(int i = 1; i <= sList.getLength(); i++)
    {
        sList.retrieve(i, f, l, ins, title, y);
        if(f.compare(coauthorFirstName) == 0 && l.compare(coauthorLastName) == 0){
            cout << "INFO: Coauthor " << coauthorFirstName << " " << coauthorLastName << " has been deleted from Paper "<< title << endl;
            sList.remove(i, a, b, c, d, y);
            removed = true;
        }
    }

    if(!removed){
        cout << "INFO: Coauthor " << coauthorFirstName << " " << coauthorLastName << " does not have any paper in the repository" << endl;
    }
}
void PaperRepository::showAllPapers()
{
    if(dList.getLength() == 0)
        cout << "---none---" << endl;
    else
        dList.showAll();
}
void PaperRepository::showCoauthor( string coauthorFirstName, string coauthorLastName )
{
    bool found = false;
    cout << coauthorFirstName << " " << coauthorLastName << endl;
    string institution = "";
    string title = "";
    if(!(sList.check(coauthorFirstName, coauthorLastName, institution, title)))
        cout << "---none---" << endl;
}
void PaperRepository::showJournal( string journalTitle )
{
    dList.checkJournal(journalTitle);
}
