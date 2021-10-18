//limyunkai19
#include <iostream>
using namespace std;

int main() {
    int t; cin >> t;
    
    while(t--) {
        int n, d, c, m;
        cin >> n >> d >> c >> m;
        
        string s;
        cin >> s;
        
        string ans = "YES";
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'D') {
                if(d == 0) {
                    ans = "NO";
                    break;
                }
                
                d--;
                c += m;
            }
            else {
                if(c == 0) d = 0;
                c--;
            }
        }
        
        cout << "Case #" << t+1 << ": " << ans << "\n";
    }
    
    return 0;
}
