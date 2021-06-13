## How to split a string in C++?

### Method 1 `stringstream`
- clear() — flushes the stream 
- str() —  converts a stream of words into a C++ string object.
- operator << — pushes a string object into the stream.
- operator >> — extracts a word from the stream.

```c++
void simple_tokenizer(string s)
{
    stringstream ss(s);
    string word;
    while (ss >> word) {
        cout << word << endl;
    }
}



std::string input = "abc,def,ghi";
std::istringstream ss(input);
std::string token;

while(std::getline(ss, token, ',')) {
    std::cout << token << '\n';
}
```

### Method 2 find and substr
```c++
void tokenize(string s, string del = " ")
{
    int start = 0;
    int end = s.find(del);
    while (end != -1) {
        cout << s.substr(start, end - start) << endl;
        start = end + del.size();
        end = s.find(del, start);
    }
    cout << s.substr(start, end - start);
}
```
