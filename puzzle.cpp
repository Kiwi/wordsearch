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
    char separator = 0;
    int k = 0;
    while (puzzle_txt.good()) {
        vector_puzzle.push_back(std::vector <char>());
         puzzle_txt.get(separator);
            while (puzzle_txt.good()) {
                
                if (separator == '\n') {
                    break;
                }
                vector_puzzle[k].push_back(separator);
                puzzle_txt.get(separator);
            }
        k++;
    }
    puzzle_txt.clear();
    std::string temp;
    height_puzzle = 0;
    while (getline(puzzle_txt, temp)) {
        height_puzzle++;
    }
    //cout << height_puzzle << std::endl;
    width_puzzle = vector_puzzle[0].size();
    //cout << width_puzzle << " " << height_puzzle << endl;
    std::cout << vector_puzzle[5][8] << std::endl;
    std::cout << vector_puzzle.at(5).at(8) << std::endl;
    puzzle_txt.close();
}

void Puzzle::print_puzzle() {
    for (int h = 0; h < height_puzzle; h++) {
        for (int w = 0; w < width_puzzle; w++) {
            std::cout << vector_puzzle[h][w];
        }
        std::cout << std::endl;
    }
}

