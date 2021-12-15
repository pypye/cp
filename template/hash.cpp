typedef long long ll;

const int base = 31;
const ll MOD = 1000000003;
const ll maxn = 1000111;

using namespace std;

ll POW[maxn], hashT[maxn];


ll getHashT(int i,int j) {
    return (hashT[j] - hashT[i - 1] * POW[j - i + 1] + MOD * MOD) % MOD;
}


int main() {
    // Input
    string T, P;
    cin >> T >> P;

    // Initialize
    int lenT = T.size(), lenP = P.size();
    T = " " + T;
    P = " " + P;
    POW[0] = 1;

    // Precalculate base^i
    for (int i = 1; i <= lenT; i++)
    	POW[i] = (POW[i - 1] * base) % MOD;

    // Calculate hash value of T[1..i]
    for (int i = 1; i <= lenT; i++)
    	hashT[i] = (hashT[i - 1] * base + T[i] - 'a' + 1) % MOD;

    // Calculate hash value of P
    ll hashP=0;
    for (int i = 1; i <= lenP; i++)
    	hashP = (hashP * base + P[i] - 'a' + 1) % MOD;

    // Finding substrings of T equal to string P
    for (int i = 1; i <= lenT - lenP + 1; i++)
    	if (hashP == getHashT(i, i + lenP - 1))
    		printf("%d ", i);
}