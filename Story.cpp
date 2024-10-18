#include "Story.h"

// Default constructor
Story::Story(){}

// Constructor that takes a title, duration, and url, setting the values to their according members in the parent function. 
// Also assigns a set 60 seconds as the max duration for a story as specified by the assignment instructions.
Story::Story(string title, int duration, string url){
    Post::set_title(title);
    Post::set_duration(duration);
    Post::set_url(url);
    Post::set_max_duration(60);
}

// Prints out a statement with the edits to the story in accordance to the assignment instructions.
void Story::edit_post(){
    cout << "You have successfully added filters, music, stickers, and effects to this story!" << endl;
}
// Displays the details of the story, including the amount of time (in hours) that is left before the story expires.
void Story::display_post(){
    chrono::steady_clock::time_point time_made = Post::get_timestamp();

    int time_left = Post::time_left();

    if (time_left > 0){
        cout << "Story details: " << endl;
        cout << "The amount of time left to view this story is: " << time_left << " hours." << endl;
        cout << "Title: " << Post::get_title() << endl;
        cout << "Duration (seconds): " << Post::get_duration() << endl;
        cout << "Likes: " << Post::get_likes() << endl;
        cout << "Url: " << Post::get_url() << endl << endl;
    } else {
        cout << "Sorry, this story has expired." << endl << endl;
    }
}