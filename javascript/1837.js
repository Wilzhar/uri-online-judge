var input = require('fs').readFileSync('1837.txt', 'utf8');
var lines = input.split('\n');

var data = lines[0].trim().split(" ");
var dividend = parseInt(data[0]);
var divisor = parseInt(data[1]);
var remainer = dividend % divisor;
var quotient = 0;
if ((divisor < 0 && dividend < 0) || (divisor > 0 && dividend > 0)) {
    quotient = Math.floor(dividend / divisor);
} else {
    quotient = Math.round(dividend / divisor);
}

var equation = (divisor * quotient) + remainer;

console.log("dividend", dividend, "divisor", divisor, "quotient", quotient, "remainer", remainer)

console.log(`dividend = (${divisor} * ${quotient}) + ${remainer}`)
console.log("equation", equation, "dividend", dividend)

if (remainer > 0) {
    if (equation == dividend) {
        console.log(quotient, remainer);
    } else {
        console.log("nope")
        // r = a - (b * q)
        if (quotient < 0) {
            quotient--;
        }
        else {
            quotient++;
        }
        console.log(`remainer = ${dividend} - (${divisor} * ${quotient})`)
        remainer = dividend - (divisor * (quotient));

        console.log(quotient, remainer);
    }
}
else {
    console.log("nope")
    // r = a - (b * q)
    if (quotient < 0) {
        quotient--;
    }
    else {
        quotient++;
    }
    console.log(`remainer = ${dividend} - (${divisor} * ${quotient})`)
    remainer = dividend - (divisor * (quotient));

    console.log(quotient, remainer);
}

