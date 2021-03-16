#include <math.h>
#include "snowman.hpp"
#define INPUT_LENGTH 8
#define HAT1 "       \n _===_ \n" 
#define HAT2 "  ___  \n ..... \n" 
#define HAT3 "   _   \n  /_\\  \n" 
#define HAT4 "  ___  \n (_*_) \n"
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
#define LARM4 "  "
#define RARM1 " >"
#define RARM2 "/ "
#define RARM3 " \\"
#define RARM4 "  "
#define TORSO1 " : "
#define TORSO2 "] ["
#define TORSO3 "> <"
#define TORSO4 "   "
#define BASE1 "\n ( : ) "
#define BASE2 "\n (\" \") "
#define BASE3 "\n (___) "
#define BASE4 "\n (   ) "

std::string HATS[4] = { HAT1, HAT2, HAT3, HAT4 };
std::string NOSES[4] = { NOSE1, NOSE2, NOSE3, NOSE4 };
std::string EYES[4] = { EYE1, EYE2, EYE3, EYE4 };
std::string LARMS[4] = { LARM1, LARM2, LARM3, LARM4 };
std::string RARMS[4] = { RARM1, RARM2, RARM3, RARM4 };
std::string TORSOS[4] = { TORSO1, TORSO2, TORSO3, TORSO4 };
std::string BASES[4] = { BASE1, BASE2, BASE3, BASE4 };




namespace ariel {
    std::string snowman(int input)
    {
        std::string empty_str = "                                      ";
        std::string snowman_str = "";
        std::string snowman_face = "";
        std::string snowman_head_line = "";
        std::string snowman_torso_line = "";
        int right_arm_type;

        if (input < 0)
            throw std::exception{ "negative input" };
        if (input < 11111111 || input > 44444444)
            throw std::exception{ "wrong range" };
        long input_iter = input;
        while (input_iter > 0)
        {
            if(input_iter%10 != 1 && input_iter % 10 != 2 && input_iter % 10 != 3 && input_iter % 10 != 4)
                throw std::exception{ "bad digit" };
            input_iter /= 10;
        }

        int digit_val;
        for (int i = 1; i <= INPUT_LENGTH; i++)
        {
            digit_val = (input / pow(10, INPUT_LENGTH - i));
            digit_val %= 10;
            digit_val--;
            switch (i)
            {
            case 1:
                snowman_str += HATS[digit_val];
                break;
            case 2:
                snowman_face += NOSES[digit_val];
                break;
            case 3:
                snowman_face = EYES[digit_val] + snowman_face;
                break;
            case 4:
                snowman_face += EYES[digit_val];
                break;
            case 5:
                snowman_head_line = LARMS[digit_val][0];
                snowman_head_line += "(" + snowman_face;
                snowman_torso_line = LARMS[digit_val][1];
                snowman_torso_line += "(";
                break;
            case 6:
                snowman_head_line += ")";
                snowman_head_line += RARMS[digit_val][0];
                snowman_head_line += "\n";
                snowman_str += snowman_head_line;
                right_arm_type = digit_val;
                break;
            case 7:
                snowman_torso_line += TORSOS[digit_val];
                snowman_torso_line += ")";
                snowman_torso_line += RARMS[right_arm_type][1];
                snowman_str += snowman_torso_line;
                //snowman_str += "\n";
                break;
            case 8:
                snowman_str += BASES[digit_val];
                break;
            default:
                break;
            }
        }
        return snowman_str;
    }
}