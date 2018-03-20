#include <iostream>
#include <iomanip>
using namespace std;
namespace{
    class Duree {
    private:
        unsigned long long myDuree;
        unsigned long long mySeconds;
        unsigned long long myMinutes;
        unsigned long long myHours;
        unsigned long long myDays;
        void normaliser () noexcept;
    public:
        Duree (const unsigned long long & d = 10) noexcept;
        void display () const;
        void inc (const unsigned long long & delta) noexcept;
        void dec (const unsigned long long & delta) noexcept;
        unsigned long long getDuree() const noexcept;
    }; //Duree

    unsigned long long Duree::getDuree() const noexcept
    {
        return myDuree;
    }

    void Duree::normaliser() noexcept
    {
        myDays = myDuree / (60*60*24);
        myHours = (myDuree - myDays * 60*60*24) / (60*60);
        myMinutes = (myDuree - myDays * 60*60*24 - myHours * 60*60) / 60;
        mySeconds = myDuree % 60;
    }

    Duree::Duree(const unsigned long long & myDuree_) noexcept:
        //Constructeur par recopie
        myDuree (myDuree_){
        normaliser();
    }

    void Duree::display() const
    {
      cout << setw(4) << myDays << "jour(s)"
           << setw(4) << myHours << "heure(s)"
           << setw(4) << myMinutes << "minute(s)"
           << setw(4) << mySeconds << "seconde(s)" << endl;
    }

    void Duree::inc(const unsigned long long &delta) noexcept
    {
        myDuree += delta;
        normaliser();
    }

    void Duree::dec(const unsigned long long &delta) noexcept
    {
        if (delta < myDuree) return;
        myDuree -= delta;
        normaliser();
    }
}

int main()
{
    //Duree D (1000000);
    //D.display();
    Duree D2;
    D2.display();
    D2.dec(10);
    D2.display();
    return 0;
}
