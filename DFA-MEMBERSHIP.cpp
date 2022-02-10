/*
 * author: pratyush
 * created: 10 Feb 2022 05:23PM
*/
#include <bits/stdc++.h>
using namespace std;

// pair input output 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename A, typename B> istream& operator>>(istream &is, pair<A, B> &p) {A x; B y; cin >> x >> y; p.first = x; p.second = y; return is;} 

// pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds; 
template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// general datatype macros
#define int long long 
#define ld long double
#define ar array

// MISRA_DEBUGGER
#ifdef MISRA_DEBUG
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "("; _print(p.first); cerr << ","; _print(p.second); cerr << ")";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

// MISRA_DEBUGGER ends

// imp shortcut / speed-up macros
#define vt                     vector
#define pb                     push_back
#define all(c)                 (c).begin(), (c).end()
#define sz(x)                  (int)(x).size()
#define fi                     first
#define se                     second
#define mp                     make_pair
#define pii                    pair<int,int>
#define pdd                       pair<double,double>
#define ppc                    __builtin_popcount
#define ppcll                  __builtin_popcountll
#define uniq(v)                {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
#define mem1(a)                memset(a,-1,sizeof(a))
#define mem0(a)                memset(a,0,sizeof(a))
#define endl                    "\n"            // remove line in case of EOF queries and use endl directly and not "\n"
#define setp(x,a)               fixed << setprecision(x) << double(a)        // sets precision of 'x' units on value 'a'    

// priority_queue typedef
#define npq priority_queue<int>                                 // normal heap of ints
#define spq priority_queue<int, vector<int>, greater<int>>         // sorted heap of ints
#define nppq priority_queue<pii>                                // normal heap of pii
#define sppq priority_queue<pii, vector<pii>, greater<pii>>        // sorted heap of pii

// defining Universal double constants
#define PI 3.1415926535
#define NE 2.7182818284

// for loop macros
#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define FORR(i, a, b) F_OR(i,a,b-1,-1)                 // FORR(i,5,1)    cout << i => 5 4 3 2 1 
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define go(x, a) for (auto& x: a)
 
template<typename T>
void output_vector(const vector<T> &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = (int)(v.size());
 
    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}

// general usefull function
template<class T> bool bet(const T& x, const T& my_val, const T& y) {return (x <= my_val && my_val <= y);}
template<class P,class Q> int ceil_div(const P& a,const Q& b){return (int)((a + b - 1) / b);}
template<class T> bool umin(T& a, const T& b) {    return b<a?a=b, 1:0;}
template<class T> bool umax(T& a, const T& b) { return a<b?a=b, 1:0;} 
int highestPow(int N){int res = 1; while(res < N) res = res << 1; if(res > N) res = res >> 1; return res;} // handle N=0 explicitly
int toint(const string &s) {stringstream ss; ss << s; int x; ss >> x; return x;}
string tostring ( int number ){stringstream ss; ss<< number; return ss.str();}
int gcd(int x, int y){return y == 0 ? x : gcd(y, x % y);}

// mercenne twister randomizer      
mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());

// ALL CONSTANT VALS
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};        // EDGES CONFIG. IN SQUARE
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};        // VERTICES + EDGES CONFIG. 
const long long INF = 1e18;
const int MOD1 = 1e9+7;
const int MOD2 = 998244353;


// ====================== MAIN CODE STARTS =======================

int SYMBOLS, STATES;        // number of symbols and states in the language
string INITIAL_STATE;
set<string> FINAL_STATES;

string INPUT;       // string whose membership needs to be checked in DFA
int INPUT_STRING_LEN;

struct state {
    string LABEL;       // label of the state
    int TYPE;           // type = initial(0), final(2) else 1
};

map<string, map<char, string>> DFA;  // storing the graph

void initialisation() {
    cin >> SYMBOLS >> STATES;

    // take all states as input as well as its directed edges
    FOR(STATES) {
        string newState;
        int type;
        cin >> newState >> type;

        if(type == 0)   INITIAL_STATE = newState;
        else if(type == 2) FINAL_STATES.insert(newState);        // !f will act as stamp for final states

        FOR(SYMBOLS) {
            char INPUT_SYMBOL;
            string nbrState;
            cin >> INPUT_SYMBOL >> nbrState;
            DFA[newState][INPUT_SYMBOL] = nbrState;
        }
    }

    /*
        Sample input for DFA ending in "aab"
        2 4
        q0 0
        a q1
        b q0
        q1 1
        a q2
        b q0
        q2 1
        a q2
        b q3
        q3 2
        a q1    
*/
}


// function to display the DFA
void display() {
    cout << "INITIAL STATE: " << INITIAL_STATE << endl;
    cout << "FINAL STATES: ";
    go(fs, FINAL_STATES)    cout << fs << " ";
    cout << endl;
    for(auto& [curr, nbrs] : DFA) {
        cout << curr << "-> ";
        for(auto& [ipt, nbr] : nbrs)
            cout << '(' << ipt << ',' << nbr << ") ";
        cout << endl; 
    }
}

bool dfs(string CURR_DFS_STATE, int pos) {
    // cout << CURR_DFS_STATE << ' ' << pos << endl;
    // check current node if at end of string
    if(pos == INPUT_STRING_LEN) 
        return (FINAL_STATES.find(CURR_DFS_STATE) != FINAL_STATES.end());

    // else curr_dfs_state ON CURRENT INPUT SYMBOL at INPUT[pos] will go to 
    char curr_char = INPUT[pos];
    return dfs(DFA[CURR_DFS_STATE][curr_char], pos + 1); 
}

// function to check membership or acceptance by DFA
bool isMember() {
    return dfs(INITIAL_STATE, 0);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);        cout.tie(0);    // remove this line for online queries
 
    //freopen("input.txt","r",stdin);            // input from text file
    //freopen("output.txt","w",stdout);          // output to text file

    // inputs
    initialisation();

    // display the graph
    display();

    // check membership
    cin >> INPUT;
    INPUT_STRING_LEN = sz(INPUT);
    cout << endl;

    bool isMem = isMember();
    cout << "\"" << INPUT << "\""<< (isMem ? " is a member of DFA" : " is not a member of DFA") << endl;

    return 0;
}