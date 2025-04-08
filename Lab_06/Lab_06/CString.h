#pragma once
class CString
{
private:
    char* str;

public:
    CString();
    CString(int size);
    CString(char*);
    CString(const CString&);

    ~CString();

    CString& operator=(const CString&);
    CString& operator+(const CString&);
    bool operator==(const CString&);

    int length();
    void print();
    void input();
};

