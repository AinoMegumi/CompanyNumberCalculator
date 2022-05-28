import test from 'ava';
import { CalcCheckDigit } from '../modules/CheckDigit.js';

// ここで検査されるメソッドの引数に渡される数値はすでに検査され、長さ12の半角数字の文字列のみであり、それ以外の値が渡されることは100%無い
// そのため、検査は長さ12の半角数字の文字列のみ実施

test('Calc Check Digit', t => {
    t.is(CalcCheckDigit('700110005901'), 8); 
});
