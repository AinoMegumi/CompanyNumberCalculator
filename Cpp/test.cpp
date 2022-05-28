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

namespace TestCaseArray {
    static const std::vector<unsigned long> CorrectCaseArr = { 7, 0, 0, 1, 1, 0, 0, 0, 5, 9, 0, 1 };
    static const std::vector<unsigned long> DataCountLowCase = { 7, 0, 0, 1, 1, 0, 0, 0, 5, 9, 0 };
    static const std::vector<unsigned long> InvalidValueIncludeCase = { 7, 0, 0, 1, 1, 0, 0, 0, 5, 9, 0, 10 };
}

constexpr const char* GeneratedCompanyNumber = "8-7001-1000-5901";

inline void Test_CheckArg(const std::string& arg, const bool& CorrectVal) {
    IUTEST_ASSERT_EQ(CalculationImpl::CheckArg(arg), CorrectVal);
}

inline void Test_ConvertNumTextToHalfSizeString(const std::string& arg, const std::string& CorrectVal) {
    std::string s = arg;
    CalculationImpl::ConvertNumTextToHalfSizeString(s);
    IUTEST_ASSERT_EQ(s, CorrectVal);
}

inline bool ArrEqual(const std::vector<unsigned long>& a, const std::vector<unsigned long>& b) {
    if (a.size() != b.size()) return false;
    for (size_t i = 0; i < a.size(); i++) {
        if (a.at(i) != b.at(i)) return false;
    }
    return true;
}

void Test_ArrEqual(const std::vector<unsigned long>& a, const std::vector<unsigned long>& b, const bool CorrectVal) {
    IUTEST_ASSERT_EQ(ArrEqual(a, b), CorrectVal);
}

inline void Test_SplitAll(const std::string& arg, const std::vector<unsigned long>& CorrectVal) {
    IUTEST_ASSERT_EQ(ArrEqual(CalculationImpl::SplitAll(arg), CorrectVal), true);
}

inline void Test_SplitAll_Empty(const std::string& arg) {
    IUTEST_ASSERT_EQ(CalculationImpl::SplitAll(arg).size(), 0);
}

inline void Test_CalcCheckDigit(const std::vector<unsigned long>& arg, const unsigned long& CorrectVal) {
    IUTEST_ASSERT_EQ(CalculationImpl::CalcCheckDigit(arg), CorrectVal);
}

inline void Test_GenerateCompanyNumber(const unsigned long& CheckDigit, const std::vector<unsigned long>& arr, const std::string& CorrectVal) {
    IUTEST_ASSERT_EQ(CalculationImpl::GenerateCompanyNumber(CheckDigit, arr), CorrectVal);
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

// 【テスト用関数のテスト】配列内容が一致しているかの確認関数のテスト
IUTEST_PMZ(ImplMethodTest_TestFunc_ArrEqual, Equal0, Test_ArrEqual, TestCaseArray::CorrectCaseArr, TestCaseArray::CorrectCaseArr, true);
IUTEST_PMZ(ImplMethodTest_TestFunc_ArrEqual, Equal0, Test_ArrEqual, TestCaseArray::CorrectCaseArr, TestCaseArray::DataCountLowCase, false);
IUTEST_PMZ(ImplMethodTest_TestFunc_ArrEqual, Equal0, Test_ArrEqual, TestCaseArray::CorrectCaseArr, TestCaseArray::InvalidValueIncludeCase, false);

// 数値の配列への分割のテスト
IUTEST_PMZ(ImplMethodTest_SplitAll, Equal0, Test_SplitAll, TestCaseStrings::CorrectCase1, TestCaseArray::CorrectCaseArr);
IUTEST_PMZ(ImplMethodTest_SplitAll, Equal1, Test_SplitAll_Empty, TestCaseStrings::CorrectCase2);
IUTEST_PMZ(ImplMethodTest_SplitAll, Equal2, Test_SplitAll_Empty, TestCaseStrings::CorrectCase3);
IUTEST_PMZ(ImplMethodTest_SplitAll, Equal3, Test_SplitAll_Empty, TestCaseStrings::InvalidCase1);
IUTEST_PMZ(ImplMethodTest_SplitAll, Equal4, Test_SplitAll_Empty, TestCaseStrings::InvalidCase2);

// チェックディジットの計算のテスト
IUTEST_PMZ(ImplMethodTest_CalcCheckDigit, Equal0, Test_CalcCheckDigit, TestCaseArray::CorrectCaseArr, 8);
IUTEST_PMZ(ImplMethodTest_CalcCheckDigit, Equal1, Test_CalcCheckDigit, TestCaseArray::DataCountLowCase, 0);
IUTEST_PMZ(ImplMethodTest_CalcCheckDigit, Equal2, Test_CalcCheckDigit, TestCaseArray::InvalidValueIncludeCase, 0);

// チェックディジットと会社法人等番号から法人番号の生成のテスト
IUTEST_PMZ(ImplMethodTest_GenNumber, Equal0, Test_GenerateCompanyNumber, 8, TestCaseArray::CorrectCaseArr, GeneratedCompanyNumber);
IUTEST_PMZ(ImplMethodTest_GenNumber, Equal1, Test_GenerateCompanyNumber, 8, TestCaseArray::DataCountLowCase, "");
IUTEST_PMZ(ImplMethodTest_GenNumber, Equal2, Test_GenerateCompanyNumber, 8, TestCaseArray::InvalidValueIncludeCase, "");
IUTEST_PMZ(ImplMethodTest_GenNumber, Equal3, Test_GenerateCompanyNumber, 0, TestCaseArray::CorrectCaseArr, "");
IUTEST_PMZ(ImplMethodTest_GenNumber, Equal4, Test_GenerateCompanyNumber, 10, TestCaseArray::CorrectCaseArr, "");

// 総合テスト
IUTEST_PMZ(MainMethodTest, Equal0, Test_CalcCompanyNumber, TestCaseStrings::CorrectCase1, GeneratedCompanyNumber);
IUTEST_PMZ(MainMethodTest, Equal1, Test_CalcCompanyNumber, TestCaseStrings::CorrectCase2, GeneratedCompanyNumber);
IUTEST_PMZ(MainMethodTest, Equal2, Test_CalcCompanyNumber, TestCaseStrings::CorrectCase3, GeneratedCompanyNumber);
IUTEST_PMZ(MainMethodTest, Equal3, Test_CalcCompanyNumber, TestCaseStrings::InvalidCase1, "");
IUTEST_PMZ(MainMethodTest, Equal4, Test_CalcCompanyNumber, TestCaseStrings::InvalidCase2, "");
