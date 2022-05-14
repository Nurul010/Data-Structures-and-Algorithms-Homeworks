// Author: Nurul Saiym
// Date: 1/29/2022
// Homework 1:

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <regex>
using namespace std;

struct word_count { // to keep track of the word and the count
	string word = "";
    int count = 0;
    int sentence_num = 0;
};

int main(int argc, char *argv[]) {
    //************************ Open input file ******************************

	ifstream input;
	input.open(argv[1]);
    //cout << "end" << endl;
    if (!input.is_open()) {
	    cout << "File not found! Exiting!" << endl;
	    exit(EXIT_FAILURE);
	}

    //************************ Store input file into vectors ******************************

    vector<string> st; // to temporarily store words of a sentence
    vector<string> words; //store words in a 1D vectore
    vector<vector<string>> str; //2D vector to keep track of sentences and store words
    vector<string> full_sentences; // vector to store sentences only
    string line;
    string temp;
    string sentence_temp = "";
    bool end_sentence = false;
    while (getline(input, line)) { // reads from file and stores each word to temp
        transform(line.begin(), line.end(), line.begin(), ::tolower); //change word to lowercase
        //cout << line << endl;
        stringstream ls( line );
        ls.seekg(0, ios::end);
        int size = ls.tellg(); //store size of stringstream ls in bytes
        ls.seekg(0, ios::beg);
        while(ls >> temp)
        {
            if (temp.find('.') != std::string::npos) // if a period is found
            {
                temp.pop_back(); //remove period
                end_sentence = true;
            }
            if(ls.tellg() == -1 || ls.tellg() == size-1){ //end of stringstream ls or one byte before the end(for a proceeding space if there are any)
                end_sentence = true;
            }

            st.push_back(temp); //store current word to temporary vector
            words.push_back(temp); // store current word to words vector
            sentence_temp += temp + " "; // store current word to temporary string for sentences
            
            if (end_sentence) // if end of sentence
            {
                str.push_back(st); // store st into str
                sentence_temp.pop_back(); // remove space from last word of temporary sentence
                full_sentences.push_back(sentence_temp); // push the temporary sentence string into the vecor
                st.clear(); // clear words of current sentence
                sentence_temp = ""; //reset temporary sentence
                end_sentence = false;
            }
        }

    }

    //****************************** TASK 1-2 **********************************

struct word_count TASK1_2[3]; //store the int values of word count
    int counter = 0; // for keeping track the count for words found
    vector<string> TASK1_2_st[3]; // store words with the 3 highest count

    for(int i = 0; i<3 ;i++){ //assigning count a value so i can oganize to min or max later
        TASK1_2[i].count = i;
        string t = "x";
        TASK1_2_st[i].push_back(t);
    }
    
    // Find most, 2nd most, and 3rd most frequent words using two loops:
    for(int i = 0; i<words.size() ; i++){
        for (int j = 0; j<words.size() ; j++){

            if(words[i]==words[j]){ // if word is found, increase word counter by 1
                counter += 1;
            }
            if(j+1 == words.size()){ // if end of loop for comparing words[i] with words[j]
                if (counter >= TASK1_2[0].count || counter >= TASK1_2[1].count || counter >= TASK1_2[2].count){ //if word count is greater or equal to any previous stored value and word[i] does not equal any stored words
                    int temp1 = TASK1_2[0].count;
                    int temp2;
                    bool  counter_greater = true;// to check if the counter is equal to a previous word
                    for(int k=0; k<3; k++) {
                        if (counter == TASK1_2[k].count){ // if the word count is equal to another word count
                            bool newword = true;
                            for(auto it = TASK1_2_st[k].begin();it != TASK1_2_st[k].end(); it++){ // check if it is a unique word;
                                if (*it == words[i]){
                                    newword = false;
                                    //cout << endl<< "it == words[i] " << *it << " == " << words[i]<< endl;
                                }
                            }
                            if(newword){ // if unique word
                                TASK1_2_st[k].push_back(words[i]); // add word to vector
                                // cout << endl<< "Counter == task12 , counter = " << counter << ", task12[" << k << "] = " << TASK1_2[k].count<<  endl;
                                // cout << "word: " << words[i] << endl;
                            }
                            counter_greater = false;
                        }
                        if(temp1>=TASK1_2[k].count) {// find the index of the word with the smallest count number
                            temp1=TASK1_2[k].count;
                            temp2=k;
                        }
                    }
                    if(counter_greater){//update the word with the smallest count number with the current word and count number
                        // cout << endl<<"Counter > task12 , counter = " << counter << ", task12[" << temp2 << "] = " << TASK1_2[temp2].count<<  endl;
                        // cout << "word: "<< words[i] << endl;
                        TASK1_2[temp2].count = counter; //update the count number
                        TASK1_2[temp2].word = words[i];
                        TASK1_2_st[temp2].clear(); // remove all vector words from previous stack
                        TASK1_2_st[temp2].push_back(TASK1_2[temp2].word);   // push new word to the vector
                        // cout << "new task12[" << temp2 << "] = " << TASK1_2[temp2].count<<  endl;
                    }
                }
                counter = 0;
            }
        }
    }

    //****************************** TASK 3-9 **********************************
    
    vector<word_count> TASK3; //should have used an array but i was too far into the program to change
    vector<word_count> TASK4;
    vector<word_count> TASK5;
    vector<word_count> TASK6;
    vector<word_count> TASK7;
    vector<word_count> TASK8;
    vector<word_count> TASK9;
    struct word_count temp_freq[10]; //temporarly store words, word count, and sentence number
    int counter4 = 0,counter5 = 0,counter6 = 0,counter7 = 0,counter8 = 0,counter9 = 0;
    string word_freq = "";

    // loop through str and full_sentence vectors
    for(int i = 0; i<str.size() ; i++){
        for(int t = 0; t<str[i].size() ; t++){
            //****** TASK 3 ******
            counter = 0;
            for (int j = 0; j<str[i].size() ; j++){
                if(str[i][t] == str[i][j]){ // if word is found, increase word counter by 1
                    counter += 1;
                }
            }
            if(counter>=temp_freq[3].count){
                int temp3 = temp_freq[3].count;
                temp_freq[3].word = str[i][t];
                temp_freq[3].count = counter;
                temp_freq[3].sentence_num = i;
                if(counter==temp3){
                    bool uniqeword = true;
                    for (int k = 0; k<TASK3.size(); k++){//makes sure the vector has unique words
                        if(TASK3[k].word == str[i][t] && TASK3[k].sentence_num == i){
                            uniqeword = false;
                        }
                    }
                    if (uniqeword){
                        TASK3.push_back(temp_freq[3]);
                    }
                }
                else{
                    TASK3.clear();//if a greater count is found, then it removes all old info and adds the new info
                    TASK3.push_back(temp_freq[3]);
                }
            }
            //****** TASK 4 ******
            if(str[i][t] == "the"){
                counter4 += 1;// if word is found, increase word counter4 by 1
            }
            //****** TASK 5 ******
            if(str[i][t] == "of"){
                counter5 += 1;// if word is found, increase word counter5 by 1
            }
            //****** TASK 6 ******
            if(str[i][t] == "was"){
                counter6 += 1;// if word is found, increase word counter6 by 1
            }
        }
        //****** TASK 4 ******
        if(counter4>=temp_freq[4].count){ // same as task 3 with few less steps
            int temp3 = temp_freq[4].count;
            temp_freq[4].word = "the";
            temp_freq[4].count = counter4;
            temp_freq[4].sentence_num = i;
            if(counter4==temp3){
                TASK4.push_back(temp_freq[4]);
            }
            else{
                TASK4.clear();
                TASK4.push_back(temp_freq[4]);
            }
        }
        counter4 = 0;

        //****** TASK 5 ******
        if(counter5>=temp_freq[5].count){ // same as task 4
            int temp3 = temp_freq[5].count;
            temp_freq[5].word = "of";
            temp_freq[5].count = counter5;
            temp_freq[5].sentence_num = i;
            if(counter5==temp3){
                TASK5.push_back(temp_freq[5]);
            }
            else{
                TASK5.clear();
                TASK5.push_back(temp_freq[5]);
            }
        }
        counter5 = 0;

        //****** TASK 6 ******
        if(counter6>=temp_freq[6].count){ // same as task 4
            int temp3 = temp_freq[6].count;
            temp_freq[6].word = "was";
            temp_freq[6].count = counter6;
            temp_freq[6].sentence_num = i;
            if(counter6==temp3){
                TASK6.push_back(temp_freq[6]);
            }
            else{
                TASK6.clear();
                TASK6.push_back(temp_freq[6]);
            }
        }
        counter6 = 0;

        //****** TASK 7 ******
        int found = -1;
        do{ // loops through and finds the number of times the phrase is found in the sentence
            found = full_sentences[i].find("but the", found+1);
            if(found != -1){
                //cout << "but the: "<< found << endl;
                counter7++;
            }
        }while(found != -1);

        if(counter7>=temp_freq[7].count){// same as task 4
            int temp3 = temp_freq[7].count;
            temp_freq[7].word = "but the";
            temp_freq[7].count = counter7;
            temp_freq[7].sentence_num = i;
            if(counter7==temp3){
                TASK7.push_back(temp_freq[7]);
            }
            else{
                TASK7.clear();
                TASK7.push_back(temp_freq[7]);
            }
        }
        counter7 = 0;

        //****** TASK 8 ******
        do{// loops through and finds the number of times the phrase is found in the sentence
            found = full_sentences[i].find("it was", found+1);
            if(found != -1){
                //cout << "it was: "<< found << endl;
                counter8++;
            }
        }while(found != -1);

        if(counter8>=temp_freq[8].count){// same as task 4
            int temp3 = temp_freq[8].count;
            temp_freq[8].word = "it was";
            temp_freq[8].count = counter8;
            temp_freq[8].sentence_num = i;
            if(counter8==temp3){
                TASK8.push_back(temp_freq[8]);
            }
            else{
                TASK8.clear();
                TASK8.push_back(temp_freq[8]);
            }
        }
        counter8 = 0;

        //****** TASK 9 ******
        do{// loops through and finds the number of times the phrase is found in the sentence
            found = full_sentences[i].find("in my", found+1);
            if(found != -1){
                //cout << "in my: "<< found << endl;
                counter9++;
            }
        }while(found != -1);

        if(counter9>=temp_freq[9].count){// same as task 4
            int temp3 = temp_freq[9].count;
            temp_freq[9].word = "in my";
            temp_freq[9].count = counter9;
            temp_freq[9].sentence_num = i;
            if(counter9==temp3){
                TASK9.push_back(temp_freq[9]);
            }
            else{
                TASK9.clear();
                TASK9.push_back(temp_freq[9]);
            }
        }
        counter9 = 0;
    }

    //****************************** Output/Debugging **********************************
    // cout << endl << endl;
    // for (int i = 0; i<3; i++){
    //     cout << "word: " << TASK1_2[i].word << " - Counter = " << TASK1_2[i].count << endl;
    // }
//     //cout << words.size() << endl;
//     cout << "TASK3.size() = " << TASK3.size() << endl;
//     cout << "TASK4.size() = " << TASK4.size() << endl;
//     cout << "TASK5.size() = " << TASK5.size() << endl;
//     cout << "TASK6.size() = " << TASK6.size() << endl;
//     // cout << temp_freq.word << ":" << temp_freq.count << ":" << full_sentences[temp_freq.sentencenum] << endl;

    // cout << endl << endl;
    // for(int j = 0; j<3; j++){
    // for (int i = 0; i<TASK1_2_st[j].size(); i++){
    //     cout << "size of TASK1_2_st[" << j << "]: " << TASK1_2_st[j].size() << endl;
    //     cout << "word: " << TASK1_2_st[j][i] << " - Counter = " << TASK1_2[j].count << endl;
    // }
    // }



//     for (int i = 0; i<TASK3.size(); i++){
//         cout << TASK3[i].word << ":" << TASK3[i].count << ":" << full_sentences[TASK3[i].sentence_num] << endl;
//     }
//     cout << endl << endl;
//     for (int i = 0; i<TASK4.size(); i++){
//         cout << TASK4[i].word << ":" << TASK4[i].count << ":" << full_sentences[TASK4[i].sentence_num] << endl;
//     }
//     cout << endl << endl;
//     for (int i = 0; i<TASK5.size(); i++){
//         cout << TASK5[i].word << ":" << TASK5[i].count << ":" << full_sentences[TASK5[i].sentence_num] << endl;
//     }
//    cout << endl << endl;
    // for (int i = 0; i<TASK6.size(); i++){
    //     cout << TASK6[i].word << ":" << TASK6[i].count << ":" << full_sentences[TASK6[i].sentence_num] << endl;
    // }
    // for (int i = 0; i<TASK7.size(); i++){
    //     cout << TASK7[i].word << ":" << TASK7[i].count << ":" << full_sentences[TASK7[i].sentence_num] << endl;
    // }
    // for (int i = 0; i<TASK8.size(); i++){
    //     cout << TASK8[i].word << ":" << TASK8[i].count << ":" << full_sentences[TASK8[i].sentence_num] << endl;
    // }
    // for (int i = 0; i<TASK9.size(); i++){
    //     cout << TASK9[i].word << ":" << TASK9[i].count << ":" << full_sentences[TASK9[i].sentence_num] << endl;
    // }


    //***************OUTPUT****************
    string x = argv[2];
    ofstream output;
    output.open(x+"1.txt");
    int temp1 = TASK1_2[0].count;
    int temp2 = 0;
    for (int i = 0 ; i<3 ; i++){
        if(temp1<=TASK1_2[i].count) {
        temp1=TASK1_2[i].count;
        temp2=i;
        }
    }
    for (auto i1 = TASK1_2_st[temp2].begin();i1 != TASK1_2_st[temp2].end(); i1++){
        output << *i1 << ":" << TASK1_2[temp2].count << endl;
    }
    output.close();

    ofstream output2;
    output2.open(x+"2.txt");
    temp1 = TASK1_2[0].count;
    temp2 = 0;
    for (int i = 0 ; i<3 ; i++){
        if(temp1>=TASK1_2[i].count) {
        temp1=TASK1_2[i].count;
        temp2=i;
        }
    }
    for (auto i2 = TASK1_2_st[temp2].begin();i2 != TASK1_2_st[temp2].end(); i2++){
        output2 << *i2 << ":" << TASK1_2[temp2].count << endl;
    }
    output2.close();

    ofstream output3;
    output3.open(x+"3.txt");
    for (int i = 0; i<TASK3.size(); i++){
        output3 << TASK3[i].word << ":" << TASK3[i].count << ":" << full_sentences[TASK3[i].sentence_num] << endl;
    }
    output3.close();

    ofstream output4;
    output4.open(x+"4.txt");
    for (int i = 0; i<TASK4.size(); i++){
        output4 << TASK4[i].word << ":" << TASK4[i].count << ":" << full_sentences[TASK4[i].sentence_num] << endl;
    }
    output4.close();

    ofstream output5;
    output5.open(x+"5.txt");
    for (int i = 0; i<TASK5.size(); i++){
        output5 << TASK5[i].word << ":" << TASK5[i].count << ":" << full_sentences[TASK5[i].sentence_num] << endl;
    }
    output5.close();

    ofstream output6;
    output6.open(x+"6.txt");
    for (int i = 0; i<TASK6.size(); i++){
        output6 << TASK6[i].word << ":" << TASK6[i].count << ":" << full_sentences[TASK6[i].sentence_num] << endl;
    }
    output6.close();

    ofstream output7;
    output7.open(x+"7.txt");
    for (int i = 0; i<TASK7.size(); i++){
        output7 << TASK7[i].word << ":" << TASK7[i].count << ":" << full_sentences[TASK7[i].sentence_num] << endl;
    }
    output7.close();

    ofstream output8;
    output8.open(x+"8.txt");
    for (int i = 0; i<TASK8.size(); i++){
        output8 << TASK8[i].word << ":" << TASK8[i].count << ":" << full_sentences[TASK8[i].sentence_num] << endl;
    }
    output8.close();

    ofstream output9;
    output9.open(x+"9.txt");
    for (int i = 0; i<TASK9.size(); i++){
        output9 << TASK9[i].word << ":" << TASK9[i].count << ":" << full_sentences[TASK9[i].sentence_num] << endl;
    }
    output9.close();

    input.close();
    return 0;
} 