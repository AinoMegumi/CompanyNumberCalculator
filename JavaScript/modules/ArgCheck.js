const argPattern = /[0-9０-９]{12}/;

/**
 * @param {string} arg
 * @returns {bool}
 */
export function CheckArg(arg) {
    return argPattern.test(arg);
};
