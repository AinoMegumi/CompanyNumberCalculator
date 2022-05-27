import { CalcCompanyNumber } from './modules/CalcMain.js';
/**
 *
 * @param {string[]} argv command line arguments
 * @returns
 */
const main = argv => {
    let dataIndex = 1;
    for (const a of argv) {
        const result = CalcCompanyNumber(a);
        if (result == null) console.log(dataIndex++ + '.' + 'Invalid value');
        else console.log(dataIndex++ + '.' + result);
    }
    return 0;
};

const args = process.argv;
args.shift();
args.shift();
main(args);
