#ifndef PAPERREPOSITORY_H
#define PAPERREPOSITORY_H
#include <iostream>
#include "CDLL.h"
using namespace std;

class PaperRepository
{   public:
        PaperRepository ();
        ~ PaperRepository ();
        void addPaper( string paperTitle, string journalTitle,int publicationYear );
        void removePaper( string paperTitle );
        void addCoauthor( string paperTitle, string coauthorFirstName, string coauthorLastName, string coauthorInstitution);
        void removeCoauthor ( string coauthorFirstName, string coauthorLastName);
        void showAllPapers();
        void showCoauthor( string coauthorFirstName, string coauthorLastName );
        void showJournal( string journalTitle );
    private:
        CDLL dList;
        LL sList;
};

#endif // PAPERREPOSITORY_H
