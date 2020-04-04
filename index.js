const mathAddon = require('./build/Release/mathaddon.node');

console.log('mathaddon', mathAddon.squareRoot(17, 3));

const classInstance = new mathAddon.ClassExample(4.3);
console.log("Testing class initial value: ", classInstance.getValue());
console.log('After adding 3.3 : ', classInstance.add(3.3));

const newFromExisting = new mathAddon.ClassExample(classInstance);
console.log('Testing class initial value for derived instance');
console.log(newFromExisting.getValue());

module.exports = mathAddon;
/* the most imporant work */