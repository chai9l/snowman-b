//
// Created by chai on 08/03/2021.
//

#include "snowman.hpp"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

const vector<vector<string>> snowmanDictionary = {
        {"",               "",   "",           "",                   "",""                },
        {"","  \n _===_  ", "  ___  \n ..... ", "    _   \n   /_\\  ", "  ___  \n (_*_) "},
        {"",",",                ".",                "_",                 " "},
        {"",".",                "o",                "O",                 "-"},
        {"",".",                "o",                "O",                 "-"},
        {"","<",                "\\",               "/",                 " "},
        {"",">",                "/",                "\\",                " "},
        {""," : ",              "] [",              "> <",               "   "},
        {""," ( : )",            " (\" \")",          " (___)",             " (   )"}
};

namespace ariel {
    string snowman(int num) {
        int lBound = 11111111;
        int rBound = 44444444;
        string input = " ";
        input += to_string(num);
        string ret;
        if(num < lBound || num > rBound) {
            throw out_of_range("Not in range");
        }

        string hat;
        string nose;
        string lEye;
        string rEye;
        string lArm;
        string rArm;
        string torso;
        string base;
        string ulArm;
        string urArm;

        for(int i = 1; i < input.length(); i++) {
            int temp = input.at(i) - 48;
            if(temp < 1 || temp > 4 ) {
                throw out_of_range("Invalid input");
            }
            if(i == hatIndex) {
                hat = snowmanDictionary[i][temp];
            }
            else if(i == noseIndex) {
                nose = snowmanDictionary[i][temp];
            }
            else if(i == lEyeIndex) {
                lEye = snowmanDictionary[i][temp];
            }
            else if(i == rEyeIndex) {
                rEye = snowmanDictionary[i][temp];
            }
            else if(i == lArmIndex) {
                if (temp == 2) {
                    ulArm = snowmanDictionary[i][temp];
                    lArm = " ";
                }
                else {
                    lArm = snowmanDictionary[i][temp];
                    ulArm = " ";
                }
            }
            else if(i == rArmIndex) {
                if(temp == 2) {
                    urArm = snowmanDictionary[i][temp];
                    rArm = " ";
                }
                else {
                    rArm = snowmanDictionary[i][temp];
                    urArm = " ";
                }
            }
            else if(i == torsoIndex) {
                torso = snowmanDictionary[i][temp];
            }
            else if(i == baseIndex) {
                base = snowmanDictionary[i][temp];
            }
        }
        ret = hat + "\n" +
             ulArm + "(" + lEye + nose + rEye + ")"+ urArm + "\n" +
             lArm + "(" + torso + ")" + rArm + "\n" +
             base;
        return ret;
    }
};