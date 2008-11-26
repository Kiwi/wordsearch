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
#include <cctype>
#include <cstring>
#include "puzzle.h"

/*
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
*/

void Puzzle::load_puzzle() {
    puzzle_txt.open("puzzle.txt");
    char temp_c = 0;
    std::size_t k = 0;
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
    width_puzzle = vector_puzzle[0].size();
    puzzle_txt.close();
    vector_puzzle_copy = vector_puzzle;
}

void Puzzle::load_wordlist() {
    wordlist_txt.open("wordlist.txt");
    char temp;
    std::size_t k = 0;
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

void Puzzle::print_puzzle() {
    for (std::size_t h = 0; h < height_puzzle; h++) {
        for (std::size_t w = 0; w < width_puzzle; w++) {
            //std::cout << vector_puzzle_copy[h][w];
            if (vector_puzzle_copy[h][w] > 64 && vector_puzzle_copy[h][w] + 26 < 123)
                std::cout << vector_puzzle_copy[h][w] << " ";
            else
                std::cout << ". ";
        }
        std::cout << std::endl;
    }
}

/*
void Puzzle::print_puzzle() {
    std::ostream_iterator<char> screen(std::cout, " ");
    for (std::size_t l = 0; l < height_puzzle; l++) {
        copy(vector_puzzle_copy[l].begin(), vector_puzzle_copy[l].end(), screen);
        std::cout << std::endl;
    }
}
*/

/* glguys replace_words_h*/
/*
void Puzzle::replace_words_h() {
    for (int e = 0; e < height_wordlist; e++)
        for (int c = 0; c < height_puzzle; c++)
            for (int d = 0; d < width_puzzle; d++)
                for (int a = 0; a+d < width_puzzle && a < vector_wordlist[e].size() 
                                              && vector_puzzle[c][d+a] == vector_wordlist[e][a]; a++)
                    if (a == vector_wordlist[e].size()-1) {
                        for (; a >=0; a--)
                            if (vector_puzzle_copy[c][d+a] >= 'a') {
                                vector_puzzle_copy[c][d+a] -= 32;//-= 'a' + 'A';
                            }
                        break;
                    }
}
*/

void Puzzle::replace_words_h() {
    std::size_t a = 0;
    for (std::size_t e = 0; e < height_wordlist; e++) {
        for (std::size_t c = 0; c < height_puzzle; c++) {
            for (std::size_t d = 0; d < width_puzzle; d++) {
                if (vector_puzzle[c][d] == vector_wordlist[e][a]) {
                    a++;
                    if (a == vector_wordlist[e].size()){
                        //for (std::size_t y = 0; y < a; y++) {
                        //   vector_puzzle_copy[d-y][c] -= 32;
                        //}
                        char i = 'a', j = 'A';
                        for (std::size_t b = 0; b < 27; b++) {
                            replace(vector_puzzle_copy[c].begin() + d - a + 1, vector_puzzle_copy[c].begin() + d + 1, i, j);
                            i++;
                            j++;
                        }
                        a = 0;
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

void Puzzle::reverse_wordlist() {
    for (std::size_t n = 0; n < height_wordlist; n++) {
        reverse(vector_wordlist[n].begin(), vector_wordlist[n].end());
    }
}

void Puzzle::replace_words_v() {
    std::size_t a = 0;
    for (std::size_t e = 0; e < height_wordlist; e++) {
        for (std::size_t c = 0; c < width_puzzle; c++) {
            for (std::size_t d = 0; d < height_puzzle; d++) {
                if (vector_puzzle[d][c] == vector_wordlist[e][a]) {
                    a++;
                    if (a == vector_wordlist[e].size()) {
                        for (std::size_t y = 0; y < a; y++) {
                            //vector_puzzle_copy[d-y][c] -= 32;
                            vector_puzzle_copy[d-y][c] = std::toupper(vector_puzzle_copy[d-y][c]);
                        }
                        a = 0;
                    }
                }
                else {
                    if (d - a >= 0) {
                        d -= a;
                    }                    
                    a = 0;
                }
            }
        }
    }
}

/*
void Puzzle::replace_words_v() {
    for (int e = 0; e < height_wordlist; e++)
        for (int c = 0; c < width_puzzle; c++)
            for (int d = 0; d < height_puzzle; d++)
                for (int a = 0; a+d < height_puzzle && a < vector_wordlist[e].size() 
                                              && vector_puzzle[d+a][c] == vector_wordlist[e][a]; a++)
                    if (a == vector_wordlist[e].size()-1) {
                        for (; a >=0; a--)
                            if (vector_puzzle_copy[d+a][c] >= 'a') {
                                vector_puzzle_copy[d+a][c] -= 32;
                            }
                        break;
                    }
}
*/
