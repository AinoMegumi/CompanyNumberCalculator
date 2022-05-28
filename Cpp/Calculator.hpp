#include <string>
#include <vector>
#include <unordered_map>
#include <regex>
#include <utility>
#include <algorithm>

namespace CalculationImpl {
    namespace {
        void ReplaceString(std::string& src, const std::string& oldStr, const std::string& newStr) noexcept {
            std::string::size_type Pos(src.find(oldStr));
            while( Pos != std::string::npos ) {
                src.replace(Pos, oldStr.length(), newStr);
                Pos = src.find(oldStr, Pos + newStr.length());
            }
        }
    }

    inline bool AllValueIsHalfNumberText(const std::string& val) {
        static const std::regex r(R"([0-9]{12})");
        return std::regex_match(val, r);
    }

    inline bool CheckArg(const std::string& val) {
        static const std::regex r(R"([0-9０-９]{12,36})");
        return std::regex_match(val, r);
    }

    inline void ConvertNumTextToHalfSizeString(std::string& str) {

        ReplaceString(str, "０", "0");
        ReplaceString(str, "１", "1");
        ReplaceString(str, "２", "2");
        ReplaceString(str, "３", "3");
        ReplaceString(str, "４", "4");
        ReplaceString(str, "５", "5");
        ReplaceString(str, "６", "6");
        ReplaceString(str, "７", "7");
        ReplaceString(str, "８", "8");
        ReplaceString(str, "９", "9");
    }

    inline unsigned long CalcCheckDigit(const std::string& val) {
        if (!AllValueIsHalfNumberText(val)) return {};

        unsigned long TotalBuf[2] = { 0, 0 };
        for (int i = 0; i < 6; i++) {
            TotalBuf[0] += static_cast<unsigned long>(val[i * 2] - '0');
            TotalBuf[1] += static_cast<unsigned long>(val[i * 2 + 1] - '0');
        }
        return 9 - ((TotalBuf[0] * 2 + TotalBuf[1]) % 9);
    }

    inline std::string GenerateCompanyNumber(const unsigned long& CheckDigit, const std::string& val) {
        if (!AllValueIsHalfNumberText(val) || CheckDigit == 0 || CheckDigit > 9) return {};
        return std::to_string(CheckDigit) + "-" + val.substr(0, 4) + "-" + val.substr(4, 4) + "-" + val.substr(8, 4);
    }
}

inline std::string CalcCompanyNumber(std::string arg) {
    if (!CalculationImpl::CheckArg(arg)) return {};
    CalculationImpl::ConvertNumTextToHalfSizeString(arg);

    const unsigned long CheckDigit = CalculationImpl::CalcCheckDigit(arg);
    if (CheckDigit == 0) return {};
    return CalculationImpl::GenerateCompanyNumber(CheckDigit, arg);
}
