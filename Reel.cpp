#include "Reel.h"

using namespace std;

// Default constructor
Reel::Reel(){} 

// Constructor that takes a title, duration, and url, setting the values to their according members in the parent function. 
// Also assigns a set 90 seconds as the max duration for a reel as specified by the assignment instructions.
Reel::Reel(string reeltitle, int reelduration, string url){
    Post::set_title(reeltitle);
    Post::set_duration(reelduration);
    Post::set_url(url);
    Post::set_max_duration(90);
}

// Prints out a statement with the edits to the reel in accordance to the assignment instructions.
void Reel::edit_post(){
    cout << "You have successfully added a filter, AR effects, and music to this reel!" << endl;
}

// Displays the details of the reel.
void Reel::display_post(){
    cout << "Reel details: " << endl;
    cout << "Title: " << Post::get_title() << endl;
    cout << "Duration (seconds): " << Post::get_duration() << endl;
    cout << "Likes: " << Post::get_likes() << endl;
    cout << "Url: " << Post::get_url() << endl << endl;
}