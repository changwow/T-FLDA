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

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "constants.h"
#include "strtokenizer.h"
#include "utils.h"
#include "dataset.h"
#include "model.h"

using namespace std;

model::~model() {
    /*if (p) {
	delete p;
    }

    if (lp0) {
    delete lp0;
    }

    if (lp1) {
    delete lp1;
    }

    if (ptrndata) {
	delete ptrndata;
    }
    
    if (pnewdata) {
	delete pnewdata;
    }

    if (z) {
	for (int m = 0; m < M; m++) {
	    if (z[m]) {
		delete z[m];
	    }
	}
    }
    
    if (nw) {
	for (int w = 0; w < V; w++) {
	    if (nw[w]) {
		delete nw[w];
	    }
	}
    }

    if (nd) {
	for (int m = 0; m < M; m++) {
	    if (nd[m]) {
		delete nd[m];
	    }
	}
    } 
    
    if (nwsum) {
	delete nwsum;
    }   
    
    if (ndsum) {
	delete ndsum;
    }

    if (lz) {
    for (int m = 0; m < M; m++) {
        if (lz[m]) {
        delete lz[m];
        }
    }
    }

    if (y) {
    for (int m = 0; m < M; m++) {
        if (y[m]) {
        delete y[m];
        }
    }
    }
    
    if (lnw) {
    for (int w = 0; w < L; w++) {
        if (lnw[w]) {
        delete lnw[w];
        }
    }
    }

    if (ly) {
    for (int w = 0; w < L; w++) {
        if (ly[w]) {
        delete ly[w];
        }
    }
    }

    if (lnd) {
    for (int m = 0; m < M; m++) {
        if (lnd[m]) {
        delete lnd[m];
        }
    }
    } 
    
    if (lny) {
        for(int m = 0; m < M; m++) {
            if(lny[m]){
                delete lny[m];
            }
        }
    }

    if (lky) {
        for(int m = 0; m < L; m++) {
            if(lky[m]){
                delete lky[m];
            }
        }
    }

	if (lkty) {
        for(int m = 0; m < L; m++) {
            if(lkty[m]){
					 for (int k = 0; k < K; k++) {
						delete lkty[m][k];
					}
            	}
        }
    }

    if (lnwsum) {
    delete lnwsum;
    }   
    
    if (lndsum) {
    delete lndsum;
    }
    
    if (lkysum) {
    delete lkysum;
    }

    if (lysum) {
    delete lysum;
    }

    if (pi) {
    delete pi;
    }

	if (pit) {
     	for (int m = 0; m < L; m++) {
	    	if (pit[m]) {
			delete pit[m];
	    	}
		}
	 	delete pit;
    }

    if (theta) {
	for (int m = 0; m < M; m++) {
	    if (theta[m]) {
		delete theta[m];
	    }
	}
    }
    
    if (phi) {
	for (int k = 0; k < K; k++) {
	    if (phi[k]) {
		delete phi[k];
	    }
	}
    }

    if (gama) {
    for (int k = 0; k < K; k++) {
        if (gama[k]) {
        delete gama[k];
        }
    }
    }

    if (mu) {
    for (int k = 0; k < M; k++) {
        if (mu[k]) {
        delete mu[k];
        }
    }
    }

    if (fpi) {
       delete fpi;
    }

    // only for inference
    if (newz) {
	for (int m = 0; m < newM; m++) {
	    if (newz[m]) {
		delete newz[m];
	    }
	}
    }
    
    if (newnw) {
	for (int w = 0; w < newV; w++) {
	    if (newnw[w]) {
		delete newnw[w];
	    }
	}
    }

    if (newnd) {
	for (int m = 0; m < newM; m++) {
	    if (newnd[m]) {
		delete newnd[m];
	    }
	}
    } 
    
    if (newnwsum) {
	delete newnwsum;
    }   
    
    if (newndsum) {
	delete newndsum;
    }
    
    if (newtheta) {
	for (int m = 0; m < newM; m++) {
	    if (newtheta[m]) {
		delete newtheta[m];
	    }
	}
    }
    
    if (newphi) {
	for (int k = 0; k < K; k++) {
	    if (newphi[k]) {
		delete newphi[k];
	    }
	}
    }*/
}

void model::set_default_values() {
    wordmapfile = "wordmap.txt";
    linkmapfile = "linkmap.txt";
	 trainlogfile = "trainlog.txt";
    tassign_suffix = ".tassign";
    theta_suffix = ".theta";
    phi_suffix = ".phi";
    gama_suffix = ".gama";
    fpi_suffix = ".fpi";
    mu_suffix = ".mu";
    others_suffix = ".others";
    twords_suffix = ".twords";
    tlinks_suffix = ".tlinks";
	 tlinksByTime_suffix = ".tlinkst";   

    dir = "./";
    dfile = "test.dat";
    lfile = "ltest.dat";
    tfile = "ttest.dat";
	 model_name = "model-final";    
    model_status = MODEL_STATUS_UNKNOWN;
    
    ptrndata = NULL;
    pnewdata = NULL;
    
    M = 0;
    V = 0;
    L = 0;
    K = 10;
	 Slices = 25;
    alpha = 50.0 / K;
    beta = 0.01;
    omega = 0.01;
    rho = 0.01;
    epsilon = 0.01;
    niters = 20;
    liter = 0;
    savestep = -1;    
    twords = 15;
    tlinks = 15;
    withrawstrs = 0;
    
    p = NULL; // temp variable for sampling
    z = NULL; // topic assignments for words, size M x doc.size()
    nw = NULL; // cwt[i][j]: number of instances of word/term i assigned to topic j, size V x K
    nd = NULL; // na[i][j]: number of words in document i assigned to topic j, size M x K
    nwsum = NULL; // nwsum[j]: total number of words assigned to topic j, size K
    ndsum = NULL; // nasum[i]: total number of words in document i, size M
    theta = NULL; // theta: document-topic distributions, size M x K
    phi = NULL; // phi: topic-word distributions, size K x V
    
    lp0 = NULL; // temp variable for sampling
    lp1 = NULL; // temp variable for sampling2
    lz = NULL; // topic assignments for links, size M x doc.size()
    y = NULL; //links type
    sum = NULL;
    lny = NULL; // number of y of i assigned to user j
    ly = NULL;
    pi = NULL;
    pit = NULL;
	 pisum = 0;
    lky = NULL;
	 lkty = NULL;
    lkysum = NULL;
    lysum = NULL;
    lnw = NULL; // cwt[i][j]: number of instances of word/term i assigned to topic j, size L x K
    lnd = NULL; // na[i][j]: number of links in document i assigned to topic j, size M x K
    lnwsum = NULL; // nwsum[j]: total number of links assigned to topic j, size K
    lndsum = NULL; // nasum[i]: total number of links in document i, size M
    gama = NULL; // phi: topic-links distributions, size K x L
    fpi = NULL; // fpi(final-pi): topic-links(no relate) distributions, size L
    mu = NULL;
    
    newM = 0;
    newV = 0;
    newz = NULL;
    newnw = NULL;
    newnd = NULL;
    newnwsum = NULL;
    newndsum = NULL;
    newtheta = NULL;
    newphi = NULL;
}

int model::parse_args(int argc, char ** argv) {
    return utils::parse_args(argc, argv, this);
}

int model::init(int argc, char ** argv) {
    // call parse_args
	//printf("let's go!\n");
    if (parse_args(argc, argv)) {	   
		return 1;
    }
    
    if (model_status == MODEL_STATUS_EST) {
        // estimating the model from scratch
			//printf("go go go!\n");
        if (init_est()) {
        	return 1;
        }
    	
    }/*else if (model_status == MODEL_STATUS_ESTC) {
    	// estimating the model from a previously estimated one
    	if (init_estc()) {
    	    return 1;
    	}
    	
    } else if (model_status == MODEL_STATUS_INF) {
    	// do inference
    	if (init_inf()) {
    	    return 1;
    	}
    }*/
    
    return 0;
}

int model::load_model(string model_name) {
    int i, j;
    
    string filename = dir + model_name + tassign_suffix;
    FILE * fin = fopen(filename.c_str(), "r");
    if (!fin) {
	printf("Cannot open file %d to load model!\n", filename.c_str());
	return 1;
    }
    
    char buff[BUFF_SIZE_LONG];
    string line;

    // allocate memory for z and ptrndata
    z = new int*[M];
    ptrndata = new dataset(M);
    ptrndata->V = V;

    for (i = 0; i < M; i++) {
	char * pointer = fgets(buff, BUFF_SIZE_LONG, fin);
	if (!pointer) {
	    printf("Invalid word-topic assignment file, check the number of docs!\n");
	    return 1;
	}
	
	line = buff;
	strtokenizer strtok(line, " \t\r\n");
	int length = strtok.count_tokens();
	
	vector<int> words;
	vector<int> topics;
	for (j = 0; j < length; j++) {
	    string token = strtok.token(j);
    
	    strtokenizer tok(token, ":");
	    if (tok.count_tokens() != 2) {
		printf("Invalid word-topic assignment line!\n");
		return 1;
	    }
	    
	    words.push_back(atoi(tok.token(0).c_str()));
	    topics.push_back(atoi(tok.token(1).c_str()));
	}
	
	// allocate and add new document to the corpus
	document * pdoc = new document(words);
	ptrndata->add_doc(pdoc, i);
	
	// assign values for z
	z[i] = new int[topics.size()];
	for (j = 0; j < topics.size(); j++) {
	    z[i][j] = topics[j];
	}
    }   
    
    fclose(fin);
    
    return 0;
}

int model::save_model(string model_name) {
    if (save_model_tassign(dir + model_name + tassign_suffix)) {
	return 1;
    }
    
    if (save_model_others(dir + model_name + others_suffix)) {
	return 1;
    }
    
    if (save_model_theta(dir + model_name + theta_suffix)) {
	return 1;
    }
    
    if (save_model_phi(dir + model_name + phi_suffix)) {
	return 1;
    }

    if (save_model_gama(dir + model_name + gama_suffix)) {
    return 1;
    }
    
    if (save_model_fpi(dir + model_name + fpi_suffix)) {
    return 1;
    }

    if (save_model_mu(dir + model_name + mu_suffix)) {
    return 1;
    }

    if (twords > 0) {
	if (save_model_twords(dir + model_name + twords_suffix)) {
	    return 1;
	}
    }
    
    if (tlinks > 0) {
    if (save_model_tlinks(dir + model_name + tlinks_suffix)) {
        return 1;
    }
    }
    
	if (save_model_tlinksByTime(dir + model_name + tlinksByTime_suffix)) {
        return 1;
    }
		

    return 0;
}

int model::save_model_tassign(string filename) {
    int i, j;
    
    FILE * fout = fopen(filename.c_str(), "w");
    if (!fout) {
	printf("Cannot open file %s to save!\n", filename.c_str());
	return 1;
    }

    // wirte docs with topic assignments for words
    for (i = 0; i < ptrndata->M; i++) {    
	for (j = 0; j < ptrndata->docs[i]->length; j++) {
	    fprintf(fout, "%d:%d ", ptrndata->docs[i]->words[j], z[i][j]);
	}
	fprintf(fout, "\n");
    }

    fclose(fout);
    
    return 0;
}

int model::save_model_theta(string filename) {
    FILE * fout = fopen(filename.c_str(), "w");
    if (!fout) {
	printf("Cannot open file %s to save!\n", filename.c_str());
	return 1;
    }
    
    for (int i = 0; i < M; i++) {
	for (int j = 0; j < K; j++) {
	    fprintf(fout, "%f ", theta[i][j]);
	}
	fprintf(fout, "\n");
    }
    
    fclose(fout);
    
    return 0;
}

int model::save_model_phi(string filename) {
    FILE * fout = fopen(filename.c_str(), "w");
    if (!fout) {
	printf("Cannot open file %s to save!\n", filename.c_str());
	return 1;
    }
    
    for (int i = 0; i < K; i++) {
	for (int j = 0; j < V; j++) {
	    fprintf(fout, "%f ", phi[i][j]);
	}
	fprintf(fout, "\n");
    }
    
    fclose(fout);    
    
    return 0;
}

int model::save_model_gama(string filename) {
    FILE * fout = fopen(filename.c_str(), "w");
    if (!fout) {
    printf("Cannot open file %s to save!\n", filename.c_str());
    return 1;
    }
    
    for (int i = 0; i < K; i++) {
    for (int j = 0; j < L; j++) {
        fprintf(fout, "%f ", gama[i][j]);
    }
    fprintf(fout, "\n");
    }
    
    fclose(fout);    
    
    return 0;
}

int model::save_model_fpi(string filename) {
    FILE * fout = fopen(filename.c_str(), "w");
    if (!fout) {
    printf("Cannot open file %s to save!\n", filename.c_str());
    return 1;
    }
    
    for (int j = 0; j < L; j++) {
        fprintf(fout, "%f\n", fpi[j]);
    }
    
    fclose(fout);    
    
    return 0;
}

int model::save_model_mu(string filename) {
    FILE * fout = fopen(filename.c_str(), "w");
    if (!fout) {
    printf("Cannot open file %s to save!\n", filename.c_str());
    return 1;
    }
    
    for (int i = 0; i < M; i++) {
    fprintf(fout, "%f %f %f%%\n", mu[i][0],mu[i][1],mu[i][1]/(mu[i][0]+mu[i][1])*100);
    }
    
    fclose(fout);    
    
    return 0;
}

int model::save_model_others(string filename) {
    FILE * fout = fopen(filename.c_str(), "w");
    if (!fout) {
	printf("Cannot open file %s to save!\n", filename.c_str());
	return 1;
    }

    fprintf(fout, "alpha=%f\n", alpha);
    fprintf(fout, "beta=%f\n", beta);
    fprintf(fout, "omega=%f\n", omega);
    fprintf(fout, "rho=%f\n", rho);
    fprintf(fout, "mu=%f\n", mu);
    fprintf(fout, "ntopics=%d\n", K);
    fprintf(fout, "ndocs=%d\n", M);
    fprintf(fout, "nwords=%d\n", V);
    fprintf(fout, "liter=%d\n", liter);
    
    fclose(fout);    
    
    return 0;
}

int model::save_model_twords(string filename) {
    FILE * fout = fopen(filename.c_str(), "w");
    if (!fout) {
	printf("Cannot open file %s to save!\n", filename.c_str());
	return 1;
    }
    
    if (twords > V) {
	twords = V;
    }
    mapid2word::iterator it;
    
    for (int k = 0; k < K; k++) {
	vector<pair<int, double> > words_probs;
	pair<int, double> word_prob;
	for (int w = 0; w < V; w++) {
	    word_prob.first = w;
	    word_prob.second = phi[k][w];
	    words_probs.push_back(word_prob);
	}
    
        // quick sort to sort word-topic probability
	utils::quicksort(words_probs, 0, words_probs.size() - 1);
	
	fprintf(fout, "Topic %dth:\n", k);
	printf("Saving twords %d\n", k);	
	for (int i = 0; i < twords; i++) {
	    it = id2word.find(words_probs[i].first);
	    if (it != id2word.end()) {
		fprintf(fout, "\t%s   %f\n", (it->second).c_str(), words_probs[i].second);
	    }
	}
    }
    
    fclose(fout);    
    
    return 0;    
}

int model::save_model_tlinks(string filename) {
    FILE * fout = fopen(filename.c_str(), "w");
    if (!fout) {
    printf("Cannot open file %s to save!\n", filename.c_str());
    return 1;
    }
    
    if (tlinks > L) {
    tlinks = L;
    }
    mapid2link::iterator it;
    
    for (int k = 0; k < K; k++) {
    vector<pair<int, double> > links_probs;
    pair<int, double> link_prob;
    for (int w = 0; w < L; w++) {
        link_prob.first = w;
        link_prob.second = gama[k][w];
        links_probs.push_back(link_prob);
    }    
        // quick sort to sort link-topic probability
    utils::quicksort(links_probs, 0, links_probs.size() - 1);
    
    fprintf(fout, "Topic %dth:\n", k);
    printf("Saving tlinks %d\n", k);
	for (int i = 0; i < tlinks; i++) {
        it = id2link.find(links_probs[i].first);
        if (it != id2link.end()) {
        fprintf(fout, "\t%s   %f\n", (it->second).c_str(), links_probs[i].second);
        }
    }
    }
    
    vector<pair<int, double> > links_probs_pi;
    pair<int, double> link_prob_pi;
    for (int w = 0; w < L; w++) {
        link_prob_pi.first = w;
        link_prob_pi.second = fpi[w];
        links_probs_pi.push_back(link_prob_pi);
    }    
        // quick sort to sort link-topic probability
    utils::quicksort(links_probs_pi, 0, links_probs_pi.size() - 1);
    
    fprintf(fout, "Topic PI:\n");
    for (int i = 0; i < tlinks; i++) {
        it = id2link.find(links_probs_pi[i].first);
        if (it != id2link.end()) {
        fprintf(fout, "\t%s   %f\n", (it->second).c_str(), links_probs_pi[i].second);
        }
    }

    fclose(fout);    
    
    return 0;    
}

int model::save_model_tlinksByTime(string filename) {
	for(int i=0;i<K;i++){    
		char fname[1024]="hello";
		sprintf(fname,"%s%d",filename.c_str(),i);
		printf("Saving %s\n",fname);

		FILE * fout = fopen(fname, "w");
    if (!fout) {
    printf("Cannot open file %s to save!\n", filename.c_str());
    return 1;
    }

		for (int j = 0; j < L; j++) {
    for (int t = 1; t < Slices+1; t++) {
        fprintf(fout, "%d ", lkty[j][i][t]);
    }
    fprintf(fout, "\n");
    }		
    fclose(fout);   
    }

	char fname[1024]="hello";
		sprintf(fname,"%s%s",filename.c_str(),"_pi");
		printf("Saving %s\n",fname);

		FILE * fout = fopen(fname, "w");
    if (!fout) {
    printf("Cannot open file %s to save!\n", filename.c_str());
    return 1;
    }

	for (int j = 0; j < L; j++) {
    for (int t = 1; t < Slices+1; t++) {
        fprintf(fout, "%d ", pit[j][t]);
    }
    fprintf(fout, "\n");
    }		
    fclose(fout);
    return 0;    
}

/*int model::save_inf_model(string model_name) {
    if (save_inf_model_tassign(dir + model_name + tassign_suffix)) {
	return 1;
    }
    
    if (save_inf_model_others(dir + model_name + others_suffix)) {
	return 1;
    }
    
    if (save_inf_model_newtheta(dir + model_name + theta_suffix)) {
	return 1;
    }
    
    if (save_inf_model_newphi(dir + model_name + phi_suffix)) {
	return 1;
    }

    if (twords > 0) {
	if (save_inf_model_twords(dir + model_name + twords_suffix)) {
	    return 1;
	}
    }
    
    return 0;
}

int model::save_inf_model_tassign(string filename) {
    int i, j;
    
    FILE * fout = fopen(filename.c_str(), "w");
    if (!fout) {
	printf("Cannot open file %s to save!\n", filename.c_str());
	return 1;
    }

    // wirte docs with topic assignments for words
    for (i = 0; i < pnewdata->M; i++) {    
	for (j = 0; j < pnewdata->docs[i]->length; j++) {
	    fprintf(fout, "%d:%d ", pnewdata->docs[i]->words[j], newz[i][j]);
	}
	fprintf(fout, "\n");
    }

    fclose(fout);
    
    return 0;
}

int model::save_inf_model_newtheta(string filename) {
    int i, j;

    FILE * fout = fopen(filename.c_str(), "w");
    if (!fout) {
	printf("Cannot open file %s to save!\n", filename.c_str());
	return 1;
    }
    
    for (i = 0; i < newM; i++) {
	for (j = 0; j < K; j++) {
	    fprintf(fout, "%f ", newtheta[i][j]);
	}
	fprintf(fout, "\n");
    }
    
    fclose(fout);
    
    return 0;
}

int model::save_inf_model_newphi(string filename) {
    FILE * fout = fopen(filename.c_str(), "w");
    if (!fout) {
	printf("Cannot open file %s to save!\n", filename.c_str());
	return 1;
    }
    
    for (int i = 0; i < K; i++) {
	for (int j = 0; j < newV; j++) {
	    fprintf(fout, "%f ", newphi[i][j]);
	}
	fprintf(fout, "\n");
    }
    
    fclose(fout);    
    
    return 0;
}

int model::save_inf_model_others(string filename) {
    FILE * fout = fopen(filename.c_str(), "w");
    if (!fout) {
	printf("Cannot open file %s to save!\n", filename.c_str());
	return 1;
    }

    fprintf(fout, "alpha=%f\n", alpha);
    fprintf(fout, "beta=%f\n", beta);
    fprintf(fout, "ntopics=%d\n", K);
    fprintf(fout, "ndocs=%d\n", newM);
    fprintf(fout, "nwords=%d\n", newV);
    fprintf(fout, "liter=%d\n", inf_liter);
    
    fclose(fout);    
    
    return 0;
}

int model::save_inf_model_twords(string filename) {
    FILE * fout = fopen(filename.c_str(), "w");
    if (!fout) {
	printf("Cannot open file %s to save!\n", filename.c_str());
	return 1;
    }
    
    if (twords > newV) {
	twords = newV;
    }
    mapid2word::iterator it;
    map<int, int>::iterator _it;
    
    for (int k = 0; k < K; k++) {
	vector<pair<int, double> > words_probs;
	pair<int, double> word_prob;
	for (int w = 0; w < newV; w++) {
	    word_prob.first = w;
	    word_prob.second = newphi[k][w];
	    words_probs.push_back(word_prob);
	}
    
        // quick sort to sort word-topic probability
	utils::quicksort(words_probs, 0, words_probs.size() - 1);
	
	fprintf(fout, "Topic %dth:\n", k);
	for (int i = 0; i < twords; i++) {
	    _it = pnewdata->_id2id.find(words_probs[i].first);
	    if (_it == pnewdata->_id2id.end()) {
		continue;
	    }
	    it = id2word.find(_it->second);
	    if (it != id2word.end()) {
		fprintf(fout, "\t%s   %f\n", (it->second).c_str(), words_probs[i].second);
	    }
	}
    }
    
    fclose(fout);    
    
    return 0;    
}*/

int model::init_est() {
    printf("init begin\n");
    int m, n, w, k;

    p = new double[K];
    lp0 = new double[K];
    lp1 = new double[K];
    
    // + read training data
    ptrndata = new dataset;
    if (ptrndata->read_trndata(dir + dfile, dir + wordmapfile)) {
        printf("Fail to read training data!\n");
        return 1;
    }

    if (ptrndata->read_ltrndata(dir + lfile, dir + tfile, dir + linkmapfile)) {
        printf("Fail to read link-training data!\n");
        return 1;
    }

	//printf("read data!\n");

    // + allocate memory and assign values for variables
    M = ptrndata->M;    //number of document
    V = ptrndata->V;    //number of words
    L = ptrndata->L;    //number of links
    // K: from command line or default value
    // alpha, beta: from command line or default values
    // niters, savestep: from command line or default values

    //printf("m:%d v:%d l:%d\n",M,V,L);
    nw = new int*[V];
    for (w = 0; w < V; w++) {
        nw[w] = new int[K];
        for (k = 0; k < K; k++) {
    	    nw[w][k] = 0;
        }
    }
	
    nd = new int*[M];
    for (m = 0; m < M; m++) {
        nd[m] = new int[K];
        for (k = 0; k < K; k++) {
    	    nd[m][k] = 0;
        }
    }
	
    nwsum = new int[K];
    for (k = 0; k < K; k++) {
	nwsum[k] = 0;
    }
    
  //  lkysum = new int[K];
 //   for (k = 0; k < K; k++) {
 //   lkysum[M] = 0;
 //   }

    ndsum = new int[M];
    for (m = 0; m < M; m++) {
	ndsum[m] = 0;
    }

    srandom(time(0)); // initialize for random number generation
    z = new int*[M];
printf("word init begin ! z\n");
    for (m = 0; m < ptrndata->M; m++) {
	    int N = ptrndata->docs[m]->length;
	    z[m] = new int[N];
	
        // initialize for z
        for (n = 0; n < N; n++) {
    	    int topic = (int)(((double)random() / RAND_MAX) * K);
    	    z[m][n] = topic;
    	    
    	    // number of instances of word i assigned to topic j
    	    nw[ptrndata->docs[m]->words[n]][topic] += 1;
    	    // number of words in document i assigned to topic j
    	    nd[m][topic] += 1;
    	    // total number of words assigned to topic j
    	    nwsum[topic] += 1;
        } 
        // total number of words in document i
        ndsum[m] = N;      
    }
    
	printf("word init finished ! z\n");

    lnw = new int*[L];
    for (w = 0; w < L; w++) {
        lnw[w] = new int[K];
        for (k = 0; k < K; k++) {
            lnw[w][k] = 0;
        }
    }
    
    ly = new int*[L];
    for (w = 0; w < L; w++) {
        ly[w] = new int[2];
        for (k = 0; k < 2; k++) {
            ly[w][k] = 0;
        }
    }

    lny = new int*[M];
    for (w = 0; w < M; w++) {
        lny[w] = new int[2];
        for (k = 0; k < 2; k++) {
            lny[w][k] = 0;
        }
    }

    lnd = new int*[M];
    for (m = 0; m < M; m++) {
        lnd[m] = new int[K];
        for (k = 0; k < K; k++) {
            lnd[m][k] = 0;
        }
    }   
    
    lky = new int*[L];
    for (m = 0; m < L; m++) {
        lky[m] = new int[K];
        for (k = 0; k < K; k++) {
            lky[m][k] = 0;
        }
    }

	lkty = new int**[L];
    for (m = 0; m < L; m++) {
        lkty[m] = new int*[K];
        for (k = 0; k < K; k++) {            
				lkty[m][k] = new int[Slices+1];
				for (int t=0;t<Slices+1;t++)
					lkty[m][k][t] = 0;
        }
    }

    lnwsum = new int[K];
    for (k = 0; k < K; k++) {
        lnwsum[k] = 0;
    }

    lkysum = new int[K];
    for (k = 0; k < K; k++) {
        lkysum[k] = 0;
    }

    lndsum = new int[M];
    for (m = 0; m < M; m++) {
        lndsum[m] = 0;
    }

    pi = new int[L];
    for (k = 0; k < L; k++) {
        pi[k] = 0;
    }

	pit = new int*[L];
    for (k = 0; k < L; k++) {
        pit[k] = new int[Slices+1];
		 for(int t=0;t<Slices+1;t++)
			pit[k][t] = 0;
    }

    lysum = new int[2];
    for (k = 0; k < 2; k++) {
        lysum[k] = 0;
    }


	//printf("read data! lz\n");
    //srandom(time(0)); // initialize for random number generation
	printf("init begin! lz\n");    
	lz = new int*[M];
    y = new int*[M];
    for (m = 0; m < ptrndata->M; m++) {
        int N = ptrndata->ldocs[m]->length;
        lz[m] = new int[N];
        y[m] = new int[N];
    
			//printf("before for!\n");
			for(int n=0;n<N;n++){
        // initialize for z             
				int w = ptrndata->ldocs[m]->words[n];				
				int t = ptrndata->tdocs[m]->words[n];	
           // printf("%d ,%d ,%d\n",w,t,N);			
				int randomY = (int)(((double)random() / RAND_MAX) * 2);
            lny[m][randomY] += 1;
            ly[w][randomY] += 1;

            lysum[randomY] += 1;
            y[m][n] = randomY;
				lz[m][n] = 0;

				//printf("M:%d N:%d\n",m,n);
				//printf("random:%d\n\n",randomY);

            if(randomY == 1){
                int topic = (int)(((double)random() / RAND_MAX) * K);
                lnd[m][topic] += 1;
                lndsum[m] += 1;
                lky[w][topic] += 1;
                lkty[w][topic][t] +=1;
					 lkysum[topic] += 1;
					 lz[m][n] = topic;
            }else{
                pi[w] += 1;
					 pit[w][t] += 1;
                pisum += 1;
 
            }
   
        }
  
    }
 	 printf("link init finished\n");
	//printf("read data! theta\n");
    theta = new double*[M];
    for (m = 0; m < M; m++) {
        theta[m] = new double[K];
    }
	
    phi = new double*[K];
    for (k = 0; k < K; k++) {
        phi[k] = new double[V];
    }

	//printf("read data! gama\n");
    gama = new double*[K];
    for (k = 0; k < K; k++) {
        gama[k] = new double[L];
    }

    mu = new double*[M];
    for (k = 0; k < M; k++) {
        mu[k] = new double[2];
    }

    fpi = new double[L];
    //show_data();

    return 0;
}

/*int model::init_estc() {
    // estimating the model from a previously estimated one
    int m, n, w, k;

    p = new double[K];

    // load moel, i.e., read z and ptrndata
    if (load_model(model_name)) {
	printf("Fail to load word-topic assignmetn file of the model!\n");
	return 1;
    }

    nw = new int*[V];
    for (w = 0; w < V; w++) {
        nw[w] = new int[K];
        for (k = 0; k < K; k++) {
    	    nw[w][k] = 0;
        }
    }
	
    nd = new int*[M];
    for (m = 0; m < M; m++) {
        nd[m] = new int[K];
        for (k = 0; k < K; k++) {
    	    nd[m][k] = 0;
        }
    }
	
    nwsum = new int[K];
    for (k = 0; k < K; k++) {
	nwsum[k] = 0;
    }
    
    ndsum = new int[M];
    for (m = 0; m < M; m++) {
	ndsum[m] = 0;
    }

    for (m = 0; m < ptrndata->M; m++) {
	int N = ptrndata->docs[m]->length;

	// assign values for nw, nd, nwsum, and ndsum	
        for (n = 0; n < N; n++) {
    	    int w = ptrndata->docs[m]->words[n];
    	    int topic = z[m][n];
    	    
    	    // number of instances of word i assigned to topic j
    	    nw[w][topic] += 1;
    	    // number of words in document i assigned to topic j
    	    nd[m][topic] += 1;
    	    // total number of words assigned to topic j
    	    nwsum[topic] += 1;
        } 
        // total number of words in document i
        ndsum[m] = N;      
    }
	
    theta = new double*[M];
    for (m = 0; m < M; m++) {
        theta[m] = new double[K];
    }
	
    phi = new double*[K];
    for (k = 0; k < K; k++) {
        phi[k] = new double[V];
    }    

    return 0;        
}*/

void model::estimate() {
    printf("begin estimate\n");
    if (twords > 0) {
	// print out top words per topic
	dataset::read_wordmap(dir + wordmapfile, &id2word);
    }

    if (tlinks > 0) {
    // print out top links per topic
    dataset::read_linkmap(dir + linkmapfile, &id2link);
    }

    printf("Sampling %d iterations!\n", niters);

    int last_iter = liter;
    for (liter = last_iter + 1; liter <= niters + last_iter; liter++) {
    	printf("Iteration %d ...\n", liter);    	

    	// for all z_i
    	for (int m = 0; m < M; m++) {
            //printf("length:=%d\n",ptrndata->docs[m]->length);
    	    for (int n = 0; n < ptrndata->docs[m]->length; n++) {
    		  // (z_i = z[m][n])
    		  // sample from p(z_i|z_-i, w)
    		  int topic = sampling(m, n);
              z[m][n] = topic;
    	    }
				//printf("z finish!\n");
        //   printf("%d,%d sample word finishied\n",liter,m);
            for (int n = 0; n < ptrndata->ldocs[m]->length; n++) {
              // (z_i = z[m][n])
              // sample from p(z_i|z_-i, w)
              int topic = lsampling(m, n);
					//printf("sampling finish\n");
              lz[m][n] = topic/2;
              y[m][n] = topic%2;
            }
           //      printf("%d,%d sample link finishied\n",liter,m);
				//printf("\n");
    	}
    	
    	if (savestep > 0) {
    	    if (liter % savestep == 0) {
    		// saving the model
    		printf("Saving the model at iteration %d ...\n", liter);
    		//show_data();
            //compute_theta();
    		compute_phi();
            compute_gama();
            compute_fpi();
            compute_mu();
    		save_model(utils::generate_model_name(liter));
    	    }
    	}
    }
    
    printf("Gibbs sampling completed!\n");
    printf("Saving the final model!\n");
    //compute_theta();
    compute_phi();
    compute_gama();
    compute_fpi();
    compute_mu();
	 
	/*for(int i=0;i<M;i++){
		for(int j=0;j<Slices;j++)
			printf("%d ",pit[i][j]);
		printf("\n");
	}*/

    liter--;
    save_model(utils::generate_model_name(-1));
}

int model::sampling(int m, int n) {
    // remove z_i from the count variables
    int topic = z[m][n];
    int w = ptrndata->docs[m]->words[n];
    nw[w][topic] -= 1;
    nd[m][topic] -= 1;
    nwsum[topic] -= 1;
    ndsum[m] -= 1;

    double Vbeta = V * beta;  
    // do multinomial sampling via cumulative method
    for (int k = 0; k < K; k++) {
	p[k] = (nw[w][k] + beta) / (nwsum[k] + Vbeta) *
		    (nd[m][k] + lnd[m][k] + alpha);
    }
    // cumulate multinomial parameters
    for (int k = 1; k < K; k++) {
	p[k] += p[k - 1];
    }
    // scaled sample because of unnormalized p[]
    double u = ((double)random() / RAND_MAX) * p[K - 1];
    
    for (topic = 0; topic < K; topic++) {
	if (p[topic] > u) {
	    break;
	}
    }
    
    // add newly estimated z_i to count variables
    nw[w][topic] += 1;
    nd[m][topic] += 1;
    nwsum[topic] += 1;
    ndsum[m] += 1;    
    return topic;
    return 0;
}

int model::lsampling(int m, int n) {
    
		//printf("    sampling start!\n");
    // remove z_i from the count variables
    int topic = lz[m][n];
    int tempY = y[m][n];
    int w = ptrndata->ldocs[m]->words[n];
    int t = ptrndata->tdocs[m]->words[n];
	//printf("%d ",t);

	//printf("    Nums:%d %d %d!\n",topic,tempY,w);

    if(tempY == 1){
    
        lky[w][topic] -= 1;
        lkysum[topic] -= 1;
		  lkty[w][topic][t] -= 1;
        lnd[m][topic] -= 1;
        lndsum[m] -= 1; // change
    }else{
        pi[w] -= 1;
        pit[w][t] -= 1;
		  pisum -= 1;
    }
    lny[m][tempY] -= 1;
    ly[w][tempY] -= 1;
    lysum[tempY] -= 1;


		//printf("    sub finished!\n");
    double Lomega = L * omega;
    double Lepsilon = L * epsilon;
    // do multinomial sampling via cumulative method
    for (int k = 0; k < K; k++) {
       // lp1[k] = (lky[w][k] + omega) / (lkysum[k] + Lomega) * (lysum[1] + rho) * (nd[m][k] + lnd[m][k] + alpha);
       // lp0[k] = (pi[w] + epsilon) / (pisum + Lepsilon) * (lysum[0] + rho) * (nd[m][k] + lnd[m][k] + alpha);

        lp1[k] = (lky[w][k] + omega) / (lkysum[k] + Lomega) * (lny[m][1] + rho) * (nd[m][k] + lnd[m][k] + alpha);
        lp0[k] = (pi[w] + epsilon) / (pisum + Lepsilon) * (lny[m][0] + rho) * (nd[m][k] + lnd[m][k] + alpha);
    }
    // cumulate multinomial parameters
    for (int k = 1; k < K; k++) {
        lp0[k] += lp0[k - 1];
        lp1[k] += lp1[k - 1];
    }

	//printf("    calculate y!\n");

    double uy = ((double)random() / RAND_MAX) * (lp0[K - 1] + lp1[K - 1]);

    if(uy<0||uy>(lp0[K - 1] + lp1[K - 1])){
        uy=0;
    printf("uy correct");
    }

    if(uy < lp0[K - 1]){
        tempY = 0;
        pi[w] += 1;
	  pit[w][t] += 1;
        pisum += 1;
        lny[m][tempY] += 1;
        ly[w][tempY] += 1;
        lysum[tempY] += 1;    
    }else{
        double u = ((double)random() / RAND_MAX) * (lp1[K - 1]);
        
        for (topic = 0; topic < K; topic++) {
        if (lp1[topic] >= u) {
            break;
        }
        }
        if(topic<0||topic>=K){
         printf("%d  out of index",topic);
        printf("topic correct\n");
         topic= int(u*K);
        }

        tempY = 1;
        lky[w][topic] += 1;
        lkysum[topic] += 1;
	  lkty[w][topic][t] += 1;
	  lnd[m][topic] += 1;
        lndsum[m] += 1;
        lny[m][tempY] += 1;
        ly[w][tempY] += 1;
        lysum[tempY] += 1;
    }
    return topic*2+tempY;
}

void model::compute_theta() {
    for (int m = 0; m < M; m++) {
    	for (int k = 0; k < K; k++) {
    	    theta[m][k] = (nd[m][k] + lnd[m][k] + alpha) / (ndsum[m] + lndsum[m] + K * alpha);
    	}
    }
}

void model::compute_phi() {
    for (int k = 0; k < K; k++) {
    	for (int w = 0; w < V; w++) {
    	    phi[k][w] = (nw[w][k] + beta) / (nwsum[k] + V * beta);
    	}
    }
}

void model::compute_gama() {
    for (int k = 0; k < K; k++) {
        for (int w = 0; w < L; w++) {
            gama[k][w] = lky[w][k];// + omega) / (lkysum[k] + L * omega);
        }
    }
}

void model::compute_fpi() {
    for(int w = 0; w < L; w++) {
        fpi[w] = pi[w];// (pi[w] + epsilon) / (pisum + L * epsilon);
    }
}

void model::compute_mu() {
    for (int m = 0; m < M; m++) {
        for (int k = 0; k < 2; k++) {
            mu[m][k] = (lny[m][k] + rho) / (lny[m][0] + lny[m][1] + 2 * rho);
        }
    }
}

/*int model::init_inf() {
    // estimating the model from a previously estimated one
    int m, n, w, k;

    p = new double[K];

    // load moel, i.e., read z and ptrndata
    if (load_model(model_name)) {
	printf("Fail to load word-topic assignmetn file of the model!\n");
	return 1;
    }

    nw = new int*[V];
    for (w = 0; w < V; w++) {
        nw[w] = new int[K];
        for (k = 0; k < K; k++) {
    	    nw[w][k] = 0;
        }
    }
	
    nd = new int*[M];
    for (m = 0; m < M; m++) {
        nd[m] = new int[K];
        for (k = 0; k < K; k++) {
    	    nd[m][k] = 0;
        }
    }
	
    nwsum = new int[K];
    for (k = 0; k < K; k++) {
	nwsum[k] = 0;
    }
    
    ndsum = new int[M];
    for (m = 0; m < M; m++) {
	ndsum[m] = 0;
    }

    for (m = 0; m < ptrndata->M; m++) {
	int N = ptrndata->docs[m]->length;

	// assign values for nw, nd, nwsum, and ndsum	
        for (n = 0; n < N; n++) {
    	    int w = ptrndata->docs[m]->words[n];
    	    int topic = z[m][n];
    	    
    	    // number of instances of word i assigned to topic j
    	    nw[w][topic] += 1;
    	    // number of words in document i assigned to topic j
    	    nd[m][topic] += 1;
    	    // total number of words assigned to topic j
    	    nwsum[topic] += 1;
        } 
        // total number of words in document i
        ndsum[m] = N;      
    }
    
    // read new data for inference
    pnewdata = new dataset;
    if (withrawstrs) {
	if (pnewdata->read_newdata_withrawstrs(dir + dfile, dir + wordmapfile)) {
    	    printf("Fail to read new data!\n");
    	    return 1;
	}    
    } else {
	if (pnewdata->read_newdata(dir + dfile, dir + wordmapfile)) {
    	    printf("Fail to read new data!\n");
    	    return 1;
	}    
    }
    
    newM = pnewdata->M;
    newV = pnewdata->V;
    
    newnw = new int*[newV];
    for (w = 0; w < newV; w++) {
        newnw[w] = new int[K];
        for (k = 0; k < K; k++) {
    	    newnw[w][k] = 0;
        }
    }
	
    newnd = new int*[newM];
    for (m = 0; m < newM; m++) {
        newnd[m] = new int[K];
        for (k = 0; k < K; k++) {
    	    newnd[m][k] = 0;
        }
    }
	
    newnwsum = new int[K];
    for (k = 0; k < K; k++) {
	newnwsum[k] = 0;
    }
    
    newndsum = new int[newM];
    for (m = 0; m < newM; m++) {
	newndsum[m] = 0;
    }

    srandom(time(0)); // initialize for random number generation
    newz = new int*[newM];
    for (m = 0; m < pnewdata->M; m++) {
	int N = pnewdata->docs[m]->length;
	newz[m] = new int[N];

	// assign values for nw, nd, nwsum, and ndsum	
        for (n = 0; n < N; n++) {
    	    int w = pnewdata->docs[m]->words[n];
    	    int _w = pnewdata->_docs[m]->words[n];
    	    int topic = (int)(((double)random() / RAND_MAX) * K);
    	    newz[m][n] = topic;
    	    
    	    // number of instances of word i assigned to topic j
    	    newnw[_w][topic] += 1;
    	    // number of words in document i assigned to topic j
    	    newnd[m][topic] += 1;
    	    // total number of words assigned to topic j
    	    newnwsum[topic] += 1;
        } 
        // total number of words in document i
        newndsum[m] = N;      
    }    
    
    newtheta = new double*[newM];
    for (m = 0; m < newM; m++) {
        newtheta[m] = new double[K];
    }
	
    newphi = new double*[K];
    for (k = 0; k < K; k++) {
        newphi[k] = new double[newV];
    }    
    
    return 0;        
}

void model::inference() {
    if (twords > 0) {
	// print out top words per topic
	dataset::read_wordmap(dir + wordmapfile, &id2word);
    }

    printf("Sampling %d iterations for inference!\n", niters);
    
    for (inf_liter = 1; inf_liter <= niters; inf_liter++) {
	printf("Iteration %d ...\n", inf_liter);
	
	// for all newz_i
	for (int m = 0; m < newM; m++) {
	    for (int n = 0; n < pnewdata->docs[m]->length; n++) {
		// (newz_i = newz[m][n])
		// sample from p(z_i|z_-i, w)
		int topic = inf_sampling(m, n);
		newz[m][n] = topic;
	    }
	}
    }
    
    printf("Gibbs sampling for inference completed!\n");
    printf("Saving the inference outputs!\n");
    compute_newtheta();
    compute_newphi();
    inf_liter--;
    save_inf_model(dfile);
}

int model::inf_sampling(int m, int n) {
    // remove z_i from the count variables
    int topic = newz[m][n];
    int w = pnewdata->docs[m]->words[n];
    int _w = pnewdata->_docs[m]->words[n];
    newnw[_w][topic] -= 1;
    newnd[m][topic] -= 1;
    newnwsum[topic] -= 1;
    newndsum[m] -= 1;
    
    double Vbeta = V * beta;
    double Kalpha = K * alpha;
    // do multinomial sampling via cumulative method
    for (int k = 0; k < K; k++) {
	p[k] = (nw[w][k] + newnw[_w][k] + beta) / (nwsum[k] + newnwsum[k] + Vbeta) *
		    (newnd[m][k] + alpha) / (newndsum[m] + Kalpha);
    }
    // cumulate multinomial parameters
    for (int k = 1; k < K; k++) {
	p[k] += p[k - 1];
    }
    // scaled sample because of unnormalized p[]
    double u = ((double)random() / RAND_MAX) * p[K - 1];
    
    for (topic = 0; topic < K; topic++) {
	if (p[topic] > u) {
	    break;
	}
    }
    
    // add newly estimated z_i to count variables
    newnw[_w][topic] += 1;
    newnd[m][topic] += 1;
    newnwsum[topic] += 1;
    newndsum[m] += 1;    
    
    return topic;
}

void model::compute_newtheta() {
    for (int m = 0; m < newM; m++) {
	for (int k = 0; k < K; k++) {
	    newtheta[m][k] = (newnd[m][k] + alpha) / (newndsum[m] + K * alpha);
	}
    }
}

void model::compute_newphi() {
    map<int, int>::iterator it;
    for (int k = 0; k < K; k++) {
	for (int w = 0; w < newV; w++) {
	    it = pnewdata->_id2id.find(w);
	    if (it != pnewdata->_id2id.end()) {
		newphi[k][w] = (nw[it->second][k] + newnw[w][k] + beta) / (nwsum[k] + newnwsum[k] + V * beta);
	    }
	}
    }
}*/

void model::show_data() {

    //##############################
    cout<<"--basic--\n";

    cout<<model_status<<endl;
    cout<<dir<<endl;
    cout<<model_name<<endl;
    cout<<dfile<<endl;
    cout<<lfile<<endl;
    cout<<alpha<<endl;
    cout<<beta<<endl;
    cout<<omega<<endl;
    cout<<rho<<endl;
    cout<<epsilon<<endl;
    cout<<K<<endl;
    cout<<niters<<endl;
    cout<<savestep<<endl;
    cout<<twords<<endl;

    //##############################
    cout<<"--size--\n";

    cout<<wordmapfile<<endl;
    cout<<linkmapfile<<endl;
    cout<<"M"<<M<<" V"<<V<<" L"<<L<<endl;

    //##############################
    cout<<"--docs--\n";

    for(int i=0;i<M;i++){
        int len = ptrndata->docs[i]->length;
        for(int j=0;j<len;j++)
            cout<<ptrndata->docs[i]->words[j]<<" ";
        cout<<endl;
    }

    //##############################
    cout<<"--ldocs--\n";

    for(int i=0;i<M;i++){
        int len = ptrndata->ldocs[i]->length;
        for(int j=0;j<len;j++)
            cout<<ptrndata->ldocs[i]->words[j]<<" ";
        cout<<endl;
    }

    //##############################
    cout<<"--nw--\n";

    for(int i=0;i<V;i++){
        for(int j=0;j<K;j++)
            cout<<nw[i][j]<<" ";
        cout<<endl;
    }

    //##############################
    cout<<"--nd--\n";

    for(int i=0;i<M;i++){
        for(int j=0;j<K;j++)
            cout<<nd[i][j]<<" ";
        cout<<endl;
    }

    //##############################
    cout<<"--lnw--\n";

    for(int i=0;i<L;i++){
        for(int j=0;j<K;j++)
            cout<<lnw[i][j]<<" ";
        cout<<endl;
    }

    //##############################
    cout<<"--lnd--\n";

    for(int i=0;i<M;i++){
        for(int j=0;j<K;j++)
            cout<<lnd[i][j]<<" ";
        cout<<endl;
    }

    //##############################
    cout<<"--p--\n";

    for(int i=0;i<=K;i++)
        cout<<p[i]<<" ";
    cout<<endl;
    //##############################
    cout<<"--lp0--\n";

    for(int i=0;i<=K;i++)
        cout<<lp0[i]<<" ";
    cout<<endl;

    //##############################
    cout<<"--lp1--\n";

    for(int i=0;i<=K;i++)
        cout<<lp1[i]<<" ";
    cout<<endl;
}
