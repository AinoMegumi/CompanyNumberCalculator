#include <string>
#include <vector>
#include <unordered_map>
#include <regex>
#include <utility>

namespace CalculationImpl {
    namespace {
        void ReplaceString(std::string& src, const std::string oldStr, const std::string newStr) noexcept {
            std::string::size_type Pos(src.find(oldStr));
            while( Pos != std::string::npos ) {
                src.replace(Pos, oldStr.length(), newStr);
                Pos = src.find(oldStr, Pos + newStr.length());
            }
        }
    }

    inline bool CheckArg(const std::string& val) {
        static const std::regex r(R"([0-9０-９]{12})");
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

    inline std::vector<unsigned long> SplitAll(const std::string& str) {
        static const std::regex r(R"([0-9]{12})");
        if (std::regex_match(str, r)) return {};

        std::vector<unsigned long> Ret{};
        for (const auto& i : str) Ret.emplace_back(static_cast<unsigned long>(i - '0'));
        return Ret;
    }

    inline unsigned long CalcCheckDigit(const std::vector<unsigned long>& arr) {
        bool b = false;
        unsigned long TotalBuf[2] = { 0, 0 };
        for (const unsigned long& i : arr) TotalBuf[std::exchange(b, !b)] += i;
        return 9 - ((TotalBuf[0] * 2 + TotalBuf[1]) % 9);
    }

    inline std::string GenerateCompanyNumber(const unsigned long& CheckDigit, const std::vector<unsigned long>& arr) {
        if (arr.size() != 12) return {};
        std::string Ret = std::to_string(CheckDigit) + "-";
        size_t start = Ret.size();
        size_t last = Ret.size();
        for (const unsigned long& i : arr) {
            Ret += std::to_string(CheckDigit);
            if (++last - start == 4) {
                Ret += "-";
                start = ++last;
            }
        }
        Ret.erase(Ret.end() - 1);
        return Ret;
    }
}

inline std::string CalcCompanyNumber(std::string arg) {
    if (!CalculationImpl::CheckArg(arg)) return {};
    CalculationImpl::ConvertNumTextToHalfSizeString(arg);
    const std::vector<unsigned long> NumArr = CalculationImpl::SplitAll(arg);
    if (NumArr.empty()) return {};
    return CalculationImpl::GenerateCompanyNumber(CalculationImpl::CalcCheckDigit(NumArr), NumArr);
}
