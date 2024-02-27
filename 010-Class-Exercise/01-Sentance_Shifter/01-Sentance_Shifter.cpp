#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class sentanceShifter {
    private:
        vector<string> sentance;

    public:
        sentanceShifter(string& buff) {
            istringstream istr(buff);

            string aWord;
            while (istr >> aWord)
                sentance.push_back(aWord);
        };

        void shift() {
            auto itBegin = sentance.begin();
            sentance.insert(itBegin, sentance.back());

            auto itEnd = sentance.end();
            itEnd--;
            sentance.erase(itEnd);
        };

        string getShiftedSentence() {
            ostringstream ostr;

            for (auto word : sentance)
                ostr << word << endl;

            return ostr.str();
        }

};

int main()
{
    string line;
    getline(cin, line);

    sentanceShifter wordsToShift(line);

    int num;
    cin >> num;

    for (; num > 0; num--)
        wordsToShift.shift();
    
    cout << wordsToShift.getShiftedSentence();
}
