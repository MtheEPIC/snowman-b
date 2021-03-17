#include <math.h>
#include "snowman.hpp"
#define INPUT_LENGTH 8
#define HAT1 "     \n_===_\n" 
#define HAT2 " ___ \n.....\n" 
#define HAT3 "  _  \n /_\\ \n" 
#define HAT4 " ___ \n(_*_)\n"
#define NOSE1 "," 
#define NOSE2 "." 
#define NOSE3 "_" 
#define NOSE4 " " 
#define EYE1 "."
#define EYE2 "o"
#define EYE3 "O"
#define EYE4 "-"
#define LARM1 " <"
#define LARM2 "\\ "
#define LARM3 " /"
#define LARM4 ""
#define RARM1 " >"
#define RARM2 "/ "
#define RARM3 " \\"
#define RARM4 ""
#define TORSO1 " : "
#define TORSO2 "] ["
#define TORSO3 "> <"
#define TORSO4 "   "
#define BASE1 "( : )"
#define BASE2 "(\" \")"
#define BASE3 "(___)"
#define BASE4 "(   )"

std::string HATS[4] = { HAT1, HAT2, HAT3, HAT4 };
std::string NOSES[4] = { NOSE1, NOSE2, NOSE3, NOSE4 };
std::string EYES[4] = { EYE1, EYE2, EYE3, EYE4 };
std::string LARMS[4] = { LARM1, LARM2, LARM3, LARM4 };
std::string RARMS[4] = { RARM1, RARM2, RARM3, RARM4 };
std::string TORSOS[4] = { TORSO1, TORSO2, TORSO3, TORSO4 };
std::string BASES[4] = { BASE1, BASE2, BASE3, BASE4 };

enum snowman_parts_enum {
        hat, nose, leftEye, rightEye, leftArm, rightArm, torso, base 
};


namespace ariel {
    std::string snowman(int input)
    {
        //std::string empty_str = "                                      ";
        std::string snowman_str = "";
        std::string snowman_face = "";
        std::string snowman_head_line = "";
        std::string snowman_torso_line = "";
		std::string prefix = "";
		std::string suffix = "";
		bool is_left_arm = false;
		bool is_right_arm = false;
        int right_arm_type;

        if (input < 0)
            throw std::out_of_range("negative input");
        if (input < 11111111 || input > 44444444)
            throw std::out_of_range("wrong range");
        long input_iter = input;
        while (input_iter > 0)
        {
            if(input_iter%10 != 1 && input_iter % 10 != 2 && input_iter % 10 != 3 && input_iter % 10 != 4)
                throw std::invalid_argument("bad digit");
            input_iter /= 10;
        }
		
		int snowman_parts[INPUT_LENGTH];
		for (int i = 0; i < INPUT_LENGTH; i++)
		{
			snowman_parts[INPUT_LENGTH -i -1] = (input%10)-1;
			input /= 10;
		}
		if (snowman_parts[leftArm] != 3)
		{
			prefix = " ";
			is_left_arm = true;
		}
		if (snowman_parts[rightArm] != 3)
		{
			suffix = " ";
			is_right_arm = true;
		}
		
        for (int i = 0; i < INPUT_LENGTH; i++)
        {
            switch (i)
            {
            case hat:
                snowman_str += prefix + HATS[snowman_parts[i]];
                break;
            case nose:
                snowman_face += NOSES[snowman_parts[i]];
                break;
            case leftEye:
                snowman_face = EYES[snowman_parts[i]] + snowman_face;
                break;
            case rightEye:
                snowman_face += EYES[snowman_parts[i]];
                break;
            case leftArm:
				if (is_left_arm)
				{
					snowman_head_line = LARMS[snowman_parts[i]][0];
					snowman_head_line += "(" + snowman_face;
					snowman_torso_line = LARMS[snowman_parts[i]][1];
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
					snowman_head_line += RARMS[snowman_parts[i]][0];
                snowman_head_line += "\n";
                snowman_str += snowman_head_line;
                right_arm_type = snowman_parts[i];
                break;
            case torso:
                snowman_torso_line += TORSOS[snowman_parts[i]];
                snowman_torso_line += ")";
				if (is_right_arm)
					snowman_torso_line += RARMS[right_arm_type][1];
                snowman_str += snowman_torso_line + "\n";
                break;
            case base:
                snowman_str += prefix + BASES[snowman_parts[i]];
                break;
            default:
                break;
            }
        }
        return snowman_str;
    }
}