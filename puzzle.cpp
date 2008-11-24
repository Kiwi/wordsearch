/*
 *      puzzle.cpp
 *      
 *      Copyright 2008  <kiwi@lappy>
 *      
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *      
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *      
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *      MA 02110-1301, USA.
 */

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include "puzzle.h"

void Puzzle::set_height() {
    puzzle_txt.open("puzzle.txt");
    std::string temp;
    height_puzzle = 0;
        while (std::getline(puzzle_txt, temp)) {
        height_puzzle++;
    }
    std::cout << height_puzzle << std::endl;
    puzzle_txt.close();
}

void Puzzle::load_puzzle() {
    puzzle_txt.open("puzzle.txt");
    char temp_c = 0;
    int k = 0;
    while (puzzle_txt.good()) {
        vector_puzzle.push_back(std::vector <char>());
        puzzle_txt.get(temp_c);
            while (puzzle_txt.good()) {
                if (temp_c == '\n') {
                    break;
                }
                vector_puzzle[k].push_back(temp_c);
                puzzle_txt.get(temp_c);
            }
        k++;
    }
    std::string temp_s;
    height_puzzle = 0;
    puzzle_txt.clear();
    puzzle_txt.seekg(0);
    while (getline(puzzle_txt, temp_s)) {
        height_puzzle++;
    }
    //std::cout << height_puzzle << std::endl;
    width_puzzle = vector_puzzle[0].size();
    //cout << width_puzzle << " " << height_puzzle << endl;
    //std::cout << vector_puzzle[5][8] << std::endl;
    //std::cout << vector_puzzle.at(5).at(8) << std::endl;
    puzzle_txt.close();
}

void Puzzle::load_wordlist() {
    wordlist_txt.open("wordlist.txt");
    char temp;
    int k = 0;
    while (wordlist_txt.good()) {
        vector_wordlist.push_back(std::vector <char>());
        wordlist_txt.get(temp);
            while (wordlist_txt.good()) {
                if (temp == '\n') {
                    break;
                }
                vector_wordlist[k].push_back(temp);
                wordlist_txt.get(temp);
            }
        k++;
    }
    std::string temp_s;
    height_wordlist = 0;
    wordlist_txt.clear();
    wordlist_txt.seekg(0);
    while (getline(wordlist_txt, temp_s)) {
        height_wordlist++;
    }
    wordlist_txt.close();
}
/*
void Puzzle::print_puzzle() {
    for (int h = 0; h < height_puzzle; h++) {
        for (int w = 0; w < width_puzzle; w++) {
            std::cout << vector_puzzle[h][w];
        }
        std::cout << std::endl;
    }
}
*/

void Puzzle::print_puzzle() {
    std::ostream_iterator<char> screen(std::cout);
    for (int l = 0; l < height_puzzle; l++) {
        copy(vector_puzzle[l].begin(), vector_puzzle[l].end(), screen);
        std::cout << std::endl;
    }
}
    
void Puzzle::replace_words_h() {
    unsigned int a = 0;
    for (int e = 0; e < height_wordlist; e++) {
        for (int c = 0; c < height_puzzle; c++) {
            for (int d = 0; d < width_puzzle; d++) {
                if (vector_puzzle[c][d] == vector_wordlist[e][a]) {
                    a++;
                    if (a == vector_wordlist[e].size()){
                        char i = 'a', j = 'A';
                        for (int b = 0; b < 27; b++) {
                            replace(vector_puzzle[c].begin() + d - a + 1, vector_puzzle[c].begin() + d + 1, i, j);
                            i++;
                            j++;
                        }
                    }
                }
                else {
                    d -= a;
                    a = 0;                    
                }
            }
        }
    }
}

