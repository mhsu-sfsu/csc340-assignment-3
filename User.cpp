#include "User.h"
#include "Reel.h"
#include "Story.h"

using namespace std;

// Default constructor
User::User(){} 

// Constructor taking a username, email, password, bio, and profile picture
User::User(const string nUname, const string nEmail, const string nPassword, const string nBio, const string nProfilepicture){
	set_username(nUname);
	set_email(nEmail);
	set_password(nPassword);
	set_bio(nBio);
	set_profilepicture(nProfilepicture);
}

// Helper functions to check for input validity
bool User::has_posts(){
	return (posts.getCurrentSize() > 0);
}

bool User::valid_index(int userindex){
	return (userindex <= posts.getCurrentSize());
}

int User::number_of_posts(){ // Returns the number of posts that the user has created
	return posts.getCurrentSize();
}

// Getters
string User::get_username() {return username;}
string User::get_email() {return emailaddress;}
string User::get_password() {return password;}
string User::get_bio() {return bio;}
string User::get_profilepic() {return profilepicture;}

// Setters
void User::set_username(string newUsername) {username = newUsername;}
void User::set_email(string newEmail) {emailaddress = newEmail;}
void User::set_password(string newPassword) {password = newPassword;}
void User::set_bio(string newBio) {bio = newBio;}
void User::set_profilepicture(string newProfilepicture) {profilepicture = newProfilepicture;}

// Display function to print out user information (minus the user's password)
void User::display_info(){
	cout << "Username: " << get_username() << endl;
	cout << "Email address: " << get_email() << endl;
	cout << "Bio: " << get_bio() << endl;
	cout << "Profile picture: " << get_profilepic() << endl;
}

// Create functions for reels and stories respectively. 
// Takes a title, duration, and url and insers a pointer to the post into the user's post list
void User::create_reel(string title, int duration, string url){
	Reel* newReel = new Reel(title, duration, url);
	posts.append(newReel);
}

void User::create_story(string title, int duration, string url){
	Story* newStory = new Story(title, duration, url);
	posts.append(newStory);
}

// Displays all of the user's posts
void User::display_all_posts(){
	// No posts are searched for unless there are posts in the list.
	if (has_posts()){ 
		Node<Post*> *curptr = posts.findKthItem(1); // Setting the first pointer to the first node (head)
		Node<Post*> *nextptr = curptr->getNext(); // Setting the second pointer to point to the node after the first

		while (curptr != nullptr) { // Displays the post as long as the pointer is not null 
			curptr->getItem()->display_post();

			curptr = nextptr; // Setting the current pointer to the next one, effectively traveling down the list

			// Checking condition because while loops only check at the beginning of the loop, the validity of the statement can change.
			if (curptr != nullptr) nextptr = nextptr->getNext(); 
		}
	} else cout << "You haven't created any posts." << endl;
}

// To display a specific post, the function takes an index as the input.
// It then calls findKthItem, passing in the index to get the pointer to the node. 
// Using that, the contents of the node can be accessed and printed
void User::display_specific_post(int postnum){
	if (has_posts() && postnum > 0){
		Node<Post*> *postptr = posts.findKthItem(postnum); // Setting the first pointer to the post at the index specified.

		postptr->getItem()->display_post(); // After getting the pointer, the post can be accessed and printed using runtime polymorphism.

	} else if (posts.getCurrentSize() <= 0 && postnum > 0) { 
		// Case for no posts in list
		cout << "There are no posts to display at this time. Please create a post first." << endl;
	} else { 
		// Case for at least 1 post in the list, prints out current size of the list.
		cout << "Invalid index entered. The minimum index is 1 and the maximum index is currently " << posts.getCurrentSize() << endl;
	}
}	

// To modify a post (change its title), the function takes an index to the post and the new title in the form of a string.
// A pointer to the node that contains the post is first made. After making a pointer to the post itself, the new title can be set.
void User::modify_post(int postnum, string newtitle){
	if (has_posts()){
		if (valid_index(postnum)){
			Node<Post*>* postptr = posts.findKthItem(postnum); // Creating pointer to the node with the item to modify
			Post* tomodify = postptr->getItem(); // Setting pointer tomodify to have contents of the item
			tomodify->set_title(newtitle); // Modifying the post
			postptr->setItem(tomodify); //Setting the item in the node to the modified item
		} else {
			// Print statement for invalid index
			cout << "Invalid index, the minimum index is 1 and the maximum index that can be entered is currently " << posts.getCurrentSize() << "." << endl;
		}
	} else {
		// Print statement for empty list
		cout << "There are no posts to modify at this time. Please try again when you have created a post." << endl;
	}
}

// To edit a post, the index to the specific post is needed. 
// This function uses runtime polymorphism so the function that is called will print the correct edits depending on the post type.
void User::edit_post(int postnum){
	if (has_posts()){
		if (valid_index(postnum)){
			Node<Post*> *postptr = posts.findKthItem(postnum); // Pointer to the post we would like to edit
			postptr->getItem()->edit_post(); // Using the pointer to access the post and the edit_post() method in the child classes.
		} else {
			// Print statement for invalid index
			 cout << "Invalid index, the minimum index is 1 and the maximum index that can be entered is currently " << posts.getCurrentSize() << "." << endl;
		}
	} else {
		// Print statement for empty list
		cout << "There are no posts to edit at this time. Please try again when you have created a post." << endl;
	}
}

// To delete a specific post, the function takes the index to the post that will be deleted.
// After the post is found, the LinkedBag remove() function is called to delete the node.
void User::delete_post(int postnum){ // user remove method from node class to delete item
	if (has_posts()){
		if (valid_index(postnum)){
			Node<Post*>* postptr = posts.findKthItem(postnum); // Pointer to node with post to delete
			posts.remove((*postptr).getItem());
		} else {
			// Print statement for invalid index
			 cout << "Invalid index, the minimum index is 1 and the maximum index that can be entered is currently " << posts.getCurrentSize() << "." << endl;
		}
	} else {
		// Print statement for empty list
		cout << "There are no posts to delete at this time. Please try again when you have created a post." << endl;
	}
}

// Function provided with starter code
bool User::operator==(const User& otherUser) const {
	return (User::username == otherUser.username) && (User::emailaddress == otherUser.emailaddress);
}