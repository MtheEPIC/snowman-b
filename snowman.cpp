#include "snowman.hpp"
#include <array>

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
const char *TORSO1 = " : ";
const char *TORSO2 = "] [";
const char *TORSO3 = "> <";
const char *TORSO4 = "   ";
const char *BASE1 = "( : )";
const char *BASE2 = "(\" \")";
const char *BASE3 = "(___)";
const char *BASE4 = "(   )";

std::array<std::string, 4> HATS = { HAT1, HAT2, HAT3, HAT4 };
std::array<std::string, 4> NOSES = { NOSE1, NOSE2, NOSE3, NOSE4 };
std::array<std::string, 4> EYES = { EYE1, EYE2, EYE3, EYE4 };
std::array<std::string, 4> LARMS = { LARM1, LARM2, LARM3, LARM4 };
std::array<std::string, 4> RARMS = { RARM1, RARM2, RARM3, RARM4 };
std::array<std::string, 4> TORSOS = { TORSO1, TORSO2, TORSO3, TORSO4 };
std::array<std::string, 4> BASES = { BASE1, BASE2, BASE3, BASE4 };

enum snowman_parts_enum {
        hat, nose, leftEye, rightEye, leftArm, rightArm, torso, base 
};


namespace ariel {
    std::string snowman(int input)
    {
        //std::string empty_str = "                                      ";
        std::string snowman_str;
        std::string snowman_face;
        std::string snowman_head_line;
        std::string snowman_torso_line;
		std::string prefix;
		std::string suffix;
		bool is_left_arm = false;
		bool is_right_arm = false;
        int right_arm_type = EMPTY_PART_INDEX;

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
		
		std::array<int, INPUT_LENGTH> snowman_parts = {};
		for (int i = 0; i < INPUT_LENGTH; i++)
		{
			snowman_parts[INPUT_LENGTH -i -1] = (input%TEN)-1;
			input /= TEN;
		}
		if (snowman_parts[leftArm] != EMPTY_PART_INDEX)
		{
			prefix = " ";
			is_left_arm = true;
		}
		if (snowman_parts[rightArm] != EMPTY_PART_INDEX)
		{
			suffix = " ";
			is_right_arm = true;
		}
		
        for (int i = 0; i < INPUT_LENGTH; i++)
        {
			int chosen_part = snowman_parts[i];
            switch (i)
            {
            case hat:
                snowman_str += prefix + HATS[chosen_part];
                break;
            case nose:
                snowman_face += NOSES[chosen_part];
                break;
            case leftEye:
                snowman_face = EYES[chosen_part] + snowman_face;
                break;
            case rightEye:
                snowman_face += EYES[chosen_part];
                break;
            case leftArm:
				if (is_left_arm)
				{
					snowman_head_line = LARMS[chosen_part][0];
					snowman_head_line += "(" + snowman_face;
					snowman_torso_line = LARMS[chosen_part][1];
					snowman_torso_line += "(";
				}
				else
				{
					snowman_head_line = "(" + snowman_face;
					snowman_torso_line = "(";
				}
                break;
            case rightArm:
                snowman_head_line += ")";
				if (is_right_arm)
				{
					snowman_head_line += RARMS[chosen_part][0];
				}
                snowman_head_line += "\n";
                snowman_str += snowman_head_line;
                right_arm_type = chosen_part;
                break;
            case torso:
                snowman_torso_line += TORSOS[chosen_part];
                snowman_torso_line += ")";
				if (is_right_arm)
				{
					snowman_torso_line += RARMS[right_arm_type][1];
				}
                snowman_str += snowman_torso_line + "\n";
                break;
            case base:
                snowman_str += prefix + BASES[chosen_part];
                break;
            default:
                break;
            }
        }
        return snowman_str;
    }
}