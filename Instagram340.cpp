// TO DO: Implementation of Instagram340 functions
#include "Instagram340.h"
using namespace std;

// Default constructor
Instagram340::Instagram340(){}

// Destructor
Instagram340::~Instagram340(){
	Instagram340::users.clear();
}

// This function takes the necessary information needed to make the user (username, email, password, a short bio, and a profile picture).
// After creating the user, it appends the user to the list.
void Instagram340::createUser(std::string& username, std::string& email, std::string& password,
				std::string& bio, std::string& profilePicture){
	User newUser = User(username, email, password, bio, profilePicture); // Creating the new user 
	shared_ptr<User> newUserptr; // Creating the shared pointer for the new user
	newUserptr = make_shared<User>(newUser); // Assigning the new user to the shared pointer
	bool status = users.append(newUserptr); // Status here specified by given code, isn't used for anything here
}

// Given an index, this function calls the method findKthItem from the LinkedBag class to find the node that the post is in.
// It then returns the user from the node.
shared_ptr<User> Instagram340::getUser(const int& indexK){ 
	Node<shared_ptr<User>>* toReturn = users.findKthItem(indexK); // Creates shared pointer to item at the index specified
	return toReturn->getItem(); // Returns the user by calling getItem on the Node which contains the User
} 