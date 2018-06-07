#include "TestCase.hpp"

    TestCase::TestCase(string TestName , ostream& error){
        this->TestName = TestName;
        this->Error = &error;
        this->Count = 0;
        this->Passed = 0;
        this->Failed = 0;
    }
    
    void TestCase::print(){
        *Error << this->TestName <<": " << Failed << " Failed  "<< Passed <<" Passed  "<< (Passed+Failed) << " total."<<endl;
        cout << "---" << endl;
    }