var input = require('fs').readFileSync('1383.txt', 'utf8');
var lines = input.split('\n');

var casesNumber = parseInt(lines[0]);

var currentLine = 1;

for (let i = 0; i < casesNumber; i++) {

    console.log(`Instancia ${i + 1}`);

    let rows = {
        1: 0,
        2: 0,
        3: 0,
        4: 0,
        5: 0,
        6: 0,
        7: 0,
        8: 0,
        9: 0
    };
    let subMatrix = {
        sub1: {
            1: 0,
            2: 0,
            3: 0,
            4: 0,
            5: 0,
            6: 0,
            7: 0,
            8: 0,
            9: 0
        },
        sub2: {
            1: 0,
            2: 0,
            3: 0,
            4: 0,
            5: 0,
            6: 0,
            7: 0,
            8: 0,
            9: 0
        },
        sub3: {
            1: 0,
            2: 0,
            3: 0,
            4: 0,
            5: 0,
            6: 0,
            7: 0,
            8: 0,
            9: 0
        }
    };
    let columns = {
        col1: {
            1: 0,
            2: 0,
            3: 0,
            4: 0,
            5: 0,
            6: 0,
            7: 0,
            8: 0,
            9: 0
        },
        col2: {
            1: 0,
            2: 0,
            3: 0,
            4: 0,
            5: 0,
            6: 0,
            7: 0,
            8: 0,
            9: 0
        },
        col3: {
            1: 0,
            2: 0,
            3: 0,
            4: 0,
            5: 0,
            6: 0,
            7: 0,
            8: 0,
            9: 0
        },
        col4: {
            1: 0,
            2: 0,
            3: 0,
            4: 0,
            5: 0,
            6: 0,
            7: 0,
            8: 0,
            9: 0
        },
        col5: {
            1: 0,
            2: 0,
            3: 0,
            4: 0,
            5: 0,
            6: 0,
            7: 0,
            8: 0,
            9: 0
        },
        col6: {
            1: 0,
            2: 0,
            3: 0,
            4: 0,
            5: 0,
            6: 0,
            7: 0,
            8: 0,
            9: 0
        },
        col7: {
            1: 0,
            2: 0,
            3: 0,
            4: 0,
            5: 0,
            6: 0,
            7: 0,
            8: 0,
            9: 0
        },
        col8: {
            1: 0,
            2: 0,
            3: 0,
            4: 0,
            5: 0,
            6: 0,
            7: 0,
            8: 0,
            9: 0
        },
        col9: {
            1: 0,
            2: 0,
            3: 0,
            4: 0,
            5: 0,
            6: 0,
            7: 0,
            8: 0,
            9: 0
        }
    };

    flag = true;

    colsNum = Object.keys(columns);
    subMatrixNum = Object.keys(subMatrix);

    for (let j = 0; j < 9 && flag; j++) {
        let row = lines[currentLine + j].trim().replace(/[\r\n\t]/g, " ").split(" ");

        for (let k = 0; k < 9 && flag; k++) {

            let value = parseInt(row[k]);

            //Check the rows
            if (rows[value] == j) {
                rows[value] += 1;
            }
            else {
                flag = false;
            }

            //Check submatrix
            if (flag) {
                let count = Math.floor(j / 3);
                let pos = Math.floor(k / 3);
                if (subMatrix[subMatrixNum[pos]][value] < count + 1) {
                    subMatrix[subMatrixNum[pos]][value] += 1;
                }
                else {
                    flag = false;
                }
            }

            //check columns
            if (flag) {
                if (columns[colsNum[k]][value] == 0) {
                    columns[colsNum[k]][value] += 1;
                }
                else {
                    flag = false;
                }
            }
        }
    }

    if (flag) {
        console.log("SIM");
    }
    else {
        console.log("NAO");
    }
    currentLine += 9;

    console.log("")
}