#include "LinkedBagDS/LinkedBag.h"
#include "User.h"

class Instagram340 {
	private:
		LinkedBag<User> users;
		
	public:
		// Constructor and destructor
		Instagram340();
		~Instagram340();

		// Create user function
		void createUser(const std::string& username, const std::string& email, const std::string& password,
						const std::string& bio, const std::string& profilePicture);

		// Get user based on position in list
		User getUser(const int& indexK);
};