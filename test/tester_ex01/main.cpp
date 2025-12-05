#include "tester.hpp"



#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"


TEST(PhonebookInterfaceTests, InvalidCommand_ShowsError)
{
    std::string input = "sjiid";
    std::string output = RUN_AND_CLEAN("../../cpp00/ex01/iphonix", input);

    EXPECT_TRUE(check_error_message(output))
        << "\033[31mExpected an error message for invalid command.\033[0m";
}

TEST(PhonebookInterfaceTests, RejectPhoneNumberWithLetters)
{
    std::string input =
        "ADD\n"
        "John\n"
        "Doe\n"
        "0a\n"                
        "johnny\n"
        "secret\n"
        "SEARCH\n"
        "EXIT\n";

    std::string output = RUN_AND_CLEAN("../../cpp00/ex01/iphonix", input);

    size_t searchPos = output.find("Index");
    std::string searchOutput;
    if (searchPos != std::string::npos) {
        searchOutput = output.substr(searchPos);
    }

    EXPECT_EQ(searchOutput.find("John"), std::string::npos)
        << "\033[31mProgram accepted invalid phone number '0a'. "
        << "Phone numbers must be digits only.\nSearch output:\n"
        << searchOutput << "\033[0m";
}

TEST(PhonebookInterfaceTests, RejectNonPrintable_LastName)
{
    std::string input =
        "ADD\n"
        "yassine\n"
        "bobalgha\x01\n"
        "1234\n"
        "ally\n"
        "secret\n"
        "SEARCH\n"
        "EXIT\n";

    std::string output = RUN_AND_CLEAN("../../cpp00/ex01/iphonix", input);

    size_t find_search = output.find("Index");
    std::string output_search;
    if (find_search != std::string::npos)
        output_search = output.substr(find_search);

    EXPECT_EQ(output_search.find("yassine"), std::string::npos)
        << "\033[31mProgram accepted non-printable characters in last name. "
        << "This is WRONG — all fields must contain only printable characters.\nSearch output:\n"
        << output_search << "\033[0m";
}

TEST(PhonebookInterfaceTests, RejectNonPrintable_FirstName)
{
    std::string input =
        "ADD\n"
        "yassine\x01\n"
        "bobalgha\n"
        "1234\n"
        "ally\n"
        "secret\n"
        "SEARCH\n"
        "EXIT\n";

    std::string output = RUN_AND_CLEAN("../../cpp00/ex01/iphonix", input);

    size_t find_search = output.find("Index");
    std::string output_search;
    if (find_search != std::string::npos)
        output_search = output.substr(find_search);

    EXPECT_EQ(output_search.find("yassine"), std::string::npos)
        << "\033[31mProgram accepted non-printable characters in first name. "
        << "This is WRONG — all fields must contain only printable characters.\nSearch output:\n"
        << output_search << "\033[0m";
}

TEST(PhonebookInterfaceTests, RejectNonPrintable_PhoneNumber)
{
    std::string input =
        "ADD\n"
        "yassine\n"
        "bobalgha\n"
        "1234\x01\n"
        "ally\n"
        "secret\n"
        "SEARCH\n"
        "EXIT\n";

    std::string output = RUN_AND_CLEAN("../../cpp00/ex01/iphonix", input);

    size_t find_search = output.find("Index");
    std::string output_search;
    if (find_search != std::string::npos)
        output_search = output.substr(find_search);

    EXPECT_EQ(output_search.find("yassine"), std::string::npos)
        << "\033[31mProgram accepted non-printable characters in phone number. "
        << "This is WRONG — all fields must contain only printable characters.\nSearch output:\n"
        << output_search << "\033[0m";
}

TEST(PhonebookInterfaceTests, RejectNonPrintable_Nickname)
{
    std::string input =
        "ADD\n"
        "yassine\n"
        "bobalgha\n"
        "1234\n"
        "ally\x01\n"
        "secret\n"
        "SEARCH\n"
        "EXIT\n";

    std::string output = RUN_AND_CLEAN("../../cpp00/ex01/iphonix", input);

    size_t find_search = output.find("Index");
    std::string output_search;
    if (find_search != std::string::npos)
        output_search = output.substr(find_search);

    EXPECT_EQ(output_search.find("yassine"), std::string::npos)
        << "\033[31mProgram accepted non-printable characters in nickname. "
        << "This is WRONG — all fields must contain only printable characters.\nSearch output:\n"
        << output_search << "\033[0m";
}

TEST(PhonebookInterfaceTests, RejectNonPrintable_Secret)
{
    std::string input =
        "ADD\n"
        "yassine\n"
        "bobalgha\n"
        "1234\n"
        "ally\n"
        "secret\x01\n"
        "SEARCH\n"
        "EXIT\n";

    std::string output = RUN_AND_CLEAN("../../cpp00/ex01/iphonix", input);

    size_t find_search = output.find("Index");
    std::string output_search;
    if (find_search != std::string::npos)
        output_search = output.substr(find_search);

    EXPECT_EQ(output_search.find("yassine"), std::string::npos)
        << "\033[31mProgram accepted non-printable characters in darkest secret. "
        << "This is WRONG — all fields must contain only printable characters.\nSearch output:\n"
        << output_search << "\033[0m";
}

TEST(PhonebookInterfaceTests, OverflowContacts_ReplacesOldest) 
{
    std::ostringstream input;
   for (int i = 0; i < 10; ++i) 
   {
    input << "ADD\n"
          << "First" << i << "\n"
          << "Last" << i << "\n"
          << "123456" << i << "\n"
          << "Nick" << i << "\n"
          << "Secret" << i << "\n";
    }
    input << "SEARCH\n";
    std::string output = RUN_AND_CLEAN("../../cpp00/ex01/iphonix", input.str());
    size_t find_search = output.find("Index");
    std::string output_search;
    if (find_search != std::string::npos) {
        output_search = output.substr(find_search);
    }
    EXPECT_EQ(output_search.find("First0"), std::string::npos)
        << "\033[31mOverflow handling failed: 'First0' still present.\033[0m";
    EXPECT_EQ(output_search.find("First1"), std::string::npos)
        << "\033[31mOverflow handling failed: 'First1' still present.\033[0m";

    for (int i = 2; i < 10; ++i) {
        std::string name = "First" + std::to_string(i);
        EXPECT_NE(output_search.find(name), std::string::npos)
            << "\033[31mOverflow handling failed: '" << name << "' missing.\033[0m";
    }
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    auto& listeners = ::testing::UnitTest::GetInstance()->listeners();
    delete listeners.Release(listeners.default_result_printer());
    listeners.Append(new UIXPrinter); 

    return RUN_ALL_TESTS();
}