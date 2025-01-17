class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        // start with the first posistion 1
        // 1 1 0
        // 1 0 1
        // 0 1 0
        int start = 1, n = derived.size();
        vector<int> first(n), second(n);
        for(int i = 0; i < n; i++) {
            first[i] = start;
            if(derived[i] == 1) {
                start = !start;
            }
        }
        start = 0;
        for(int i = 0; i < n; i++) {
            second[i] = start;
            if(derived[i] == 1) {
                start = !start;
            } 
        }

        vector<int> ansfirst(n), anssecond(n);
        for(int i = 1; i < n; i++) {
            ansfirst[i - 1] = first[i - 1] ^ first[i];
            anssecond[i - 1] = second[i - 1] ^ second[i];
        }

        ansfirst[n - 1] = first[n - 1] ^ first[0];
        anssecond[n - 1] = second[n - 1] ^ second[0];
        bool of = true, os = true;
        for(int i = 0; i < n; i++) {
            if(ansfirst[i] != derived[i]) {
                of = false;
                break;
            }
        }
        for(int i = 0; i < n; i++) {
            if(anssecond[i] != derived[i]) {
                os = false;
                break;
            }
        }
        for(int i = 0; i < n; i++) {
            cout << first[i] << " ";
        }
        cout << endl;

        for(int i = 0; i < n; i++) {
            cout << second[i] << " ";
        }
        cout << endl;
        for(int i = 0; i < n; i++) {
            cout << ansfirst[i] << " ";
        }
        cout << endl;

        for(int i = 0; i < n; i++) {
            cout << anssecond[i] << " ";
        }
        cout << endl;
        if(of == false and os == false) {
            return false;
        }
        return true;
    }
};