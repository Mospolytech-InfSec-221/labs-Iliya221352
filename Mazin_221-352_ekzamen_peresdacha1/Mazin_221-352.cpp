
#include "iostream"
#include "vector"

using std::cout;
using std::cin;
using std::string;
using std::vector;

class WordGame {
private:
    // свойства класса
    string default_word;
    int players_number;
    int order = 1;
    vector<int> points;
    vector<string> named_words;
    string word;

public:
    WordGame() {

    }
    ~WordGame() {

    }

    void start_game(string word, int number) {
        default_word = word;
        players_number = number;
        cout << players_number;
    }

    bool move(string word) {

        for (int i = 0; i < named_words.size(); ++i) {
            if (named_words[i] == word) {
                cout << "Wrong word!" << std::endl;
                return 0;
            }
        }
        string src_word = default_word;
        string temp_word = word;
        bool flag = true;


        for (int i = 0; i < temp_word.length(); i++) {
            bool flag = true;
            for (int j = 0; j < default_word.length(); j++) {
                if (temp_word[i] == default_word[j]) {
                    flag = false;
                }


            if (flag == true) {
                cout << "Wrong word!";
                break;
                }


            }
            if (i == temp_word.length()) cout << "Right word!";
        }

    }
      
        
    

    void play(int number) {
        players_number = number;
        while (true)
        {
            string word;
            cout << players_number;
            
            cout << "Player " << order << " write your word: ";
            cin >> word;
            if (order < players_number) {
                order++;
               
            }
            else {
                order = 1;
            }
            move(word);
        }

    }
};


int main() {
    WordGame().start_game("cosablenki", 4);
    WordGame().play(4);

}