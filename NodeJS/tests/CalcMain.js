import test from 'ava';
import { CalcCompanyNumber } from '../modules/CalcMain.js';

test('Calc Company Number', t => {
    t.is(CalcCompanyNumber('700110005901'), '8-7001-1000-5901');
    t.is(CalcCompanyNumber('７００１１０００５９０１'), '8-7001-1000-5901');
    t.is(CalcCompanyNumber('70011０００5901'), '8-7001-1000-5901');
    t.is(CalcCompanyNumber('7001005901'), null);
    t.is(CalcCompanyNumber('HelloWorld11'), null);
});
