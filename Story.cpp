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
void Story::display_post(Story specificstory){
    chrono::steady_clock::time_point time_made = Post::get_timestamp();

    int time_left = Post::time_left();

    if (time_left > 0){
        cout << specificstory;
    } else {
        cout << "Sorry, this story has expired.\n\n";
    }
}

int Story::time_left(){
    int timeleft = Post::time_left();
    return timeleft;
}

inline ostream& operator<<(ostream& os, Story& specificstory) {
    os << "Story details: \n" 
       << "The amount of time left to view this story is: " << specificstory.time_left() << " hours.\n"
       << "Title: " << specificstory.get_title() << "\n"
       << "Duration (seconds): " << specificstory.get_duration() << "\n"
       << "Likes: " << specificstory.get_likes() << "\n"
       << "Url: " << specificstory.get_url() << "\n\n";
	return os;
} 

inline ostream& operator<<(ostream& os, string& message) {
	os << message;
	return os;
} 