#include <iostream>
using namespace std;

class GameEntry {
    private:
        string name;
        int score;
    public:
        GameEntry(const string& n = "", int s = 0) {
            name = n;
            score = s;
        }; //constructor
        ~GameEntry() {};
        string getName() const {
            return name;
        };     // get player name
        int getScore() const {
            return score;
        };       // get score
};

class Scores {  // stores game high scores
    private:
        int maxEntries;     // maximum number of entries
        int numEntries;     // actual number of entries
        GameEntry* entries; // array of game entries
    public:
        Scores(int maxEnt = 10) {           // constructor
            maxEntries = maxEnt;
            entries = new GameEntry[maxEntries];
            numEntries = 0;
        };        
        ~Scores() {
            delete[] entries;
        };                                  // destructor
        void add(const GameEntry& e) {      // add a game entry
            int newScore = e.getScore();
            if (numEntries >= maxEntries && newScore <= entries[numEntries - 1].getScore()) {
                return;
            }
            if (numEntries < maxEntries) {
                numEntries++;
            }
            int i = numEntries - 2;
            while (i >= 0 && entries[i].getScore() < newScore) {
                entries[i + 1] = entries[i];
                i--;
            }
            entries[i + 1] = e;
            return;
        };   
        //GameEntry remove(int i)         // remove the ith entry
            //throw(IndexOutOfBounds);
};

/*
배열의 문제점
삽입: 배열에 공간을 만들기 위해 먼저 값을 옆 인덱스로 shift해야함
삭제: 삭제 한 후 뒤의 값을 옆으로 공간을 채워야 한다.
-> 고정된 사이즈 때문에 resizing 하기 어렵다
이 문제점을 해결하려면 물리적보다는 논리적으로 요소들을 연결하는 linked list를 사용하자. 
*/

int main(void) {
    string name;
    int score;
    Scores rankList(10);

    for(int i = 0; i < 10; i++) {
        cin >> name >> score;
        GameEntry player(name, score);
        rankList.add(player);
    }

    return 0;
}