/**
 * 法人番号のチェックディジットの計算
 * @param {string} CompanyNumberOnRegistry 会社法人等番号
 * @returns {number} 法人番号のチェックディジット
 */
export function CalcCheckDigit(CompanyNumberOnRegistry) {
    let AddIndex = 0;
    const totalArr = [0, 0];
    for (const a of CompanyNumberOnRegistry.split('')) {
        totalArr[AddIndex] += parseInt(a);
        AddIndex = (AddIndex + 1) % 2;
    }
    return 9 - ((totalArr[0] * 2 + totalArr[1]) % 9);
}
