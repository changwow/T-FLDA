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

#ifndef	_MODEL_H
#define	_MODEL_H

#include "constants.h"
#include "dataset.h"
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// LDA model
class model {
public:
    // fixed options
    string wordmapfile;		// file that contains word map [string -> integer id]
    string linkmapfile;      // file that contains link map [string -> integer id]
    string trainlogfile;	// training log file
    string tassign_suffix;	// suffix for topic assignment file
    string theta_suffix;	// suffix for theta file
    string phi_suffix;		// suffix for phi file
    string gama_suffix;     // suffix for gama file
    string fpi_suffix;     // suffix for fpi file
    string mu_suffix;     // suffix for mu file
    string others_suffix;	// suffix for file containing other parameters
    string twords_suffix;	// suffix for file containing words-per-topics
    string tlinks_suffix;   // suffix for file containing links-per-topics
	 string tlinksByTime_suffix;

    string dir;			// model directory
    string dfile;		// data file
    string lfile;       // link file    
    string tfile;		//time file
	 string model_name;		// model name
    int model_status;		// model status:
				// MODEL_STATUS_UNKNOWN: unknown status
				// MODEL_STATUS_EST: estimating from scratch
				// MODEL_STATUS_ESTC: continue to estimate the model from a previous one
				// MODEL_STATUS_INF: do inference

    dataset * ptrndata;	// pointer to training dataset object
    dataset * pnewdata; // pointer to new dataset object

    mapid2word id2word; // word map [int => string]
    mapid2link id2link; // link map [int => string]
    
    // --- model parameters and variables ---    
    int M; // dataset size (i.e., number of docs)
    int V; // vocabulary size
    int L; // number of links
    int K; // number of topics
	 int Slices; // number of time slices;
    double alpha, beta, omega, rho, epsilon; // LDA hyperparameters 
    int niters; // number of Gibbs sampling iterations
    int liter; // the iteration at which the model was saved
    int savestep; // saving period
    int twords; // print out top words per each topic
    int tlinks; // print out top links per each topic
    int withrawstrs;

    double * p; // temp variable for sampling
    int ** z; // topic assignments for words, size M x doc.size()
    int ** nw; // cwt[i][j]: number of instances of word/term i assigned to topic j, size V x K
    int ** nd; // na[i][j]: number of words in document i assigned to topic j, size M x K
    int * nwsum; // nwsum[j]: total number of words assigned to topic j, size K
    int * ndsum; // nasum[i]: total number of words in document i, size M
    double ** theta; // theta: document-topic distributions, size M x K
    double ** phi; // phi: topic-word distributions, size K x V
    
    double * lp0; // temp variable for sampling
    double * lp1; // temp variable for sampling2
    int ** lz; // topic assignments for links, size M x doc.size()
    int ** y; //links type
    int * sum;
    int ** lny; // number of y of i assigned to user j
    int ** ly;  // 2*M
    int *  pi;
    int ** pit;  //
	 int    pisum;
    int ** lky; // number of links of l assigned to topic k when y = 1
    int *** lkty; // number of links of l assigned to topic k at time t when y = 1
	 int * lkysum; // the sum of all links assigned to topic k when y = 1
    int * lysum; // how many y==1 and how many y==0
    int ** lnw; // cwt[i][j]: number of instances of word/term i assigned to topic j, size L x K
    int ** lnd; // na[i][j]: number of links in document i assigned to topic j, size M x K
    int * lnwsum; // nwsum[j]: total number of links assigned to topic j, size K
    int * lndsum; // nasum[i]: total number of links in document i, size M
    double ** gama; // phi: topic-links distributions, size K x L
    double *  fpi; // fpi(final-pi): topic-links(no relate) distributions, size L
    double ** mu;

    // for inference only
    int inf_liter;
    int newM;
    int newV;
    int ** newz;
    int ** newnw;
    int ** newnd;
    int * newnwsum;
    int * newndsum;
    double ** newtheta;
    double ** newphi;
    // --------------------------------------
    
    model() {
	set_default_values();
    }
          
    ~model();
    
    // set default values for variables
    void set_default_values();   

    // parse command line to get options
    int parse_args(int argc, char ** argv);
    
    // initialize the model
    int init(int argc, char ** argv);
    
    // load LDA model to continue estimating or to do inference
    int load_model(string model_name);
    
    // save LDA model to files
    // model_name.tassign: topic assignments for words in docs
    // model_name.theta: document-topic distributions
    // model_name.phi: topic-word distributions
    // model_name.others: containing other parameters of the model (alpha, beta, M, V, K)
    int save_model(string model_name);
    int save_model_tassign(string filename);
    int save_model_theta(string filename);
    int save_model_phi(string filename);
    int save_model_gama(string filename);
    int save_model_fpi(string filename);
    int save_model_mu(string filename);
    int save_model_others(string filename);
    int save_model_twords(string filename);
    int save_model_tlinks(string filename);
	 int save_model_tlinksByTime(string filename);    

    // saving inference outputs
    int save_inf_model(string model_name);
    int save_inf_model_tassign(string filename);
    int save_inf_model_newtheta(string filename);
    int save_inf_model_newphi(string filename);
    int save_inf_model_others(string filename);
    int save_inf_model_twords(string filename);
    int save_inf_model_tlinks(string filename);
    
    // init for estimation
    int init_est();
    int init_estc();
	
    // estimate LDA model using Gibbs sampling
    void estimate();
    int sampling(int m, int n);
    int lsampling(int m, int n);
    void compute_theta();
    void compute_phi();
    void compute_gama();
    void compute_fpi();
    void compute_mu();
    
    // init for inference
    int init_inf();
    // inference for new (unseen) data based on the estimated LDA model
    void inference();
    int inf_sampling(int m, int n);
    void compute_newtheta();
    void compute_newphi();

    void show_data();
};

#endif

