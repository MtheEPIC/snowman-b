#include "doctest.h"
#include "snowman.hpp"
#include <string.h>

using namespace ariel;
using namespace std;

TEST_CASE("Good snowman example")
{
    CHECK(snowman(11114411) == string("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(snowman(11113411) == string(" _===_\n (.,.)\n/( : )\n ( : )"));
    CHECK(snowman(11114311) == string("_===_ \n(.,.) \n( : )\\\n( : ) "));
    CHECK(snowman(11113311) == string(" _===_ \n (.,.) \n/( : )\\\n ( : ) "));

    CHECK(snowman(41114411) == string(" ___ \n(_*_)\n(.,.)\n( : )\n( : )"));
    CHECK(snowman(41113411) == string("  ___ \n (_*_)\n (.,.)\n/( : )\n ( : )"));
    CHECK(snowman(41114311) == string(" ___  \n(_*_) \n(.,.) \n( : )\\\n( : ) "));
    CHECK(snowman(41113311) == string("  ___  \n (_*_) \n (.,.) \n/( : )\\\n ( : ) "));
}

TEST_CASE("Bad snowman input length")
{
    CHECK_THROWS(snowman(111144114));
    CHECK_THROWS(snowman(1111441));
    //CHECK_THROWS(snowman(NULL));
}

TEST_CASE("Good snowman output length")
{
    // small hat
    CHECK(snowman(11114411).length() == 24); // no arms
    CHECK(snowman(11113411).length() == 28); // one arm
    CHECK(snowman(11114311).length() == 28); // one arm
    CHECK(snowman(11113311).length() == 32); // two arm
    // big hat
    CHECK(snowman(21114411).length() == 30); // no arms
    CHECK(snowman(21113411).length() == 35); // one arm
    CHECK(snowman(21114311).length() == 35); // one arm
    CHECK(snowman(21113311).length() == 40); // two arm
}

TEST_CASE("Bad snowman values")
{
    CHECK_THROWS(snowman(11104411));
    CHECK_THROWS(snowman(11154411));
    CHECK_THROWS(snowman(11114410));
    CHECK_THROWS(snowman(01114411));
    CHECK_THROWS(snowman(-11114411));
}

TEST_CASE("Good snowman hat")
{
    CHECK(snowman(11114411).substr(0, 5) == string("_===_"));
    CHECK(snowman(21114411).substr(0, 11) == string(" ___ \n....."));
    CHECK(snowman(31114411).substr(0, 11) == string("  _   \n /_\\ "));
    CHECK(snowman(41114411).substr(0, 11) == string(" ___ \n(_*_)"));
}

TEST_CASE("Good snowman nose")
{
    // small hat
    // no hands
    CHECK(snowman(11114411)[8] == ',');
    CHECK(snowman(12114411)[8] == '.');
    CHECK(snowman(13114411)[8] == '_');
    CHECK(snowman(14114411)[8] == ' ');
    // left hand
    CHECK(snowman(11113411)[10] == ',');
    CHECK(snowman(12113411)[10] == '.');
    CHECK(snowman(13113411)[10] == '_');
    CHECK(snowman(14113411)[10] == ' ');
    // right hand
    CHECK(snowman(11113411)[9] == ',');
    CHECK(snowman(12113411)[9] == '.');
    CHECK(snowman(13113411)[9] == '_');
    CHECK(snowman(14113411)[9] == ' ');
    // two hands
    CHECK(snowman(11113411)[11] == ',');
    CHECK(snowman(12113411)[11] == '.');
    CHECK(snowman(13113411)[11] == '_');
    CHECK(snowman(14113411)[11] == ' ');
    
    // big hat
    // no hands
    CHECK(snowman(21114411)[15] == ',');
    CHECK(snowman(22114411)[15] == '.');
    CHECK(snowman(23114411)[15] == '_');
    CHECK(snowman(24114411)[15] == ' ');
    // left hand
    CHECK(snowman(21113411)[18] == ',');
    CHECK(snowman(22113411)[18] == '.');
    CHECK(snowman(23113411)[18] == '_');
    CHECK(snowman(24113411)[18] == ' ');
    // right hand
    CHECK(snowman(21113411)[17] == ',');
    CHECK(snowman(22113411)[17] == '.');
    CHECK(snowman(23113411)[17] == '_');
    CHECK(snowman(24113411)[17] == ' ');
    // two hands
    CHECK(snowman(21113411)[20] == ',');
    CHECK(snowman(22113411)[20] == '.');
    CHECK(snowman(23113411)[20] == '_');
    CHECK(snowman(24113411)[20] == ' ');
}

TEST_CASE("Good snowman left eye")
{
    // small hat
    // no hands
    CHECK(snowman(11114411)[7] == '.');
    CHECK(snowman(11214411)[7] == 'o');
    CHECK(snowman(11314411)[7] == 'O');
    CHECK(snowman(11414411)[7] == '-');
    // left hand
    CHECK(snowman(11113411)[9] == '.');
    CHECK(snowman(11213411)[9] == 'o');
    CHECK(snowman(11313411)[9] == 'O');
    CHECK(snowman(11413411)[9] == '-');
    // right hand
    CHECK(snowman(11114411)[8] == '.');
    CHECK(snowman(11214311)[8] == 'o');
    CHECK(snowman(11314311)[8] == 'O');
    CHECK(snowman(11414311)[8] == '-');
    // two hands
    CHECK(snowman(11113311)[10] == '.');
    CHECK(snowman(11213311)[10] == 'o');
    CHECK(snowman(11313311)[10] == 'O');
    CHECK(snowman(11413311)[10] == '-');

    // big hat
    // no hands
    CHECK(snowman(21114411)[14] == '.');
    CHECK(snowman(21214411)[14] == 'o');
    CHECK(snowman(21314411)[14] == 'O');
    CHECK(snowman(21414411)[14] == '-');
    // left hand
    CHECK(snowman(21113411)[17] == '.');
    CHECK(snowman(21213411)[17] == 'o');
    CHECK(snowman(21313411)[17] == 'O');
    CHECK(snowman(21413411)[17] == '-');
    // right hand
    CHECK(snowman(21114411)[16] == '.');
    CHECK(snowman(21214311)[16] == 'o');
    CHECK(snowman(21314311)[16] == 'O');
    CHECK(snowman(21414311)[16] == '-');
    // two hands
    CHECK(snowman(21113311)[19] == '.');
    CHECK(snowman(21213311)[19] == 'o');
    CHECK(snowman(21313311)[19] == 'O');
    CHECK(snowman(21413311)[19] == '-');
}

TEST_CASE("Good snowman right eye")
{
    // small hat
    // no hands
    CHECK(snowman(11114411)[9] == '.');
    CHECK(snowman(11124411)[9] == 'o');
    CHECK(snowman(11134411)[9] == 'O');
    CHECK(snowman(11144411)[9] == '-');
    // left hand
    CHECK(snowman(11113411)[11] == '.');
    CHECK(snowman(11123411)[11] == 'o');
    CHECK(snowman(11133411)[11] == 'O');
    CHECK(snowman(11143411)[11] == '-');
    // right hand
    CHECK(snowman(11114411)[10] == '.');
    CHECK(snowman(11124311)[10] == 'o');
    CHECK(snowman(11134311)[10] == 'O');
    CHECK(snowman(11144311)[10] == '-');
    // two hands
    CHECK(snowman(11113311)[12] == '.');
    CHECK(snowman(11123311)[12] == 'o');
    CHECK(snowman(11133311)[12] == 'O');
    CHECK(snowman(11143311)[12] == '-');

    // big hat
    // no hands
    CHECK(snowman(21114411)[16] == '.');
    CHECK(snowman(21124411)[16] == 'o');
    CHECK(snowman(21134411)[16] == 'O');
    CHECK(snowman(21144411)[16] == '-');
    // left hand
    CHECK(snowman(21113411)[19] == '.');
    CHECK(snowman(21123411)[19] == 'o');
    CHECK(snowman(21133411)[19] == 'O');
    CHECK(snowman(21143411)[19] == '-');
    // right hand
    CHECK(snowman(21114411)[18] == '.');
    CHECK(snowman(21124311)[18] == 'o');
    CHECK(snowman(21134311)[18] == 'O');
    CHECK(snowman(21144311)[18] == '-');
    // two hands
    CHECK(snowman(21113311)[21] == '.');
    CHECK(snowman(21123311)[21] == 'o');
    CHECK(snowman(21133311)[21] == 'O');
    CHECK(snowman(21143311)[21] == '-');
}

TEST_CASE("Good snowman left arm")
{
    CHECK((snowman(11111411)[12] == ' ' && snowman(11111411)[20] == '<' && snowman(11111411).length() == 28));
    CHECK((snowman(11112411)[12] == '\\' && snowman(11112411)[20] == ' ' && snowman(11112411).length() == 28));
    CHECK((snowman(11113411)[12] == ' ' && snowman(11113411)[20] == '/' && snowman(11113411).length() == 28));
    CHECK(snowman(11114411).length() == 24);

    CHECK((snowman(21111411)[14] == ' ' && snowman(21111411)[22] == '<' && snowman(21111411).length() == 35));
    CHECK((snowman(21112411)[14] == '\\' && snowman(21112411)[22] == ' ' && snowman(21112411).length() == 35));
    CHECK((snowman(21113411)[14] == ' ' && snowman(21113411)[22] == '/' && snowman(21113411).length() == 35));
    CHECK(snowman(21114411).length() == 30);
}

TEST_CASE("Good snowman right arm")
{
    CHECK((snowman(11114111)[18] == ' ' && snowman(11114111)[26] == '>' && snowman(11114111).length() == 28));
    CHECK((snowman(11114211)[18] == '/' && snowman(11114211)[26] == ' ' && snowman(11114211).length() == 28));
    CHECK((snowman(11114311)[18] == ' ' && snowman(11114311)[26] == '\\' && snowman(11114311).length() == 28));
    CHECK(snowman(11114411).length() == 24);

    CHECK((snowman(21114111)[20] == ' ' && snowman(21114111)[28] == '>' && snowman(21114111).length() == 35));
    CHECK((snowman(21114211)[20] == '/' && snowman(21114211)[28] == ' ' && snowman(21114211).length() == 35));
    CHECK((snowman(21114311)[20] == ' ' && snowman(21114311)[28] == '\\' && snowman(21114311).length() == 35));
    CHECK(snowman(21114411).length() == 30);
}

TEST_CASE("Good snowman torso")
{
    // small hat
    // no hands
    CHECK(snowman(11114411).substr(13, 3) == string(" : "));
    CHECK(snowman(11114421).substr(13, 3) == string("] ["));
    CHECK(snowman(11114431).substr(13, 3) == string("> <"));
    CHECK(snowman(11114441).substr(13, 3) == string("   "));
    // left hand
    CHECK(snowman(11113411).substr(16, 3) == string(" : "));
    CHECK(snowman(11113421).substr(16, 3) == string("] ["));
    CHECK(snowman(11113431).substr(16, 3) == string("> <"));
    CHECK(snowman(11113441).substr(16, 3) == string("   "));
    // right hand
    CHECK(snowman(11114311).substr(15, 3) == string(" : "));
    CHECK(snowman(11114321).substr(15, 3) == string("] ["));
    CHECK(snowman(11114331).substr(15, 3) == string("> <"));
    CHECK(snowman(11114341).substr(15, 3) == string("   "));
    // both hand
    CHECK(snowman(11113311).substr(18, 3) == string(" : "));
    CHECK(snowman(11113321).substr(18, 3) == string("] ["));
    CHECK(snowman(11113331).substr(18, 3) == string("> <"));
    CHECK(snowman(11113341).substr(18, 3) == string("   "));

    // big hat
    // no hands
    CHECK(snowman(21114411).substr(19, 3) == string(" : "));
    CHECK(snowman(21114421).substr(19, 3) == string("] ["));
    CHECK(snowman(21114431).substr(19, 3) == string("> <"));
    CHECK(snowman(21114441).substr(19, 3) == string("   "));
    // left hand
    CHECK(snowman(21113411).substr(23, 3) == string(" : "));
    CHECK(snowman(21113421).substr(23, 3) == string("] ["));
    CHECK(snowman(21113431).substr(23, 3) == string("> <"));
    CHECK(snowman(21113441).substr(23, 3) == string("   "));
    // right hands
    CHECK(snowman(21114311).substr(22, 3) == string(" : "));
    CHECK(snowman(21114321).substr(22, 3) == string("] ["));
    CHECK(snowman(21114331).substr(22, 3) == string("> <"));
    CHECK(snowman(21114341).substr(22, 3) == string("   "));
    // both hands
    CHECK(snowman(21113311).substr(26, 3) == string(" : "));
    CHECK(snowman(21113321).substr(26, 3) == string("] ["));
    CHECK(snowman(21113331).substr(26, 3) == string("> <"));
    CHECK(snowman(21113341).substr(26, 3) == string("   "));
}

TEST_CASE("Good snowman base")
{
    // small hat
    // no hands
    CHECK(snowman(11114411).substr(19, 3) == string(" : "));
    CHECK(snowman(11114412).substr(19, 3) == string("\" \""));
    CHECK(snowman(11114413).substr(19, 3) == string("___"));
    CHECK(snowman(11114414).substr(19, 3) == string("   "));
    // left hands
    CHECK(snowman(11113411).substr(23, 3) == string(" : "));
    CHECK(snowman(11113412).substr(23, 3) == string("\" \""));
    CHECK(snowman(11113413).substr(23, 3) == string("___"));
    CHECK(snowman(11113414).substr(23, 3) == string("   "));
    // right hands
    CHECK(snowman(11114311).substr(22, 3) == string(" : "));
    CHECK(snowman(11114312).substr(22, 3) == string("\" \""));
    CHECK(snowman(11114313).substr(22, 3) == string("___"));
    CHECK(snowman(11114314).substr(22, 3) == string("   "));
    // both hands
    CHECK(snowman(11113311).substr(26, 3) == string(" : "));
    CHECK(snowman(11113312).substr(26, 3) == string("\" \""));
    CHECK(snowman(11113313).substr(26, 3) == string("___"));
    CHECK(snowman(11113314).substr(26, 3) == string("   "));

    // big hat
    // no hands
    CHECK(snowman(21114411).substr(25, 3) == string(" : "));
    CHECK(snowman(21114412).substr(25, 3) == string("\" \""));
    CHECK(snowman(21114413).substr(25, 3) == string("___"));
    CHECK(snowman(21114414).substr(25, 3) == string("   "));
    // left hands
    CHECK(snowman(21113411).substr(30, 3) == string(" : "));
    CHECK(snowman(21113412).substr(30, 3) == string("\" \""));
    CHECK(snowman(21113413).substr(30, 3) == string("___"));
    CHECK(snowman(21113414).substr(30, 3) == string("   "));
    // right hands
    CHECK(snowman(21114311).substr(29, 3) == string(" : "));
    CHECK(snowman(21114312).substr(29, 3) == string("\" \""));
    CHECK(snowman(21114313).substr(29, 3) == string("___"));
    CHECK(snowman(21114314).substr(29, 3) == string("   "));
    // both hands
    CHECK(snowman(21113311).substr(34, 3) == string(" : "));
    CHECK(snowman(21113312).substr(34, 3) == string("\" \""));
    CHECK(snowman(21113313).substr(34, 3) == string("___"));
    CHECK(snowman(21113314).substr(34, 3) == string("   "));
}