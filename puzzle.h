/*
 *      puzzle.h
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


#ifndef PUZZLE_H
#define PUZZLE_H

class Puzzle {
    private:
        std::vector <std::vector<char> > vector_puzzle;
        std::vector<std::string> word_bank;
        int width_puzzle;
        int height_puzzle;
        std::ifstream puzzle_txt;
    public:
        void set_height();
        void load_puzzle();
        void print_puzzle();
};

#endif /* PUZZLE_H */ 
