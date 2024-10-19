#include "Post.h"

using namespace std;

#ifndef STORY_H
#define STORY_H

class Story : public Post{ 
    public:
        // Constructors and destructor
        Story();
        Story(string title, int duration, string url);
        ~Story(){};

        // Functions that will override parent class (runtime polymorphism)
        void edit_post();
        void display_post(Story specificstory);
        int time_left();

        // Operator overloading functions
        friend ostream& operator<<(ostream& os, string& message);
        friend ostream& operator<<(ostream& os, Story& specificstory);
};

#endif