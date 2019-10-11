# C++ Memo

## String

### Tokenize String

```c++
vector<string> toTokenVector(string str)
{
    vector<string> out;
    istringstream tokenStream(str);
    string token;
    char delim = ',';
    while (getline(tokenStream, token, delim)) {
        out.push_back(token);
    }
    return out;
}
```
