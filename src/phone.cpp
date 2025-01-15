#include <RandyConfig.h>
#include <iostream>
#include <memory>
#include <phone.hpp>
#include <random>
#include <string>
#include <unordered_map>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::mt19937;
using std::random_device;
using std::string;
using std::uniform_int_distribution;
using std::unordered_map;
using std::vector;

void setup_phone(CLI::App& app) {
    auto  opt = std::make_shared<PhoneOptions>();
    auto* sub = app.add_subcommand("phone", "Generate Random phone number(s)");
    sub->add_option("-s,--state", opt->state, "Select a US state/territory")
        ->ignore_case()
        ->required();
    sub->add_option("-n,--number", opt->number, "Specify how many to generate")
        ->needs("--state")
        ->default_val(1);
    sub->callback([opt]() { run_phone(*opt); });
    std::string usage_msg =
        "Usage: " + std::string(Randy_TARGET_FILE) + " phone [OPTIONS]";
    sub->usage(usage_msg);
}

class Rand {
   public:
    int number(int min, int max) {
        random_device              rd;
        mt19937                    gen(rd());
        uniform_int_distribution<> distrib(min, max);
        int                        randomValue = distrib(gen);
        return randomValue;
    }

    int vector(vector<int> vec) {
        int randomPosition = rand() % vec.size();
        int randomElement  = vec[randomPosition];
        return randomElement;
    }
};

int run_phone(PhoneOptions const& opt) {
    srand(time(0));
    // Define options
    Rand                                    rand;
    vector<int>                             areaCodes;

    const static unordered_map<string, int> string_to_case {
        {"AL", 1},  {"AK", 2},  {"AZ", 3},  {"AR", 4},  {"AS", 5},  {"CA", 6},
        {"CO", 7},  {"CT", 8},  {"DE", 9},  {"DC", 10}, {"FL", 11}, {"GA", 12},
        {"GU", 13}, {"HI", 14}, {"ID", 15}, {"IL", 16}, {"IN", 17}, {"IA", 18},
        {"KS", 19}, {"LA", 20}, {"ME", 21}, {"MD", 22}, {"MA", 23}, {"MI", 24},
        {"MN", 25}, {"MS", 26}, {"MO", 27}, {"MT", 28}, {"NE", 29}, {"NV", 30},
        {"NH", 31}, {"NJ", 32}, {"NM", 33}, {"NY", 34}, {"NC", 35}, {"ND", 36},
        {"MP", 37}, {"OK", 38}, {"OR", 39}, {"PA", 40}, {"PR", 41}, {"RI", 42},
        {"SC", 43}, {"SD", 44}, {"TN", 45}, {"TX", 46}, {"UT", 47}, {"VT", 48},
        {"VA", 49}, {"VI", 50}, {"WA", 51}, {"WV", 52}, {"WI", 53}, {"WY", 54}
    };
    switch (string_to_case.count(opt.state) ? string_to_case.at(opt.state) : 0
    ) {
        case 1: areaCodes = {205, 251, 256, 334, 659, 938}; break;
        case 2: areaCodes = {907}; break;
        case 3: areaCodes = {480, 520, 602, 623, 928}; break;
        case 4: areaCodes = {327, 479, 501, 870}; break;
        case 5: areaCodes = {684}; break;
        case 7:
            areaCodes = {209, 213, 279, 310, 323, 341, 350, 369, 408, 415,
                         424, 442, 510, 530, 559, 562, 619, 626, 628, 650,
                         657, 661, 669, 707, 714, 747, 760, 805, 818, 820,
                         831, 840, 858, 909, 916, 925, 949, 951};
            break;
        case 8 : areaCodes = {303, 719, 720, 970, 983}; break;
        case 9 : areaCodes = {203, 475, 860, 959}; break;
        case 10: areaCodes = {302}; break;
        case 11: areaCodes = {202, 771}; break;
        case 12:
            areaCodes = {239, 305, 321, 324, 352, 386, 407, 448,
                         561, 645, 656, 689, 727, 728, 754, 772,
                         786, 813, 850, 863, 904, 941, 954};
            break;
        case 13:
            areaCodes = {229, 404, 470, 478, 678, 706, 762, 770, 912, 943};
            break;
        case 14: areaCodes = {671}; break;
        case 15: areaCodes = {808}; break;
        case 16: areaCodes = {208, 986}; break;
        case 17:
            areaCodes = {217, 224, 309, 312, 331, 447, 464, 618, 630,
                         708, 730, 773, 779, 815, 847, 861, 872};
            break;
        case 18: areaCodes = {219, 260, 317, 463, 574, 765, 812, 930}; break;
        case 19: areaCodes = {319, 515, 563, 641, 712}; break;
        case 20: areaCodes = {316, 620, 785, 913}; break;
        case 21: areaCodes = {270, 364, 502, 606, 859}; break;
        case 22: areaCodes = {225, 318, 337, 504, 985}; break;
        case 23: areaCodes = {207}; break;
        case 24: areaCodes = {227, 240, 301, 410, 443, 667}; break;
        case 25:
            areaCodes = {339, 351, 413, 508, 617, 774, 781, 857, 978};
            break;
        case 26:
            areaCodes = {231, 248, 269, 313, 517, 586,
                         616, 734, 810, 906, 947, 989};
            break;
        case 27: areaCodes = {218, 320, 507, 612, 651, 763, 952}; break;
        case 28: areaCodes = {228, 601, 662, 769}; break;
        case 29:
            areaCodes = {235, 314, 417, 557, 573, 636, 660, 816, 975};
            break;
        case 30: areaCodes = {406}; break;
        case 31: areaCodes = {308, 402, 531}; break;
        case 32: areaCodes = {702, 725, 775}; break;
        case 33: areaCodes = {603}; break;
        case 34:
            areaCodes = {201, 551, 609, 640, 732, 848, 856, 862, 908, 973};
            break;
        case 35: areaCodes = {505, 575}; break;
        case 36:
            areaCodes = {212, 315, 329, 332, 347, 363, 516, 518, 585, 607, 624,
                         631, 646, 680, 716, 718, 838, 845, 914, 917, 929, 934};
            break;
        case 37:
            areaCodes = {252, 336, 472, 704, 743, 828, 910, 919, 980, 984};
            break;
        case 38: areaCodes = {701}; break;
        case 39: areaCodes = {670}; break;
        case 40:
            areaCodes = {216, 220, 234, 283, 326, 330, 380, 419,
                         436, 440, 513, 567, 614, 740, 937};
            break;
        case 41: areaCodes = {405, 539, 572, 580, 918}; break;
        case 42: areaCodes = {458, 503, 541, 971}; break;
        case 43:
            areaCodes = {215, 223, 267, 272, 412, 445, 484, 570,
                         582, 610, 717, 724, 814, 835, 878};
            break;
        case 44: areaCodes = {787, 939}; break;
        case 45: areaCodes = {401}; break;
        case 46: areaCodes = {803, 839, 843, 854, 864}; break;
        case 47: areaCodes = {605}; break;
        case 48: areaCodes = {423, 615, 629, 731, 865, 901, 931}; break;
        case 49:
            areaCodes = {210, 214, 254, 281, 325, 346, 361, 409, 430, 432,
                         469, 512, 682, 713, 726, 737, 806, 817, 830, 832,
                         903, 915, 936, 940, 945, 956, 972, 979};
            break;
        case 50: areaCodes = {385, 435, 801}; break;
        case 51: areaCodes = {802}; break;
        case 52:
            areaCodes = {276, 434, 540, 571, 686, 703, 757, 804, 826, 948};
            break;
        case 53: areaCodes = {340}; break;
        case 54: areaCodes = {206, 253, 360, 425, 509, 564}; break;
        case 55: areaCodes = {304, 681}; break;
        case 56: areaCodes = {262, 274, 353, 414, 534, 608, 715, 920}; break;
        case 57: areaCodes = {307}; break;
        case 0:
            cerr << "Please enter a Valid State or Territory in a 2 letter "
                    "format"
                 << endl;
            return 1;
    }
    for (int i = 0; i < opt.number; i++) {
        cout << "\033[38;2;255;105;180m" << i + 1
             << ": \033[38;2;220;20;60m(\033[38;2;255;234;0m"
             << rand.vector(areaCodes)
             << "\033[38;2;220;20;60m) \033[38;2;124;252;0m"
             << rand.number(0, 9) << rand.number(0, 9) << rand.number(0, 9)
             << "\033[38;2;220;20;60m-\033[38;2;0;206;209m" << rand.number(0, 9)
             << rand.number(0, 9) << rand.number(0, 9) << rand.number(0, 9)
             << "\033[0m" << endl;
    }
    return 0;
}
