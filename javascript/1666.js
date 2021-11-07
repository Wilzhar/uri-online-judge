var input = require('fs').readFileSync('1666.txt', 'utf8');
var lines = input.split('\n');

var casesNumber = parseInt(lines[0]);

for (let i = 1; i <= casesNumber; i++) {
    let set = lines[i].trim();

    if (isSet(set)) {
        console.log(`Word #${i}: Set`);
    }
    else {
        console.log(`Word #${i}: No Set`);
    }
}

function isSet(set) {
    if (!(set[0] == "{" && set[set.length - 1] == "}")) {
        return false;
    }

    if (isElementList(set.substring(1, set.length - 1))) {
        return true;
    }

    return false;
}

function isElementList(set) {
    if (set == "") {
        return true;
    }

    if (isList(set)) {
        return true;
    }

    return false;


}

function isList(set) {
    if (isElement(set)) {
        return true;
    }

    let items = set.split(",");
    if (items.length > 0) {
        for (let i = 1; i < items.length; i++) {
            let tempArr = items.slice(0, i).join(",");
            if (isElement(tempArr)) {
                if (set[tempArr.length] == ",") {
                    if (isList(set.substring(tempArr.length + 1, set.length))) {
                        return true;
                    }
                }
            }
        }

    }
    return false;

}

function isElement(set) {
    if (isAtom(set) || isSet(set)) {
        return true;
    }
    else {
        return false;
    }
}


function isAtom(set) {
    if (set == "{" || set == "}" || set == ",") {
        return true;
    }
    else {
        return false;
    }
}
