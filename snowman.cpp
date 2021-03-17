#include "snowman.hpp"
#include <math.h>
#include <vector>

constexpr int INPUT_LENGTH = 8;
constexpr int MIN_INPUT = 11111111;
constexpr int MAX_INPUT = 44444444;
constexpr int EMPTY_PART_INDEX = 3;
constexpr int TEN = 10;
const char *HAT1  = "     \n_===_\n";
const char *HAT2 = " ___ \n.....\n";
const char *HAT3 = "  _  \n /_\\ \n"; 
const char *HAT4 = " ___ \n(_*_)\n";
const char *NOSE1 = ",";
const char *NOSE2 = ".";
const char *NOSE3 = "_"; 
const char *NOSE4 = " ";
const char *EYE1 = ".";
const char *EYE2 = "o";
const char *EYE3 = "O";
const char *EYE4 = "-";
const char *LARM1 = " <";
const char *LARM2 = "\\ ";
const char *LARM3 = " /";
const char *LARM4 = "";
const char *RARM1 = " >";
const char *RARM2 = "/ ";
const char *RARM3 = " \\";
const char *RARM4 = "";
const char *TORSO1 = "( : )";
const char *TORSO2 = "(] [)";
const char *TORSO3 = "(> <)";
const char *TORSO4 = "(   )";
const char *BASE1 = "( : )";
const char *BASE2 = "(\" \")";
const char *BASE3 = "(___)";
const char *BASE4 = "(   )";

const vector<string> HATS = { HAT1, HAT2, HAT3, HAT4 };
const vector<string> NOSES = { NOSE1, NOSE2, NOSE3, NOSE4 };
const vector<string> EYES = { EYE1, EYE2, EYE3, EYE4 };
const vector<string> LARMS = { LARM1, LARM2, LARM3, LARM4 };
const vector<string> RARMS = { RARM1, RARM2, RARM3, RARM4 };
const vector<string> TORSOS = { TORSO1, TORSO2, TORSO3, TORSO4 };
const vector<string> BASES = { BASE1, BASE2, BASE3, BASE4 };

enum snowman_parts_enum {
        hat, nose, leftEye, rightEye, leftArm, rightArm, torso, base 
};


namespace ariel {
	std::vector<int> snowman_parts;
	std::string snowman_str;
	std::string snowman_face;
	std::string snowman_head_line;
	std::string snowman_torso_line;
	std::string prefix;
	bool is_left_arm;
	bool is_right_arm;
		
    std::string snowman(int input)
    {
		snowman_parts.clear();
		snowman_str = "";
		snowman_face = "";
		snowman_head_line = "";
		snowman_torso_line = "";
		prefix = "";
		is_left_arm = false;
		is_right_arm = false;
		
		// Check input
        if (input < 0)
		{
            throw std::out_of_range("negative input");
		}
        if (input < MIN_INPUT || input > MAX_INPUT)
		{
            throw std::out_of_range("wrong range");
		}
        long input_iter = input;
        while (input_iter > 0)
        {
            if(input_iter % TEN != 1 && input_iter % TEN != 2 && input_iter % TEN != 3 && input_iter % TEN != 4)
			{
                throw std::invalid_argument("bad digit");
			}
            input_iter /= TEN;
        }
		
		// Parse values
		for (int i = 1; i <= INPUT_LENGTH; i++)
		{
			int digit = (input / (int) pow(TEN, INPUT_LENGTH - i));
			digit = (digit % TEN) -1;
			snowman_parts.push_back(digit);
		}
		if (snowman_parts.at(leftArm) != EMPTY_PART_INDEX)
		{
			prefix = " ";
			is_left_arm = true;
		}
		if (snowman_parts.at(rightArm) != EMPTY_PART_INDEX)
		{
			is_right_arm = true;
		}
		
		// Run snowman
		add_hat();
		add_face();
		add_torso();
		add_base();
		
        return snowman_str;
    }
	
	void add_hat()
	{
		snowman_str = prefix;
		snowman_str.append(HATS.at(snowman_parts.at(hat)));
	}
	
	void add_face()
	{
		snowman_face = "(";
		snowman_face.append(EYES.at(snowman_parts.at(leftEye)));
		snowman_face.append(NOSES.at(snowman_parts.at(nose)));
		snowman_face.append(EYES.at(snowman_parts.at(rightEye)));
		snowman_face.append(")");
	}
	
	void add_left_arm()
	{
		if (is_left_arm)
		{
			snowman_head_line = LARMS.at(snowman_parts.at(leftArm))[0];
			snowman_torso_line = LARMS.at(snowman_parts.at(leftArm))[1];
		}
	}
	
	void add_right_arm()
	{
		if (is_right_arm)
		{
			snowman_head_line += RARMS.at(snowman_parts.at(rightArm))[0];
			snowman_torso_line += RARMS[snowman_parts.at(rightArm)][1];
		}
	}
	
	void add_torso()
	{
		add_left_arm();
		
		snowman_head_line.append(snowman_face);
		snowman_torso_line.append(TORSOS.at(snowman_parts.at(torso)));
		
		add_right_arm();
		
		snowman_head_line.append("\n");
		snowman_str.append(snowman_head_line);
		
		snowman_str.append(snowman_torso_line + "\n");
	}
	
	void add_base()
	{
		snowman_str += prefix + BASES.at(snowman_parts.at(base));
	}
}