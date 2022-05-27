import { CheckArg } from './ArgCheck.js';
import { CalcCheckDigit } from './CheckDigit.js';

/**
 * 
 * @param {string} val 商業登記簿記載の会社法人等番号
 * @returns {string} 法人番号
 */
export function CalcCompanyNumber(val) {
    if (!CheckArg(val)) return null;
    const CompanyNumberOnRegistry = val.replace(/[０-９]/g, s => String.fromCharCode(s.charCodeAt(0) - 0xfee0));
    const CheckDigit = CalcCheckDigit(CompanyNumberOnRegistry);
    return (
        CheckDigit +
        '-' +
        CompanyNumberOnRegistry.substr(0, 4) +
        '-' +
        CompanyNumberOnRegistry.substr(4, 4) +
        '-' +
        CompanyNumberOnRegistry.substr(8, 4)
    );
}
