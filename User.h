// TO DO: #include all the standard libraries and your own libraries here

// To DO: define the class User with the necessary functions and data fields

// This is a function that allows you to compare two users based on their username and email address.  
// You may directly include it in your class definition. 
// You don't need to modify it but will have to put it inside your class. 
// Operator == overloading function prototype:

#include <iostream>
#include <string>
#include "Post.h"
#include "LinkedBagDS/LinkedBag.h"

using namespace std;

#ifndef USER_H
#define USER_H

class User{
    private:
        string username;
        string emailaddress;
        string password;
        string bio;
        string profilepicture;
        LinkedBag<shared_ptr<Post>> posts;

    public:
        // Constructors and destructor
        User();
        User(string nUname, string nEmail, string nPassword, string nBio, string nProfilepicture);
        ~User(){}

        // Helper functions to check for input validity
        bool has_posts();
        bool valid_index(int userinput);
        int number_of_posts();

        // Getters
        string get_username();
        string get_email();
        string get_password();
        string get_bio();
        string get_profilepic();

        // Setters
        void set_username(string newUsername);
        void set_email(string newEmail);
        void set_password(string newPassword);
        void set_bio(string newBio);
        void set_profilepicture(string newProfilepicture);

        // Create post functions
        void create_reel(string title, int duration, string url);
        void create_story(string title, int duration, string url);
        
        // Display functions
        void display_info();
        void display_all_posts();
        void display_specific_post(int postnum);

        // Altering posts
        void modify_post(int postnum, string newtitle);
        void edit_post(int postnum);

        // Deleting posts
        void delete_post(int postnum);

        // Given comparison function
        bool operator==(const User& otherUser) const; 
};


#endif

