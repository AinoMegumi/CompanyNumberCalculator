#if !defined IUTEST_USE_MAIN
#define IUTEST_USE_MAIN
#endif
#include <iutest.hpp>
#include "Calculator.hpp"
#include <functional>
namespace TestCaseStrings {
    constexpr const char* CorrectCase1 = "700110005901";
    constexpr const char* CorrectCase2 = "７００１１０００５９０１";
    constexpr const char* CorrectCase3 = "70011０００5901";
    constexpr const char* InvalidCase1 = "70010005901";
    constexpr const char* InvalidCase2 = "HelloWorld11";
}

constexpr const char* GeneratedCompanyNumber = "8-7001-1000-5901";

inline void Test_CheckArg(const std::string& arg, const bool& CorrectVal) {
    IUTEST_ASSERT_EQ(CalculationImpl::CheckArg(arg), CorrectVal);
}

inline void Test_ConvertNumTextToHalfSizeString(std::string arg, const std::string& CorrectVal) {
    CalculationImpl::ConvertNumTextToHalfSizeString(arg);
    IUTEST_ASSERT_EQ(arg, CorrectVal);
}

inline void Test_CalcCheckDigit(const std::string& arg, const unsigned long& CorrectVal) {
    IUTEST_ASSERT_EQ(CalculationImpl::CalcCheckDigit(arg), CorrectVal);
}

inline void Test_GenerateCompanyNumber(const unsigned long& CheckDigit, const std::string& arg, const std::string& CorrectVal) {
    IUTEST_ASSERT_EQ(CalculationImpl::GenerateCompanyNumber(CheckDigit, arg), CorrectVal);
}

inline void Test_CalcCompanyNumber(const std::string& src, const std::string& CorrectVal) {
    IUTEST_ASSERT_EQ(CalcCompanyNumber(src), CorrectVal);
}

// 引数検査のテスト
IUTEST_PMZ(ImplMethodTest_CheckArg, Equal0, Test_CheckArg, TestCaseStrings::CorrectCase1, true);
IUTEST_PMZ(ImplMethodTest_CheckArg, Equal1, Test_CheckArg, TestCaseStrings::CorrectCase2, true);
IUTEST_PMZ(ImplMethodTest_CheckArg, Equal2, Test_CheckArg, TestCaseStrings::CorrectCase3, true);
IUTEST_PMZ(ImplMethodTest_CheckArg, Equal3, Test_CheckArg, TestCaseStrings::InvalidCase1, false);
IUTEST_PMZ(ImplMethodTest_CheckArg, Equal4, Test_CheckArg, TestCaseStrings::InvalidCase2, false);

// 半角変換のテスト
IUTEST_PMZ(ImplMethodTest_HalfSizeStr, Equal0, Test_ConvertNumTextToHalfSizeString, TestCaseStrings::CorrectCase1, TestCaseStrings::CorrectCase1);
IUTEST_PMZ(ImplMethodTest_HalfSizeStr, Equal1, Test_ConvertNumTextToHalfSizeString, TestCaseStrings::CorrectCase2, TestCaseStrings::CorrectCase1);
IUTEST_PMZ(ImplMethodTest_HalfSizeStr, Equal2, Test_ConvertNumTextToHalfSizeString, TestCaseStrings::CorrectCase3, TestCaseStrings::CorrectCase1);

// チェックディジットの計算のテスト
IUTEST_PMZ(ImplMethodTest_CheckArg, Equal0, Test_CalcCheckDigit, TestCaseStrings::CorrectCase1, 8);
IUTEST_PMZ(ImplMethodTest_CheckArg, Equal1, Test_CalcCheckDigit, TestCaseStrings::CorrectCase2, 0);
IUTEST_PMZ(ImplMethodTest_CheckArg, Equal2, Test_CalcCheckDigit, TestCaseStrings::CorrectCase3, 0);
IUTEST_PMZ(ImplMethodTest_CheckArg, Equal3, Test_CalcCheckDigit, TestCaseStrings::InvalidCase1, 0);
IUTEST_PMZ(ImplMethodTest_CheckArg, Equal4, Test_CalcCheckDigit, TestCaseStrings::InvalidCase2, 0);

// チェックディジットと会社法人等番号から法人番号の生成のテスト
IUTEST_PMZ(ImplMethodTest_GenerateCompanyNumber, Equal0, Test_GenerateCompanyNumber, 8, TestCaseStrings::CorrectCase1, GeneratedCompanyNumber);
IUTEST_PMZ(ImplMethodTest_GenerateCompanyNumber, Equal1, Test_GenerateCompanyNumber, 8, TestCaseStrings::CorrectCase2, "");
IUTEST_PMZ(ImplMethodTest_GenerateCompanyNumber, Equal2, Test_GenerateCompanyNumber, 8, TestCaseStrings::CorrectCase3, "");
IUTEST_PMZ(ImplMethodTest_GenerateCompanyNumber, Equal3, Test_GenerateCompanyNumber, 8, TestCaseStrings::InvalidCase1, "");
IUTEST_PMZ(ImplMethodTest_GenerateCompanyNumber, Equal4, Test_GenerateCompanyNumber, 8, TestCaseStrings::InvalidCase2, "");
IUTEST_PMZ(ImplMethodTest_GenerateCompanyNumber, Equal0, Test_GenerateCompanyNumber, 0, TestCaseStrings::CorrectCase1, "");
IUTEST_PMZ(ImplMethodTest_GenerateCompanyNumber, Equal0, Test_GenerateCompanyNumber, 10, TestCaseStrings::CorrectCase1, "");

// 総合テスト
IUTEST_PMZ(MainMethodTest, Equal0, Test_CalcCompanyNumber, TestCaseStrings::CorrectCase1, GeneratedCompanyNumber);
IUTEST_PMZ(MainMethodTest, Equal1, Test_CalcCompanyNumber, TestCaseStrings::CorrectCase2, GeneratedCompanyNumber);
IUTEST_PMZ(MainMethodTest, Equal2, Test_CalcCompanyNumber, TestCaseStrings::CorrectCase3, GeneratedCompanyNumber);
IUTEST_PMZ(MainMethodTest, Equal3, Test_CalcCompanyNumber, TestCaseStrings::InvalidCase1, "");
IUTEST_PMZ(MainMethodTest, Equal4, Test_CalcCompanyNumber, TestCaseStrings::InvalidCase2, "");
