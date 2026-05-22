#include "Bureaucrat.hpp"

int main()
{
    std::cout << "=== Test 1: Perfect Creation & Ranks ===" << std::endl;
    try {
        Bureaucrat hermes("Hermes Conrad", 34);
        std::cout << hermes;
        
        std::cout << "\nPromoting Hermes by 10 grades..." << std::endl;
        hermes.promote(10);
        std::cout << hermes;
        
        std::cout << "\nDemoting Hermes by 5 grades..." << std::endl;
        hermes.demote(5);
        std::cout << hermes;
    }
    catch (const std::exception& e) {
        std::cerr << "Unexpected exception in Test 1: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 2: Grade Too High Construction ===" << std::endl;
    try {
        Bureaucrat boss("The Big Boss", 0);
        std::cout << boss << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Caught expected error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 3: Grade Too Low Construction ===" << std::endl;
    try {
        Bureaucrat intern("Sad Intern", 151);
        std::cout << intern << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Caught expected error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 4: Over-Promotion Out of Bounds ===" << std::endl;
    try {
        Bureaucrat highRank("High Ranker", 2);
        std::cout << highRank;
        std::cout << "Attempting to promote by 3 ranks..." << std::endl;
        highRank.promote(3);
        std::cout << "This line should never be reached." << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Caught expected error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 5: Over-Demotion Out of Bounds ===" << std::endl;
    try {
        Bureaucrat lowRank("Low Ranker", 145);
        std::cout << lowRank;
        std::cout << "Attempting to demote by 10 ranks..." << std::endl;
        lowRank.demote(10);
        std::cout << "This line should never be reached." << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Caught expected error: " << e.what() << std::endl;
    }

    std::cout << "\nProgram successfully completed without standard system crashing!" << std::endl;
    return 0;
}