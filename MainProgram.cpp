// ============================================================
// Lab: Strings and String Operations with Function & Operator
// Overloading in C++
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
MyString operator+(const MyString& other) const; // Concatenation
bool operator==(const MyString& other) const; // Equality
bool operator!=(const MyString& other) const; // Inequality
bool operator<(const MyString& other) const; // Less than
bool operator>(const MyString& other) const; // Greater than
char operator[](int index) const; // Indexing
MyString operator*(int times) const; // Repeat
 
// ---- Stream Overloading ----
friend ostream& operator<<(ostream& os, const MyString& s);
friend istream& operator>>(istream& is, MyString& s);
};
 
// ================================
// FUNCTION IMPLEMENTATIONS
// ================================
 
// ---- Constructors ----
 
MyString::MyString() {
// TODO: Initialize with empty string
data="";
}
 
MyString::MyString(const string& str) {
// TODO: Initialize data with the given std::string
data=str;
}
 
MyString::MyString(const char* str) {
// TODO: Initialize data with the given C-string
data=str;
}
 
// ---- Getter ----
 
string MyString::getData() const {
// TODO: Return the internal string data
return data;
}
 
// ---- Basic String Operations ----
 
int MyString::length() const {
// TODO: Return the length of the string
return data.length();
}
 
char MyString::charAt(int index) const {
// TODO: Return character at given index
// Throw std::out_of_range if index is invalid (negative or >= length)
if ( index< 0 || index >= static_cast<int>(data.length())){
throw out_of_range("İndex out of range in charAt");
}
return data[index];
}
 
MyString MyString::substring(int start, int len) const {
// TODO: Return a substring starting at 'start' with length 'len'
// Throw std::out_of_range if start is invalid (negative or >= length)
// Hint: Use std::string::substr()
if ( start< 0 || start > static_cast<int>(data.length())){
throw out_of_range ("İndex out of range in substring");
}
return MyString(data.substr(start,len));
}
 
// ---- String Manipulation ----
 
MyString MyString::toUpperCase() const {
// TODO: Return a NEW MyString with all characters converted to upper case
// Hint: Use std::transform with ::toupper
// Do NOT modify the original object
string result = data;
transform(result.begin() , result.end() , result.begin(),
[](unsigned char c) {return toupper(c);});
return MyString(result);
}
 
MyString MyString::toLowerCase() const {
// TODO: Return a NEW MyString with all characters converted to lower case
// Hint: Use std::transform with ::tolower
// Do NOT modify the original object
string result = data;
transform(result.begin() , result.end() , result.begin(),
[](unsigned char c) {return tolower(c);});
return MyString(result);
}
 
MyString MyString::trim() const {
// TODO: Return a NEW MyString with leading and trailing whitespace removed
// Whitespace includes: space, tab (\t), newline (\n), carriage return (\r)
// Hint: Use find_first_not_of and find_last_not_of
size_t start = data.find_first_not_of(" \t\n\r");
if ( start == string::npos) return MyString("");
size_t end = data.find_last_not_of(" \t\n\r");
return MyString(data.substr(start, end - start + 1));
}
 
MyString MyString::reverse() const {
// TODO: Return a NEW MyString with characters in reverse order
// Hint: Use std::reverse on a copy
string result = data;
std::reverse(result.begin(), result.end());
return MyString(result);
}
 
// ---- Search Operations ----
 
int MyString::find(const MyString& target) const {
// TODO: Return index of first occurrence of target, or -1 if not found
// Hint: Use std::string::find, check against string::npos
size_t pos = data.find(target.data);
return (pos == string::npos)? -1 : pos;
}
 
int MyString::count(char ch) const {
// TODO: Return the number of occurrences of character ch in the string
int cnt = 0;
for(char c : data){
if(c == ch) cnt++;
}
return cnt;
}
 
// ---- Function Overloading: append ----
 
MyString MyString::append(const MyString& other) const {
return MyString(data + other.data);
}
 
MyString MyString::append(const char* cstr) const {
return MyString(data + string(cstr));
}
 
MyString MyString::append(char ch) const {
return MyString(data + ch);
}
 
MyString MyString::append(int number) const {
return MyString(data + to_string(number));
}
 
// ---- Function Overloading: replace ----
 
MyString MyString::replace(char oldCh, char newCh) const {
string result = data;
for (char& c : result) {
if (c == oldCh) c = newCh;
}
return MyString(result);
}
 
MyString MyString::replace(const string& oldStr, const string& newStr) const {
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
throw out_of_range("Index out of range in operator[]");
}
return data[index];
}
 
MyString MyString::operator*(int times) const {
if (times <= 0) return MyString("");
string result;
for (int i = 0; i < times; i++) {
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
 
MyString padded(" spaces around ");
cout << "Before trim: [" << padded << "]" << endl;
cout << "After trim: [" << padded.trim() << "]" << endl;
 
cout << "Reverse of s1: " << s1.reverse() << endl;
 
// --- 3. Search Operations ---
cout << "\n--- Search Operations ---" << endl;
cout << "find 'World' in s1: " << s1.find(MyString("World")) << endl;
cout << "find 'xyz' in s1: " << s1.find(MyString("xyz")) << endl;
cout << "count 'l' in s1: " << s1.count('l') << endl;
cout << "count 'z' in s1: " << s1.count('z') << endl;
 
// --- 4. Function Overloading: append ---
cout << "\n--- Function Overloading: append ---" << endl;
MyString base("Data");
cout << "append(MyString): " << base.append(MyString("Base")) << endl;
cout << "append(C-str): " << base.append("_v2") << endl;
cout << "append(char): " << base.append('!') << endl;
cout << "append(int): " << base.append(42) << endl;
 
// --- 5. Function Overloading: replace ---
cout << "\n--- Function Overloading: replace ---" << endl;
MyString rep("aabcaabc");
cout << "Original: " << rep << endl;
cout << "replace('a','x'): " << rep.replace('a', 'x') << endl;
cout << "replace(\"abc\",\"XYZ\"): " << rep.replace(string("abc"), string("XYZ")) << endl;
 
// --- 6. Operator Overloading ---
cout << "\n--- Operator Overloading ---" << endl;
MyString a("Hello");
MyString b(" World");
MyString c("Hello");
 
cout << "a + b: " << a + b << endl;
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
