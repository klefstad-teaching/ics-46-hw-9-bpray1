#include "ladder.h"

void error(string word1, string word2, string msg) {
    cerr << "Error: " << msg << endl;
    cerr << "Word 1: " << word1 << endl;
    cerr << "Word 2: " << word2 << endl;
}

// Check if the edit distance between two strings is within a certain threshold
bool edit_distance_within(const std::string& str1, const std::string& str2, int d) {
    // Simple base case
    if (str1 == str2) {
        return true;
    }
    
    // If the length difference is more than d, can't be within edit distance d
    if (abs(static_cast<int>(str1.length()) - static_cast<int>(str2.length())) > d) {
        return false;
    }

    // If lengths are the same, count differing characters
    if (str1.length() == str2.length()) {
        int diff_count = 0;
        for (size_t i = 0; i < str1.length(); ++i) {
            if (str1[i] != str2[i]) {
                diff_count++;
                if (diff_count > d) {
                    return false;
                }
            }
        }
        return true;
    }
    
    // If the lengths differ by 1, check for single insertion/deletion
    if (abs(static_cast<int>(str1.length()) - static_cast<int>(str2.length())) == 1) {
        const std::string& shorter = str1.length() < str2.length() ? str1 : str2;
        const std::string& longer = str1.length() < str2.length() ? str2 : str1;
        
        // Check if we can transform shorter to longer by inserting one character
        size_t i = 0, j = 0;
        int diff_count = 0;
        
        while (i < shorter.length() && j < longer.length()) {
            if (shorter[i] == longer[j]) {
                i++;
                j++;
            } else {
                // Skip the extra character in the longer string
                j++;
                diff_count++;
                if (diff_count > d) {
                    return false;
                }
            }
        }
        
        // We've reached the end of shorter, but longer might have one more char
        return (diff_count <= d);
    }
    
    return false;
}

// Check if two words are adjacent (can be transformed with one edit)
bool is_adjacent(const string& word1, const string& word2) {
    // Same words are considered adjacent (based on test requirement)
    if (word1 == word2) {
        return true;
    }
    
    int len1 = word1.length();
    int len2 = word2.length();
    
    // If length differs by more than 1, they can't be adjacent
    if (abs(len1 - len2) > 1) {
        return false;
    }
    
    // Case 1: Same length - check for one character difference
    if (len1 == len2) {
        int diff_count = 0;
        for (int i = 0; i < len1; ++i) {
            if (word1[i] != word2[i]) {
                diff_count++;
            }
            if (diff_count > 1) {
                return false;
            }
        }
        return diff_count <= 1; // Allow 0 or 1 differences
    }
    
    // Case 2: Different length - check if insertion/deletion of one character
    const string& shorter = (len1 < len2) ? word1 : word2;
    const string& longer = (len1 < len2) ? word2 : word1;
    
#include "ladder.h"

void error(string word1, string word2, string msg) {
    cerr << "Error: " << msg << endl;
    cerr << "Word 1: " << word1 << endl;
    cerr << "Word 2: " << word2 << endl;
}

// Check if the edit distance between two strings is within a certain threshold
bool edit_distance_within(const std::string& str1, const std::string& str2, int d) {
    // Simple base case
    if (str1 == str2) {
        return true;
    }
    
    // If the length difference is more than d, can't be within edit distance d
    if (abs(static_cast<int>(str1.length()) - static_cast<int>(str2.length())) > d) {
        return false;
    }

    // If lengths are the same, count differing characters
    if (str1.length() == str2.length()) {
        int diff_count = 0;
        for (size_t i = 0; i < str1.length(); ++i) {
            if (str1[i] != str2[i]) {
                diff_count++;
                if (diff_count > d) {
                    return false;
                }
            }
        }
        return true;
    }
    
    // If the lengths differ by 1, check for single insertion/deletion
    if (abs(static_cast<int>(str1.length()) - static_cast<int>(str2.length())) == 1) {
        const std::string& shorter = str1.length() < str2.length() ? str1 : str2;
        const std::string& longer = str1.length() < str2.length() ? str2 : str1;
        
        // Check if we can transform shorter to longer by inserting one character
        size_t i = 0, j = 0;
        int diff_count = 0;
        
        while (i < shorter.length() && j < longer.length()) {
            if (shorter[i] == longer[j]) {
                i++;
                j++;
            } else {
                // Skip the extra character in the longer string
                j++;
                diff_count++;
                if (diff_count > d) {
                    return false;
                }
            }
        }
        
        // We've reached the end of shorter, but longer might have one more char
        return (diff_count <= d);
    }
    
    return false;
}

// Check if two words are adjacent (can be transformed with one edit)
bool is_adjacent(const string& word1, const string& word2) {
    // Same words are considered adjacent (based on test requirement)
    if (word1 == word2) {
        return true;
    }
    
    int len1 = word1.length();
    int len2 = word2.length();
    
    // If length differs by more than 1, they can't be adjacent
    if (abs(len1 - len2) > 1) {
        return false;
    }
    
    // Case 1: Same length - check for one character difference
    if (len1 == len2) {
        int diff_count = 0;
        for (int i = 0; i < len1; ++i) {
            if (word1[i] != word2[i]) {
                diff_count++;
            }
            if (diff_count > 1) {
                return false;
            }
        }
        return diff_count <= 1; // Allow 0 or 1 differences
    }
    
    // Case 2: Different length - check if insertion/deletion of one character
    const string& shorter = (len1 < len2) ? word1 : word2;
    const string& longer = (len1 < len2) ? word2 : word1;
    
    // Check if longer is formed by inserting one character in shorter
    int i = 0, j = 0, diff = 0;
    
    while (i < shorter.length() && j < longer.length()) {
        if (shorter[i] == longer[j]) {
            i++;
            j++;
        } else {
            // Skip this character in longer
            j++;
            diff++;
            if (diff > 1) {
                return false;
            }
        }
    }
    
    // If we've processed all characters in shorter, but not in longer,
    // the remaining characters in longer count as differences
    diff += longer.length() - j;
    
    return diff <= 1;
}

// Generate a word ladder from begin_word to end_word
vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list) {
    // Check if begin_word and end_word are the same
    if (begin_word == end_word) {
        vector<string> result = {begin_word};
        return result;
    }
    
    // Convert words to lowercase for case-insensitive comparison
    string start_word = begin_word;
    string target_word = end_word;
    for (char& c : start_word) c = tolower(c);
    for (char& c : target_word) c = tolower(c);
    
    // Check if end_word is in the dictionary
    if (word_list.find(target_word) == word_list.end()) {
        return vector<string>();
    }
    
    // Pre-process the dictionary to group words by length for faster lookup
    // This significantly reduces the number of words we need to check
    map<int, vector<string>> words_by_length;
    for (const string& word : word_list) {
        words_by_length[word.length()].push_back(word);
    }
    
    // Queue to store partial ladders (each partial ladder is a vector of strings)
    queue<vector<string>> ladder_queue;
    
    // Start with the begin_word
    ladder_queue.push({start_word});
    
    // Set to keep track of visited words
    set<string> visited;
    visited.insert(start_word);
    
    // BFS to find the shortest ladder
    while (!ladder_queue.empty()) {
        vector<string> current_ladder = ladder_queue.front();
        ladder_queue.pop();
        
        string last_word = current_ladder.back();
        
        // If we reached the target word, return the ladder
        if (last_word == target_word) {
            return current_ladder;
        }
        
        int len = last_word.length();
        
        // Only check words of the same length or +/- 1 length
        for (int l = max(1, len-1); l <= len+1; ++l) {
            const vector<string>& potential_words = words_by_length[l];
            
            // Try words of similar length from the dictionary
            for (const string& word : potential_words) {
                // Skip words we've already visited
                if (visited.find(word) != visited.end()) {
                    continue;
                }
                
                // Check if this word is adjacent
                if (is_adjacent(last_word, word)) {
                    // Mark as visited
                    visited.insert(word);
                    
                    // Create a new ladder by adding this word
                    vector<string> new_ladder = current_ladder;
                    new_ladder.push_back(word);
                    
                    // If this is the end word, we're done
                    if (word == target_word) {
                        return new_ladder;
                    }
                    
                    // Otherwise, add this new ladder to the queue
                    ladder_queue.push(new_ladder);
                }
            }
        }
    }
    
    // If no ladder is found
    return vector<string>();
}

// Load words from a file into a set
void load_words(set<string>& word_list, const string& file_name) {
    ifstream in_file(file_name);
    if (!in_file) {
        cerr << "Error: Could not open file " << file_name << endl;
        return;
    }
    
    string word;
    while (in_file >> word) {
        // Convert to lowercase
        for (char& c : word) {
            c = tolower(c);
        }
        word_list.insert(word);
    }
    
    in_file.close();
}

// Print the word ladder
void print_word_ladder(const vector<string>& ladder) {
    if (ladder.empty()) {
        cout << "No word ladder found." << endl;
        return;
    }
    
    cout << "Word ladder found: ";
    for (size_t i = 0; i < ladder.size(); ++i) {
        cout << ladder[i] << " ";
    }
    cout << endl;
}

// Verify word ladder function for testing
void verify_word_ladder() {
    set<string> word_list;
    load_words(word_list, "words.txt");
    
    #define my_assert(e) {cout << #e << ((e) ? " passed": " failed") << endl;}
    
    my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);
    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);
    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);
    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);
    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);
}
                // If this is the end word, we're done
                if (word == target_word) {
                    return new_ladder;
                }
                
                // Otherwise, add this new ladder to the queue
                ladder_queue.push(new_ladder);
            }
        }
    }
    
    // If no ladder is found
    return vector<string>();
}

// Load words from a file into a set
void load_words(set<string>& word_list, const string& file_name) {
    ifstream in_file(file_name);
    if (!in_file) {
        cerr << "Error: Could not open file " << file_name << endl;
        return;
    }
    
    string word;
    while (in_file >> word) {
        // Convert to lowercase
        for (char& c : word) {
            c = tolower(c);
        }
        word_list.insert(word);
    }
    
    in_file.close();
}

// Print the word ladder
void print_word_ladder(const vector<string>& ladder) {
    if (ladder.empty()) {
        cout << "No word ladder found." << endl;
        return;
    }
    
    cout << "Word ladder found: ";
    for (size_t i = 0; i < ladder.size(); ++i) {
        cout << ladder[i];
        cout << " ";
    }
    cout << endl;
}

// Verify word ladder function for testing
void verify_word_ladder() {
    set<string> word_list;
    load_words(word_list, "words.txt");
    
    #define my_assert(e) {cout << #e << ((e) ? " passed": " failed") << endl;}
    
    my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);
    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);
    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);
    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);
    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);
}