#include <string>
#include <iostream>
#include <sstream>
#include <stdlib.h>
using namespace std;

 
class TestCase{
    private:
        int Count = 0;
        int Passed = 0;
        int Failed = 0;
        string TestName;
        ostream* Error; 
        
    public:
        TestCase(string TestName , ostream& error);
        void print();
    
   
    
template <typename T>
TestCase check_equal(const T& a,const T& b){
    this->Count++;
    if((T)a == (T)b){
        Passed++; 
    }
    else{
        *Error << this->TestName << ": Failure in test #" << Count << ": " << a << " should equal " << b << "!" << endl; 
        Failed++;
    }
    
       
    return *this;
}

template <typename T>
TestCase check_different(const T& a,const T& b){
    this->Count++;
    if((T)a == (T)b){
        *Error << this->TestName << ": Failure in test #" << Count << ": The numbers are equals!" <<endl;
        Failed++;
    }
    else
        Passed++;
    return *this;
}

template <typename T>
TestCase check_output(const T& a,const string& b){
    this->Count++;
    ostringstream keep;
    keep<<a;
    if(keep.str() != b){
        *Error << this->TestName << ": Failure in test #" << Count << ": string value should be " << b 
                  << " but is " << a << endl;
        Failed++;
        
    }
    else
        Passed++;
        
    return *this;
}

template < typename T ,typename G ,typename R >
TestCase check_function(G func,const T& Argument, const R& ExpectedResault ){
    this->Count++;
    R test = func(Argument);
    if(((R)test) != (R)ExpectedResault){
         *Error << this->TestName << ": Failure in test #" << Count << ": Function should return " << ExpectedResault 
               << " but returned " <<(R)test <<"!" <<endl;
        Failed++;
        
    }
    else
       Passed++;
        
    return *this;
}

};