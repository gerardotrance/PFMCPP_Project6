/*
 Project 6: Part 1 / 2
 Video: Chapter 3 Part 2

Create a branch named Part1

Purpose:  This project will show you the difference between member functions and static class functions, as well as the difference between pointers and references and the code semantics that accompany pointers and references.

 Pointers

 Please look at the screenshot in the files to see what happens if you paste this assignment into an existing cpp file in an xcode project
 
 Task: replace all of the <place holder> with proper names and types that will make this program compile and run.
 
 steps:
 
 0) press the Compile, link and run... button and work your way through all of the error messages.
         you can click on them to be taken to the appropriate line number.
 
 1) finish implementing the constructor for T. the constructor parameters need to initialize 2) and 3)
 
 2) provide a member variable in T of a type of your choosing that works with the compare function below T
         note the name of the variable used in the compare function
 
 3) provide a member variable of type std::string in T that works with the *first* cout statement in main().
         note the name of the variable used in the *first* cout statement in main()
 
 4) finish defining the struct with the compare function
 5) provide proper types for the arguments to compare, and a proper return value
         be sure to make it work with the pointer semantics being used in the if statements.
         see 8) for a hint about what type to use.
 
 6) finish instantiating the two T instances being declared in main(), based on the constructor you finished implementing in T
     Their names (line 105,106) are different than the member variables names (line 77), even tho the placeholders share the same name.
     Don't let this confuse you.
 
 7) Declare 'f' with the proper type so the call to f.compare works
 
 8) call f.compare() with the correct arguments, based on 2) and 5)
 
 9) correct the cout that uses bigger's member variable with some safe pointer usage.
         the possible return values of the compare() function should give you a hint.
 
 10) complete the implementation for the static function in <structName2>
 
 11) call the <structName2> static function correctly in main()
 
 12) replicate the functionality of <structName2>'s static function by implementing a member function in U that does the same thing.
 
 13) remember the rules for using pointers!  What is the one thing we always do before we use a pointer?
 
 After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 */

#include <iostream>
#include <string>
struct T
{
    float value;
    std::string name;
    
    T(float v, const char* nameptr) : value(v), name(nameptr){}   //1
    //2
    //3
};

struct MyStruct                                //4
{
    T* compare(T* a, T* b) //5
    {
        if(a != nullptr && b != nullptr)
        {
            if( a->value < b->value ) return a;
            if( a->value > b->value ) return b;
        }    
        return nullptr;
    }
};

struct U
{
    float value1 { 0.f }, value2 { 0.f };
    float multiply(float* updatedValue)      //12
    {
        if(updatedValue != nullptr)
        {
          std::cout << "U's value1 value is " << this->value1 << std::endl;
          value1 = *updatedValue;
          std::cout << "U's value1 new value is " << this->value1 << std::endl;
        }

        while(std::abs(value1 - value2) > 0.001f)
        {
            value2 += 0.1f;
        }

        std::cout << "U's value2 updated value: " << value2 << std::endl;

        return value2 * value1;      
    }

};

struct StaticStruct
{
    static float staticFunction(U* that, float* updatedValue){   
        if(that != nullptr && updatedValue != nullptr)
        {
            std::cout << "U's value1 value: " << that->value1 << std::endl;
            that->value1 = *updatedValue;
            std::cout << "U's value1 updated value: " << that->value1 << std::endl;
            while(std::abs(that->value2 - that->value1) > 0.001f)
            {
                that->value2 +=0.1f;
            }
        
        std::cout << "U's value2 updated value: " << that->value2 << std::endl;
        }
        
        return that->value2 * that->value1;
    }
};
        
int main()
{
    T t1(1.2f , "t1");                                             //6
    T t2(-0.2f , "t2");                                             //6
    
    MyStruct f;                                            //7
    auto* smaller = f.compare(&t1 ,&t2);                         
    if(smaller != nullptr)      //8
        std::cout << "the smaller one is << " << smaller->name << std::endl; //9
        
    else
        std::cout << t1.name << "and" << t2.name << " are equel." << std::endl;
    
    U u1;
    float updatedValue = 5.f;
    std::cout << "[static func] u1's multiplied values: " << StaticStruct::staticFunction(&u1, &updatedValue)<< std::endl;                  //11
    
    U u2;
    std::cout << "[member func] u2's multiplied values: " << u2.multiply( &updatedValue ) << std::endl;
}

        
        
        
        
        
        
        
