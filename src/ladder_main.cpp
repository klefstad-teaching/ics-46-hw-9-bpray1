#include "ladder.h"
#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    // Load the dictionary
    set<string> word_list;
    load_words(word_list, "words.txt");
    
    // Uncomment to run tests
    // verify_word_ladder();
    
    string start_word, end_word;
    
    cout << "Word Ladder Program" << endl;
    cout << "-------------------" << endl;
    
    cout << "Enter start word: ";
    cin >> start_word;
    
    cout << "Enter end word: ";
    cin >> end_word;
    
    // Check if the start and end words are the same
    if (start_word == end_word) {
        cout << "Error: Start and end words are the same!" << endl;
        return 1;
    }
    
    // Generate the word ladder
    vector<string> ladder = generate_word_ladder(start_word, end_word, word_list);
    
    // Print the result
    print_word_ladder(ladder);
    
    return 0;
}