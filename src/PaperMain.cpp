#include <iostream>
using namespace std;
#include "PaperRepository.h"
int main()
{
    PaperRepository pr;
    cout << endl;
    pr.showAllPapers();
    cout << endl;
    pr.addPaper("Smoke Simulation", "SIGGRAPH", 2010);
    pr.addPaper("3D Thumbnail", "Algorithms and Technologies", 2011);
    pr.addPaper("Dynamic Clustering", "SIGIR", 1999);
    pr.addPaper("Efficient SVMs", "IEEE", 1999);
    pr.addPaper("Neural Networks", "IEEE", 2002);
    pr.addPaper("Neural Networks", "ICML", 2005);
    cout << endl;
    pr.showAllPapers();
    cout << endl;
    pr.addCoauthor("Smoke Simulation", "Okan", "Arikan", "Bilkent");
    pr.addCoauthor("3D Thumbnail", "Sena", "Atik", "AYESAS");
    pr.addCoauthor("3D Thumbnail", "Funda", "Atik", "AYESAS");
    pr.addCoauthor("Dynamic Clustering", "Gokhan", "Akcay", "Bilkent");
    pr.addCoauthor("Neural Networks", "Aynur", "Dayanik", "Bilkent");
    pr.addCoauthor("Neural Networks", "Funda", "Atik", "Bilkent");
    pr.addCoauthor("Explosion Simulation", "Aynur", "Dayanik", "Bilkent");
    pr.addCoauthor("Neural Networks", "Aynur", "Dayanik", "Bilkent");
    pr.addCoauthor("3D Thumbnail", "Yeliz", "Yigit", "Yogurt Tech.");
    pr.addCoauthor("Efficient SVMs", "Cigdem", "Gunduz Demir", "Bilkent");
    pr.addCoauthor("Efficient SVMs", "Funda", "Atik", "Bilkent");
    cout << endl;
    pr.showCoauthor("Funda", "Atik");
    cout << endl;
    pr.showCoauthor("Aynur", "Dayanik");
    cout << endl;
    pr.removeCoauthor("Funda", "Atik");
    pr.removeCoauthor("Aynur", "Dayanik");
    pr.removeCoauthor("Can", "Koyuncu");
    cout << endl;
    pr.showCoauthor("Funda", "Atik");
    cout << endl;
    pr.showCoauthor("Aynur", "Dayanik");
    cout << endl;
    pr.showJournal("Algorithms and Technologies");
    cout << endl;
    pr.showJournal("IEEE");
    cout << endl;
    pr.removePaper("Neural Networks");
    pr.removePaper("3D Thumbnail");
    pr.removePaper("Explosion Simulation");
    cout << endl;
    pr.showJournal("Algorithms and Technologies");
    cout << endl;
    pr.showJournal("IEEE");
    cout << endl;
    pr.showAllPapers();
    cout << endl;
    return 0;
}
