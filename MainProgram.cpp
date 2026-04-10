// ============================================================
// Lab: Strings and String Operations with Function & Operator
//       Overloading in C++
// Course: Object-Oriented Programming for Engineers
// Level: 2nd Year Engineering
// Duration: 70 minutes
// ============================================================
// SINGLE FILE IMPLEMENTATION - No header files allowed
// ============================================================
// STUDENT VERSION - Implement all TODO sections
// ============================================================

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <vector>
#include <stdexcept>

using namespace std;

// ================================
// CLASS DEFINITIONS
// ================================

class MyString {
private:
    string data;

public:
    // ---- Constructors ----
    MyString();
    MyString(const string& str);
    MyString(const char* str);

    // ---- Getter ----
    string getData() const;

    // ---- Basic String Operations ----
    int length() const;
    char charAt(int index) const;
    MyString substring(int start, int len) const;

    // ---- String Manipulation ----
    MyString toUpperCase() const;
    MyString toLowerCase() const;
    MyString trim() const;
    MyString reverse() const;

    // ---- Search Operations ----
    int find(const MyString& target) const;
    int count(char ch) const;

    // ---- Function Overloading: append ----
    MyString append(const MyString& other) const;
    MyString append(const char* cstr) const;
    MyString append(char ch) const;
    MyString append(int number) const;

    // ---- Function Overloading: replace ----
    MyString replace(char oldCh, char newCh) const;
    MyString replace(const string& oldStr, const string& newStr) const;

    // ---- Operator Overloading ----
    MyString operator+(const MyString& other) const;   // Concatenation
    bool operator==(const MyString& other) const;      // Equality
    bool operator!=(const MyString& other) const;      // Inequality
    bool operator<(const MyString& other) const;       // Less than
    bool operator>(const MyString& other) const;       // Greater than
    char operator[](int index) const;                  // Indexing
    MyString operator*(int times) const;               // Repeat

    // ---- Stream Overloading ----
    friend ostream& operator<<(ostream& os, const MyString& s);
    friend istream& operator>>(istream& is, MyString& s);
};

// ================================
// FUNCTION IMPLEMENTATIONS
// ================================

// ---- Constructors ----

MyString::MyString() : data("") {
    // Initialize with empty string
}

MyString::MyString(const string& str) : data(str) {
    // Initialize data with the given std::string
}

MyString::MyString(const char* str) : data(str ? str : "") {
    // Initialize data with the given C-string
}

// ---- Getter ----

string MyString::getData() const {
    return data;
}

// ---- Basic String Operations ----

int MyString::length() const {
    return static_cast<int>(data.length());
}

char MyString::charAt(int index) const {
    if (index < 0 || index >= static_cast<int>(data.length())) {
        throw out_of_range("Index out of range");
    }
    return data[index];
}

MyString MyString::substring(int start, int len) const {
    if (start < 0 || start >= static_cast<int>(data.length())) {
        throw out_of_range("Start index out of range");
    }
    return MyString(data.substr(static_cast<size_t>(start), static_cast<size_t>(len)));
}

// ---- String Manipulation ----

MyString MyString::toUpperCase() const {
    string result = data;
    transform(result.begin(), result.end(), result.begin(),
              [](unsigned char c) { return static_cast<char>(toupper(c)); });
    return MyString(result);
}

MyString MyString::toLowerCase() const {
    string result = data;
    transform(result.begin(), result.end(), result.begin(),
              [](unsigned char c) { return static_cast<char>(tolower(c)); });
    return MyString(result);
}

MyString MyString::trim() const {
    const string whitespace = " \t\n\r";
    size_t first = data.find_first_not_of(whitespace);

    if (first == string::npos) {
        return MyString("");
    }

    size_t last = data.find_last_not_of(whitespace);
    return MyString(data.substr(first, last - first + 1));
}

MyString MyString::reverse() const {
    string result = data;
    std::reverse(result.begin(), result.end());
    return MyString(result);
}

// ---- Search Operations ----

int MyString::find(const MyString& target) const {
    size_t pos = data.find(target.data);
    if (pos == string::npos) {
        return -1;
    }
    return static_cast<int>(pos);
}

int MyString::count(char ch) const {
    return static_cast<int>(std::count(data.begin(), data.end(), ch));
}

// ---- Function Overloading: append ----

MyString MyString::append(const MyString& other) const {
    return MyString(data + other.data);
}

MyString MyString::append(const char* cstr) const {
    return MyString(data + string(cstr ? cstr : ""));
}

MyString MyString::append(char ch) const {
    return MyString(data + string(1, ch));
}

MyString MyString::append(int number) const {
    return MyString(data + to_string(number));
}

// ---- Function Overloading: replace ----

MyString MyString::replace(char oldCh, char newCh) const {
    string result = data;
    std::replace(result.begin(), result.end(), oldCh, newCh);
    return MyString(result);
}

MyString MyString::replace(const string& oldStr, const string& newStr) const {
    if (oldStr.empty()) {
        return MyString(data);
    }

    string result = data;
    size_t pos = 0;

    while ((pos = result.find(oldStr, pos)) != string::npos) {
        result.replace(pos, oldStr.length(), newStr);
        pos += newStr.length();
    }

    return MyString(result);
}

// ---- Operator Overloading ----

MyString MyString::operator+(const MyString& other) const {
    return MyString(data + other.data);
}

bool MyString::operator==(const MyString& other) const {
    return data == other.data;
}

bool MyString::operator!=(const MyString& other) const {
    return data != other.data;
}

bool MyString::operator<(const MyString& other) const {
    return data < other.data;
}

bool MyString::operator>(const MyString& other) const {
    return data > other.data;
}

char MyString::operator[](int index) const {
    if (index < 0 || index >= static_cast<int>(data.length())) {
        throw out_of_range("Index out of range");
    }
    return data[index];
}

MyString MyString::operator*(int times) const {
    if (times <= 0) {
        return MyString("");
    }

    string result;
    for (int i = 0; i < times; ++i) {
        result += data;
    }
    return MyString(result);
}

// ---- Stream Overloading ----

ostream& operator<<(ostream& os, const MyString& s) {
    os << s.data;
    return os;
}

istream& operator>>(istream& is, MyString& s) {
    is >> s.data;
    return is;
}

// ================================
// MAIN FUNCTION
// ================================

int main() {
    cout << "=== MyString Lab Demo ===" << endl;

    // --- Constructors ---
    MyString s1("Hello World");
    MyString s2("hello world");
    MyString s3;
    MyString s4(string("C++ Programming"));

    // --- 1. Basic Operations ---
    cout << "\n--- Basic Operations ---" << endl;
    cout << "s1: " << s1 << endl;
    cout << "s4: " << s4 << endl;
    cout << "Length of s1: " << s1.length() << endl;
    cout << "charAt(0) of s1: " << s1.charAt(0) << endl;
    cout << "charAt(6) of s1: " << s1.charAt(6) << endl;
    cout << "substring(0,5) of s1: " << s1.substring(0, 5) << endl;
    cout << "substring(6,5) of s1: " << s1.substring(6, 5) << endl;

    // --- 2. String Manipulation ---
    cout << "\n--- String Manipulation ---" << endl;
    cout << "toUpperCase of s1: " << s1.toUpperCase() << endl;
    cout << "toLowerCase of s1: " << s1.toLowerCase() << endl;

    MyString padded("   spaces around   ");
    cout << "Before trim: [" << padded << "]" << endl;
    cout << "After  trim: [" << padded.trim() << "]" << endl;

    cout << "Reverse of s1: " << s1.reverse() << endl;

    // --- 3. Search Operations ---
    cout << "\n--- Search Operations ---" << endl;
    cout << "find 'World' in s1: " << s1.find(MyString("World")) << endl;
    cout << "find 'xyz' in s1:   " << s1.find(MyString("xyz")) << endl;
    cout << "count 'l' in s1:    " << s1.count('l') << endl;
    cout << "count 'z' in s1:    " << s1.count('z') << endl;

    // --- 4. Function Overloading: append ---
    cout << "\n--- Function Overloading: append ---" << endl;
    MyString base("Data");
    cout << "append(MyString): " << base.append(MyString("Base")) << endl;
    cout << "append(C-str):    " << base.append("_v2") << endl;
    cout << "append(char):     " << base.append('!') << endl;
    cout << "append(int):      " << base.append(42) << endl;

    // --- 5. Function Overloading: replace ---
    cout << "\n--- Function Overloading: replace ---" << endl;
    MyString rep("aabcaabc");
    cout << "Original:                " << rep << endl;
    cout << "replace('a','x'):        " << rep.replace('a', 'x') << endl;
    cout << "replace(\"abc\",\"XYZ\"): " << rep.replace(string("abc"), string("XYZ")) << endl;

    // --- 6. Operator Overloading ---
    cout << "\n--- Operator Overloading ---" << endl;
    MyString a("Hello");
    MyString b(" World");
    MyString c("Hello");

    cout << "a + b:  " << a + b << endl;
    cout << "a == c: " << (a == c) << endl;
    cout << "a == b: " << (a == b) << endl;
    cout << "a != b: " << (a != b) << endl;

    MyString apple("Apple");
    MyString banana("Banana");
    cout << "Apple < Banana: " << (apple < banana) << endl;
    cout << "Banana > Apple: " << (banana > apple) << endl;

    cout << "a[0]: " << a[0] << endl;
    cout << "a[4]: " << a[4] << endl;

    cout << "a * 3: " << a * 3 << endl;
    cout << "a * 0: [" << a * 0 << "]" << endl;

    // --- 7. Stream Operators ---
    cout << "\n--- Stream Operators ---" << endl;
    MyString x("Stream");
    MyString y("Test");
    cout << "Chained output: " << x << " " << y << endl;

    cout << "\nAll demos complete!" << endl;
    return 0;
}
