#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int errNumb = 0;
    int *const curErr = &errNumb;
    int errNumb2 = 1;
    *curErr = 1;
    const double pi = 3.14159;
    const double *const pip = &pi;
    int i = 0;
    int *const p1 = &i;
    const int ci = 42;
    const int *p2 = &ci;
    const int *const p3 = p2;

    string s1;
    string s2 = s1;
    string s3(s1);
    string s4 = "hello";
    string("hello");
    string(3,'c');
    string s7 = string(3,'c');
    string world;
    /*while(cin >> world)
        cout << world << endl;
    return 0;*/
    string line("line");
    auto len = line.size();
    string s("Hello World!!");
    for(auto &c: s){
        c = toupper(c);
    }
    /*for (decltype(s.size()) i =0; index != s.size() && !isspace(s[i]); ++i)
        s[i] = toupper(s[i]);*/
    cout << s << endl;
    vector<int> ivec;
    /*vector<string> svec3{'a', "an", "the"};*/
    vector<int> ivec4(10,-1);
    vector<string> svec4(10);
    vector<int> v;
    for(int i=0; i!=100; ++i)
        v.push_back(i);
    for(auto i : v)
        cout << i << " ";
    cout << endl;
    string t("some string");
    for (auto it = t.begin(); it != t.end() && isspace(*it); ++i)
        *it = toupper(*it);
    vector<int> suuji(2,0);
    vector<int>::iterator it = suuji.begin();
    *it = 3;
    string ww("This class is boring");
    string::iterator it2 = ww.begin();
    *it2 = 't';
    cout << ww << endl;
    string text("I am taiga");
    string sought;
    cin >> sought;
    auto beg = text.begin(), end = text.end();
    auto mid = text.begin() + (end-beg)/2;
    while(mid!=end && *mid != sought){
        if(sought < *mid)
            end = mid;
        else 
            beg = mid+1;
        mid = beg+(end-beg)/2;
    }
}