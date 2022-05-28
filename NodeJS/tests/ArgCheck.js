import test from 'ava';
import { CheckArg } from '../modules/ArgCheck.js';

test('Argument check', t => {
    t.is(CheckArg('700110005901'), true);
    t.is(CheckArg('７００１１０００５９０１'), true);
    t.is(CheckArg('70011０００5901'), true);
    t.is(CheckArg('7001005901'), false);
    t.is(CheckArg('HelloWorld11'), false);
});
