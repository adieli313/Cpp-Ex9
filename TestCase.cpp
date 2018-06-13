#include "TestCase.hpp"

    TestCase::TestCase(string TestName , ostream& error){
        this->TestName = TestName;
        this->Error = &error;
        this->Count = 0;
        this->Passed = 0;
        this->Failed = 0;
    }
    
    void TestCase::print(){
        *Error << this->TestName <<": " << Failed << " failed, "<< Passed <<" passed, "<< Count << " total."<<endl;
        cout << "---" << endl;
    }