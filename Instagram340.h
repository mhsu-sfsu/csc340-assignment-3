#include "LinkedBagDS/LinkedBag.h"
#include "User.h"
#include <iostream>

#ifndef INSTAGRAM340_H
#define INSTAGRAM340_H

class Instagram340 {
	private:
		LinkedBag<shared_ptr<User>> users;
		
	public:
		// Constructor and destructor
		Instagram340();
		~Instagram340();

		// Create user function
		void createUser(std::string& username, std::string& email, std::string& password,
						std::string& bio, std::string& profilePicture);

		// Get user based on position in list
		shared_ptr<User> getUser(const int& indexK);

		friend ostream& operator<<(ostream& outputStream, const LinkedBag<User>& outputList);
};

#endif