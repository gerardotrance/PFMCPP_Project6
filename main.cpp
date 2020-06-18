/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert all of the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
struct T
{
    T(float v, const char* nameptr) : value(v), name(nameptr){}   //1
    float value;//2
    std::string name;//3
};

struct Struct1                                //4
{
    const T* compare(const T& a, const T& b) //5
    {
        if( a.value < b.value ) return &a;
        if( a.value > b.value ) return &b;
        return nullptr;
    }
};

struct U
{
    float value1 { 0 }, value2 { 0 };
    
    float memberFunction(const float& updatedValue)      //12
    {
        std::cout << "value1 value: " << this->value1 << std::endl;
        this->value1 = updatedValue;
        std::cout << "value1's updated value: " << this->value1 << std::endl;
				    
        while( std::abs(this->value2 - this->value1) > 0.001f)
        {
            this->value2 += 0.1f;
        }
				    
        std::cout << "value2 updated value: " << this->value2 << std::endl;
			
        return this->value2 * this->value1;
   
    }
};

struct StaticStruct
{
    static float staticFunction(U& that, const float& updatedValue )
    {
        std::cout << "U's value1 value: " << that.value1 << std::endl;
        that.value1 = updatedValue;
        std::cout << "U's value1 updated value: " << that.value1 << std::endl;
			      
        while( std::abs(that.value2 - that.value1) > 0.001f )
        {
            that.value2 += 0.1f ;
        }
			      
        std::cout << "U's value2 updated value: " << that.value2 << std::endl;
			
        return that.value2 * that.value1;

    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T t1(0.5f, "t1" );                                             //6
    T t2(0.2f, "t2" );                                             //6
    
    Struct1 f;                                            //7
    auto* smaller = f.compare( t1, t2 );
    if(smaller != nullptr)
    {     
        std::cout << "the smaller one is << " << smaller->name << std::endl;
    } //9

    
    U u1;
    float updatedValue = 5.f;
    std::cout << "[static func] u1's multiplied values: " << StaticStruct::staticFunction(u1 , updatedValue ) << std::endl;               //11
    
    U u2;
    std::cout << "[member func] u2's multiplied values: " << u2.memberFunction( updatedValue ) << std::endl;
}

        
        
        
        
        
        
        
