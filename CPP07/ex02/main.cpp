#include <iostream>
#include <Array.hpp>

#define MAX_VAL 750
int main(int, char**)
{
    std::cout << "--- Construction of two array, one being the one fom template class : Array. The other one is a checker --- " << std::endl; 
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    
    srand(time(NULL)); //setting for the randomizer

    std::cout << "\n --- Filling both Arrays with the same random int values ---" << std::endl; 
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    //SCOPE
    std::cout << "\n --- Testing the Copy Constructor ---" << std::endl;
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);

        //My added test
        std::cout << "\n        --- Verify if the Copy has the same values as the checker ---" << std::endl; 
            for (int i = 0; i < MAX_VAL; i++)
            {
                if (mirror[i] != test[i])
                {
                    std::cerr << "didn't save the same value!!" << std::endl;
                    return 1;
                }
            }
            std::cerr << "       All good !!\n" << std::endl;
    }
    
    std::cout << "\n --- Verify if the Array version has the same values as the checker : it has not lost informations with the copy ---" << std::endl; 
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    std::cerr << "All good !!" << std::endl;

    std::cout << "\n --- Checks negative or too big indexes ---" << std::endl; 
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\n --- Checks to fill the first array : if the deep copy isnt good -> segfault ---\n" << std::endl; 

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}



// OFFICIAL MAIN WITHOUT COMMENTS:

// #include <iostream>
// #include <Array.hpp>

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }
