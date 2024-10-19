// TO DO: #include all the standard libraries and your own libraries here

// To DO: define the class Post with the necessary functions' prototypes and data fields

#include <iostream>
#include <chrono>
using namespace std;

#ifndef POST_H
#define POST_H

class Post{
    private:
        string title;
        chrono::steady_clock::time_point time_stamp;
        int likes;
        string url;
        int duration;
        int max_duration;

        // This is a helper function -- it should be private.
        int computeTimeToExpiration() const;

    public:
        // Constructors and destructor
        Post(); 
        Post(const string& posttitle, const int& newduration, string url);
        ~Post(){}

        // Getters
        string get_title();
        int get_likes();
        string get_url();
        int get_duration();
        chrono::steady_clock::time_point get_timestamp();

        // Setters
        void set_title(string posttitle);
        void set_duration(int duration);
        void set_url(string mediaurl);
        void set_max_duration(int maxdur);

        int time_left();

        // Virtual functions
        virtual void display_post();
        virtual void edit_post();

        // This is a function that allows you to compare two posts based on their title. 
        // You may directly include it in your class definition. 
        // You don't need to modify it but will have to put it inside your class. 
        // Operator overloading function prototype:
        bool operator==(const Post& otherPost) const; 


        // Operator overloading functions
        friend ostream& operator<<(ostream& os, string& message);
};

#endif