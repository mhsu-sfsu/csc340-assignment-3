#include <chrono>
#include <random>
#include "Post.h"
#include "Reel.h"
#include "Story.h"

// Default constructor
// Sets the timestamp (fixed) and likes (not required but I thought it was fun)
Post::Post(){
	time_stamp = chrono::steady_clock::now();
	likes = std::rand(); // What's life without a little random fun?
}

// Constructor that takes a title, duration of the post, and the url to the media. 
Post::Post(const string& posttitle, const int& newduration, string url){
	set_title(posttitle);
	duration = newduration;
	time_stamp = chrono::steady_clock::now();
	likes = std::rand(); // What's life without a little random fun?
	set_url(url);
}

// Getters
chrono::steady_clock::time_point Post::get_timestamp(){return time_stamp;}
string Post::get_title() {return title;}
int Post::get_likes() {return likes;}
string Post::get_url() {return url;}
int Post::get_duration(){return duration;}

// Setters
void Post::set_title(string posttitle) {title = posttitle;}
void Post::set_duration(int postduration){duration = postduration;}
void Post::set_url(string mediaurl){url = mediaurl;}
void Post::set_max_duration(int maxdur){max_duration = maxdur;}

// time_left() has no parameters and returns the amount of time left that a story is accessible.
int Post::time_left(){ 
	return computeTimeToExpiration();
}

// Virtual functions, they can't be empty so they contain a print statement for each.
void Post::display_post(){
	cout << "display_post function from Post class" << endl;
}

void Post::edit_post(){
	cout << "edit_post function from Post class" << endl;
}


// Given code: --------------------------------------------

// Operator overloading implementation
bool Post::operator==(const Post& otherPost) const {
	return Post::title == otherPost.title;
}

// When displaying a story, use this to compute expected expiration time: timeToExpiration
// Define this as a private function 
int Post::computeTimeToExpiration() const{
	const int secondsInHour = 3600;
	// 24 hours in seconds
	const int expiresAfter = 24 * secondsInHour; 

	// Get current time
	auto time_now = std::chrono::steady_clock::now();
	// Compute elapsed time since post creation
	std::chrono::duration<double> elapsed_seconds = time_now - time_stamp;

	// time to expiration in hours
	int timeToExpiration = (expiresAfter - elapsed_seconds.count()) / secondsInHour;

	return timeToExpiration;
}

// Operator Overloading functions

inline ostream& operator<<(ostream& os, string& message) {
	os << message;
	return os;
} 