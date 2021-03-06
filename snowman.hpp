#pragma once
#include<iostream>
using namespace std;

namespace ariel {
    string snowman(int); // main func to create snowman
	
	void check_input(int); // checks if input is valid
	void parse_input(int); // parses input into vars
	
	void add_hat(); // creates hat
	void add_face(); // creates nose and eyes
	void add_torso(); // creates torso
	void add_left_arm(); // called by 'add_torso' and add arms if needed
	void add_right_arm(); // called by 'add_torso' and add arms if needed
	void add_base(); // creates base
}