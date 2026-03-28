#include <iostream>
#include <map>
using namespace std;

class AuthenticationManager {
private:
    int timeToLive;
    map<string, int> tokens;

public:
    AuthenticationManager(int timeToLive) {
        this->timeToLive = timeToLive;
    }

    void generate(string tokenId, int currentTime) {
        tokens[tokenId] = currentTime + timeToLive;
    }

    void renew(string tokenId, int currentTime) {
        if (tokens.count(tokenId)) {
            if (tokens[tokenId] > currentTime) {
                tokens[tokenId] = currentTime + timeToLive;
            }
        }
    }

    int countUnexpiredTokens(int currentTime) {
        int count = 0;

        for (auto it = tokens.begin(); it != tokens.end(); it++) {
            if (it->second > currentTime) {
                count = count + 1;
            }
        }

        return count;
    }
};

int main() {
    AuthenticationManager auth(5);

    auth.renew("aaa", 1);
    auth.generate("aaa", 2);
    cout << auth.countUnexpiredTokens(6) << endl; // 1

    auth.generate("bbb", 7);
    auth.renew("aaa", 8);
    auth.renew("bbb", 10);
    cout << auth.countUnexpiredTokens(15) << endl; // 0

    return 0;
}