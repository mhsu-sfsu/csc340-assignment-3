#include "Post.h"

using namespace std;

#ifndef REEL_H
#define REEL_H

class Reel : public Post{
    public:
        // Constructors and destructor
        Reel();
        Reel(string title, int duration, string url);
        ~Reel(){};

        // Functions that will override parent class (runtime polymorphism)
        void edit_post();
        void display_post();

        friend ostream& operator<<(ostream& os, string& message);
        friend ostream& operator<<(ostream& os, Reel& specificreel);
};

#endif