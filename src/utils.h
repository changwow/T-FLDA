/*
 * Copyright (C) 2016 by
 * 
 * 	Wang Yakun
 * 	Beijing University of Post & Telecommunication 
 *
 * T-FLDA is a free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published
 * by the Free Software Foundation; either version 2 of the License,
 * or (at your option) any later version.
 *
 * T-FLDA is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with T-FLDA; if not, write to the Free Software Foundation.
 */

#ifndef _UTILS_H
#define _UTILS_H

#include <string>
#include <cstdlib>

using namespace std;

class model;

class utils {
public:
    // parse command line arguments
    static int parse_args(int argc, char ** argv, model * pmodel);
    
    // read and parse model parameters from <model_name>.others
    static int read_and_parse(string filename, model * model); 
    
    // generate the model name for the current iteration
    // iter = -1 => final model
    static string generate_model_name(int iter);  
    
    // sort    
    static void sort(vector<double> & probs, vector<int> & words);
    static void quicksort(vector<pair<int, double> > & vect, int left, int right);
};

#endif

