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

#include "model.h"
#include "strtokenizer.h"
#include "utils.h"
#include <cstdio>

using namespace std;

void show_help();

int main(int argc, char ** argv) {
    model lda;

    if (lda.init(argc, argv)) {
	   show_help();
	   return 1;
    }

    //lda.show_data();

    if (lda.model_status == MODEL_STATUS_EST || lda.model_status == MODEL_STATUS_ESTC) {
	// parameter estimation
	lda.estimate();
    }
    
    /*if (lda.model_status == MODEL_STATUS_INF) {
	// do inference
	lda.inference();
    }*/
    
    return 0;
}

void show_help() {
    printf("Command line usage:\n");
    printf("\tlda -est -alpha <double> -beta <double> -omega <double> -rho <double> -epsilon <double> -ntopics <int> -niters <int> -savestep <int> -twords <int> -tlinks <int> -dfile <string> -lfile <string> -tfile <string>\n");
    //printf("\tlda -estc -dir <string> -model <string> -niters <int> -savestep <int> -twords <int>\n");
    //printf("\tlda -inf -dir <string> -model <string> -niters <int> -twords <int> -dfile <string>\n");
    // printf("\tlda -inf -dir <string> -model <string> -niters <int> -twords <int> -dfile <string> -withrawdata\n");
}

