const { LLVM } = require('smake');
const { LibCron } = require('./lib');

const test = new LLVM('test', 'x86_64-linux-gnu');
test.files = ['test.cc'];
LibCron.config(test);

module.exports = [test];
