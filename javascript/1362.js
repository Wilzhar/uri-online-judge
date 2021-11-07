var input = require('fs').readFileSync('1362.txt', 'utf8');
var lines = input.split('\n');

var casesNumber = parseInt(lines[0]);

var lineNumber = 1;

for (let i = 0; i < casesNumber; i++) {
    let data = lines[lineNumber].trim().split(" ");
    let tShirtAvailableNumber = parseInt(data[0]) / 6;
    let volunteersNumber = parseInt(data[1]);

    let tShirts = {
        XS: 0,
        S: 0,
        M: 0,
        L: 0,
        XL: 0,
        XXL: 0
    };

    if (matchTShirts(lineNumber, volunteersNumber, 0, 1, tShirts, tShirtAvailableNumber)) {
        console.log("YES");
    }
    else {
        console.log("NO");
    }

    lineNumber += volunteersNumber + 1;
}


function matchTShirts(lineNumber, volunteersNumber, currentVolunteerNumber, pos, tShirts, tShirtsNumber) {
    if (currentVolunteerNumber == volunteersNumber) {
        return true;
    }
    else if (pos > volunteersNumber) {
        return false;
    }
    else {
        let volunteerTypes = lines[lineNumber + pos].trim().split(" ");


        for (let i = 0; i < volunteerTypes.length; i++) {

            if (tShirts[volunteerTypes[i]] < tShirtsNumber) {
                tShirts[volunteerTypes[i]] += 1;
                if (matchTShirts(lineNumber, volunteersNumber, currentVolunteerNumber + 1, pos + 1, tShirts, tShirtsNumber)) {
                    return true;
                }
                tShirts[volunteerTypes[i]] -= 1;
            }
        }

        return false;
    }
}