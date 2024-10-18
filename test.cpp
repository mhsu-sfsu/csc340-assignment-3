#include <iostream>
#include "Instagram340.h"
using namespace std;

int main(){
    Instagram340 ig = Instagram340();
    ig.createUser("meg", "xx@gmail.com", "pw", "yipppeeeee!", "pfp url");
    // ig.createUser("ryan", "xx@gmail.com", "password123", "bio", "pfp url");
    // ig.createUser("aaron", "xx@gmail.com", "password", "bio", "pfp url");

    User temp = ig.getUser(1);
    cout << "user info: " << endl;
    temp.display_info();

    cout << endl << "-------------" << endl << endl;

    //given that user wants to make a reel:
    temp.create_story("story title", 50, "someurltomediahere");
    temp.create_reel("reel title", 30, "someurltomediahere2");
    temp.display_all_posts();

    //given that user wants to make a story:

    // cout << endl << "-------------" << endl;
    // cout << "changing post title:" << endl;

    // cout << "expected title after change: new and improved title!" << endl;
    // temp.modify_post(2, "new and improved title!");

    // cout << endl << "results: " << endl;
    // temp.display_specific_post(2);
    // temp.display_all_posts();

    return 0;
}