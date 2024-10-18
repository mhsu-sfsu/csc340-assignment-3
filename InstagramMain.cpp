#include <iostream> 
#include <string>

// TO DO: #include any other libraries you need
#include "Instagram340.h"
#include <cctype>

using namespace std;

/** 
 * 
 * Displays the application's main menu
 * pre create a new object of type User
 * @param user object to interact with
 * 
 * */

void displayUserManu(User& user){
	int userChoice = 0;
	do {
		cout << "\nHi, "<< user.get_username() <<", what would you like to do:\n"
		<< "1. Display Profile\n"
		<< "2. Modify Password\n"
		<< "3. Create Post\n"
		<< "4. Display All Posts\n"
		<< "5. Display Kth Post\n"
		<< "6. Modify Post\n"
		<< "7. Edit Post\n"
		<< "8. Delete Post\n"
		<< "0. Logout\n"
		<< "Choice: ";
		cin >> userChoice;

		switch (userChoice) {
			case 1:{ 
				// Displays user's profile information
				cout << endl << "Here is your account information: " << endl;
				user.display_info();
				break;
			}
			case 2: { 
				// Asks for new password and update user's password
				cout << "Please enter your new password: ";
				string newpw = "";
				getline(cin >> ws, newpw);
				user.set_password(newpw);
				break;
			}
			case 3: { 
				// Asks user to choose to create a reel or story, then takes input for title, url, and length. 
				// Uses this information to create the post, and adds post to the user's list of posts.
				while (true){
					string ans;
					while (true){
						cout << "Would you like to make a story or reel? Enter 's' or 'story' for the former, 'r' or 'reel for the latter: ";
						getline(cin >> ws, ans);
						std::transform(ans.begin(), ans.end(), ans.begin(), ::tolower);
						if (ans != "r" && ans != "reel" && ans != "s" && ans != "story") {
							cout << "Your input was invalid, please try again. " << endl;
						} else break;
					}

					string title;
					cout << "Enter the title of the post: ";
					getline(cin >> ws, title);

					string url;
					cout << "Emter the media URL of the post: ";
					getline(cin >> ws, url);

					int vidlen;
					std::transform(ans.begin(), ans.end(), ans.begin(), ::tolower);
					if (ans == "r" || ans == "reel"){ // Creating a reel post
						// Checking integer entered for validity
						while (true){
							cout << "Enter the video length of the post (in seconds): ";
							cin >> vidlen;
							if (vidlen > 90 || vidlen < 1){
								cout << "Error, the minimum amount of time is 1 second and the maximum amount of time is 90 seconds. Please try again. " << endl;
								cin.clear();
							} else {
								break;
							}
						}
						
						user.create_reel(title, vidlen, url);
						cout << "Successfully created the reel. " << endl;
						break;
					} else{ // Creating a story post
						// Checking integer entered for validity
						while (true){
							cout << "Enter the video length of the post (in seconds): ";
							cin >> vidlen;
							if (vidlen > 60 || vidlen < 1){
								cout << "Error, the minimum amount of time is 1 second and the maximum amount of time is 60 seconds. Please try again. " << endl;
								cin.clear();
							} else {
								break;
							}
						}

						user.create_story(title, vidlen, url);
						cout << "Successfully created the story. " << endl;
						break;
					} 
				}
				break;
			}
			case 4:{
				// Displays all of the user's posts
				user.display_all_posts();
				break;
			}
			case 5: {
				// Given an index by the user, displays the post at that position in the list of posts.
				// If the index is invalid, the user will be notified of the maximum index that is valid and will be prompted for valid input.
				int index;
				bool display = false;
				bool status = true;
				while (status){
					cout << "Enter in a number k to return the post at that index: ";
					cin >> index;
					
					if (user.number_of_posts() < 1){
						cout << "There are no posts to display at this time. Please create one before trying again. " << endl;
						status = false;
						break;
					} else if (index > user.number_of_posts() && index > 0){
						cout << "Error, the minimum index is 1 and the maximum index of the posts is " << user.number_of_posts() << ". Please try again. " << endl;
						cin.clear();
					} else {
						display = true;
						break;
					}
				}

				if (display) user.display_specific_post(index);
				break;
			}
			case 6: {
				// Modifies post title given an index to the post to be modified, then finds the post and updates it accordingly. 
				// Displays error message with size of the LinkedBag if invalid input is entered and prompts user for input again.

				int index;
				bool status = true;
				bool modify = false;

				while (status){
					cout << "Enter in a number k to modify the post at that index: ";
					cin >> index;
					
					if (user.number_of_posts() < 1){
						cout << "There are no posts to modify at this time. Please create one before trying again. " << endl;
						status = false;
						break;
					} else if (index > user.number_of_posts() && index > 0){
						cout << "Error, the minimum index is 1 and the maximum index of the posts is " << user.number_of_posts() << ". Please try again. " << endl;
						cin.clear();
					} else {
						modify = true;
						break;
					}
				}

				if (modify){
					cout << "Enter the new title of the post: ";
					string newtitle;
					getline(cin >> ws, newtitle);

					user.modify_post(index, newtitle);
				}
				
				break;
			}
			case 7: {
				// Asks user for an index to the post that they would like to edit.
				// Finds post, edits it, and prints confirmation of it.
				int index;
				while (true){
					cout << "Enter in a number k to edit the post at that index: ";
					cin.clear();
					cin >> index;
					if (index > user.number_of_posts() && index > 0){
						if (user.number_of_posts() < 1){
							cout << "There are no posts to edit at the moment. Please create one before trying again. " << endl;
						} else {
							cout << "Error, the minimum index is 1 and the maximum index of the posts is " << user.number_of_posts() << ". " << endl;
						}
					} else {
						break;
					}
				}

				user.edit_post(index);
				break;
				
			}
			case 8: {
				// Asks user for the index of the post that they would like to delete, then deletes it.
				// Displays error message and prompts for an index again if previous input is invalid.
				int index;
				while (true){
					cout << "Enter in a number k to delete the post at that index: ";
					cin.clear();
					cin >> index;
					if (index > user.number_of_posts() && index > 0){
						if (user.number_of_posts() < 1){
							cout << "There are no posts to delete at the moment. Please create one before trying again. " << endl;
						} else {
							cout << "Error, the minimum index is 1 and the maximum index of the posts is " << user.number_of_posts() << ". " << endl;
						}
					} else {
						break;
					}
				}

				user.delete_post(index);				
				break;
			}
			case 0: {
				cout << "Logging you out. " << endl;
				break;
			}
			default:
				cout << "Invalid choice. Please try again. " << endl;
		}

	} while (userChoice != 0);
}


int main(){
	// Instantiating the program using the default constructor
	// With this implementation, the application will only have one user
	Instagram340 instagram; 

	cout << "\nWelcome to Instagram340:" << endl;

	cout << "Please enter a username for your account: ";
	string username;
	getline(cin >> ws, username);

	cout << endl << "Please enter an email address for your account: ";
	string email;
	getline(cin >> ws, email);

	cout << endl << "Please enter a password for your account: ";
	string password;
	getline(cin >> ws, password);

	cout << endl << "Please enter a short bio for your account: ";
	string bio;
	getline(cin >> ws, bio);

	cout << endl << "Please enter the path to the profile picture for your account: ";
	string profilepic;
	getline(cin >> ws, profilepic);

	instagram.createUser(username, email, password, bio, profilepic);	

	// Retrieve the user 
	// User is set to 1 because if we are asking for the first user then we'd assume that 1 = first.
	// All functions in this program are coded in this manner.

	User currentUser = instagram.getUser(1); 

	displayUserManu(currentUser);
				
	return 0;
}